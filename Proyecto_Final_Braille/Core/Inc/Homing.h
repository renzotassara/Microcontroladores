#ifndef HOMING_H
#define HOMING_H
#include <stdint.h>

//#include "cmsis_os.h"

extern uint8_t homingX;
extern uint8_t homingY;
extern uint16_t velocidad1_homing;
extern uint16_t velocidad2_homing;

extern void Homing();

#endif /* HOMMING_H */
