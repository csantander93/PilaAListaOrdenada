#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct ListaE{

PtrNodo primero;

};

struct PilaE{

PtrNodo primero;

};

struct NodoE{

PtrDato dato;
struct NodoE * siguiente;

};

PtrLista crearLista(){

    PtrLista lista = malloc (sizeof(struct ListaE));
    lista->primero = NULL;
    return lista;

}

PtrLista crearPila(){

    PtrPila pila = malloc (sizeof(struct PilaE));
    pila->primero = NULL;
    return pila;

}

PtrNodo crearNodo(PtrDato dato){

    PtrNodo nodo = malloc(sizeof(struct NodoE));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    return nodo;

}

void desapilar(PtrPila pila){

    if(pila->primero != NULL){
        PtrNodo actual = pila->primero;
        PtrNodo anterior = NULL;

        while(actual->siguiente != NULL){
            anterior = actual;
            actual = actual->siguiente;
        }

        if(anterior != NULL){
            anterior->siguiente = NULL;
        }else{
            pila->primero = NULL;
        }
        free(actual);
    }

}

void insertarInicio(PtrLista lista, PtrDato dato){

PtrNodo nuevoNodo = crearNodo(dato);
nuevoNodo->siguiente = lista->primero;
lista->primero = nuevoNodo;

}

void apilar(PtrPila pila, PtrDato dato){

    PtrNodo nuevoNodo = crearNodo(dato);
    if(pila->primero == NULL){
        pila->primero = nuevoNodo;
    }else{
    PtrNodo actual = pila->primero;
    while(actual->siguiente != NULL){
        actual = actual->siguiente;
    }
    actual->siguiente = nuevoNodo;
    }

}

void insertarOrdenado(PtrLista lista, PtrDato dato){

    PtrNodo nuevoNodo = crearNodo(dato);
    if(lista->primero == NULL || dato < lista->primero->dato){
        nuevoNodo->siguiente = lista->primero;
        lista->primero = nuevoNodo;
    } else {

        PtrNodo actual = lista->primero;
        PtrNodo anterior = NULL;

        while(actual != NULL && dato >= actual->dato){
            anterior = actual;
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual;
        anterior->siguiente = nuevoNodo;
    }

}

PtrDato getDatoPila(PtrPila pila){

    PtrNodo actual = pila->primero;
    while(actual->siguiente != NULL){
        actual = actual->siguiente;
    }
return actual->dato;
}

void mostrarPila(PtrPila pila){

PtrNodo actual = pila->primero;

while(actual != NULL){
    printf(" %d ", (int) actual->dato);
    actual = actual->siguiente;
}

}

void mostrarLista(PtrLista lista){

PtrNodo actual = lista->primero;

while(actual != NULL){
    printf(" %d ", (int) actual->dato);
    actual = actual->siguiente;
}

}

void copiarPilaALista(PtrPila pila, PtrLista lista){

    while(pila->primero != NULL){

        insertarOrdenado(lista, getDatoPila(pila));
        desapilar(pila);

    }

}
