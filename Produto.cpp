#include "Produto.h"

/**
 * Construtor da classe Produto
 * @param nome nome do Produto
 * @param numero identificador do Produto
 * @param tprod tipo do Produto
 * @param qualidade nota qualitativa de má a excelente atribuida ao Produto
 * @param preco preço do Produto
 */
Produto::Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int s, string sup){
    this->nome = nome;
    this->numero = abs(numero);
    this->tprod = tprod;
    this->qualidade = qualidade;
    this->preco = preco;
    this->supplier = sup;
    this->stock = s;
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
    if (getRating() < p.getRating()) {
        return true;
    }
    else if (getRating() > p.getRating()) {
        return false;
    }
    else return getStock() < p.getStock();
}

BuyProduct::BuyProduct(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int s, string sup) : Produto(nome, numero, tprod, qualidade, preco, s, sup) {}

int Produto::getStock() const {
    return stock;
}

string Produto::getSupplier() const {
    return supplier;
}

nota_avaliacao Produto::getRating() const {
    return qualidade;
}

void Produto::setRating(nota_avaliacao newr) {
    qualidade = newr;
}

priority_queue<Produto> BuyProduct::getCompras() const {
    return compras;
}

void BuyProduct::addCompra(const Produto& p) {
    compras.push(p);
}
