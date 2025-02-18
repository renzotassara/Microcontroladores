#include "Movimiento_Servo.h"
#include "stm32f1xx_hal.h"
#include "main.h"

uint16_t pos_final = 750;	//550 = 0º y 2450 = 180º
uint8_t vel_servo = 5;	//Cuanto menor sea el numero, mas rapido será
uint16_t pos_inicial = 550;	//Valor inicial (0º)
uint16_t pos_actual;
uint16_t t_reposo = 10;


void Movimiento_Servo(){

	pos_actual = pos_inicial;

	while(pos_actual <= pos_final){
		HAL_Delay(vel_servo);
		TIM2->CCR3 = pos_actual;
		pos_actual += 5;	//Incremento
	}

	HAL_Delay(t_reposo);

	while (pos_actual >= pos_inicial){
		HAL_Delay(vel_servo);
		TIM2->CCR3 = pos_actual;
		pos_actual -= 5;	//Decremento
	}
}
