#include "Juego.h"
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
    //inicializarTablero(tablero, configIniciales[0], configIniciales[1]);
    patronPlaneador(tablero, configIniciales[0], configIniciales[0]);
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

    while(generacion < 30) // bucle infinito  {Cambiar condicoon para hacer paso a paso}
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
    destruirTablero(tablero, configIniciales[0]);
}






