#include <math.h>
#include <stdio.h>
#include <string.h>
#include "analisi_dc.h"
#include "resistor.h"
#include "generator.h"
#include "circuito.h"
#include "nodo.h"

#define MAX_NODI 100
#define MAX_EQUAZIONI (MAX_NODI + 100)

static double tensioni_nodi[MAX_NODI] = {0};

void risolvi_dc(CircuitoElettronico* c) {
    int n = c->num_nodi;
    int m = c->num_generatori;
    int dim = n + m;

    double A[MAX_EQUAZIONI][MAX_EQUAZIONI] = {0};
    double b[MAX_EQUAZIONI] = {0};

    // Costruzione matrice G da resistenze
    for (int i = 0; i < c->num_resistors; i++) {
        Resistor* r = c->resistors[i];
        int a = r->nodoA->id;
        int b_ = r->nodoB->id;
        double g = 1.0 / r->resistenza;
        if (a >= 0) {
            A[a][a] += g;
            if (b_ >= 0) A[a][b_] -= g;
        }
        if (b_ >= 0) {
            A[b_][b_] += g;
            if (a >= 0) A[b_][a] -= g;
        }
    }

    // Aggiunta generatori DC usando MNA
    for (int k = 0; k < m; k++) {
        Generatore* g = c->generatori[k];
        if (g->tipo != GENERATORE_DC) continue;

        int pos = g->nodo_pos->id;
        int neg = g->nodo_neg->id;
        int eq = n + k; // equazione extra per il generatore

        // Equazione KVL
        if (pos >= 0) {
            A[eq][pos] = 1.0;
            A[pos][eq] = 1.0;
        }
        if (neg >= 0) {
            A[eq][neg] = -1.0;
            A[neg][eq] = -1.0;
        }
        b[eq] = g->valore;
    }

    // Vincola il nodo 0 (massa) a 0V
    for (int j = 0; j < dim; j++) A[0][j] = 0.0;
    A[0][0] = 1.0;
    b[0] = 0.0;

    // Eliminazione di Gauss
    for (int i = 0; i < dim; i++) {
        if (fabs(A[i][i]) < 1e-12) continue;
        for (int k = i + 1; k < dim; k++) {
            double f = A[k][i] / A[i][i];
            for (int j = i; j < dim; j++) A[k][j] -= f * A[i][j];
            b[k] -= f * b[i];
        }
    }

    // Sostituzione all'indietro
    double x[MAX_EQUAZIONI] = {0};
    for (int i = dim - 1; i >= 0; i--) {
        if (fabs(A[i][i]) < 1e-12) {
            printf("Errore: A[%d][%d] = 0\n", i, i);
            x[i] = 0.0;
            continue;
        }
        x[i] = b[i];
        for (int j = i + 1; j < dim; j++) x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }

    for (int i = 0; i < n; i++) tensioni_nodi[i] = x[i];
}

double get_tensione_nodo(NodoElettrico* nodo) {
    return tensioni_nodi[nodo->id];
}

double get_corrente_resistenza(const Resistor* r) {
    double va = get_tensione_nodo(r->nodoA);
    double vb = get_tensione_nodo(r->nodoB);
    return (va - vb) / r->resistenza;
}
