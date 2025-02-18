#include "Funcion_Delay.h"
#include "main.h"

uint8_t contador_delay = 0;

void delay(uint16_t milisegundos)
{
	contador_delay = 0;
	while (contador_delay < 10){
		if ((__HAL_TIM_GET_COUNTER(&htim4)) < milisegundos){
			//__NOP();
		}	//Espera
		else{
			contador_delay++;						//Lo tuve que agregar para que cuente ms y no us
			__HAL_TIM_SET_COUNTER(&htim4, 0);
		}
	}
}

