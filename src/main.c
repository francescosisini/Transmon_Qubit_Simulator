// main.c
#include <stdio.h>
#include "resonator.h"
#include "transmon.h"

int main() {
    // Creazione dei nodi elettrici
    NodoElettrico nodo1 = { .id = 1, .nome = "A" };
    NodoElettrico nodo2 = { .id = 2, .nome = "B" };
    NodoElettrico nodo3 = { .id = 3, .nome = "C" };
    NodoElettrico nodo4 = { .id = 4, .nome = "D" };

    // Creazione di un risonatore LC tra A e B
    Resonator* r = crea_risonatore_LC(1e-9, 1e-12, 1000.0, &nodo1, &nodo2);
    stampa_risonatore(r);

    // Creazione di un transmon tra C e D
    Transmon* t = crea_transmon(1e-12, 1e-22, &nodo3, &nodo4);
    stampa_transmon(t);

    // Liberazione della memoria
    free(r);
    free(t);

    return 0;
}
