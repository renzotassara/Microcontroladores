
#include "main.h"
#include "Matriz.h"
#include "Movimiento_Motores.h"
#include <stdio.h>
#include <stdlib.h>


const uint16_t pxmmX = 150; //Pasos por mm del motor X (previamente calibrados, no es numero al azar)
const uint16_t pxmmY = 150; //Pasos por mm del motor Y
uint8_t velocidad = 1;	//Mientras mas grande es el numero => menor velocidad tendra

//---Estandarizaciones del sistema Braille---
const uint8_t a = 2.5;
const uint8_t b = 2.5;
const uint8_t c = 6.5;
const uint8_t d = 10.5;

void Movimiento_Motores(int accion){
	switch(accion){
		case CAMBIO_RENGLON:	//Cambio de renglon
				for (int i = 0; i < pxmmY*d; i++){
					HAL_GPIO_TogglePin(GPIOA, motorY_Pin);
					HAL_Delay(velocidad);
				}
				break;	//break esta comentado porque generaba problemas

		case CAMBIO_FILA:	//Cambio de fila

				for (int i = 0; i < pxmmY*b; i++){
					HAL_GPIO_TogglePin(GPIOA, motorY_Pin);
					HAL_Delay(velocidad);
				}
				HAL_GPIO_TogglePin(GPIOB, dir_motorX_Pin); //Cambio de sentido el motor X
				break;

		case CAMBIO_COLUMNA: //Cambio de columna
				for (int i = 0; i < pxmmX*a; i++){
					HAL_GPIO_TogglePin(GPIOA, motorX_Pin);
					HAL_Delay(velocidad);
				}
				break;

		case CAMBIO_LETRA://Cambio de letra
				for (int i = 0; i < pxmmX*(c-a); i++){
					HAL_GPIO_TogglePin(GPIOA, motorX_Pin);
					HAL_Delay(velocidad);
				}
				break;
	}
}
