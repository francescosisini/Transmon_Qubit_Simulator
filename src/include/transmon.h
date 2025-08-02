// transmon.h
#ifndef TRANSMON_H
#define TRANSMON_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Costanti fisiche
#define PI 3.141592653589793
#define HBAR 1.0545718e-34
#define E_CHARGE 1.60217662e-19

// Struttura dati per il transmon
typedef struct {
    double E_C;     // Energia di carica (Joule)
    double E_J;     // Energia di Josephson (Joule)
    double freq_q;  // Frequenza del qubit (rad/s)
    double alpha;   // Anarmonicita (rad/s)
} Transmon;

// Crea un transmon dato C e E_J
Transmon* crea_transmon(double C, double E_J);

// Stampa i parametri principali del transmon
void stampa_transmon(const Transmon* t);

#endif
