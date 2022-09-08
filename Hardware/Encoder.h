#ifndef __ENCODER_H
#define __ENCODER_H

#include "stm32f1xx_hal.h"

extern void Encoder_start(void);
extern int Read_Encoder(uint8_t TIMX);

#endif
