#ifndef CIRCUITO_H
#define CIRCUITO_H

#include "resistor.h"
#include "generator.h"
#include "capacitor.h"
#include "nodo.h"
#include "resonator.h"
#include "transmon.h"
#include "coaxial.h"

#define MAX_COMPONENTI 100

typedef struct {
    NodoElettrico* nodi[MAX_COMPONENTI];
    int num_nodi;

    Resistor* resistors[MAX_COMPONENTI];
    int num_resistors;

    Generatore* generatori[MAX_COMPONENTI];
    int num_generatori;

    Capacitor* capacitors[MAX_COMPONENTI];
    int num_capacitors;

    Resonator* risonatori[MAX_COMPONENTI];
    int num_risonatori;

    Transmon* transmon[MAX_COMPONENTI];
    int num_transmon;

    CoaxialCable* coassiali[MAX_COMPONENTI];
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

#endif
