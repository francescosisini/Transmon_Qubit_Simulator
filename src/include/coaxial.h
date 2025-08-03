// coaxial.h
#ifndef COAXIAL_H
#define COAXIAL_H

#include "nodo.h"

typedef struct {
    const char* nome;
    NodoElettrico* ingresso_core;
    NodoElettrico* ingresso_schermo;
    NodoElettrico* uscita_core;
    NodoElettrico* uscita_schermo;
} CoaxialCable;

CoaxialCable* crea_coaxial(const char* nome,
                           NodoElettrico* in_core, NodoElettrico* in_gnd,
                           NodoElettrico* out_core, NodoElettrico* out_gnd);

void stampa_coaxial(const CoaxialCable* cavo);

#endif
