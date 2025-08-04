// circuito.h
#ifndef CIRCUITO_H
#define CIRCUITO_H

#include "nodo.h"
#include "resonator.h"
#include "transmon.h"
#include "capacitor.h"
#include "coaxial.h"
#include "resistor.h"
#include "generator.h"

typedef struct {
    NodoElettrico** nodi;
    int num_nodi;

    Resonator** risonatori;
    int num_risonatori;

    Transmon** transmon;
    int num_transmon;

    Capacitor** condensatori;
    int num_condensatori;

    CoaxialCable** coassiali;
    int num_coassiali;

    // Aggiunte necessarie:
    Resistor** resistors;
    int num_resistors;

    Generatore** generatori;
    int num_generatori;
} CircuitoElettronico;

// Metodi esistenti
CircuitoElettronico* crea_circuito();
void aggiungi_nodo(CircuitoElettronico* c, NodoElettrico* n);
void aggiungi_risonatore(CircuitoElettronico* c, Resonator* r);
void aggiungi_transmon(CircuitoElettronico* c, Transmon* t);
void aggiungi_capacitor(CircuitoElettronico* c, Capacitor* cap);
void aggiungi_coassiale(CircuitoElettronico* c, CoaxialCable* cavo);

// Metodi da aggiungere
void aggiungi_resistor(CircuitoElettronico* c, Resistor* res);
void aggiungi_generatore(CircuitoElettronico* c, Generatore* gen);

// Utility
void stampa_topologia(const CircuitoElettronico* c);
void libera_circuito(CircuitoElettronico* c);

#endif
