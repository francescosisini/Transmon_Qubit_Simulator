// resistor.c
#include <stdio.h>
#include <stdlib.h>
#include "resistor.h"

Resistor* crea_resistor(const char* nome, double R, NodoElettrico* A, NodoElettrico* B) {
    Resistor* r = malloc(sizeof(Resistor));
    if (!r) return NULL;
    r->nome = nome;
    r->resistenza = R;
    r->nodoA = A;
    r->nodoB = B;
    return r;
}

void stampa_resistor(const Resistor* r) {
    printf("Resistenza %s tra %s e %s: %.2f Ohm\n",
           r->nome, r->nodoA->nome, r->nodoB->nome, r->resistenza);
}
