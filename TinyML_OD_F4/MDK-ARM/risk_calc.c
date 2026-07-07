#include "risk_calc.h"
#include <stdio.h>

#define SIM_SPEED_M_S   10
#define SIM_DISTANCE_M  10

void RiskCalc_CalculateTTC(VehicleState_t *state) {
    state->speed_m_s = SIM_SPEED_M_S;
    state->distance_m = SIM_DISTANCE_M;
    
    if (state->speed_m_s > 0) {
        state->ttc_ms = (state->distance_m * 1000) / state->speed_m_s;
    } else {
        state->ttc_ms = 9999; 
    }
}