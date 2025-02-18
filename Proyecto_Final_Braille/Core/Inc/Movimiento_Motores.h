#ifndef MOVIMIENTO_MOTORES_H
#define MOVIMIENTO_MOTORES_H
#include <stdint.h>

extern const uint16_t pxmmX;
extern const uint16_t pxmmY;
extern uint8_t velocidad;

extern const uint8_t a;
extern const uint8_t b;
extern const uint8_t c;
extern const uint8_t d;

void Movimiento_Motores(int accion);

#endif
