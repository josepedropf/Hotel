#ifndef HOTEL_CLIENTE_H
#define HOTEL_CLIENTE_H


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Data.h"
#include "Reserva.h"

using namespace std;

class Cliente{
public:
    string nome;
    int nif;
    bool cliente_usual, nohotel;
    vector <Reserva *> estadias_anteriores, reservas_cliente;
    Reserva *estadia_atual;
    Cliente(string nome, int nif);
    Cliente(string nome, int nif, bool usual);
    ~Cliente() {};
    void Info() const;
    bool operator==(const Cliente &c2) const{return (nome == c2.nome && nif == c2.nif);}

    void Reservar(vector<Quarto> quartos, int num, data di, data df, int lp, vector <int> numq);
    void Reservar(Reserva reserva);
};


#endif //HOTEL_CLIENTE_H
