#ifndef MOVIMIENTO_SERVO_H
#define MOVIMIENTO_SERVO_H
#include <stdint.h>

extern uint16_t pos_final;
extern uint8_t vel_servo;
extern uint16_t pos_inicial;
extern uint16_t t_reposo;
extern uint16_t pos_actual;

void Movimiento_Servo();

#endif
