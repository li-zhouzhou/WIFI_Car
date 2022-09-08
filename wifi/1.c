#include "stm32f1xx_hal.h"
#include "my_func.h"
#include "stdio.h"

#include "main.h"


extern UART_HandleTypeDef huart1;//wifi
extern UART_HandleTypeDef huart2;//usb



//extern TIM_HandleTypeDef htim1;
//extern TIM_HandleTypeDef htim2;
//extern TIM_HandleTypeDef htim3;
//extern TIM_HandleTypeDef htim4;




uint8_t my_re_buf1[2000];//wifi
uint8_t my_re_buf2[2000];
uint8_t send_buf[512];
uint16_t pt_w1=0,pt_w2=0,pt_r1=0,pt_r2=0;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart==&huart1)
	{	
		HAL_UART_Receive_IT(&huart1,&my_re_buf1[++pt_w1],1);			
	}
	
	if(huart==&huart2)
	{	
		HAL_UART_Receive_IT(&huart2,&my_re_buf2[++pt_w2],1);
	}
	
}


//==========================
extern TIM_HandleTypeDef htim4;

int t4_count=0,m=0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim)
{
	int i=0,len=0;
	if(htim==&htim4)
	{
		
		
		t4_count++;
		

			while(pt_r1<pt_w1 )
		{
			while(pt_r1<pt_w1)
				HAL_UART_Transmit(&huart2,&my_re_buf1[pt_r1++],1,1000);				//将wifi发给板子的数据转发到PC机
			HAL_UART_Transmit(&huart2,(uint8_t *)"\r\n",2,1000);						//每输出一行后自动换行
								
			//test begin 
			if(find_str("LED")){
		
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);			
			//HAL_UART_Transmit(&huart1, (uint8_t *)"success", 7, 0xFFFF);   //return 
			
			}
			
			if(find_str("OFF")){
		
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);			
			//HAL_UART_Transmit(&huart1, (uint8_t *)"success", 7, 0xFFFF);   //return 
			
			}
			
			 
			if(find_str("GO")){
				
				
				
				 HAL_GPIO_WritePin(GPIOA, MOT2_H_Pin|MOT3_H_Pin|MOT4_H_Pin|MOT1_H_Pin, GPIO_PIN_SET);
       
				
				
		
//			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,600);
//				__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,600);
//				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,600);
//					__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,600);
			
			}
			
			if(find_str("LEFT")){
		
			 HAL_GPIO_WritePin(GPIOA, MOT3_H_Pin|MOT2_H_Pin, GPIO_PIN_SET);
				
			 HAL_GPIO_WritePin(GPIOA, MOT4_L_Pin|MOT1_L_Pin, GPIO_PIN_SET);
       
			
			}
			
			if(find_str("SHOT")){
		
			 HAL_GPIO_WritePin(GPIOA, MOT3_H_Pin|MOT2_H_Pin, GPIO_PIN_SET);
			
			}
			
			if(find_str("BACK")){
		
		  HAL_GPIO_WritePin(GPIOA, MOT4_L_Pin|MOT1_L_Pin, GPIO_PIN_SET);
			
			}
			
			
			
			
			if(find_str("STOP")){
				
				
				
				 HAL_GPIO_WritePin(GPIOA, MOT4_L_Pin|MOT1_L_Pin|MOT2_H_Pin|MOT3_H_Pin|MOT4_H_Pin|MOT1_H_Pin, GPIO_PIN_RESET);
         HAL_GPIO_WritePin(GPIOB, MOT3_L_Pin|MOT2_L_Pin, GPIO_PIN_RESET);
	
		
//			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,0);
//				__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
//				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
//				__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,0);
			
			}
			
			
			
			
			
			//test end
			
		}
		
		if(pt_r1>=pt_w1)
		{
			pt_w1=pt_r1=0;
			HAL_UART_AbortReceive_IT(&huart1);
			HAL_UART_Receive_IT(&huart1,my_re_buf1,1);
		}
		
		
		while(send_buf[i])send_buf[i++]=0x00;			//清空send_buf数组
		while(pt_r2<pt_w2 )
		{
			
			
			
			
			HAL_UART_Transmit(&huart1,&my_re_buf2[pt_r2++],1,1000);					//将PC发给板子的数据转发到wifi模块
			
			HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);    //LED
			
			
			
//			while(pt_r2<pt_w2)
//				send_buf[len++]=my_re_buf2[pt_r2++];
//			wifi_send(send_buf,len);
//			
			
			
		}
		if(pt_r2>=pt_w2)
		{
			pt_w2=pt_r2=0;
			HAL_UART_AbortReceive_IT(&huart2);	
			HAL_UART_Receive_IT(&huart2,my_re_buf2,1);
		}
		
	}
	
	
}





//=============================
//int x=0;
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
//{ 
//	
//	if(GPIO_Pin==GPIO_PIN_13)
//	{
//			x++;
//		if(x%2==0)
//		{
//			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);
//		}
//		else
//		{
//			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
//		}
//		
//	}
//	
//	
//	
//	
//}









