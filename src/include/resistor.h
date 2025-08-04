// resistor.h
#ifndef RESISTOR_H
#define RESISTOR_H

#include "nodo.h"

typedef struct {
    const char* nome;
    double resistenza;
    NodoElettrico* nodoA;
    NodoElettrico* nodoB;
} Resistor;

Resistor* crea_resistor(const char* nome, double R, NodoElettrico* A, NodoElettrico* B);
void stampa_resistor(const Resistor* r);

#endif
