// main.c
#include "resonator.h"
#include "transmon.h"

int main() {
    // --- Risonatore ---
    double L = 10e-9;     // 10 nH
    double C_r = 100e-15; // 100 fF
    double Q = 10000.0;

    Resonator* r = crea_risonatore_LC(L, C_r, Q);
    if (!r) {
        fprintf(stderr, "Errore nella creazione del risonatore.\n");
        return 1;
    }

    stampa_risonatore(r);

    // --- Transmon ---
    double C_q = 80e-15;     // 80 fF
    double EJ = 20e-24;      // 20 aJoule (≈ 125 GHz * hbar)

    Transmon* t = crea_transmon(C_q, EJ);
    if (!t) {
        fprintf(stderr, "Errore nella creazione del transmon.\n");
        free(r);
        return 1;
    }

    stampa_transmon(t);

    // --- Cleanup ---
    free(r);
    free(t);
    return 0;
}
