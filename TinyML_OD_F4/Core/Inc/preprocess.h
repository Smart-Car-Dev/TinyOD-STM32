#ifndef __PREPROCESS_H
#define __PREPROCESS_H

#include <stdint.h>

void Preprocess_NormalizeFloat(const uint8_t *raw_pixels,
                               float *model_input_buffer,
                               uint32_t num_elements);

#endif