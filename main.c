#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __MINGW32__
#define SDL_MAIN_HANDLED
#include <SDL_main.h>
#endif
#include <SDL.h>
#include "Juego.h"

void drawFilledCircle(SDL_Renderer* renderer, int cx, int cy, int radius)
{
    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -radius; x <= radius; x++)
        {
            if (x*x + y*y <= radius*radius)
            {
                SDL_RenderDrawPoint(renderer, cx + x, cy + y);
            }
        }
    }
}


int main(int argc, char *argv[])
{
    //Inicializar variables
    unsigned char done;
    int k;
    int delay = 100;
    SDL_Window* window = NULL;
    SDL_Renderer* renderer  = NULL;
    SDL_Event e;
    SDL_Rect fillRect;

    //Inicializando SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL NO SE PUDO INICIALIZAR, ERROR: %s", SDL_GetError() );
        return 1;
    }

    //Crear window = primero el nombre de la ventana, la posiciones, tamaño y visibilidad
    window = SDL_CreateWindow(
                 "Ventana de prueba",
                 SDL_WINDOWPOS_UNDEFINED,
                 SDL_WINDOWPOS_UNDEFINED,
                 800,
                 600,
                 SDL_WINDOW_SHOWN
             );
    //Validar que se creo la ventan
    if(window == NULL)
    {
        SDL_Log("No se puede crear la ventana %s", SDL_GetError());
        SDL_Quit(); //limpia y libera todo los recursos de SDL
        return -1;
    }

    //
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(!renderer)
    {
        SDL_Log("No se pudo crear el lienzo, %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }
    ///
    int fila = 15;
    int col = 15;
    int **tablero = crearTablero(fila, col);
    inicializarTablero(tablero, fila, col);
    ///
    //Crear evento que muestre pantalla
    while(!done)
    {
        //Pregunta si lo hay eventos en la cola
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                done = 1;
            }
        }

        //Pintar el lienzo
        SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0xFF);
        SDL_RenderClear(renderer);

        //Imprimir
        int posX = 0;
        for(int i = 0; i<fila; i++)
        {
            int posY= 0;
            for(int j = 0; j<col; j++)
            {

                if(tablero[i][j] != 0)
                {
                    fillRect.x = posX;
                    fillRect.y = posY;
                    fillRect.h = 30;
                    fillRect.w = 30;
                    /*Color*/
                    SDL_SetRenderDrawColor(renderer, 0, 200, 0, 0xFF);
                    SDL_RenderFillRect(renderer, &fillRect);
                }
                posY+=30;
            }
            posX +=30;
        }

        //
        tablero = procesarTablero(tablero, fila, col);





        //prensentar el lienzo
        SDL_RenderPresent(renderer);


        SDL_Delay(delay);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    destruirTablero(tablero, fila);

    /*
    while (!done){ //Se puede parar tambien cuando no se observen cambios!


        // Actualizacion del "lienzo"
        SDL_RenderPresent(renderer);
        k++;
        //SDL_UpdateWindowSurface(window);

        //Titulo/caption de la ventana
        SDL_SetWindowTitle(window, "Porque no usar esto para poner alguna info del proceso?");
        SDL_Delay(delay);

        //Procesamiento de matriz?
    }
    /*
    //destruyo todos los elementos creados
    //Observar ni mas ni menos que destructores, en la asignatura no inventamos nada!
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    */
    return 0;
}

