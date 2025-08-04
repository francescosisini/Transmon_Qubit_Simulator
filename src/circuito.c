// circuito.c
#include <stdio.h>
#include <stdlib.h>
#include "circuito.h"

CircuitoElettronico* crea_circuito() {
    CircuitoElettronico* c = malloc(sizeof(CircuitoElettronico));
    if (!c) return NULL;
    c->nodi = NULL; c->num_nodi = 0;
    c->risonatori = NULL; c->num_risonatori = 0;
    c->transmon = NULL; c->num_transmon = 0;
    c->condensatori = NULL; c->num_condensatori = 0;
    c->coassiali = NULL; c->num_coassiali = 0;
    c->resistors = NULL; c->num_resistors = 0;
    c->generatori = NULL; c->num_generatori = 0;
    return c;
}

void aggiungi_nodo(CircuitoElettronico* c, NodoElettrico* n) {
    c->nodi = realloc(c->nodi, (c->num_nodi + 1) * sizeof(NodoElettrico*));
    c->nodi[c->num_nodi++] = n;
}

void aggiungi_risonatore(CircuitoElettronico* c, Resonator* r) {
    c->risonatori = realloc(c->risonatori, (c->num_risonatori + 1) * sizeof(Resonator*));
    c->risonatori[c->num_risonatori++] = r;
}

void aggiungi_transmon(CircuitoElettronico* c, Transmon* t) {
    c->transmon = realloc(c->transmon, (c->num_transmon + 1) * sizeof(Transmon*));
    c->transmon[c->num_transmon++] = t;
}

void aggiungi_capacitor(CircuitoElettronico* c, Capacitor* cap) {
    c->condensatori = realloc(c->condensatori, (c->num_condensatori + 1) * sizeof(Capacitor*));
    c->condensatori[c->num_condensatori++] = cap;
}

void aggiungi_coassiale(CircuitoElettronico* c, CoaxialCable* cavo) {
    c->coassiali = realloc(c->coassiali, (c->num_coassiali + 1) * sizeof(CoaxialCable*));
    c->coassiali[c->num_coassiali++] = cavo;
}

// Nuove implementazioni mancanti
void aggiungi_resistor(CircuitoElettronico* c, Resistor* res) {
    c->resistors = realloc(c->resistors, (c->num_resistors + 1) * sizeof(Resistor*));
    c->resistors[c->num_resistors++] = res;
}

void aggiungi_generatore(CircuitoElettronico* c, Generatore* gen) {
    c->generatori = realloc(c->generatori, (c->num_generatori + 1) * sizeof(Generatore*));
    c->generatori[c->num_generatori++] = gen;
}

void stampa_topologia(const CircuitoElettronico* c) {
    printf("\nTopologia del circuito:\n");
    for (int i = 0; i < c->num_nodi; i++) {
        printf("Nodo %d: %s\n", c->nodi[i]->id, c->nodi[i]->nome);
    }
    for (int i = 0; i < c->num_risonatori; i++) {
        stampa_risonatore(c->risonatori[i]);
    }
    for (int i = 0; i < c->num_transmon; i++) {
        stampa_transmon(c->transmon[i]);
    }
    for (int i = 0; i < c->num_condensatori; i++) {
        stampa_capacitor(c->condensatori[i]);
    }
    for (int i = 0; i < c->num_coassiali; i++) {
        stampa_coaxial(c->coassiali[i]);
    }
    for (int i = 0; i < c->num_resistors; i++) {
        stampa_resistor(c->resistors[i]);
    }
    for (int i = 0; i < c->num_generatori; i++) {
        stampa_generatore(c->generatori[i]);
    }
}

void libera_circuito(CircuitoElettronico* c) {
    if (!c) return;
    free(c->nodi);
    free(c->risonatori);
    free(c->transmon);
    free(c->condensatori);
    free(c->coassiali);
    free(c->resistors);
    free(c->generatori);
    free(c);
}
