#ifndef __FSM_CONTROLLER_H
#define __FSM_CONTROLLER_H

#include "stdint.h"
#include "risk_calc.h"

typedef enum
{
    STATE_NORMAL,
    STATE_WARNING,
    STATE_BRAKE,
    STATE_SAFE_STOP
} SystemState_t;

void FSM_Init(void);
void FSM_Update(uint8_t obstacle_prob, VehicleState_t *v_state);
SystemState_t FSM_GetState(void);

#endif