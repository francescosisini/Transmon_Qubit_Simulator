// transmon.h
#ifndef TRANSMON_H
#define TRANSMON_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Nodo elettrico (riutilizzato)
typedef struct {
    int id;
    const char* nome;
} NodoElettrico;

// Struttura dati per il transmon
typedef struct {
    NodoElettrico* nodo_A;  // Nodo iniziale
    NodoElettrico* nodo_B;  // Nodo finale
    double C;         // Capacita in Farad
    double EJ;        // Energia di Josephson in Joule
    double EC;        // Energia di carica in Joule
    double omega_q;   // Frequenza del qubit in rad/s
    double alpha;     // Anarmonicita in rad/s
} Transmon;

// Funzione per creare un transmon
Transmon* crea_transmon(double C, double EJ, NodoElettrico* nodo_A, NodoElettrico* nodo_B);

// Funzione per stampare i parametri del transmon
void stampa_transmon(const Transmon* t);

#endif
