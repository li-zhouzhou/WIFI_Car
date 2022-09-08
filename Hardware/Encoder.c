#include "main.h"
#include "stm32f1xx_hal.h"
 
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;

void Encoder_start(void)
{
    __HAL_TIM_SET_COUNTER(&htim2,0);
    __HAL_TIM_SET_COUNTER(&htim4,0);
	  HAL_TIM_Encoder_Start_IT(&htim2,TIM_CHANNEL_ALL);
	  HAL_TIM_Encoder_Start_IT(&htim4,TIM_CHANNEL_ALL);
	  HAL_TIM_Encoder_Start(&htim2,TIM_CHANNEL_ALL);
	  HAL_TIM_Encoder_Start(&htim4,TIM_CHANNEL_ALL);
}
/**************************************************************************
function: unit time read encoder numbers
function input:time 
function output:  speed value    
notition: Encoder_TIM>0 -> forward run
          Encoder_TIM<0 -> back run
**************************************************************************/
int Read_Encoder(uint8_t TIMX)
{
    int Encoder_TIM = 0;  
    switch(TIMX)
	{
	    case 2:  
			    Encoder_TIM= -(short)__HAL_TIM_GET_COUNTER(&htim2);
          	
		      __HAL_TIM_SET_COUNTER(&htim2,0);
		      break;
		/*case 3:  
			Encoder_TIM= __HAL_TIM_GET_COUNTER(&htim2);  TIM3 -> CNT=0;break;	
		*/
		 case 4:  
			    Encoder_TIM= -(short)__HAL_TIM_GET_COUNTER(&htim4);     
		      __HAL_TIM_SET_COUNTER(&htim4,0);
		      break;	
		 default:  
			    Encoder_TIM=0;
	  }
		return Encoder_TIM;
}
