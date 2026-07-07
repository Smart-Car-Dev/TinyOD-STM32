#include "infer_engine.h"
#include "ai_platform.h"
#include "ob_model.h"
#include "ob_model_data.h"
#include "ob_model_data_params.h"
#include "preprocess.h"
#include "sensor_sim.h"
#include <string.h>
#include <stdio.h>

#include "stm32f4xx_hal.h"

#ifndef IMG_SIZE
#define IMG_SIZE AI_OB_MODEL_IN_1_SIZE
#endif

#ifndef OUT_SIZE
#define OUT_SIZE AI_OB_MODEL_OUT_1_SIZE
#endif

extern void UART_Print(const char *msg);
AI_ALIGNED(32)
static ai_u8 activations[AI_OB_MODEL_DATA_ACTIVATIONS_SIZE];

static ai_handle ob_model_network = AI_HANDLE_NULL;

AI_ALIGNED(4)
static float ai_in_buffer[IMG_SIZE];
AI_ALIGNED(4)
static float ai_out_buffer[OUT_SIZE];
char result_buffer[200];

static ai_buffer ai_input[1];
static ai_buffer ai_output[1];

static void InferEngine_PrepareData(void)
{
    const uint8_t *raw_image_ptr = SensorSim_GetImagePtr();
    Preprocess_NormalizeFloat(raw_image_ptr, ai_in_buffer, IMG_SIZE);
}

int8_t InferEngine_Init(void)
{
    ai_error err;
    ai_network_params params;

    if (ob_model_network != AI_HANDLE_NULL) {
        return 0; 
    }
		
    err = ai_ob_model_create(&ob_model_network, AI_OB_MODEL_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE) {
        UART_Print("AI Create Error\r\n");
        return -1;
    }

    if (!ai_ob_model_data_params_get(&params)) {
        UART_Print("AI Error: ai_ob_model_data_params_get failed!\r\n");
        ai_ob_model_destroy(ob_model_network);
        ob_model_network = AI_HANDLE_NULL;
        return -1;
    }

    if (params.map_activations.size > 0 && params.map_activations.buffer != NULL) {
        params.map_activations.buffer[0].data = AI_HANDLE_PTR(activations);
    } else {
        UART_Print("AI Error: Activations buffer array is empty!\r\n");
        ai_ob_model_destroy(ob_model_network);
        ob_model_network = AI_HANDLE_NULL;
        return -1;
    }

    snprintf(result_buffer, sizeof(result_buffer), "Act Size: %d, Weights Size: %d\r\n", 
             params.map_activations.buffer[0].size, 
             params.map_weights.buffer[0].size);
    UART_Print(result_buffer);
		HAL_Delay(1000);
    if (ai_ob_model_init(ob_model_network, &params)) {
        err = ai_ob_model_get_error(ob_model_network);
        
        if (err.type == 0 && err.code == 0) {
            UART_Print("AI Init Failed: Silent Error (Check Alignment or CRC)\r\n");
        } else {
            snprintf(result_buffer, sizeof(result_buffer), "AI Init Error: type=%d, code=%d\r\n", err.type, err.code);
            UART_Print(result_buffer);
        }
        
        ai_ob_model_destroy(ob_model_network);
        ob_model_network = AI_HANDLE_NULL;
        return -1;
    }

    UART_Print("AI Engine Initialized Successfully!\r\n");
    return 0;
}

uint8_t InferEngine_Run(void)
{
    ai_i32 n_batch;

    if (ob_model_network == AI_HANDLE_NULL)
    {
        snprintf(result_buffer, sizeof(result_buffer), "AI ERROR: Network Not Initialized\r\n");
        UART_Print(result_buffer);
        return 0;
    }

    InferEngine_PrepareData();
    
    ai_input[0] = ai_ob_model_inputs_get(ob_model_network, NULL)[0];
    ai_output[0] = ai_ob_model_outputs_get(ob_model_network, NULL)[0];

    ai_input[0].data = AI_HANDLE_PTR(ai_in_buffer);
    ai_output[0].data = AI_HANDLE_PTR(ai_out_buffer);

    snprintf(result_buffer, sizeof(result_buffer), "Input Size: %d, Output Size: %d | ", ai_input[0].size, ai_output[0].size);
    UART_Print(result_buffer);

    n_batch = ai_ob_model_run(ob_model_network, &ai_input[0], &ai_output[0]);
    
    if (n_batch != 1)
    {
        ai_error run_err = ai_ob_model_get_error(ob_model_network);
        snprintf(result_buffer, sizeof(result_buffer),
             "AI ERROR: n_batch=%ld type=%d code=%d\r\n",
             (long)n_batch, run_err.type, run_err.code);
        UART_Print(result_buffer);
        return 0;
    }
        
    float prob = ai_out_buffer[0];
    
    if (prob < 0.0f) prob = 0.0f;
    if (prob > 1.0f) prob = 1.0f;
        
    uint8_t prob_percent = (uint8_t)(prob * 100.0f);
        
    snprintf(result_buffer, sizeof(result_buffer), "Inference OK.");
    UART_Print(result_buffer);

    return prob_percent;
}