#include "Produto.h"

/**
 * Construtor da classe Produto
 * @param nome nome do Produto
 * @param numero identificador do Produto
 * @param tprod tipo do Produto
 * @param qualidade nota qualitativa de má a excelente atribuida ao Produto
 * @param preco preço do Produto
 */
Produto::Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco){
    this->nome = nome;
    this->numero = abs(numero);
    this->tprod = tprod;
    this->qualidade = qualidade;
    this->preco = preco;
}

/**
 * Imprime as Informações do Produto
 */
void Produto::Info() const{
    cout << "<PRODUTO>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Numero: " << numero << " | ";
    cout << "Tipo de Produto: " << tprod << " | ";
    cout << "Preco: " << preco << " | ";
    cout << "Qualidade: " << qualidade;
    cout << endl;
}
