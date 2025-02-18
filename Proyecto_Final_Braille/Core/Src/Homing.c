#include <Homing.h>
#include "Movimiento_Motores.h"
#include "main.h"
#include "lcd.h"

uint16_t velocidad1_homing = 1;
uint16_t velocidad2_homing = 3;
//const uint16_t pxmmX = 110; //Pasos por mm del motor X (previamente calibrados, no es numero al azar)
//const uint16_t pxmmY = 110; //Pasos por mm del motor Y

void Homing(){
	homingX = 1;
	homingY = 1;
	Lcd_PortType ports[] = { GPIOB, GPIOB, GPIOB, GPIOB };
	Lcd_PinType pins[] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_10, GPIO_PIN_11};
	Lcd_HandleTypeDef lcd;
	lcd = Lcd_create(ports, pins, GPIOA, GPIO_PIN_1, GPIOA, GPIO_PIN_3, LCD_4_BIT_MODE);

	//====Homing rapido====
	HAL_GPIO_WritePin(GPIOB, dir_motorX_Pin, GPIO_PIN_RESET);	//seteo sentido de cada motor
	HAL_GPIO_WritePin(GPIOB, dir_motorY_Pin, GPIO_PIN_RESET);

	while(homingX == 1 || homingY == 1){
		if (homingX == 1){
			HAL_GPIO_TogglePin(GPIOA, motorX_Pin);
		}
		if (homingY == 1){
			HAL_GPIO_TogglePin(GPIOA, motorY_Pin);
		}
		HAL_Delay(velocidad1_homing);
	}

	//===Retroceso===
	HAL_GPIO_WritePin(GPIOB, dir_motorX_Pin, GPIO_PIN_SET);	//seteo sentido de cada motor
	HAL_GPIO_WritePin(GPIOB, dir_motorY_Pin, GPIO_PIN_SET);
	NVIC_DisableIRQ(EXTI9_5_IRQn);
	for (int i = 0; i < 1000; i++){
		HAL_GPIO_TogglePin(GPIOA, motorX_Pin);
		HAL_GPIO_TogglePin(GPIOA, motorY_Pin);
		HAL_Delay(velocidad1_homing);
	}
	NVIC_EnableIRQ(EXTI9_5_IRQn);

	//===Homing lento===
	HAL_GPIO_WritePin(GPIOB, dir_motorX_Pin, GPIO_PIN_RESET);	//seteo sentido de cada motor
	HAL_GPIO_WritePin(GPIOB, dir_motorY_Pin, GPIO_PIN_RESET);


	while(homingX == 2 || homingY == 2){
		if (homingX == 2){
			HAL_GPIO_TogglePin(GPIOA, motorX_Pin);
		}
		if (homingY == 2){
			HAL_GPIO_TogglePin(GPIOA, motorY_Pin);
		}
		HAL_Delay(velocidad2_homing);
	}

	HAL_GPIO_WritePin(GPIOB, dir_motorY_Pin, GPIO_PIN_SET);
	for (int i = 0; i < pxmmY*35; i++){	//Eje Y se va al extremo opuesto al del final de carrera alli es donde debe comenzar la impresion
		HAL_GPIO_TogglePin(GPIOA, motorY_Pin);
		HAL_Delay(velocidad1_homing);
	}
	HAL_GPIO_WritePin(GPIOB, dir_motorX_Pin, GPIO_PIN_SET);	//seteo sentido de cada motor
	HAL_GPIO_WritePin(GPIOB, dir_motorY_Pin, GPIO_PIN_SET);
	homingX = 0;
	homingY = 0;
}

