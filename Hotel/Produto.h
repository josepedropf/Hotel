#ifndef HOTEL_PRODUTO_H
#define HOTEL_PRODUTO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

enum avaliacao {ma = 1, insuficiente = 2, razoavel = 3, boa = 4, excelente = 5};
enum tipo_produto {restauracao = 0, limpeza = 1};

class Produto{
public:
    tipo_produto tprod;
    avaliacao qualidade;
    float preco;
    Produto(tipo_produto tp, avaliacao q, float p);
    ~Produto() {};
    void Info();
};


#endif //HOTEL_PRODUTO_H
