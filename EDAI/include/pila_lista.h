#ifndef PILA_LISTA_H
#define PILA_LISTA_H

typedef struct NodoPila {
    int dato;
    struct NodoPila* siguiente;
} NodoPila;

typedef struct {
    NodoPila* tope;
    int tamanio;
} PilaLista;

PilaLista* crear_pila_lista();
void destruir_pila_lista(PilaLista *p);
void push_lista(PilaLista *p, int elemento);
int pop_lista(PilaLista *p);
int peek_lista(PilaLista *p);
int esta_vacia_lista(PilaLista *p);
int tamanio_lista(PilaLista *p);

#endif