#ifndef HOTEL_PRODUTO_H
#define HOTEL_PRODUTO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

enum nota_avaliacao {ma = 1, insuficiente = 2, razoavel = 3, boa = 4, excelente = 5};
enum tipo_produto {restauracao = 0, limpeza = 1};

class Produto{
public:
    tipo_produto tprod;
    nota_avaliacao qualidade;
    float preco;
    Produto(tipo_produto tp, nota_avaliacao q, float p);
    ~Produto() {};
    void Info() const;
};


#endif //HOTEL_PRODUTO_H
