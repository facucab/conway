#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <SDL.h>
#define TAM_SQUARE 10
#define INDEX_F 0
#define INDEX_C 1
int** crearTablero(unsigned int fila, unsigned int col);
void destruirTablero(int **tablero, unsigned int fila);
void inicializarTablero(int **tablero, unsigned int fila, unsigned int col);
void procesarTablero(int **tablero, unsigned int fila, unsigned int col);
int cantVecinosVivos(int ** tablero, int x, int y, unsigned int fila, unsigned int col);
void configurarTablero(int * config);
void drawSquare(SDL_Renderer * renderer, unsigned int posX, unsigned int posY);
void patron_canonPlaneador(int **tablero, unsigned int fila, unsigned int col);
void imprimirTablero(int **tablero, unsigned int fila, int unsigned col, SDL_Renderer * renderer );
#endif // JUEGO_H_INCLUDED
