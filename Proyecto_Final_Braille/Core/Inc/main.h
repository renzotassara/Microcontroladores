/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim2;
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWM_Servo_Pin GPIO_PIN_2
#define PWM_Servo_GPIO_Port GPIOA
#define motorX_Pin GPIO_PIN_4
#define motorX_GPIO_Port GPIOA
#define motorY_Pin GPIO_PIN_5
#define motorY_GPIO_Port GPIOA
#define FinalCarreraX_Pin GPIO_PIN_6
#define FinalCarreraX_GPIO_Port GPIOA
#define FinalCarreraX_EXTI_IRQn EXTI9_5_IRQn
#define FinalCarreraY_Pin GPIO_PIN_7
#define FinalCarreraY_GPIO_Port GPIOA
#define FinalCarreraY_EXTI_IRQn EXTI9_5_IRQn
#define Fila1_EXTI_Pin GPIO_PIN_12
#define Fila1_EXTI_GPIO_Port GPIOB
#define Fila1_EXTI_EXTI_IRQn EXTI15_10_IRQn
#define Fila2_EXTI_Pin GPIO_PIN_13
#define Fila2_EXTI_GPIO_Port GPIOB
#define Fila2_EXTI_EXTI_IRQn EXTI15_10_IRQn
#define Fila3_EXTI_Pin GPIO_PIN_14
#define Fila3_EXTI_GPIO_Port GPIOB
#define Fila3_EXTI_EXTI_IRQn EXTI15_10_IRQn
#define Fila4_EXTI_Pin GPIO_PIN_15
#define Fila4_EXTI_GPIO_Port GPIOB
#define Fila4_EXTI_EXTI_IRQn EXTI15_10_IRQn
#define Columna1_Pin GPIO_PIN_8
#define Columna1_GPIO_Port GPIOA
#define Columna2_Pin GPIO_PIN_9
#define Columna2_GPIO_Port GPIOA
#define Columna3_Pin GPIO_PIN_10
#define Columna3_GPIO_Port GPIOA
#define Columna4_Pin GPIO_PIN_11
#define Columna4_GPIO_Port GPIOA
#define dir_motorY_Pin GPIO_PIN_3
#define dir_motorY_GPIO_Port GPIOB
#define dir_motorX_Pin GPIO_PIN_4
#define dir_motorX_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

//==========Variables AUX================
extern int8_t interrupcion;
extern GPIO_InitTypeDef GPIO_InitStructPrivate;
extern uint32_t miliseg_prev;
extern uint32_t miliseg_actual;
typedef enum{
	TEXTO,
	HOME,
	IMPRIMIR,
	MENU,
	ESPERAR
} EstadoImpresora;

extern EstadoImpresora estado_impresora;
//extern uint8_t homingX;
//extern uint8_t homingY;

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
