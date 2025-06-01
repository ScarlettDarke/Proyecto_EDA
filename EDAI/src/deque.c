#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

// Crear una deque vacía
Deque* crear_deque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    if (dq == NULL) {
        fprintf(stderr, "Error al asignar memoria para la deque\n");
        exit(EXIT_FAILURE);
    }
    dq->frente = NULL;
    dq->final = NULL;
    dq->tamaño = 0;
    return dq;
}

// Liberar toda la memoria de la deque
void destruir_deque(Deque* dq) {
    while (!esta_vacia(dq)) {
        eliminar_frente(dq);
    }
    free(dq);
}

// Insertar elemento por el frente
void insertar_frente(Deque* dq, int dato) {
    NodoDeque* nuevo = (NodoDeque*)malloc(sizeof(NodoDeque));
    if (nuevo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = dq->frente;
    
    if (esta_vacia(dq)) {
        dq->final = nuevo;
    } else {
        dq->frente->anterior = nuevo;
    }
    
    dq->frente = nuevo;
    dq->tamaño++;
}

// Eliminar elemento por el frente
int eliminar_frente(Deque* dq) {
    if (esta_vacia(dq)) {
        fprintf(stderr, "Error: deque vacía\n");
        exit(EXIT_FAILURE);
    }
    
    NodoDeque* temp = dq->frente;
    int dato = temp->dato;
    
    dq->frente = dq->frente->siguiente;
    if (dq->frente == NULL) {
        dq->final = NULL;
    } else {
        dq->frente->anterior = NULL;
    }
    
    free(temp);
    dq->tamaño--;
    return dato;
}

// Ver elemento del frente sin eliminarlo
int ver_frente(Deque* dq) {
    if (esta_vacia(dq)) {
        fprintf(stderr, "Error: deque vacía\n");
        exit(EXIT_FAILURE);
    }
    return dq->frente->dato;
}

// Insertar elemento por el final
void insertar_final(Deque* dq, int dato) {
    NodoDeque* nuevo = (NodoDeque*)malloc(sizeof(NodoDeque));
    if (nuevo == NULL) {
        fprintf(stderr, "Error al asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = dq->final;
    
    if (esta_vacia(dq)) {
        dq->frente = nuevo;
    } else {
        dq->final->siguiente = nuevo;
    }
    
    dq->final = nuevo;
    dq->tamaño++;
}

// Eliminar elemento por el final
int eliminar_final(Deque* dq) {
    if (esta_vacia(dq)) {
        fprintf(stderr, "Error: deque vacía\n");
        exit(EXIT_FAILURE);
    }
    
    NodoDeque* temp = dq->final;
    int dato = temp->dato;
    
    dq->final = dq->final->anterior;
    if (dq->final == NULL) {
        dq->frente = NULL;
    } else {
        dq->final->siguiente = NULL;
    }
    
    free(temp);
    dq->tamaño--;
    return dato;
}

// Ver elemento del final sin eliminarlo
int ver_final(Deque* dq) {
    if (esta_vacia(dq)) {
        fprintf(stderr, "Error: deque vacía\n");
        exit(EXIT_FAILURE);
    }
    return dq->final->dato;
}

// Verificar si la deque está vacía
int esta_vacia(Deque* dq) {
    return dq->frente == NULL;
}

// Obtener el tamaño de la deque
int tamanio_deque(Deque* dq) {
    return dq->tamaño;
}

// Imprimir todos los elementos de la deque
void imprimir_deque(Deque* dq) {
    NodoDeque* actual = dq->frente;
    printf("Deque [ ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("]\n");
}