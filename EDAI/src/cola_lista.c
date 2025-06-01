#include <stdio.h>
#include <stdlib.h>
#include "cola_lista.h"

ColaLista* crear_cola_lista() {
    ColaLista *q = (ColaLista*)malloc(sizeof(ColaLista));
    if (q == NULL) {
        fprintf(stderr, "Error al crear cola\n");
        exit(EXIT_FAILURE);
    }
    q->frente = NULL;
    q->final = NULL;
    q->tam = 0;
    return q;
}

void destruir_cola_lista(ColaLista *q) {
    while (!esta_vacia_lista(q)) {
        desencolar_lista(q);
    }
    free(q);
}

void encolar_lista(ColaLista *q, int elemento) {
    NodoCola *nuevo = (NodoCola*)malloc(sizeof(NodoCola));
    if (nuevo == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo->dato = elemento;
    nuevo->siguiente = NULL;
    
    if (esta_vacia_lista(q)) {
        q->frente = nuevo;
    } else {
        q->final->siguiente = nuevo;
    }
    
    q->final = nuevo;
    q->tam++;
}

int desencolar_lista(ColaLista *q) {
    if (esta_vacia_lista(q)) {
        fprintf(stderr, "Error: cola vacía\n");
        exit(EXIT_FAILURE);
    }
    
    NodoCola *temp = q->frente;
    int dato = temp->dato;
    
    q->frente = q->frente->siguiente;
    if (q->frente == NULL) {
        q->final = NULL;
    }
    
    free(temp);
    q->tam--;
    return dato;
}

int frente_lista(ColaLista *q) {
    if (esta_vacia_lista(q)) {
        fprintf(stderr, "Error: cola vacía\n");
        exit(EXIT_FAILURE);
    }
    return q->frente->dato;
}

int esta_vacia_lista(ColaLista *q) {
    return q->frente == NULL;
}

int tamanio_lista(ColaLista *q) {
    return q->tam;
}