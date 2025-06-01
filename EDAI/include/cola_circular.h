#ifndef COLA_CIRCULAR_H
#define COLA_CIRCULAR_H

#define CAPACIDAD_INICIAL 4

typedef struct {
    int *elementos;
    int capacidad;
    int frente;
    int final;
    int tam;
} ColaCircular;

// Funciones básicas
ColaCircular* crear_cola_circular();
void destruir_cola_circular(ColaCircular *cc);

// Operaciones principales
void encolar_circular(ColaCircular *cc, int dato);
int desencolar_circular(ColaCircular *cc);
int frente_cola_circular(ColaCircular *cc);

// Funciones de utilidad
int esta_vacia_cola_circular(ColaCircular *cc);
int esta_llena_cola_circular(ColaCircular *cc);
int tamanio_cola_circular(ColaCircular *cc);
void redimensionar_cola_circular(ColaCircular *cc, int nueva_capacidad);
void imprimir_cola_circular(ColaCircular *cc);

#endif 