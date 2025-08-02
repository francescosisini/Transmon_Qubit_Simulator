// main.c
#include "resonator.h"

int main() {
    // Valori realistici: L = 10 nH, C = 100 fF, Q = 10000
    double L = 10e-9;     // 10 nanoHenry
    double C = 100e-15;   // 100 femtoFarad
    double Q = 10000.0;

    Resonator* r = crea_risonatore_LC(L, C, Q);
    if (!r) {
        fprintf(stderr, "Errore nella creazione del risonatore.\n");
        return 1;
    }

    stampa_risonatore(r);

    free(r);
    return 0;
}
