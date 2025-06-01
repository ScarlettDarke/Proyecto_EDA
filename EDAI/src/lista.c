#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Crear una nueva lista vacía
Lista* crear_lista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista == NULL) {
        fprintf(stderr, "Error al asignar memoria para la lista\n");
        exit(EXIT_FAILURE);
    }
    lista->cabeza = NULL;
    lista->tamaño = 0;
    return lista;
}

// Liberar la memoria de la lista
void destruir_lista(Lista* lista) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(lista);
}

// Insertar un elemento al inicio de la lista
void insertar_inicio(Lista* lista, int dato) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = lista->cabeza;
    lista->cabeza = nuevo_nodo;
    lista->tamaño++;
}

// Insertar un elemento al final de la lista
void insertar_final(Lista* lista, int dato) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = NULL;
    
    if (lista->cabeza == NULL) {
        lista->cabeza = nuevo_nodo;
    } else {
        Nodo* actual = lista->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo_nodo;
    }
    lista->tamaño++;
}

// Eliminar un elemento de la lista
void eliminar_elemento(Lista* lista, int dato) {
    Nodo* actual = lista->cabeza;
    Nodo* anterior = NULL;
    
    while (actual != NULL && actual->dato != dato) {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    if (actual == NULL) {
        printf("Elemento no encontrado en la lista\n");
        return;
    }
    
    if (anterior == NULL) {
        lista->cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    
    free(actual);
    lista->tamaño--;
}

// Buscar un elemento en la lista
int buscar(Lista* lista, int dato) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        if (actual->dato == dato) {
            return 1; // Encontrado
        }
        actual = actual->siguiente;
    }
    return 0; // No encontrado
}

// Obtener el tamaño de la lista
int obtener_tamaño(Lista* lista) {
    return lista->tamaño;
}

// Imprimir los elementos de la lista
void imprimir_lista(Lista* lista) {
    Nodo* actual = lista->cabeza;
    printf("Lista: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}