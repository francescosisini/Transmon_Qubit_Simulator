int main() {
    CircuitoElettronico* circuito = crea_circuito();

    // Massa è nodo 0
    NodoElettrico* massa = crea_nodo(0);
    NodoElettrico* nodo1 = crea_nodo(1);

    aggiungi_nodo(circuito, massa);
    aggiungi_nodo(circuito, nodo1);

    Generatore* gen = crea_generatore("V1", GENERATORE_DC, 5.0, 0.0, nodo1, massa);
    aggiungi_generatore(circuito, gen);

    Resistor* res = crea_resistor("R1", 1000.0, nodo1, massa);
    aggiungi_resistor(circuito, res);

    risolvi_dc(circuito);

    printf("Tensione nodo1: %.2f V\n", get_tensione_nodo(nodo1));
    printf("Corrente nella resistenza: %.6f A\n", get_corrente_resistenza(res));

    return 0;
}
