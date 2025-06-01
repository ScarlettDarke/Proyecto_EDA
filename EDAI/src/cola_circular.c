#include <stdio.h>
#include <stdlib.h>
#include "cola_circular.h"

// Crear una nueva cola circular vacía
ColaCircular* crear_cola_circular() {
    ColaCircular *cc = (ColaCircular*)malloc(sizeof(ColaCircular));
    if (cc == NULL) {
        fprintf(stderr, "Error al asignar memoria para la cola circular\n");
        exit(EXIT_FAILURE);
    }
    
    cc->elementos = (int*)malloc(CAPACIDAD_INICIAL * sizeof(int));
    if (cc->elementos == NULL) {
        free(cc);
        fprintf(stderr, "Error al asignar memoria para los elementos\n");
        exit(EXIT_FAILURE);
    }
    
    cc->capacidad = CAPACIDAD_INICIAL;
    cc->frente = 0;
    cc->final = -1;
    cc->tamaño = 0;
    return cc;
}

// Liberar toda la memoria de la cola circular
void destruir_cola_circular(ColaCircular *cc) {
    free(cc->elementos);
    free(cc);
}

// Insertar un elemento al final de la cola
void encolar_circular(ColaCircular *cc, int dato) {
    if (esta_llena_cola_circular(cc)) {
        redimensionar_cola_circular(cc, cc->capacidad * 2);
    }
    
    cc->final = (cc->final + 1) % cc->capacidad;
    cc->elementos[cc->final] = dato;
    cc->tamaño++;
}

// Eliminar y devolver el elemento del frente
int desencolar_circular(ColaCircular *cc) {
    if (esta_vacia_cola_circular(cc)) {
        fprintf(stderr, "Error: cola circular vacía\n");
        exit(EXIT_FAILURE);
    }
    
    int dato = cc->elementos[cc->frente];
    cc->frente = (cc->frente + 1) % cc->capacidad;
    cc->tamaño--;
    
    // Reducir capacidad si hay mucha capacidad no utilizada
    if (cc->tamaño < cc->capacidad / 4 && cc->capacidad > CAPACIDAD_INICIAL) {
        redimensionar_cola_circular(cc, cc->capacidad / 2);
    }
    
    return dato;
}

// Ver el elemento del frente sin eliminarlo
int frente_cola_circular(ColaCircular *cc) {
    if (esta_vacia_cola_circular(cc)) {
        fprintf(stderr, "Error: cola circular vacía\n");
        exit(EXIT_FAILURE);
    }
    return cc->elementos[cc->frente];
}

// Verificar si la cola está vacía
int esta_vacia_cola_circular(ColaCircular *cc) {
    return cc->tamaño == 0;
}

// Verificar si la cola está llena
int esta_llena_cola_circular(ColaCircular *cc) {
    return cc->tamaño == cc->capacidad;
}

// Obtener el número de elementos en la cola
int tamanio_cola_circular(ColaCircular *cc) {
    return cc->tamaño;
}

// Redimensionar el arreglo interno
void redimensionar_cola_circular(ColaCircular *cc, int nueva_capacidad) {
    int *nuevos_elementos = (int*)malloc(nueva_capacidad * sizeof(int));
    if (nuevos_elementos == NULL) {
        fprintf(stderr, "Error al redimensionar la cola circular\n");
        exit(EXIT_FAILURE);
    }
    
    // Copiar elementos al nuevo arreglo manteniendo el orden
    for (int i = 0; i < cc->tamaño; i++) {
        nuevos_elementos[i] = cc->elementos[(cc->frente + i) % cc->capacidad];
    }
    
    free(cc->elementos);
    cc->elementos = nuevos_elementos;
    cc->frente = 0;
    cc->final = cc->tamaño - 1;
    cc->capacidad = nueva_capacidad;
}

// Imprimir todos los elementos de la cola circular
void imprimir_cola_circular(ColaCircular *cc) {
    printf("Cola Circular [ ");
    for (int i = 0; i < cc->tamaño; i++) {
        printf("%d ", cc->elementos[(cc->frente + i) % cc->capacidad]);
    }
    printf("] (Capacidad: %d)\n", cc->capacidad);
}