#ifndef HOTEL_PRODUTO_H
#define HOTEL_PRODUTO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

enum nota_avaliacao {ma = 1, insuficiente = 2, razoavel = 3, boa = 4, excelente = 5};
enum tipo_produto {restauracao = 0, limpeza = 1, souvenir = 2};

class Produto{
public:
    string nome;
    int numero, stock;
    tipo_produto tprod;
    nota_avaliacao qualidade;
    float preco;
    Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco);
    Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int stock);
    ~Produto() {};
    void Info() const;
    int ID() const {return numero;}
    int getStock() const;
    void updateStock(int new_stock);
    void setAvaliacao(nota_avaliacao newr);
    nota_avaliacao getAvaliacao() const;
    bool operator==(const Produto &p2) const{return numero == p2.numero;}
};

class Compra{
private:

public:
    string fornecedor;
    int stock, quantidade, id;
    nota_avaliacao rating;
    Produto * produto_comprado;
    Compra(int id, Produto * produto_comprado, string fornecedor, int quantidade);
    Compra(int id, Produto * produto_comprado, string fornecedor);
    Compra() : id(-1), produto_comprado(NULL), fornecedor("") {}
    void Info() const;
    int ID() const {return id;}
    nota_avaliacao getAvaliacao() const {return produto_comprado->qualidade;}
    string getFornecedor() const;
    int getStock() const;
    int getQuantidade() const {return quantidade;}
    int getProdNumber() const {return produto_comprado->numero;}
    void updateStock(int new_stock);
    void ConsumirProdutos(int prods_consumidos) {updateStock(getStock() - prods_consumidos);}
    void AdicionarProdutos(int prods_ad) {updateStock(getStock() + prods_ad);}
    void setRating(nota_avaliacao newr);
    nota_avaliacao getRating() {return rating;}
    bool operator < (const Compra & c2) const;
    bool operator== (const Compra & c2) const {return ID() == c2.ID();}
};
#endif //HOTEL_PRODUTO_H
