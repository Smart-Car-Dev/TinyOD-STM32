#ifndef __RISK_CALC_H
#define __RISK_CALC_H

#include <stdint.h>

typedef struct
{
    uint32_t speed_m_s;
    uint32_t distance_m;
    uint32_t ttc_ms;
} VehicleState_t;

void RiskCalc_CalculateTTC(VehicleState_t *state);

#endif