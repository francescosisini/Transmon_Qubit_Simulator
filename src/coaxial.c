// coaxial.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coaxial.h"

CoaxialCable* crea_coaxial(const char* nome,
                           NodoElettrico* in_core, NodoElettrico* in_gnd,
                           NodoElettrico* out_core, NodoElettrico* out_gnd) {
    CoaxialCable* cavo = malloc(sizeof(CoaxialCable));
    if (!cavo) return NULL;
    cavo->nome = strdup(nome);
    cavo->ingresso_core = in_core;
    cavo->ingresso_schermo = in_gnd;
    cavo->uscita_core = out_core;
    cavo->uscita_schermo = out_gnd;
    return cavo;
}

void stampa_coaxial(const CoaxialCable* cavo) {
    if (!cavo) return;
    printf("Cavo Coassiale %s:\n", cavo->nome);
    printf("  Ingresso: core=%s, schermo=%s\n",
           cavo->ingresso_core->nome, cavo->ingresso_schermo->nome);
    printf("  Uscita:  core=%s, schermo=%s\n",
           cavo->uscita_core->nome, cavo->uscita_schermo->nome);
}
