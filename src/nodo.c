// nodo.c
#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"

NodoElettrico* crea_nodo(int id) {
    NodoElettrico* n = malloc(sizeof(NodoElettrico));
    if (!n) return NULL;

    n->id = id;

    // Generazione automatica del nome tipo "N0", "N1", ecc.
    char* nome = malloc(10);
    snprintf(nome, 10, "N%d", id);
    n->nome = nome;

    return n;
}
