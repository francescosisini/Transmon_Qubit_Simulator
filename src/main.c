// main.c – Esempio base con circuito resistivo e generatore DC
#include <stdio.h>
#include "circuito.h"
#include "resistor.h"
#include "generator.h"
#include "analisi_dc.h"
#include "nodo.h"

int main() {
    // Creazione circuito
    CircuitoElettronico* circuito = crea_circuito();

    // Creazione nodi
    NodoElettrico* massa = crea_nodo(0);
    NodoElettrico* nodo1 = crea_nodo(1);

    aggiungi_nodo(circuito, massa);
    aggiungi_nodo(circuito, nodo1);

    // Generatore DC 5V tra nodo1 e massa
    Generatore* gen = crea_generatore("V1", GENERATORE_DC, 5.0, 0.0, 0.0, nodo1, massa);
    aggiungi_generatore(circuito, gen);

    // Resistenza da 1000 ohm tra nodo1 e massa
    Resistor* res = crea_resistor("R1", 1000.0, nodo1, massa);
    aggiungi_resistor(circuito, res);

    // Analisi in DC
    risolvi_dc(circuito);

    // Output
    printf("Tensione nodo1: %.2f V\n", get_tensione_nodo(nodo1));
    printf("Corrente nella resistenza: %.6f A\n", get_corrente_resistenza(res));

    return 0;
}
