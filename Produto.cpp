#include "Produto.h"

Produto::Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco){
    this->nome = nome;
    this->numero = numero;
    this->tprod = tprod;
    this->qualidade = qualidade;
    this->preco = preco;
}

void Produto::Info() const{
    cout << "<PRODUTO>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Tipo de Produto: " << tprod << " | ";
    cout << "Preço: " << preco << " | ";
    cout << "Qualidade: " << qualidade;
    cout << endl;
}
