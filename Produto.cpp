#include "Produto.h"

/**
 * Construtor da classe Produto
 * @param nome nome do Produto
 * @param numero identificador do Produto
 * @param tprod tipo do Produto
 * @param qualidade nota qualitativa de má a excelente atribuida ao Produto
 * @param preco preço do Produto
 */
Produto::Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int stock, string fornecedor){
    this->nome = nome;
    this->numero = abs(numero);
    this->tprod = tprod;
    this->qualidade = qualidade;
    this->preco = preco;
    this->fornecedor = fornecedor;
    this->stock = stock;
}

Produto::Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, string fornecedor){
    this->nome = nome;
    this->numero = abs(numero);
    this->tprod = tprod;
    this->qualidade = qualidade;
    this->preco = preco;
    this->fornecedor = fornecedor;
    this->stock = 1;
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

bool Produto::operator<(const Produto &p) const {
    if (getAvaliacao() < p.getAvaliacao()) {
        return true;
    }
    else if (getAvaliacao() > p.getAvaliacao()) {
        return false;
    }
    else return getStock() < p.getStock();
}

CompraProduto::CompraProduto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int stock, string fornecedor) : Produto(nome, numero, tprod, qualidade, preco, stock, fornecedor) {}

int Produto::getStock() const {
    return stock;
}

string Produto::getFornecedor() const {
    return fornecedor;
}

nota_avaliacao Produto::getAvaliacao() const {
    return qualidade;
}

void Produto::setAvaliacao(nota_avaliacao newr) {
    qualidade = newr;
}

priority_queue<Produto> CompraProduto::getCompras() const {
    return compras;
}

void CompraProduto::addCompra(const Produto& p) {
    compras.push(p);
}
