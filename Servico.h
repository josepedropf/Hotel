#ifndef HOTEL_SERVICO_H
#define HOTEL_SERVICO_H

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>

#include "Data.h"
#include "Funcionario.h"

using namespace std;

class Servico{
public:
    string nome;
    int idnumero;
    data data_realizacao;
    float margem_lucro, custo, preco_consumidor, taxa, lucro;
    list <Produto *> produtos_consumidos;
    list <Funcionario *> funcionarios_ocupados;
    Servico(string nome, int idnumero, data data_realizacao, float taxa);
    Servico(string nome, int idnumero, data data_realizacao, float taxa, list <Funcionario *> funcionarios_ocupados);
    Servico(string nome, int idnumero, data data_realizacao, float taxa, list <Funcionario *> funcionarios_ocupados, list <Produto *> produtos_consumidos, float margem_lucro);
    Servico(string nome, int idnumero, data data_realizacao, float taxa, list <Produto *> produtos_consumidos, float margem_lucro);
    ~Servico() {};
    void Info() const;
    bool operator==(const Servico &s2) const{return idnumero == s2.idnumero;}
};




#endif //HOTEL_SERVICO_H
