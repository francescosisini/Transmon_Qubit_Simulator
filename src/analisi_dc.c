// analisi_dc.c

#include "analisi_dc.h"

/**
 * Risolve il circuito in continua usando il metodo dei nodi:
 * Si costruisce la matrice G (conduttanza) e il vettore I (correnti iniettate).
 * Il sistema lineare G * V = I viene poi risolto con eliminazione di Gauss.
 *
 * Metodo di Gauss:
 *  - Eliminazione in avanti: si riduce il sistema in forma triangolare superiore
 *  - Sostituzione all’indietro: si risolve la triangolare ottenuta per ottenere le tensioni
 */
#include "resistor.h"
#include "generator.h"
#include "circuito.h"
#include "nodo.h"

void risolvi_dc(CircuitoElettronico* c) {
    int n = c->nodo_count;
    double G[MAX_NODI][MAX_NODI] = {0};
    double I[MAX_NODI] = {0};

    for (int i = 0; i < c->resistor_count; i++) {
        Resistor* r = c->resistors[i];
        int a = r->nodoA->id;
        int b = r->nodoB->id;
        double g = 1.0 / r->resistenza;
        if (a >= 0) {
            G[a][a] += g;
            if (b >= 0) G[a][b] -= g;
        }
        if (b >= 0) {
            G[b][b] += g;
            if (a >= 0) G[b][a] -= g;
        }
    }

    for (int i = 0; i < c->generatore_count; i++) {
        Generatore* g = c->generatori[i];
        if (g->tipo != GENERATORE_DC) continue;
        int pos = g->nodo_pos->id;
        int neg = g->nodo_neg->id;
        double v = g->valore;
        if (pos >= 0) I[pos] += v;
        if (neg >= 0) I[neg] -= v;
    }

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (fabs(G[i][i]) < 1e-12) continue;
            double f = G[k][i] / G[i][i];
            for (int j = i; j < n; j++) G[k][j] -= f * G[i][j];
            I[k] -= f * I[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        tensioni_nodi[i] = I[i];
        for (int j = i + 1; j < n; j++) tensioni_nodi[i] -= G[i][j] * tensioni_nodi[j];
        tensioni_nodi[i] /= G[i][i];
    }
}

double get_tensione_nodo(NodoElettrico* nodo) {
    return tensioni_nodi[nodo->id];
}

double get_corrente_resistenza(const Resistor* r) {
    double va = get_tensione_nodo(r->nodoA);
    double vb = get_tensione_nodo(r->nodoB);
    return (va - vb) / r->resistenza;
}
