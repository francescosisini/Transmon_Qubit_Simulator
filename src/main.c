// main.c
#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "resonator.h"
#include "transmon.h"
#include "circuito.h"

int main() {
    // Crea il circuito
    CircuitoElettronico* circuito = crea_circuito();

    // Crea e registra i nodi
    NodoElettrico* nodo1 = malloc(sizeof(NodoElettrico)); nodo1->id = 1; nodo1->nome = "A";
    NodoElettrico* nodo2 = malloc(sizeof(NodoElettrico)); nodo2->id = 2; nodo2->nome = "B";
    NodoElettrico* nodo3 = malloc(sizeof(NodoElettrico)); nodo3->id = 3; nodo3->nome = "C";
    NodoElettrico* nodo4 = malloc(sizeof(NodoElettrico)); nodo4->id = 4; nodo4->nome = "D";

    aggiungi_nodo(circuito, nodo1);
    aggiungi_nodo(circuito, nodo2);
    aggiungi_nodo(circuito, nodo3);
    aggiungi_nodo(circuito, nodo4);

    // Crea e registra un risonatore LC
    Resonator* r = crea_risonatore_LC(1e-9, 1e-12, 1000.0, nodo1, nodo2);
    aggiungi_risonatore(circuito, r);

    // Crea e registra un transmon
    Transmon* t = crea_transmon(1e-12, 1e-22, nodo3, nodo4);
    aggiungi_transmon(circuito, t);

    // Stampa la topologia
    stampa_topologia(circuito);

    // Libera la memoria
    libera_circuito(circuito);
    free(nodo1); free(nodo2); free(nodo3); free(nodo4);

    return 0;
}
