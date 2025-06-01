#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

// Crear una nueva lista circular vacía
ListaCircular* crear_lista_circular() {
    ListaCircular* lc = (ListaCircular*)malloc(sizeof(ListaCircular));
    if (lc == NULL) {
        fprintf(stderr, "Error al asignar memoria para la lista circular\n");
        exit(EXIT_FAILURE);
    }
    lc->cabeza = NULL;
    lc->tam = 0;
    return lc;
}

// Liberar toda la memoria de la lista circular
void destruir_lista_circular(ListaCircular* lc) {
    if (esta_vacia_lista_circular(lc)) {
        free(lc);
        return;
    }

    NodoCircular* actual = lc->cabeza->siguiente;
    while (actual != lc->cabeza) {
        NodoCircular* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(lc->cabeza);
    free(lc);
}

// Insertar elemento al inicio de la lista
void insertar_inicio_lista_circular(ListaCircular* lc, int dato) {
    NodoCircular* nuevo = (NodoCircular*)malloc(sizeof(NodoCircular));
    if (nuevo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo->dato = dato;
    
    if (esta_vacia_lista_circular(lc)) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        lc->cabeza = nuevo;
    } else {
        nuevo->siguiente = lc->cabeza;
        nuevo->anterior = lc->cabeza->anterior;
        lc->cabeza->anterior->siguiente = nuevo;
        lc->cabeza->anterior = nuevo;
        lc->cabeza = nuevo;
    }
    
    lc->tam++;
}

// Insertar elemento al final de la lista
void insertar_final_lista_circular(ListaCircular* lc, int dato) {
    if (esta_vacia_lista_circular(lc)) {
        insertar_inicio_lista_circular(lc, dato);
        return;
    }
    
    NodoCircular* nuevo = (NodoCircular*)malloc(sizeof(NodoCircular));
    if (nuevo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = lc->cabeza;
    nuevo->anterior = lc->cabeza->anterior;
    lc->cabeza->anterior->siguiente = nuevo;
    lc->cabeza->anterior = nuevo;
    
    lc->tam++;
}

// Eliminar y devolver el elemento del inicio
int eliminar_inicio_lista_circular(ListaCircular* lc) {
    if (esta_vacia_lista_circular(lc)) {
        fprintf(stderr, "Error: lista circular vacía\n");
        exit(EXIT_FAILURE);
    }
    
    int dato = lc->cabeza->dato;
    NodoCircular* temp = lc->cabeza;
    
    if (lc->tam == 1) {
        lc->cabeza = NULL;
    } else {
        lc->cabeza->anterior->siguiente = lc->cabeza->siguiente;
        lc->cabeza->siguiente->anterior = lc->cabeza->anterior;
        lc->cabeza = lc->cabeza->siguiente;
    }
    
    free(temp);
    lc->tam--;
    return dato;
}

// Eliminar y devolver el elemento del final
int eliminar_final_lista_circular(ListaCircular* lc) {
    if (esta_vacia_lista_circular(lc)) {
        fprintf(stderr, "Error: lista circular vacía\n");
        exit(EXIT_FAILURE);
    }
    
    if (lc->tam == 1) {
        return eliminar_inicio_lista_circular(lc);
    }
    
    NodoCircular* temp = lc->cabeza->anterior;
    int dato = temp->dato;
    
    temp->anterior->siguiente = lc->cabeza;
    lc->cabeza->anterior = temp->anterior;
    
    free(temp);
    lc->tam--;
    return dato;
}

// Buscar un elemento en la lista
NodoCircular* buscar_lista_circular(ListaCircular* lc, int dato) {
    if (esta_vacia_lista_circular(lc)) {
        return NULL;
    }
    
    NodoCircular* actual = lc->cabeza;
    do {
        if (actual->dato == dato) {
            return actual;
        }
        actual = actual->siguiente;
    } while (actual != lc->cabeza);
    
    return NULL;
}

// Verificar si la lista está vacía
int esta_vacia_lista_circular(ListaCircular* lc) {
    return lc->cabeza == NULL;
}

// Obtener el número de elementos en la lista
int tamanio_lista_circular(ListaCircular* lc) {
    return lc->tam;
}

// Imprimir la lista hacia adelante
void imprimir_adelante_lista_circular(ListaCircular* lc) {
    if (esta_vacia_lista_circular(lc)) {
        printf("Lista circular vacía\n");
        return;
    }
    
    NodoCircular* actual = lc->cabeza;
    printf("Lista Circular [ ");
    do {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    } while (actual != lc->cabeza);
    printf("]\n");
}

// Imprimir la lista hacia atrás
void imprimir_atras_lista_circular(ListaCircular* lc) {
    if (esta_vacia_lista_circular(lc)) {
        printf("Lista circular vacía\n");
        return;
    }
    
    NodoCircular* actual = lc->cabeza->anterior;
    printf("Lista Circular [ ");
    do {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    } while (actual != lc->cabeza->anterior);
    printf("]\n");
}

// Rotar la lista hacia adelante (mover cabeza al siguiente)
void rotar_adelante_lista_circular(ListaCircular* lc) {
    if (!esta_vacia_lista_circular(lc)) {
        lc->cabeza = lc->cabeza->siguiente;
    }
}

// Rotar la lista hacia atrás (mover cabeza al anterior)
void rotar_atras_lista_circular(ListaCircular* lc) {
    if (!esta_vacia_lista_circular(lc)) {
        lc->cabeza = lc->cabeza->anterior;
    }
}