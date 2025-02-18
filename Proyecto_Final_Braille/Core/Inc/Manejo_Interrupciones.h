#ifndef MANEJO_INTERRUPCIONES_H
#define MANEJO_INTERRUPCIONES_H

#include <stdint.h>
#include <stdbool.h>

extern uint8_t filas;
extern uint8_t columnas;
extern char texto[15];
extern uint8_t i;
extern uint8_t cont_espacios;

extern void Manejo_Interrupciones(int pin);


#endif
