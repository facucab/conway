#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void juego();
int** crearTablero(unsigned int fila, unsigned int col);
void destruirTablero(int **tablero, unsigned int fila);
void imprimirTablero(int **tablero, unsigned int fila, unsigned int col);
void configurarTablero(int * config);
void inicializarTablero(int **tablero, int fila, int col);
int ** procesarTablero(int **tablero, int fila, int col);
int cantVecinosVivos(int ** tablero, int x, int y, int fila, int col);
void patronPlaneador(int **tablero, int fila, int col);


#endif // JUEGO_H_INCLUDED
