#include "Quarto.h"

/**
 * Construtor da classe Quarto
 * @param tquarto tipo do Quarto (com vista, sem vista ou suite)
 * @param piso número do piso onde se encontra o Quarto
 * @param numero número do Quarto
 * @param capacidade capacidade do Quarto
 * @param preco preço do Quarto
 */
Quarto::Quarto(tipo_quarto tquarto, int piso, int numero, int capacidade, float preco) {
    this->tquarto = tquarto;
    this->piso = piso;
    this->numero = abs(numero);
    this->capacidade = capacidade;
    this->preco = preco;
    this->promo = tquarto;
}

/**
 * Imprime as Informações do Quarto
 */
void Quarto::Info() const{
    cout << "<QUARTO>" << endl;
    cout << "Numero: " << numero << " | ";
    cout << "Piso: " << piso << " | ";
    if(tquarto == suite) cout << "Tipo de Quarto: " << "suite" << " | ";
    else if(tquarto == sem_vista) cout << "Tipo de Quarto: " << "sem vista" << " | ";
    else cout << "Tipo de Quarto: " << "com vista" << " | ";
    cout << "Preco por noite: " << preco << " | ";
    cout << "Capacidade: " << capacidade << " | ";
    if(ocupado) cout << "Status: Ocupado!";
    else cout << "Status: Livre!";
    cout << endl;
}