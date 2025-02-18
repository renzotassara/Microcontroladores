#include "Manejo_Interrupciones.h"
#include "Matriz.h"
#include "Texto.h"
#include "Homing.h"

#include "main.h"
#include "lcd.h"

uint8_t filas = 3*3;	//
uint8_t columnas = 5*2;
uint8_t i = 0;
uint8_t cont_espacios = 0;
char texto[15] = "              ";	//string de caracteres de la variable texto (inicialmente vacia)

void Manejo_Interrupciones(int pin) {
	//currentMillis = HAL_GetTick();
	Lcd_PortType ports[] = { GPIOB, GPIOB, GPIOB, GPIOB };
	Lcd_PinType pins[] = {GPIO_PIN_0, GPIO_PIN_1, GPIO_PIN_10, GPIO_PIN_11};
	Lcd_HandleTypeDef lcd;
	lcd = Lcd_create(ports, pins, GPIOA, GPIO_PIN_1, GPIOA, GPIO_PIN_3, LCD_4_BIT_MODE);

/*=======================================================================
* ===========================Texto======================================
* ======================================================================*/

	if(estado_impresora == TEXTO){
//---Columna 1---
		Lcd_clear(&lcd);
		Lcd_cursor(&lcd, 0,0);
		Lcd_string(&lcd, "Escriba el texto");

		HAL_GPIO_WritePin(GPIOA, Columna1_Pin, 1);	//Habilito primera columna de teclado (1,4,7,*)
		HAL_GPIO_WritePin(GPIOA, Columna2_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, Columna3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, Columna4_Pin, 0);

		if(pin == 1 && HAL_GPIO_ReadPin(GPIOB, Fila1_EXTI_Pin)){	//Al apretar el 1, el texto no se modifica

			texto[i] = Texto(1);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);

		}
		else if(pin == 2 && HAL_GPIO_ReadPin(GPIOB, Fila2_EXTI_Pin)){

			texto[i] = Texto(4);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);

		}
		else if(pin == 3 && HAL_GPIO_ReadPin(GPIOB, Fila3_EXTI_Pin)){

			texto[i] = Texto(7);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
		}
		else if(pin == 4 && HAL_GPIO_ReadPin(GPIOB, Fila4_EXTI_Pin)){	//'*' borra letra

			texto[i] = ' ';
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,5);
			Lcd_string(&lcd, "Letra");
			Lcd_cursor(&lcd, 1,4);
			Lcd_string(&lcd, "borrada");
			HAL_Delay(1000);

			if (i == 0){
				i = 0;
			}
			else{
				i--;
			}
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
		}

//---Columna 2----

		HAL_GPIO_WritePin(GPIOA, Columna1_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, Columna2_Pin, 1);	//Habilito segunda columna de teclado (2,5,8,0)
		HAL_GPIO_WritePin(GPIOA, Columna3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, Columna4_Pin, 0);

		if(pin == 1 && HAL_GPIO_ReadPin(GPIOB, Fila1_EXTI_Pin)){

			texto[i] = Texto(2);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
		}
		else if(pin == 2 && HAL_GPIO_ReadPin(GPIOB, Fila2_EXTI_Pin)){

			texto[i] = Texto(5);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
		}
		else if(pin == 3 && HAL_GPIO_ReadPin(GPIOB, Fila3_EXTI_Pin)){

			texto[i] = Texto(8);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
		}
		else if(pin == 4 && HAL_GPIO_ReadPin(GPIOB, Fila4_EXTI_Pin)){	//Espacio

			texto[i] = Texto(0);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
		}

//---Columna 3----

		HAL_GPIO_WritePin(GPIOA, Columna1_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, Columna2_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, Columna3_Pin, 1);	//Habilito tercera columna de teclado (3,6,9,#)
		HAL_GPIO_WritePin(GPIOA, Columna4_Pin, 0);

		if(pin == 1 && HAL_GPIO_ReadPin(GPIOB, Fila1_EXTI_Pin)){

			texto[i] = Texto(3);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
		}
		else if(pin == 2 && HAL_GPIO_ReadPin(GPIOB, Fila2_EXTI_Pin)){

			texto[i] = Texto(6);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
			HAL_Delay(1000);
		}
		else if(pin == 3 && HAL_GPIO_ReadPin(GPIOB, Fila3_EXTI_Pin)){

			texto[i] = Texto(9);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
		}
		else if(pin == 4 && HAL_GPIO_ReadPin(GPIOB, Fila4_EXTI_Pin)){	//Selecciona letra

			texto[i] = Texto(11);
			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,1);
			Lcd_string(&lcd, "     Letra");
			Lcd_cursor(&lcd, 1,1);
			Lcd_string(&lcd, "  seleccionada");
			HAL_Delay(500);

			Lcd_clear(&lcd);
			Lcd_cursor(&lcd, 0,0);
			Lcd_string(&lcd, "Escriba el texto");
			Lcd_cursor(&lcd, 1,0);
			Lcd_string(&lcd, texto);
			i++;
		}

		HAL_GPIO_WritePin(GPIOA, Columna1_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, Columna2_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, Columna3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, Columna4_Pin, 1);	//Habilito primera columna de teclado (A,B,C,D)

		if(pin == 4 && HAL_GPIO_ReadPin(GPIOB, Fila4_EXTI_Pin)){	//Solo leo D ya que es para volver al menu, las otra teclas no sirven por ahora
			estado_impresora = MENU;
		}
	}

/*=======================================================================
* ===========================Imprimir======================================
* ======================================================================*/

		    else if(estado_impresora == IMPRIMIR){

		    	for(int i = 0; i < sizeof(texto); i++){	//Corroboro si escribi algo
		    		if (texto[i] == ' '){
		    			cont_espacios++;
		    		}
		    	}
		    	if (cont_espacios == sizeof(texto)-1){
				    Lcd_clear(&lcd);
				    Lcd_cursor(&lcd, 0,1);
				    Lcd_string(&lcd, "Escriba algo");
				    HAL_Delay(1000);
				    cont_espacios = 0;
				    estado_impresora = MENU;
		    	}
		    	else{
				    Lcd_clear(&lcd);
				    Lcd_cursor(&lcd, 0,1);
				    Lcd_string(&lcd, "Imprimiendo...");

		    		Armado_Matriz(texto, filas, columnas);

				    Lcd_clear(&lcd);
				    Lcd_cursor(&lcd, 0,1);
				    Lcd_string(&lcd, "Retire la hoja");
				    HAL_Delay(5000);
				    estado_impresora = MENU;
		    	}
		    }
/*=======================================================================
* =============================HOME======================================
* ======================================================================*/

		    else if (estado_impresora == HOME){
		    	estado_impresora = HOME;
			    Lcd_clear(&lcd);
			    Lcd_cursor(&lcd, 0,1);
			    Lcd_string(&lcd, "Homing...");
		    	Homing();
			    Lcd_clear(&lcd);
			    Lcd_cursor(&lcd, 0,1);
			    Lcd_string(&lcd, "Home");
			    Lcd_cursor(&lcd, 1,1);
			    Lcd_string(&lcd, "finalizado");
			    HAL_Delay(2000);
			    estado_impresora = MENU;
		    }

}
