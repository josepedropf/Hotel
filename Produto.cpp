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
    this->stock = 1;
}

Produto::Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int stock){
    this->nome = nome;
    this->numero = abs(numero);
    this->tprod = tprod;
    this->qualidade = qualidade;
    this->preco = preco;
    if(stock > 1) this->stock = stock;
    else this->stock = 1;
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
    cout << "Stock: " << stock << " | ";
    cout << "Qualidade: " << qualidade;
    cout << endl;
}

int Produto::getStock() const {
    return stock;
}

void Produto::updateStock(int new_stock){
    stock = new_stock;
}

nota_avaliacao Produto::getAvaliacao() const {
    return qualidade;
}

void Produto::setAvaliacao(nota_avaliacao newr) {
    qualidade = newr;
}

/**
 * Construtor da classe Compra
 * @param id id do produto
 * @param produto_comprado apontador para o produto comprado
 * @param fornecedor fornecedor do produto
 * @param quantidade quantidade a comprar
 */
Compra::Compra(int id, Produto * produto_comprado, string fornecedor, int quantidade){
    this->id = id;
    this->produto_comprado = produto_comprado;
    this->fornecedor = fornecedor;
    this->quantidade = quantidade;
    this->rating = produto_comprado->getAvaliacao();
    this->stock = produto_comprado->getStock() + quantidade;
    produto_comprado->updateStock(produto_comprado->getStock() + quantidade);
}

Compra::Compra(int id, Produto * produto_comprado, string fornecedor){
    this->id = id;
    this->produto_comprado = produto_comprado;
    this->fornecedor = fornecedor;
    this->quantidade = 1;
    this->rating = produto_comprado->getAvaliacao();
    this->stock = produto_comprado->getStock() + 1;
    produto_comprado->updateStock(produto_comprado->getStock());
}
/**
 *
 * @return stock do produto comprado
 */
int Compra::getStock() const {
    return stock;
}
/**
 *
 * @return fornecedor do produto comprado
 */
string Compra::getFornecedor() const {
    return fornecedor;
}
/**
 * Define uma nova nota qualitativa para o produto comprado
 * @param newr nota qualitativa a atribuir
 */
void Compra::setRating(nota_avaliacao newr) {
    rating = newr;
    produto_comprado->setAvaliacao(newr);
}
/**
 * Atualiza o stock do produto comprado
 * @param new_stock novo stock
 */
void Compra::updateStock(int new_stock){
    stock = new_stock;
    produto_comprado->updateStock(new_stock);
}


bool Compra::operator<(const Compra &c2) const {
    if (this->getAvaliacao() != c2.getAvaliacao()) return this->getAvaliacao() < c2.getAvaliacao();
    else return this->getStock() < c2.getStock();
}
/**
 * Imprime as informações da compra
 */
void Compra::Info() const{
    cout << "<COMPRA>" << endl;
    cout << "Nome: " << produto_comprado->nome << " | ";
    cout << "Quantidade: " << quantidade << " | ";
    cout << "Numero ID: " << id << " | ";
    cout << "Tipo de Produto: " << produto_comprado->tprod << " | ";
    cout << "Preco Total: " << produto_comprado->preco * quantidade << " | ";
    cout << "Rating: " << rating << " | ";
    cout << "Stock: " << stock << " | ";
    cout << "Fornecedor: " << fornecedor;
    cout << endl;
}
