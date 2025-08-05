#ifndef CIRCUITO_H
#define CIRCUITO_H

#include "resistor.h"
#include "generator.h"
#include "capacitor.h"
#include "nodo.h"
#include "resonator.h"
#include "transmon.h"
#include "coaxial.h"

typedef struct {
    NodoElettrico** nodi;
    int num_nodi;

    Resistor** resistors;
    int num_resistors;

    Generatore** generatori;
    int num_generatori;

    Capacitor** condensatori;
    int num_condensatori;

    Resonator** risonatori;
    int num_risonatori;

    Transmon** transmon;
    int num_transmon;

    CoaxialCable** coassiali;
    int num_coassiali;
} CircuitoElettronico;

CircuitoElettronico* crea_circuito();
void aggiungi_nodo(CircuitoElettronico* c, NodoElettrico* n);
void aggiungi_resistor(CircuitoElettronico* c, Resistor* r);
void aggiungi_generatore(CircuitoElettronico* c, Generatore* g);
void aggiungi_capacitor(CircuitoElettronico* c, Capacitor* cap);
void aggiungi_risonatore(CircuitoElettronico* c, Resonator* r);
void aggiungi_transmon(CircuitoElettronico* c, Transmon* t);
void aggiungi_coassiale(CircuitoElettronico* c, CoaxialCable* cavo);

void stampa_topologia(const CircuitoElettronico* c);
void libera_circuito(CircuitoElettronico* c);

#endif
