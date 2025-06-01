#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

// Crear una nueva lista vacía
ListaDoble* crear_lista_doble() {
    ListaDoble* lista = (ListaDoble*)malloc(sizeof(ListaDoble));
    if (lista == NULL) {
        fprintf(stderr, "Error al asignar memoria para la lista\n");
        exit(EXIT_FAILURE);
    }
    lista->cabeza = NULL;
    lista->cola = NULL;
    lista->tam = 0;
    return lista;
}

// Liberar la memoria de la lista
void destruir_lista_doble(ListaDoble* lista) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(lista);
}

// Insertar un elemento al inicio de la lista
void insertar_inicio(ListaDoble* lista, int dato) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo_nodo->dato = dato;
    nuevo_nodo->anterior = NULL;
    nuevo_nodo->siguiente = lista->cabeza;
    
    if (lista->cabeza == NULL) {
        // Lista vacía
        lista->cola = nuevo_nodo;
    } else {
        lista->cabeza->anterior = nuevo_nodo;
    }
    
    lista->cabeza = nuevo_nodo;
    lista->tam++;
}

// Insertar un elemento al final de la lista
void insertar_final(ListaDoble* lista, int dato) {
    Nodo* nuevo_nodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo_nodo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo_nodo->dato = dato;
    nuevo_nodo->siguiente = NULL;
    nuevo_nodo->anterior = lista->cola;
    
    if (lista->cola == NULL) {
        // Lista vacía
        lista->cabeza = nuevo_nodo;
    } else {
        lista->cola->siguiente = nuevo_nodo;
    }
    
    lista->cola = nuevo_nodo;
    lista->tam++;
}

// Eliminar un elemento de la lista
void eliminar_elemento(ListaDoble* lista, int dato) {
    Nodo* actual = lista->cabeza;
    
    while (actual != NULL && actual->dato != dato) {
        actual = actual->siguiente;
    }
    
    if (actual == NULL) {
        printf("Elemento no encontrado en la lista\n");
        return;
    }
    
    if (actual->anterior == NULL) {
        // Es el primer nodo
        lista->cabeza = actual->siguiente;
    } else {
        actual->anterior->siguiente = actual->siguiente;
    }
    
    if (actual->siguiente == NULL) {
        // Es el último nodo
        lista->cola = actual->anterior;
    } else {
        actual->siguiente->anterior = actual->anterior;
    }
    
    free(actual);
    lista->tam--;
}

// Buscar un elemento desde el inicio
int buscar_adelante(ListaDoble* lista, int dato) {
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        if (actual->dato == dato) {
            return 1; // Encontrado
        }
        actual = actual->siguiente;
    }
    return 0; // No encontrado
}

// Buscar un elemento desde el final
int buscar_atras(ListaDoble* lista, int dato) {
    Nodo* actual = lista->cola;
    while (actual != NULL) {
        if (actual->dato == dato) {
            return 1; // Encontrado
        }
        actual = actual->anterior;
    }
    return 0; // No encontrado
}

// Obtener el tamaño de la lista
int obtener_tamaño(ListaDoble* lista) {
    return lista->tam;
}

// Imprimir la lista desde el inicio
void imprimir_adelante(ListaDoble* lista) {
    Nodo* actual = lista->cabeza;
    printf("Lista (adelante): ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Imprimir la lista desde el final
void imprimir_atras(ListaDoble* lista) {
    Nodo* actual = lista->cola;
    printf("Lista (atrás): ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}