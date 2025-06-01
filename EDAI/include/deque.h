#ifndef DEQUE_H
#define DEQUE_H

typedef struct NodoDeque {
    int dato;
    struct NodoDeque* anterior;
    struct NodoDeque* siguiente;
} NodoDeque;

typedef struct {
    NodoDeque* frente;
    NodoDeque* final;
    int tamaño;
} Deque;

// Funciones básicas
Deque* crear_deque();
void destruir_deque(Deque* dq);

// Operaciones por el frente
void insertar_frente(Deque* dq, int dato);
int eliminar_frente(Deque* dq);
int ver_frente(Deque* dq);

// Operaciones por el final
void insertar_final(Deque* dq, int dato);
int eliminar_final(Deque* dq);
int ver_final(Deque* dq);

// Funciones de utilidad
int esta_vacia(Deque* dq);
int tamanio_deque(Deque* dq);
void imprimir_deque(Deque* dq);

#endif