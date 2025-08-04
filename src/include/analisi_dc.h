// analisi_dc.h
#ifndef ANALISI_DC_H
#define ANALISI_DC_H

#include "circuito.h"

// Risolve il circuito in continua e assegna tensioni ai nodi
void risolvi_dc(CircuitoElettronico* c);

// Dopo risoluzione, restituisce la tensione al nodo
double get_tensione_nodo(NodoElettrico* nodo);

// Dopo risoluzione, restituisce corrente su resistenza
double get_corrente_resistenza(const Resistor* r);

#endif
