#include "main.h"
#include "stm32f1xx_hal.h"

#define PwmA_In1_ON  HAL_GPIO_WritePin(MoterA_1_GPIO_Port,MoterA_1_Pin,GPIO_PIN_SET)
#define PwmA_In1_OFF HAL_GPIO_WritePin(MoterA_1_GPIO_Port,MoterA_1_Pin,GPIO_PIN_RESET)
#define PwmA_In2_ON  HAL_GPIO_WritePin(MoterA_2_GPIO_Port,MoterA_2_Pin,GPIO_PIN_SET)
#define PwmA_In2_OFF HAL_GPIO_WritePin(MoterA_2_GPIO_Port,MoterA_2_Pin,GPIO_PIN_RESET)

#define PwmB_In1_ON  HAL_GPIO_WritePin(MoterB_1_GPIO_Port,MoterB_1_Pin,GPIO_PIN_SET)
#define PwmB_In1_OFF HAL_GPIO_WritePin(MoterB_1_GPIO_Port,MoterB_1_Pin,GPIO_PIN_RESET)
#define PwmB_In2_ON  HAL_GPIO_WritePin(MoterB_2_GPIO_Port,MoterB_2_Pin,GPIO_PIN_SET)
#define PwmB_In2_OFF HAL_GPIO_WritePin(MoterB_2_GPIO_Port,MoterB_2_Pin,GPIO_PIN_RESET)

extern TIM_HandleTypeDef htim1;

/**************************************************************************
函数功能：绝对值函数
入口参数：int
返回  值：unsigned int
**************************************************************************/
uint16_t myabs(int16_t a)
{ 		   
	  int16_t temp;
		if(a<0)  temp=-a;  
	  else temp=a;
	  return temp;
}

void Moter_Start(void)
{
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	  HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_4);
}
void Right_Moter(int16_t pwm_val)
{
	  if(pwm_val>0)			
		{
			  PwmA_In2_ON;			
			  PwmA_In1_OFF;
		}
		else
		{			
			  PwmA_In2_OFF;			
			  PwmA_In1_ON;
		}
		pwm_val = myabs(pwm_val);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,pwm_val);
}

void Left_Moter(int16_t pwm_val)
{
	  if(pwm_val>0)			
		{
			  PwmB_In2_OFF;			
			  PwmB_In1_ON;
		}      
		else   
		{			 
			  PwmB_In2_ON;			
			  PwmB_In1_OFF;
		}
		pwm_val = myabs(pwm_val);
    __HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_4,pwm_val);
}





