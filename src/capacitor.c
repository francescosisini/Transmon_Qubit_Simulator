// capacitor.c
#include <stdio.h>
#include <stdlib.h>
#include "capacitor.h"

Capacitor* crea_capacitor(double C, NodoElettrico* a, NodoElettrico* b) {
    Capacitor* cap = malloc(sizeof(Capacitor));
    if (!cap) return NULL;
    cap->capacitance = C;
    cap->nodoA = a;
    cap->nodoB = b;
    return cap;
}

void stampa_capacitor(const Capacitor* c) {
    if (!c) return;
    printf("Capacitor tra %s e %s: C = %g F\n",
           c->nodoA->nome, c->nodoB->nome, c->capacitance);
}
