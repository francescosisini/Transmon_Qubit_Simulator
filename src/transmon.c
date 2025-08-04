#include "transmon.h"
#include "costanti_fisiche.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

Transmon* crea_transmon(double C, double EJ, NodoElettrico* nodo_A, NodoElettrico* nodo_B) {
    Transmon* t = (Transmon*)malloc(sizeof(Transmon));
    if (!t) return NULL;

    t->C = C;
    t->EJ = EJ;
    t->nodo_A = nodo_A;
    t->nodo_B = nodo_B;

    // Energia di carica: EC = e^2 / (2C)
    t->EC = pow(E_CHARGE, 2) / (2.0 * C);

    // Frequenza del qubit: omega_q ≈ sqrt(8EJEC)/h - EC/h
    double sqrt8EJEC = sqrt(8.0 * EJ * t->EC);
    t->omega_q = (sqrt8EJEC - t->EC) / HBAR;

    // Anarmonicita (approssimazione): alpha ≈ -EC/h
    t->alpha = -t->EC / HBAR;

    return t;
}

void stampa_transmon(const Transmon* t) {
    if (!t) return;
    printf("Transmon tra nodi %s e %s:\n", t->nodo_A->nome, t->nodo_B->nome);
    printf("  C = %.3e F\n", t->C);
    printf("  EJ = %.3e J\n", t->EJ);
    printf("  EC = %.3e J\n", t->EC);
    printf("  omega_q = %.3e rad/s\n", t->omega_q);
    printf("  alpha = %.3e rad/s\n", t->alpha);
}
