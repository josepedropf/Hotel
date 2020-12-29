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
    string supplier; // new
    Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int s, string sup); //foi alterada
    ~Produto() {};
    void Info() const;
    int ID() const {return numero;}
    int getStock() const;
    string getSupplier() const;
    nota_avaliacao getRating() const;
    bool operator < (const Produto & p) const; //nnc sei se ta certo lol
    bool operator==(const Produto &p2) const{return numero == p2.numero;}
};

class BuyProduct: public Produto {  //n tem de ser derivada mas por agr é
private:
    priority_queue<Produto> compras;
public:
    BuyProduct(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco, int s, string sup);
    priority_queue<Produto> getCompras() const;
};
#endif //HOTEL_PRODUTO_H
