// resonator.c
#include "resonator.h"

Resonator* crea_risonatore_LC(double L, double C, double Q, NodoElettrico* nodo_A, NodoElettrico* nodo_B) {
    Resonator* r = (Resonator*)malloc(sizeof(Resonator));
    if (!r) return NULL;

    r->L = L;
    r->C = C;
    r->Q = Q;
    r->nodo_A = nodo_A;
    r->nodo_B = nodo_B;

    r->omega_r = 1.0 / sqrt(L * C);
    r->Z_r = sqrt(L / C);
    r->kappa = r->omega_r / Q;

    return r;
}

void stampa_risonatore(const Resonator* r) {
    if (!r) return;
    printf("Risonatore LC tra nodi %s e %s:\n", r->nodo_A->nome, r->nodo_B->nome);
    printf("  L = %.3e H\n", r->L);
    printf("  C = %.3e F\n", r->C);
    printf("  omega_r = %.3e rad/s\n", r->omega_r);
    printf("  Z_r = %.3e Ohm\n", r->Z_r);
    printf("  Q = %.3f\n", r->Q);
    printf("  kappa = %.3e rad/s\n", r->kappa);
} 
