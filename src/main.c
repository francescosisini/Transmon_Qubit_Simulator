// main.c
#include <stdio.h>
#include "circuito.h"
#include "resistor.h"
#include "generator.h"
#include "analisi_dc.h"

int main() {
    CircuitoElettronico circuito = crea_circuito();

    // Nodo 0 = massa, Nodo 1 = nodo positivo del generatore e della resistenza
    NodoElettrico* massa = aggiungi_nodo(&circuito); // id 0
    NodoElettrico* nodo1 = aggiungi_nodo(&circuito); // id 1

    // Generatore DC da 5V: da massa (negativo) a nodo1 (positivo)
    Generatore* gen = crea_generatore(GENERATORE_DC, 5.0, nodo1, massa);
    aggiungi_generatore(&circuito, gen);

    // Resistenza da 1k Ohm tra nodo1 e massa
    Resistor* res = crea_resistor(1000.0, nodo1, massa);
    aggiungi_resistor(&circuito, res);

    // Analisi DC
    risolvi_dc(&circuito);

    // Stampa risultati
    printf("Tensione nodo 0 (massa): %.2f V\n", get_tensione_nodo(massa));
    printf("Tensione nodo 1: %.2f V\n", get_tensione_nodo(nodo1));
    printf("Corrente nella resistenza: %.6f A\n", get_corrente_resistenza(res));

    return 0;
}
