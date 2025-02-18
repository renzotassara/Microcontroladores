
#include <Matriz.h>
#include "Base_de_Datos.h"
#include "Movimiento_Motores.h"
#include "Movimiento_Servo.h"
#include "main.h"
#include "Homing.h"
#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"

uint8_t m = 0;
const uint8_t filasSubmatriz = 3;
const uint8_t columnasSubmatriz = 2;
uint8_t contador_fila = 0;
uint8_t contador_columna = 0;
uint8_t contador_elementos = 0;


void Armado_Matriz(char texto[],int filasMatriz, int columnasMatriz) {	// Se arma matriz donde se ingresan 1 si se debe hacer punto y 0 donde no hace nada

	// Creo la matriz de ceros
	uint8_t matriz[filasMatriz][columnasMatriz];

	//Completo con 1 y 0 la matriz segun el texto escrito
    for (int i = 0; i < filasMatriz; i += filasSubmatriz) {
        for (int j = 0; j < columnasMatriz; j += columnasSubmatriz) {
        	m++;	//Cambio de submatriz (letra)
            for (int k = 0; k < filasSubmatriz; k++) {
                for (int l = 0; l < columnasSubmatriz; l++) {
                    matriz[i + k][j + l] = Base_de_Datos(texto[m-1],k,l);
                }
            }
        }
    }
    m = 0; //reinicio la vaariable m
    Movimiento_Matriz(filasMatriz,columnasMatriz,matriz);
}

void Movimiento_Matriz(int filasMatriz, int columnasMatriz,uint8_t matriz[filasMatriz][columnasMatriz]) {

	estado_impresora = HOME;	//Realizo Homing antes de comenzar la impresion
	Homing();
	Lcd_PortType ports[] = { GPIOB, GPIOB, GPIOB, GPIOB };
		Lcd_PinType pins[] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_10, GPIO_PIN_11};
		Lcd_HandleTypeDef lcd;
		lcd = Lcd_create(ports, pins, GPIOA, GPIO_PIN_1, GPIOA, GPIO_PIN_3, LCD_4_BIT_MODE);
	//Pequeño movimiento para separarse de los finales de carrera ('OFFSET')
	/*HAL_GPIO_WritePin(GPIOB, dir_motorX_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, dir_motorY_Pin, GPIO_PIN_RESET);
	Movimiento_Motores(CAMBIO_FILA);
	Movimiento_Motores(CAMBIO_COLUMNA);*/
	HAL_GPIO_WritePin(GPIOB, dir_motorX_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, dir_motorY_Pin, GPIO_PIN_RESET);
	estado_impresora = IMPRIMIR;

	//=======IMPRESION=======

		for (int i = 0; i < filasMatriz; i++) {
			if (i > 0){
				if (contador_fila == 3){
					Movimiento_Motores(CAMBIO_RENGLON);
					contador_fila = 0;
				}
				else{
					Movimiento_Motores(CAMBIO_FILA);
					contador_fila++;
				}
			}

			if ((i == 0) || (i%2 == 0)){
				for (int j = 0; j < columnasMatriz; j++){	//Movimiento de izquierda a derecha
					Lcd_clear(&lcd);
					Lcd_cursor(&lcd, 0,0);
					Lcd_string(&lcd, "ELEMENTO [I,J]");
					Lcd_cursor(&lcd, 1,0);
					Lcd_string(&lcd, "[");
					Lcd_cursor(&lcd, 1,1);
					Lcd_int(&lcd, i);
					Lcd_cursor(&lcd, 1,2);
					Lcd_string(&lcd, ",");
					Lcd_cursor(&lcd, 1,3);
					Lcd_int(&lcd, j);
					Lcd_cursor(&lcd, 1,4);
					Lcd_string(&lcd, "]");
					//===Movimiento===
					if ((j%2 == 0) && j!=0){
						Movimiento_Motores(CAMBIO_LETRA);
					}
					else if ((j%2 != 0) && j!=0){
						Movimiento_Motores(CAMBIO_COLUMNA);
					}
					//===Analizo Matriz===
					if (matriz[i][j] == 1){
						Movimiento_Servo();
						matriz[i][j] = 0;
					    for (int fila = 0; fila < filasMatriz; fila++) {	//Corroboro si falta hacer mas punzados, de lo contrario finalizo impresion
					        for (int columna = 0; columna < columnasMatriz; columna++) {
					            if (matriz[fila][columna] == 1) {
					                contador_elementos++; // Se encontró al menos un elemento igual a 1
					            }
					        }
					    }
					    if (contador_elementos == 0){
					    	i = filasMatriz - 1;
					    	j = columnasMatriz - 1;
					    	estado_impresora = HOME;
					    }
					    else{
					    	contador_elementos = 0;
					    }
					}
				}

			}
			else{
				for (int k = (columnasMatriz-1); k >= 0; k--){
					Lcd_clear(&lcd);
					Lcd_cursor(&lcd, 0,0);
					Lcd_string(&lcd, "ELEMENTO [I,J]");
					Lcd_cursor(&lcd, 1,0);
					Lcd_string(&lcd, "[");
					Lcd_cursor(&lcd, 1,1);
					Lcd_int(&lcd, i);
					Lcd_cursor(&lcd, 1,2);
					Lcd_string(&lcd, ",");
					Lcd_cursor(&lcd, 1,3);
					Lcd_int(&lcd, k);
					Lcd_cursor(&lcd, 1,4);
					Lcd_string(&lcd, "]");
					if ( (k%2 == 0) && k != (columnasMatriz-1)){
						Movimiento_Motores(CAMBIO_COLUMNA);
					}
					else if ((k%2 != 0) && k != (columnasMatriz-1)){
						Movimiento_Motores(CAMBIO_LETRA);
					}
					if (matriz[i][k] == 1){
						Movimiento_Servo();
						matriz[i][k] = 0;
					    for (int fila = 0; fila < filasMatriz; fila++) {
					        for (int columna = 0; columna < columnasMatriz; columna++) {
					            if (matriz[fila][columna] == 1) {
					                contador_elementos++; // Se encontró al menos un elemento igual a 1
					            }
					        }
					    }
					    if (contador_elementos == 0){
					    	i = filasMatriz - 1;
					    	k = 0;
					    	estado_impresora = HOME;
					    }
					    else{
					    	contador_elementos = 0;
					    }
					}


				}
			}

	}

	contador_fila = 0;
	contador_columna = 0;
	contador_elementos = 0;
	Homing();	//Realizo Homing() despues de terminar la impresion para retirar mas comodo la hoja
	estado_impresora = IMPRIMIR;
}

