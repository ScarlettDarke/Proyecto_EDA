#ifndef LISTA_DOBLE_CIRCULAR_H
#define LISTA_DOBLE_CIRCULAR_H

typedef struct NodoDobleCircular {
    int dato;
    struct NodoDobleCircular* anterior;
    struct NodoDobleCircular* siguiente;
} NodoDobleCircular;

typedef struct {
    NodoDobleCircular* cabeza;
    int tamaño;
} ListaDobleCircular;

// Funciones básicas
ListaDobleCircular* crear_lista_doble_circular();
void destruir_lista_doble_circular(ListaDobleCircular* ldc);

// Operaciones de inserción
void insertar_inicio_doble_circular(ListaDobleCircular* ldc, int dato);
void insertar_final_doble_circular(ListaDobleCircular* ldc, int dato);
void insertar_ordenado_doble_circular(ListaDobleCircular* ldc, int dato);

// Operaciones de eliminación
int eliminar_inicio_doble_circular(ListaDobleCircular* ldc);
int eliminar_final_doble_circular(ListaDobleCircular* ldc);
int eliminar_valor_doble_circular(ListaDobleCircular* ldc, int dato);

// Operaciones de búsqueda
NodoDobleCircular* buscar_doble_circular(ListaDobleCircular* ldc, int dato);

// Funciones de utilidad
int esta_vacia_doble_circular(ListaDobleCircular* ldc);
int tamanio_doble_circular(ListaDobleCircular* ldc);
void imprimir_adelante_doble_circular(ListaDobleCircular* ldc);
void imprimir_atras_doble_circular(ListaDobleCircular* ldc);
void rotar_adelante_doble_circular(ListaDobleCircular* ldc);
void rotar_atras_doble_circular(ListaDobleCircular* ldc);

#endif