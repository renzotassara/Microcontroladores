#ifndef MATRIZ_H
#define MATRIZ_H
#include <stdint.h>

extern uint8_t m;
extern const uint8_t filasSubmatriz;
extern const uint8_t columnasSubmatriz;
extern uint8_t contador_elementos;

typedef enum{
	CAMBIO_RENGLON,
	CAMBIO_FILA,
	CAMBIO_COLUMNA,
	CAMBIO_LETRA
} EstadoMovimiento;

void Armado_Matriz(char texto[], int filas, int columnas);
void Movimiento_Matriz(int filasMatriz, int columnasMatriz,uint8_t matriz[filasMatriz][columnasMatriz]);

#endif
