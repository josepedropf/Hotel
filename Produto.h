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
    int numero;
    tipo_produto tprod;
    nota_avaliacao qualidade;
    float preco;
    int stock; //stock no hotel ou na loja? dont know //new
    string fornecedor; // new
    Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int stock, string fornecedor); //foi alterada
    Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, string fornecedor);
    ~Produto() {};
    void Info() const;
    int ID() const {return numero;}
    int getStock() const;
    string getFornecedor() const;
    void setAvaliacao(nota_avaliacao newr);
    nota_avaliacao getAvaliacao() const;
    bool operator < (const Produto & p) const; //nnc sei se ta certo lol
    bool operator==(const Produto &p2) const{return numero == p2.numero;}
};

class CompraProduto: public Produto {  //n tem de ser derivada mas por agr é
private:
    priority_queue<Produto> compras;
public:
    CompraProduto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int stock, string fornecedor);
    priority_queue<Produto> getCompras() const;
    void addCompra(const Produto& p);
};
#endif //HOTEL_PRODUTO_H
