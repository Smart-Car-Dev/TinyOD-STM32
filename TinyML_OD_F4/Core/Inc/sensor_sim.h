#ifndef __SENSOR_SIM_H
#define __SENSOR_SIM_H

#include <stdint.h>

#define FRAME_WIDTH   96
#define FRAME_HEIGHT  96
#define FRAME_SIZE    (FRAME_WIDTH * FRAME_HEIGHT)
#define IMG_SIZE      9216

const uint8_t* SensorSim_GetImagePtr(void);

void SensorSim_InitTestbench(void);
uint8_t SensorSim_CaptureDynamicFrame(uint8_t *out_frame_buffer);

#endif