// capacitor.h
#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "nodo.h"

typedef struct {
    double capacitance;
    NodoElettrico* nodoA;
    NodoElettrico* nodoB;
} Capacitor;

Capacitor* crea_capacitor(double C, NodoElettrico* a, NodoElettrico* b);
void stampa_capacitor(const Capacitor* c);

#endif
