#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct NodoCircular {
    int dato;
    struct NodoCircular* anterior;
    struct NodoCircular* siguiente;
} NodoCircular;

typedef struct {
    NodoCircular* cabeza;
    int tam;
} ListaCircular;

// Funciones básicas
ListaCircular* crear_lista_circular();
void destruir_lista_circular(ListaCircular* lc);

// Operaciones de inserción
void insertar_inicio_lista_circular(ListaCircular* lc, int dato);
void insertar_final_lista_circular(ListaCircular* lc, int dato);
void insertar_ordenado_lista_circular(ListaCircular* lc, int dato);

// Operaciones de eliminación
int eliminar_inicio_lista_circular(ListaCircular* lc);
int eliminar_final_lista_circular(ListaCircular* lc);
int eliminar_valor_lista_circular(ListaCircular* lc, int dato);

// Operaciones de búsqueda
NodoCircular* buscar_lista_circular(ListaCircular* lc, int dato);

// Funciones de utilidad
int esta_vacia_lista_circular(ListaCircular* lc);
int tamanio_lista_circular(ListaCircular* lc);
void imprimir_adelante_lista_circular(ListaCircular* lc);
void imprimir_atras_lista_circular(ListaCircular* lc);
void rotar_adelante_lista_circular(ListaCircular* lc);
void rotar_atras_lista_circular(ListaCircular* lc);

#endif