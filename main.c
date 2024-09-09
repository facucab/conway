#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int** crearTablero(int fila, int col);
void imprimirTablero(int **tablero, int fila, int col);
void configurarTablero(int * config);
void inicializarTablero(int **tablero, int fila, int col);
int ** procesarTablero(int **tablero, int fila, int col);
int cantVecinosVivos(int ** tablero, int x, int y, int fila, int col);
void juego();
int main()
{
    juego();


    return 0;
}
void juego(){ ///Cuerpo del juego

    int configIniciales[2] = {0};

    ///Configuro las condiciones inciales del tablero:
    configurarTablero(configIniciales);

    ///Creo el tablero
    int **tablero = crearTablero(configIniciales[0], configIniciales[1]);

    ///inicializo la matriz con un patron básico:
    inicializarTablero(tablero, configIniciales[0], configIniciales[1]);

    ///imprimo el tablero:
    printf("\n\n");
    imprimirTablero(tablero, configIniciales[0], configIniciales[1]);

    ///Mover paso a paso las generaciones
    int ejecutar = 1;
    /*
    printf("\n\n Ingrese 1 para la siguiente generacion: ");
    int ejecutar = 0;
    scanf("%d", &ejecutar);
    */
    int generacion = 1;

    while(ejecutar == 1) // bucle infinito  {Cambiar condicoon para hacer paso a paso}
    {

        system("cls");
        printf("\nGENERACION: %d\n", generacion);
        tablero = procesarTablero(tablero, configIniciales[0], configIniciales[1]);
        imprimirTablero(tablero, configIniciales[0], configIniciales[1]);
        generacion++;

        Sleep(300);

        ///Mover paso a paso las generaciones
        /*
        printf("\n\nIngrese 1 para la siguiente generacion: ");
        scanf("%d", &ejecutar);
        */
    }

}
int cantVecinosVivos(int ** tablero, int x, int y, int fila, int col)
{
    int cantVivas = 0;
    for(int i = x-1; i<= x+1; i++)
    {
        for(int j = y -1; j<= y+1; j++)
        {
            /*
                evito excederme de los limites del tablero:
                i no pueden ser nunca negativas (significa que esto al limite del lado izquierdo del tablero)
                j no pueden ser nunca negativas (significa que esto al limite del lado superior del tablero)
                i no pueden exceder a la cantidad de filas (significa que estoy al limite del lado derecho)
                j no pueden exceder a la cantidad de columnas (significa que estoy al limite del lado inferior del tablero)
            */
            if( i >=0 && i<fila  && j>=0 && j<col) //
            {
                if(tablero[i][j] == 1 && !(i == x && j == y) )
                {
                    cantVivas++;
                }
            }
        }
    }
    return cantVivas;
}
int ** procesarTablero(int **tablero, int fila, int col)
{
    int** tableroSiguiente = crearTablero(fila, col);
    int cantVecinos = 0;
    for(int i = 0; i<fila; i++)
    {
        for(int j = 0; j<col; j++)
        {
            cantVecinos = cantVecinosVivos(tablero, i, j, fila, col);
            if( (cantVecinos== 2 || cantVecinos==3)  && tablero[i][j] == 1 )
            {
                //permanece viva
                tableroSiguiente[i][j] = 1;
            }
            else if (tablero[i][j] == 0 && cantVecinos == 3)
            {
                tableroSiguiente[i][j] = 1;
            }
            else
            {
                tableroSiguiente[i][j] = 0;
            }
        }
    }

    for(int i = 0; i<fila; i++)
    {
        for(int j= 0; j<col; j++)
        {
            tablero[i][j] = tableroSiguiente[i][j];
        }
    }

    return tableroSiguiente;
}
void inicializarTablero(int **tablero, int fila, int col)
{
        int x = (fila - 1) / 2;
        int y = (col -1)  / 2;

        tablero[x][y] = 1;
        tablero[x][y + 1] = 1;
        tablero[x+1][y+1] = 1;
        tablero[x+2][y+1] = 1;
        tablero[x+1][y+2] = 1;
}
void configurarTablero(int * config)
{
    printf("\n----------- CONFIGURACIONES INICIALES -----------\n");

    ///Ingresar filas:
    printf("\nIngrese un numero de filas entre 5 y 20: ");
    scanf("%d", config);
    while(*config <5 || *config > 20)
    {
        printf("\nNumero de filas invalido, vuelva intentar: ");
        scanf("%d", config);
    }

    ///Ingresar columnas:
    printf("\nIngrese un numero de columnas entre 5 y 20:");
    config++;
    scanf("%d", config);
    while(*config <5 || *config > 20)
    {
        printf("\nNumero de columnas invalido, vuelva intentar: ");
        scanf("%d", config);
    }

    printf("\n-------------------------------------------------\n");
}

void imprimirTablero(int **tablero, int fila, int col)
{
    for(int i = 0; i<fila; i++)
    {

        for(int j = 0; j<col; j++)
        {
            if(tablero[i][j] == 0)
            {
                printf(" [ ] ");
            }
            else{
                printf("\033[32m [*] \033[0m");
            }
            //printf("  %d  ", tablero[i][j]);
        }
        printf("\n");
    }
}
int** crearTablero(int fila, int col)
{
    //srand(time(NULL));
    int ** tablero = (int**)calloc(fila, sizeof(int *));

    if(tablero == NULL)
    {
        printf("ERROR CREANDO FILAS");
    }

    ///Falta liberar memoria en caso de falla
    for(int i = 0; i<fila; i++)
    {
        tablero[i] = (int *)calloc(col, sizeof(int));
        if(tablero[i] == NULL)
        {
            printf("ERROR CREANDO COLUMNAS");
        }

        for(int j = 0; j < col; j++)
        {
            //tablero[i][j] = rand() % 2;
        }

    }
    return tablero;
}
