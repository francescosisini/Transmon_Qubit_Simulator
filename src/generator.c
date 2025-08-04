// generator.c
#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

Generatore* crea_generatore(const char* nome, TipoGeneratore tipo, double valore, double freq,
                            NodoElettrico* pos, NodoElettrico* neg) {
    Generatore* g = malloc(sizeof(Generatore));
    if (!g) return NULL;
    g->nome = nome;
    g->tipo = tipo;
    g->valore = valore;
    g->frequenza = freq;
    g->nodo_pos = pos;
    g->nodo_neg = neg;
    return g;
}

void stampa_generatore(const Generatore* g) {
    const char* tipo_str = (g->tipo == GENERATORE_DC) ? "DC" :
                           (g->tipo == GENERATORE_SINUSOIDALE) ? "Sinusoidale" : "Forma d'Onda";
    printf("Generatore %s (%s) tra %s e %s: ampiezza %.2f V, freq %.2f Hz\n",
           g->nome, tipo_str, g->nodo_pos->nome, g->nodo_neg->nome, g->valore, g->frequenza);
}
