#include "main.h"
#include "stm32f1xx_hal.h"
/**************************************************************************
函数功能：LED闪烁
入口参数：闪烁频率 
返回  值：无
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
