// circuito.h
#ifndef CIRCUITO_H
#define CIRCUITO_H

#include "nodo.h"
#include "resonator.h"
#include "transmon.h"

// Placeholder future components
// #include "capacitor.h"
// #include "coaxial.h"

typedef struct {
    NodoElettrico** nodi;
    int num_nodi;

    Resonator** risonatori;
    int num_risonatori;

    Transmon** transmon;
    int num_transmon;

    // Future additions
    // Capacitor** condensatori;
    // int num_condensatori;

    // CoaxialCable** cavi;
    // int num_cavi;

} CircuitoElettronico;

CircuitoElettronico* crea_circuito();
void aggiungi_nodo(CircuitoElettronico* c, NodoElettrico* n);
void aggiungi_risonatore(CircuitoElettronico* c, Resonator* r);
void aggiungi_transmon(CircuitoElettronico* c, Transmon* t);
void stampa_topologia(const CircuitoElettronico* c);
void libera_circuito(CircuitoElettronico* c);

#endif
