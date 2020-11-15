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
    bool cliente_usual = estadias_anteriores.size() > 0, nohotel = false;
    vector <Reserva> estadias_anteriores;
    Reserva *reserva_atual, *estadia_atual;
    Cliente(string na, int n);
    ~Cliente() {};
    void Info();
    bool operator==(const Cliente &c2) const{return (nome == c2.nome && nif == c2.nif);}

    void Reservar(data di, data df, int lp, vector <Quarto> q);
};


#endif //HOTEL_CLIENTE_H
