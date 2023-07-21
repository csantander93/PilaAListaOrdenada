#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    PtrPila pila = crearPila();
    apilar(pila, 6);
    apilar(pila, 1);
    apilar(pila, 20);
    apilar(pila, 30);
    apilar(pila, 2);
    mostrarPila(pila);

    PtrLista listaCopia = crearLista();

    copiarPilaALista(pila, listaCopia);

    printf("\n\nLista copiada");
    mostrarLista(listaCopia);

    return 0;
}
