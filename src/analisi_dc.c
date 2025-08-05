#include <math.h>
#include <stdio.h>
#include <string.h>
#include "analisi_dc.h"
#include "resistor.h"
#include "generator.h"
#include "capacitor.h"
#include "circuito.h"
#include "nodo.h"

#define MAX_NODI 100
#define MAX_EQUAZIONI (MAX_NODI + 100)

static double tensioni_nodi[MAX_NODI] = {0};
static double correnti_generatori[100] = {0}; // Assumiamo massimo 100 generatori DC

void risolvi_dc(CircuitoElettronico* c) {
    int n = c->num_nodi;
    int m = c->num_generatori; // numero generatori DC
    int dim = n + m; // dimensione del sistema aumentato

    double A[MAX_EQUAZIONI][MAX_EQUAZIONI] = {0};
    double b[MAX_EQUAZIONI] = {0};

    // Costruzione matrice di conduttanza G (n x n)
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

    // I condensatori non vengono inclusi nell'analisi DC, ma si potrebbero stampare

    // Gestione generatori di tensione ideali
    for (int k = 0; k < m; k++) {
        Generatore* g = c->generatori[k];
        if (g->tipo != GENERATORE_DC) continue;

        int pos = g->nodo_pos->id;
        int neg = g->nodo_neg->id;
        int riga = n + k;

        if (pos >= 0) {
            A[riga][pos] = 1.0;
            A[pos][riga] = 1.0;
        }
        if (neg >= 0) {
            A[riga][neg] = -1.0;
            A[neg][riga] = -1.0;
        }
        b[riga] = g->valore;
    }

    // Vincola massa a 0V
    for (int i = 0; i < dim; i++) A[0][i] = 0.0;
    A[0][0] = 1.0;
    b[0] = 0.0;

    // DEBUG: stampa matrice A e vettore b
    printf("\nMatrice A:\n");
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%10.3e ", A[i][j]);
        }
        printf("\n");
    }
    printf("\nVettore b:\n");
    for (int i = 0; i < dim; i++) {
        printf("%10.3e\n", b[i]);
    }

    // Eliminazione in avanti (Gauss)
    for (int i = 0; i < dim; i++) {
        for (int k = i + 1; k < dim; k++) {
            if (fabs(A[i][i]) < 1e-12) continue;
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

    // Salva le tensioni nei nodi
    for (int i = 0; i < n; i++) tensioni_nodi[i] = x[i];

    // Salva le correnti nei generatori
    for (int k = 0; k < m; k++) correnti_generatori[k] = x[n + k];
}

double get_tensione_nodo(NodoElettrico* nodo) {
    return tensioni_nodi[nodo->id];
}

double get_corrente_resistenza(const Resistor* r) {
    double va = get_tensione_nodo(r->nodoA);
    double vb = get_tensione_nodo(r->nodoB);
    return (va - vb) / r->resistenza;
}

double get_corrente_generatore(const Generatore* g, CircuitoElettronico* c) {
    for (int k = 0; k < c->num_generatori; k++) {
        if (c->generatori[k] == g) return correnti_generatori[k];
    }
    return 0.0;
}
