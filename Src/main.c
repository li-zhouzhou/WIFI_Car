/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "DataScope_DP.h"

#include "my_func.h"

//#include "Oled.h"

//#include "IIC.h"
//#include "Mpu6050.h"
#include "Printf.h"


#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;

osThreadId defaultTaskHandle;
osThreadId myTask02Handle;
osThreadId myTask03Handle;
osThreadId myTask04Handle;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM4_Init(void);
void StartDefaultTask(void const * argument);
void StartTask02(void const * argument);
void StartTask03(void const * argument);
void StartTask04(void const * argument);


void GET(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


extern UART_HandleTypeDef huart1;
#ifdef __GNUC__
	#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
	#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
		HAL_UART_Transmit(&huart2 , (uint8_t *)&ch, 1, 0xFFFF);
		return ch;
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  /* USER CODE BEGIN 1 */
    int Vol = 0,i;
	int Send_Count = 0;
	int temp;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
	
	
	
	//angle varity
	

	
	
	
	//uart wifi
	
	extern uint8_t my_re_buf1[];
	extern uint8_t my_re_buf2[];
	HAL_UART_Receive_IT(&huart1,my_re_buf1,1);
	HAL_UART_Receive_IT(&huart2,my_re_buf2,1);
	
	
	HAL_TIM_Base_Start_IT(&htim4);
	
	
		switch(wifi_init())
	{
		case -1:HAL_UART_Transmit(&huart2, (uint8_t *)AT_ERROR, strlen(AT_ERROR), 0xFFFF);break;
		case -2:HAL_UART_Transmit(&huart2, (uint8_t *)MODE_ERROR, strlen(MODE_ERROR), 0xFFFF);break;
		case -3:HAL_UART_Transmit(&huart2, (uint8_t *)CONECT_WIFI_ERROR, strlen(CONECT_WIFI_ERROR), 0xFFFF);break;
		
		//test begin
		
		default :{
			HAL_UART_Transmit(&huart2, (uint8_t *)"wifi连接成功\r\n", 14, 0xFFFF);
			
			for(i=0;i++;i<3){
				
				GET();
			}
			
			break;
		}
		
	}
	
	
	
	
	


  HAL_GPIO_WritePin(GPIOA, MOT4_L_Pin|MOT1_L_Pin|MOT2_H_Pin|MOT3_H_Pin|MOT4_H_Pin|MOT1_H_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOB, MOT3_L_Pin|MOT2_L_Pin, GPIO_PIN_RESET);
	
//	
//		HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
//			HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
//				HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
//					HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1);
		
		
    
	//OLED_Init();

//	MPU6050_initialize();
	//DMP_Init();
  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of myTask02 */
  osThreadDef(myTask02, StartTask02, osPriorityIdle, 0, 128);
  myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

  /* definition and creation of myTask03 */
  osThreadDef(myTask03, StartTask03, osPriorityIdle, 0, 128);
  myTask03Handle = osThreadCreate(osThread(myTask03), NULL);

  /* definition and creation of myTask04 */
  osThreadDef(myTask04, StartTask04, osPriorityIdle, 0, 128);
  myTask04Handle = osThreadCreate(osThread(myTask04), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();
 
  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		 
		
//		 
//	//  Read_DMP();
//      Right_Moter(pwma_val);
//      Left_Moter(pwmb_val);
//	    counter1 = (float)Read_Encoder(2);
//	    coun2 ter2 = (float)Read_Encoder(4);
//	  //temp = Read_Temperature();
//	  printf("temp: %d\r\n",temp);
//	  printf("Pitch: %f\r\n",Pitch);
//	  printf("Roll: %f\r\n",Roll);
//		
//		
//		
//		    //TEST   MOTOR
////		
////				__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,800);
////						__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,800);
////								__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,800);
////										__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,800);
////		
//		
//		
//		
//		
//		//TEST ONE 
//		
//		if(Pitch>20){
//			
//			MOT1 = 1;
//			MOT3 = 0;
//			
//		}else if(Pitch<-20){
//			
//			MOT3 = 1;
//			MOT1 = 0;
//			
//		}
//		
//		
//		
//		if(MOT1 == 1){
//			
//			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,800);
//			
//		}else if(MOT3 = 1){
//			
//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,800);
//			
//		}else if(MOT1 = 0){
//			
//			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,0);
//			
//		}else if(MOT3 = 0){
//			
//			__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
//			
//		}
//		
//		
//		
//		
//		
//		
//		
//		if(Pitch>20){
//			
//			MOT1 = MOT1-Pitch;
//			
//			__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,MOT1);
//			
//			
//		}else if(Pitch<-20){
//			
//				MOT3 = MOT3-Pitch;
//			
//				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,MOT3);
//		}else{
//			
//				__HAL_TIM_SET_COMPARE(&htim1,TIM_CHANNEL_1,0);
//				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,0);
//		}
//		
//		if(Roll>40){
//			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,800);
//			
//			
//		}else if(Roll<-40){
//		
//				__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,800);
//			
//		}else {
//			
//			__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,0);
//				__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,0);
//		}
//		
//		
		
		

//    DataScope_Get_Channel_Data(Read_Temperature(), 1 );
//	  DataScope_Get_Channel_Data(Pitch, 2 );
//	  DataScope_Get_Channel_Data(Roll, 3 ); 
//	  DataScope_Get_Channel_Data(counter2, 4 ); 
//	  Send_Count = DataScope_Data_Generate(3);
//      HAL_UART_Transmit(&huart1,DataScope_OutPut_Buffer,Send_Count,10);	  
	  
//      Vol = Get_battery_volt();
//	  OLED_ShowString(0,0,"DMP");	
//	  OLED_ShowString(00,40,"Vol");
//      OLED_ShowString(58,40,".");
//      OLED_ShowString(90,40,"V");
//      OLED_ShowNumber(40,40,Vol/1000,2,12);
//      OLED_ShowNumber(70,40,Vol%1000,2,12);
//      
//      OLED_Refresh_Gram();	
      HAL_Delay(100);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 200;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 3000;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, MOT1_L_Pin|MOT2_H_Pin|MOT3_H_Pin|MOT4_H_Pin 
                          |MOT1_H_Pin|MOT4_L_Pin|OLED_DC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OLED_RST_Pin|MOT3_L_Pin|OLED_D0_SCL_Pin|MOT2_L_Pin 
                          |FEN_Pin|LEDB9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Pin */
  GPIO_InitStruct.Pin = LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : MOT1_L_Pin MOT2_H_Pin MOT3_H_Pin MOT4_H_Pin 
                           MOT1_H_Pin MOT4_L_Pin */
  GPIO_InitStruct.Pin = MOT1_L_Pin|MOT2_H_Pin|MOT3_H_Pin|MOT4_H_Pin 
                          |MOT1_H_Pin|MOT4_L_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : OLED_DC_Pin */
  GPIO_InitStruct.Pin = OLED_DC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(OLED_DC_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : OLED_RST_Pin OLED_D0_SCL_Pin */
  GPIO_InitStruct.Pin = OLED_RST_Pin|OLED_D0_SCL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : MOT3_L_Pin MOT2_L_Pin FEN_Pin LEDB9_Pin */
  GPIO_InitStruct.Pin = MOT3_L_Pin|MOT2_L_Pin|FEN_Pin|LEDB9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */




/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */ 
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  for(;;)
  {
    
		 HAL_GPIO_WritePin(GPIOB,FEN_Pin, GPIO_PIN_RESET);
		
		HAL_Delay(1000);
		
		 HAL_GPIO_WritePin(GPIOB,FEN_Pin, GPIO_PIN_SET);
		
			HAL_Delay(200);
		
  }
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void const * argument)
{
  /* USER CODE BEGIN StartTask03 */
  /* Infinite loop */
  for(;;)
  {
    
		
		 HAL_GPIO_WritePin(GPIOB,LEDB9_Pin, GPIO_PIN_RESET);
		
		HAL_Delay(1000);
		
		 HAL_GPIO_WritePin(GPIOB,LEDB9_Pin, GPIO_PIN_SET);
		
			HAL_Delay(1000);
		
		
  }
  /* USER CODE END StartTask03 */
}

/* USER CODE BEGIN Header_StartTask04 */
/**
* @brief Function implementing the myTask04 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask04 */
void StartTask04(void const * argument)
{
  /* USER CODE BEGIN StartTask04 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask04 */
}



void GET(void)
{
   HAL_GPIO_WritePin(GPIOB,FEN_Pin, GPIO_PIN_RESET);
		
		HAL_Delay(500);
		
		 HAL_GPIO_WritePin(GPIOB,FEN_Pin, GPIO_PIN_SET);
		
			HAL_Delay(100);
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
