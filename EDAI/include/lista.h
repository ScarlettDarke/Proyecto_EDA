#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

typedef struct Lista {
    Nodo* cabeza;
    int tam;
} Lista;

// Funciones para operaciones básicas de la lista
Lista* crear_lista();
void destruir_lista(Lista* lista);
void insertar_inicio(Lista* lista, int dato);
void insertar_final(Lista* lista, int dato);
void eliminar_elemento(Lista* lista, int dato);
int buscar(Lista* lista, int dato);
int obtener_tam(Lista* lista);
void imprimir_lista(Lista* lista);

#endif 