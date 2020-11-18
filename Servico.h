#ifndef HOTEL_SERVICO_H
#define HOTEL_SERVICO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Data.h"
#include "Funcionario.h"
#include "Cliente.h"

using namespace std;

class Servico{
public:
    string nome;
    float custo, preco;
    vector <Funcionario> func_ocupados;
    vector <Cliente> clientes_servidos;
    bool extra;

};


#endif //HOTEL_SERVICO_H
