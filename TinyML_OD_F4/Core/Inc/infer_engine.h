#ifndef INFER_ENGINE_H
#define INFER_ENGINE_H

#include <stdint.h>

/**
 * @brief مقداردهی اولیه موتور استنتاج هوش مصنوعی
 * @return int8_t وضعیت مقداردهی (0 = موفق، -1 = خطا)
 */
int8_t InferEngine_Init(void);

/**
 * @brief اجرای استنتاج شبکه عصبی
 * @return uint8_t درصد احتمال مانع
 */
uint8_t InferEngine_Run(void);

#endif /* INFER_ENGINE_H */