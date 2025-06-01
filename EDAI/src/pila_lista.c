#include <stdio.h>
#include <stdlib.h>
#include "pila_lista.h"

PilaLista* crear_pila_lista() {
    PilaLista *p = (PilaLista*)malloc(sizeof(PilaLista));
    if (p == NULL) {
        fprintf(stderr, "Error al crear pila\n");
        exit(EXIT_FAILURE);
    }
    p->tope = NULL;
    p->tamanio = 0;
    return p;
}

void destruir_pila_lista(PilaLista *p) {
    while (!esta_vacia_lista(p)) {
        pop_lista(p);
    }
    free(p);
}

void push_lista(PilaLista *p, int elemento) {
    NodoPila *nuevo = (NodoPila*)malloc(sizeof(NodoPila));
    if (nuevo == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo->dato = elemento;
    nuevo->siguiente = p->tope;
    p->tope = nuevo;
    p->tamanio++;
}

int pop_lista(PilaLista *p) {
    if (esta_vacia_lista(p)) {
        fprintf(stderr, "Error: pila vacía\n");
        exit(EXIT_FAILURE);
    }
    
    NodoPila *temp = p->tope;
    int dato = temp->dato;
    p->tope = temp->siguiente;
    free(temp);
    p->tamanio--;
    
    return dato;
}

int peek_lista(PilaLista *p) {
    if (esta_vacia_lista(p)) {
        fprintf(stderr, "Error: pila vacía\n");
        exit(EXIT_FAILURE);
    }
    return p->tope->dato;
}

int esta_vacia_lista(PilaLista *p) {
    return p->tope == NULL;
}

int tamanio_lista(PilaLista *p) {
    return p->tamanio;
}