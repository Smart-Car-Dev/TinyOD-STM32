#include "fsm_controller.h"
#include "risk_calc.h"

static SystemState_t current_state = STATE_NORMAL;

void FSM_Init(void) {
    current_state = STATE_NORMAL;
}

void FSM_Update(uint8_t obstacle_prob, VehicleState_t *v_state) {
    switch(current_state) {
        
        case STATE_NORMAL:
            if (obstacle_prob > 60) {
                current_state = STATE_WARNING;
            } else {
                v_state->ttc_ms = 0;
            }
            break;

        case STATE_WARNING:
            RiskCalc_CalculateTTC(v_state);
            
            if (v_state->ttc_ms < 1200) {
                current_state = STATE_BRAKE;
            } 
            else if (obstacle_prob <= 60) {
                current_state = STATE_NORMAL;
            }
            break;

        case STATE_BRAKE:
            current_state = STATE_SAFE_STOP;
            break;

        case STATE_SAFE_STOP:
            if (obstacle_prob <= 60) {
                current_state = STATE_NORMAL;
            }
            break;

        default:
            current_state = STATE_NORMAL;
            break;
    }

    if (current_state == STATE_NORMAL) {
        v_state->ttc_ms = 0;
    }
}

SystemState_t FSM_GetState(void) {
    return current_state;
}