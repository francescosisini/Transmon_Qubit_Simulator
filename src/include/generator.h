// generator.h
#ifndef GENERATOR_H
#define GENERATOR_H

#include "nodo.h"

typedef enum {
    GENERATORE_DC,
    GENERATORE_SINUSOIDALE,
    GENERATORE_FORMA_ONDA
} TipoGeneratore;

typedef struct {
    const char* nome;
    TipoGeneratore tipo;
    double valore;      // Ampiezza o valore costante
    double frequenza;   // Solo per sinusoidale
    NodoElettrico* nodo_pos;
    NodoElettrico* nodo_neg;
} Generatore;

Generatore* crea_generatore(const char* nome, TipoGeneratore tipo, double valore, double freq,
                            NodoElettrico* pos, NodoElettrico* neg);
void stampa_generatore(const Generatore* g);

#endif
