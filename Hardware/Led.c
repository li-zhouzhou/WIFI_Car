#include "main.h"
#include "stm32f1xx_hal.h"
/**************************************************************************
�������ܣ�LED��˸
��ڲ�������˸Ƶ�� 
����  ֵ����
**************************************************************************/
void Led_Flash(uint16_t time)
{
	  static int16_t temp;
		if(++temp==time)
		{
		    HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
			  temp=0;
		}			
}
