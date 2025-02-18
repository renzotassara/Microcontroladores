#include "Texto.h"


uint8_t cont[10] = {0};
char caracter;

char Texto(int numero) {
	switch(numero){
		case(0):
				if (cont[0] == 0){	//el cero solo se usa para el espacio
					caracter = ' ';
					return caracter;

				}
				break;

		case(1):
				break;	//No realiza ninguna accion, pero se dejo para posibles mejoras (agregado de caracteres por ejemplo)
		case(2):
				if (cont[2] == 0){
					caracter = 'a';
					cont[2]++;
					return caracter;
				}
				else if(cont[2] == 1){
					caracter = 'b';
					cont[2]++;
					return caracter;
				}
				else if(cont[2] == 2){
					caracter = 'c';
					cont[2] = 0;
					return caracter;
				}
				break;
		case(3):
				if (cont[3] == 0){
					caracter = 'd';
					cont[3]++;
					return caracter;
				}
				else if(cont[3] == 1){
					caracter = 'e';
					cont[3]++;
					return caracter;
				}
				else if(cont[3] == 2){
					caracter = 'f';
					cont[3] = 0;
					return caracter;
				}
				break;
		case(4):
				if (cont[4] == 0){
					caracter = 'g';
					cont[4]++;
					return caracter;
				}
				else if(cont[4] == 1){
					caracter = 'h';
					cont[4]++;
					return caracter;
				}
				else if(cont[4] == 2){
					caracter = 'i';
					cont[4] = 0;
					return caracter;

				}
				break;
		case(5):
				if (cont[5] == 0){
					caracter = 'j';
					cont[5]++;
					return caracter;
				}
				else if(cont[5] == 1){
					caracter = 'k';
					cont[5]++;
					return caracter;
				}
				else if(cont[5] == 2){
					caracter = 'l';
					cont[5] = 0;
					return caracter;
				}
				break;
		case(6):
				if (cont[6] == 0){
					caracter = 'm';
					cont[6]++;
					return caracter;
				}
				else if(cont[6] == 1){
					caracter = 'n';
					cont[6]++;
					return caracter;
				}
				else if(cont[6] == 2){
					caracter = 'o';
					cont[6] = 0;
					return caracter;
				}
				break;
		case(7):
				if (cont[7] == 0){
					caracter = 'p';
					cont[7]++;
					return caracter;
				}
				else if(cont[7] == 1){
					caracter = 'q';
					cont[7]++;
					return caracter;
				}
				else if(cont[7] == 2){
					caracter = 'r';
					cont[7]++;
					return caracter;
				}
				else if(cont[7] == 3){
					caracter = 's';
					cont[7] = 0;
					return caracter;
				}

				break;
		case(8):
				if (cont[8] == 0){
					caracter = 't';
					cont[8]++;
					return caracter;
				}
				else if(cont[8] == 1){
					caracter = 'u';
					cont[8]++;
					return caracter;
				}
				else if(cont[8] == 2){
					caracter = 'v';
					cont[8] = 0;
					return caracter;
				}
				break;
		case(9):
				if (cont[9] == 0){
					caracter = 'w';
					cont[9]++;
					return caracter;
				}
				else if(cont[9] == 1){
					caracter = 'x';
					cont[9]++;
					return caracter;
				}
				else if(cont[9] == 2){
					caracter = 'y';
					cont[9]++;
					return caracter;
				}
				else if(cont[9] == 3){
					caracter = 'z';
					cont[9] = 0;
					return caracter;
				}
				break;
		case(11):
				for (int k = 0; k <= 9;k++){	//Reinicio de contadores
					cont[k] = 0;
				}
				return caracter;	//Devuelve caracter actual
	}
	return ' ';
}
