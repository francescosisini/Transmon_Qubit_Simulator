// resonator.h
#ifndef RESONATOR_H
#define RESONATOR_H

#include <math.h>

// Costanti fisiche
#define PI 3.141592653589793
#define HBAR 1.0545718e-34
#define E_CHARGE 1.60217662e-19

// Struttura dati per il risonatore
typedef struct {
    double L;         // Induttanza in Henry
    double C;         // Capacita in Farad
    double omega_r;   // Frequenza angolare in rad/s
    double Z_r;       // Impedenza caratteristica in Ohm
    double Q;         // Fattore di qualita
    double kappa;     // Larghezza di riga in rad/s
} Resonator;

// Funzione per creare un risonatore LC
Resonator* crea_risonatore_LC(double L, double C, double Q);

// Funzione per stampare i parametri del risonatore
void stampa_risonatore(const Resonator* r);

#endif
