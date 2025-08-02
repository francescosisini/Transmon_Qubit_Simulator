// transmon.c
#include "transmon.h"
#include <math.h>
Transmon* crea_transmon(double C, double E_J) {
    Transmon* t = (Transmon*) malloc(sizeof(Transmon));
    if (!t) return NULL;

    double E_C = pow(E_CHARGE, 2) / (2.0 * C); // energia di carica in Joule
    double omega_q = sqrt(8.0 * E_C * E_J) / HBAR;
    double alpha = -E_C / HBAR; // anarmonicità negativa

    t->E_C = E_C;
    t->E_J = E_J;
    t->freq_q = omega_q;
    t->alpha = alpha;

    return t;
}

void stampa_transmon(const Transmon* t) {
    if (!t) return;

    printf("--- Parametri del Transmon ---\n");
    printf("E_C = %.3e J (%.3f GHz)\n", t->E_C, t->E_C / (HBAR * 2.0 * PI * 1e9));
    printf("E_J = %.3e J\n", t->E_J);
    printf("freq_q = %.3e rad/s (%.3f GHz)\n", t->freq_q, t->freq_q / (2.0 * PI * 1e9));
    printf("alpha = %.3e rad/s (%.3f MHz)\n", t->alpha, t->alpha / (2.0 * PI * 1e6));
    printf("------------------------------\n");
}
