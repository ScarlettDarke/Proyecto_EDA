#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

typedef struct Nodo {
    int dato;
    struct Nodo* anterior;
    struct Nodo* siguiente;
} Nodo;

typedef struct ListaDoble {
    Nodo* cabeza;
    Nodo* cola;
    int tam;
} ListaDoble;

// Funciones para operaciones básicas de la lista
ListaDoble* crear_lista_doble();
void destruir_lista_doble(ListaDoble* lista);
void insertar_inicio(ListaDoble* lista, int dato);
void insertar_final(ListaDoble* lista, int dato);
void eliminar_elemento(ListaDoble* lista, int dato);
int buscar_adelante(ListaDoble* lista, int dato);
int buscar_atras(ListaDoble* lista, int dato);
int obtener_tam(ListaDoble* lista);
void imprimir_adelante(ListaDoble* lista);
void imprimir_atras(ListaDoble* lista);

#endif 