#ifndef __ADC_H
#define __ADC_H	

#include "main.h"

void Adc_Init(void);
uint32_t Get_Adc(uint8_t ch);
int Get_battery_volt(void);  

#endif 
 
