#ifndef NODO_H
#define NODO_H



typedef struct {
    int id;
    const char* nome;
} NodoElettrico;

NodoElettrico* crea_nodo(int id);


#endif
