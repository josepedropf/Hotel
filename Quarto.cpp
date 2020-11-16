#include "Quarto.h"

Quarto::Quarto(tipo_quarto tq, int p, int n, int c, float pb) {
    tquarto = tq;
    piso = p;
    numero = n;
    capacidade = c;
    preco_base = pb;
    promo = tquarto;
}

void Quarto::Info() {
    cout << "<QUARTO>" << endl;
    cout << "Número: " << numero << " | ";
    cout << "Piso: " << piso << " | ";
    if(tquarto == suite) cout << "Tipo de Quarto: " << "suite" << " | ";
    else if(tquarto == sem_vista) cout << "Tipo de Quarto: " << "sem vista" << " | ";
    else cout << "Tipo de Quarto: " << "com vista" << " | ";
    cout << "Preço por noite: " << preco_base << " | ";
    cout << "Capacidade: " << capacidade << " | ";
    if(ocupado) cout << "Status: Ocupado!";
    else cout << "Status: Livre!";
    cout << endl;
}