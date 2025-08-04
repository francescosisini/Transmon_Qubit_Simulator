#include <math.h>
#include <stdio.h>
#include "analisi_dc.h"
#include "resistor.h"
#include "generator.h"
#include "circuito.h"
#include "nodo.h"

#define MAX_NODI 100

static double tensioni_nodi[MAX_NODI] = {0};

void risolvi_dc(CircuitoElettronico* c) {
    int n = c->num_nodi;
    double G[MAX_NODI][MAX_NODI] = {0};
    double I[MAX_NODI] = {0};

    // Costruzione matrice di conduttanza G
    for (int i = 0; i < c->num_resistors; i++) {
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

    // Correnti iniettate da generatori DC
    for (int i = 0; i < c->num_generatori; i++) {
        Generatore* g = c->generatori[i];
        if (g->tipo != GENERATORE_DC) continue;
        int pos = g->nodo_pos->id;
        int neg = g->nodo_neg->id;
        double v = g->valore;
        if (pos >= 0) I[pos] += v;
        if (neg >= 0) I[neg] -= v;
    }

    // Eliminazione in avanti (Gauss)
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (fabs(G[i][i]) < 1e-12) continue;
            double f = G[k][i] / G[i][i];
            for (int j = i; j < n; j++) G[k][j] -= f * G[i][j];
            I[k] -= f * I[i];
        }
    }

    // Sostituzione all'indietro
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
