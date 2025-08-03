// resonator.h
#ifndef RESONATOR_H
#define RESONATOR_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Costanti fisiche
#define PI 3.141592653589793
#define HBAR 1.0545718e-34
#define E_CHARGE 1.60217662e-19

// Nodo elettrico
typedef struct {
    int id;
    const char* nome;
} NodoElettrico;

// Struttura dati per il risonatore
typedef struct {
    NodoElettrico* nodo_A;  // Nodo iniziale
    NodoElettrico* nodo_B;  // Nodo finale
    double L;         // Induttanza in Henry
    double C;         // Capacita in Farad
    double omega_r;   // Frequenza angolare in rad/s
    double Z_r;       // Impedenza caratteristica in Ohm
    double Q;         // Fattore di qualita
    double kappa;     // Larghezza di riga in rad/s
} Resonator;

// Funzione per creare un risonatore LC
Resonator* crea_risonatore_LC(double L, double C, double Q, NodoElettrico* nodo_A, NodoElettrico* nodo_B);

// Funzione per stampare i parametri del risonatore
void stampa_risonatore(const Resonator* r);

#endif
