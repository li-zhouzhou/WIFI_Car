#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f1xx_hal.h"

extern void Moter_Start(void);
extern void Right_Moter(int16_t pwm_val);
extern void Left_Moter(int16_t pwm_val);

#endif
