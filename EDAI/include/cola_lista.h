#ifndef COLA_LISTA_H
#define COLA_LISTA_H

typedef struct NodoCola {
    int dato;
    struct NodoCola* siguiente;
} NodoCola;

typedef struct {
    NodoCola* frente;
    NodoCola* final;
    int tam;
} ColaLista;

ColaLista* crear_cola_lista();
void destruir_cola_lista(ColaLista *q);
void encolar_lista(ColaLista *q, int elemento);
int desencolar_lista(ColaLista *q);
int frente_lista(ColaLista *q);
int esta_vacia_lista(ColaLista *q);
int tamanio_lista(ColaLista *q);

#endif 