#include "preprocess.h"

void Preprocess_NormalizeFloat(const uint8_t *raw_pixels,
                               float *model_input_buffer,
                               uint32_t num_elements) {
    for (uint32_t i = 0; i < num_elements; i++) {
        model_input_buffer[i] = (float)raw_pixels[i] / 255.0f;
    }
}