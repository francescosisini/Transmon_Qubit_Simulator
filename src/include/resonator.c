// resonator.c
#include "resonator.h"

Resonator* crea_risonatore_LC(double L, double C, double Q) {
    Resonator* r = (Resonator*) malloc(sizeof(Resonator));
    if (!r) return NULL;

    r->L = L;
    r->C = C;
    r->omega_r = 1.0 / sqrt(L * C);
    r->Z_r = sqrt(L / C);
    r->Q = Q;
    r->kappa = r->omega_r / Q;

    return r;
}

void stampa_risonatore(const Resonator* r) {
    if (!r) return;
    printf("--- Parametri del Risonatore ---\n");
    printf("L = %.3e H\n", r->L);
    printf("C = %.3e F\n", r->C);
    printf("\u03C9_r = %.3e rad/s (%.3f GHz)\n", r->omega_r, r->omega_r / (2.0 * PI * 1e9));
    printf("Z_r = %.3f Ohm\n", r->Z_r);
    printf("Q = %.1f\n", r->Q);
    printf("\u03BA = %.3e rad/s\n", r->kappa);
    printf("-------------------------------\n");
}
