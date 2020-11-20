#ifndef HOTEL_CLIENTE_H
#define HOTEL_CLIENTE_H


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Data.h"
#include "Reserva.h"
#include "Exceptions.h"


using namespace std;

class Cliente{
public:
    string nome;
    int nif;
    bool cliente_usual, nohotel;
    vector <Reserva> estadias_anteriores, reservas_cliente;
    Reserva *estadia_atual;
    Cliente(string nome, int nif);
    Cliente(string nome, int nif, bool usual);
    Cliente(string nome, int nif, vector <Reserva> estadias_anteriores);
    ~Cliente() {};
    void Info() const;
    bool operator==(const Cliente &c2) const{return (nif == c2.nif);}

    float GetConta();

private:
    float conta;
};


#endif //HOTEL_CLIENTE_H
