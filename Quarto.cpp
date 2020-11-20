#include "Quarto.h"

Quarto::Quarto(tipo_quarto tquarto, int piso, int numero, int capacidade, float preco) {
    this->tquarto = tquarto;
    this->piso = piso;
    this->numero = numero;
    this->capacidade = capacidade;
    this->preco = preco;
    this->promo = tquarto;
}

void Quarto::Info() const{
    cout << "<QUARTO>" << endl;
    cout << "Número: " << numero << " | ";
    cout << "Piso: " << piso << " | ";
    if(tquarto == suite) cout << "Tipo de Quarto: " << "suite" << " | ";
    else if(tquarto == sem_vista) cout << "Tipo de Quarto: " << "sem vista" << " | ";
    else cout << "Tipo de Quarto: " << "com vista" << " | ";
    cout << "Preço por noite: " << preco << " | ";
    cout << "Capacidade: " << capacidade << " | ";
    if(ocupado) cout << "Status: Ocupado!";
    else cout << "Status: Livre!";
    cout << endl;
}