#include <stdio.h>
#include <stdlib.h>
#include "lista_doble_circular.h"

// Crear una nueva lista doblemente circular vacía
ListaDobleCircular* crear_lista_doble_circular() {
    ListaDobleCircular* ldc = (ListaDobleCircular*)malloc(sizeof(ListaDobleCircular));
    if (ldc == NULL) {
        fprintf(stderr, "Error al asignar memoria para la lista\n");
        exit(EXIT_FAILURE);
    }
    ldc->cabeza = NULL;
    ldc->tamaño = 0;
    return ldc;
}

// Liberar toda la memoria de la lista
void destruir_lista_doble_circular(ListaDobleCircular* ldc) {
    if (esta_vacia_doble_circular(ldc)) {
        free(ldc);
        return;
    }

    NodoDobleCircular* actual = ldc->cabeza->siguiente;
    while (actual != ldc->cabeza) {
        NodoDobleCircular* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(ldc->cabeza);
    free(ldc);
}

// Insertar elemento al inicio de la lista
void insertar_inicio_doble_circular(ListaDobleCircular* ldc, int dato) {
    NodoDobleCircular* nuevo = (NodoDobleCircular*)malloc(sizeof(NodoDobleCircular));
    if (nuevo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo->dato = dato;
    
    if (esta_vacia_doble_circular(ldc)) {
        nuevo->anterior = nuevo;
        nuevo->siguiente = nuevo;
        ldc->cabeza = nuevo;
    } else {
        nuevo->anterior = ldc->cabeza->anterior;
        nuevo->siguiente = ldc->cabeza;
        ldc->cabeza->anterior->siguiente = nuevo;
        ldc->cabeza->anterior = nuevo;
        ldc->cabeza = nuevo;
    }
    
    ldc->tamaño++;
}

// Insertar elemento al final de la lista
void insertar_final_doble_circular(ListaDobleCircular* ldc, int dato) {
    if (esta_vacia_doble_circular(ldc)) {
        insertar_inicio_doble_circular(ldc, dato);
        return;
    }
    
    NodoDobleCircular* nuevo = (NodoDobleCircular*)malloc(sizeof(NodoDobleCircular));
    if (nuevo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = ldc->cabeza;
    nuevo->anterior = ldc->cabeza->anterior;
    ldc->cabeza->anterior->siguiente = nuevo;
    ldc->cabeza->anterior = nuevo;
    
    ldc->tamaño++;
}

// Eliminar y devolver el elemento del inicio
int eliminar_inicio_doble_circular(ListaDobleCircular* ldc) {
    if (esta_vacia_doble_circular(ldc)) {
        fprintf(stderr, "Error: lista vacía\n");
        exit(EXIT_FAILURE);
    }
    
    int dato = ldc->cabeza->dato;
    NodoDobleCircular* temp = ldc->cabeza;
    
    if (ldc->tamaño == 1) {
        ldc->cabeza = NULL;
    } else {
        ldc->cabeza->anterior->siguiente = ldc->cabeza->siguiente;
        ldc->cabeza->siguiente->anterior = ldc->cabeza->anterior;
        ldc->cabeza = ldc->cabeza->siguiente;
    }
    
    free(temp);
    ldc->tamaño--;
    return dato;
}

// Eliminar y devolver el elemento del final
int eliminar_final_doble_circular(ListaDobleCircular* ldc) {
    if (esta_vacia_doble_circular(ldc)) {
        fprintf(stderr, "Error: lista vacía\n");
        exit(EXIT_FAILURE);
    }
    
    if (ldc->tamaño == 1) {
        return eliminar_inicio_doble_circular(ldc);
    }
    
    NodoDobleCircular* temp = ldc->cabeza->anterior;
    int dato = temp->dato;
    
    temp->anterior->siguiente = ldc->cabeza;
    ldc->cabeza->anterior = temp->anterior;
    
    free(temp);
    ldc->tamaño--;
    return dato;
}

// Buscar un elemento en la lista
NodoDobleCircular* buscar_doble_circular(ListaDobleCircular* ldc, int dato) {
    if (esta_vacia_doble_circular(ldc)) {
        return NULL;
    }
    
    NodoDobleCircular* actual = ldc->cabeza;
    do {
        if (actual->dato == dato) {
            return actual;
        }
        actual = actual->siguiente;
    } while (actual != ldc->cabeza);
    
    return NULL;
}

// Verificar si la lista está vacía
int esta_vacia_doble_circular(ListaDobleCircular* ldc) {
    return ldc->cabeza == NULL;
}

// Obtener el tamaño de la lista
int tamanio_doble_circular(ListaDobleCircular* ldc) {
    return ldc->tamaño;
}

// Imprimir la lista hacia adelante
void imprimir_adelante_doble_circular(ListaDobleCircular* ldc) {
    if (esta_vacia_doble_circular(ldc)) {
        printf("Lista vacía\n");
        return;
    }
    
    NodoDobleCircular* actual = ldc->cabeza;
    printf("Lista Doble Circular [ ");
    do {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    } while (actual != ldc->cabeza);
    printf("]\n");
}

// Imprimir la lista hacia atrás
void imprimir_atras_doble_circular(ListaDobleCircular* ldc) {
    if (esta_vacia_doble_circular(ldc)) {
        printf("Lista vacía\n");
        return;
    }
    
    NodoDobleCircular* actual = ldc->cabeza->anterior;
    printf("Lista Doble Circular [ ");
    do {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    } while (actual != ldc->cabeza->anterior);
    printf("]\n");
}

// Rotar la lista hacia adelante
void rotar_adelante_doble_circular(ListaDobleCircular* ldc) {
    if (!esta_vacia_doble_circular(ldc)) {
        ldc->cabeza = ldc->cabeza->siguiente;
    }
}

// Rotar la lista hacia atrás
void rotar_atras_doble_circular(ListaDobleCircular* ldc) {
    if (!esta_vacia_doble_circular(ldc)) {
        ldc->cabeza = ldc->cabeza->anterior;
    }
}