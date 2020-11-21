#ifndef HOTEL_PRODUTO_H
#define HOTEL_PRODUTO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


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
    Produto(string nome, int numero, tipo_produto tprod, nota_avaliacao qualidade, float preco);
    ~Produto() {};
    void Info() const;
    bool operator==(const Produto &p2) const{return numero == p2.numero;}
};


#endif //HOTEL_PRODUTO_H
