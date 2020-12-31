#ifndef HOTEL_CLIENTE_H
#define HOTEL_CLIENTE_H


#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

#include "Data.h"
#include "Reserva.h"
#include "Exceptions.h"
#include "Servico.h"


using namespace std;

class Cliente{
public:
    string nome;
    int nif, promo;
    bool cliente_usual, nohotel;
    list <Servico *> servicos_consumidos;
    list <Reserva *> estadias_anteriores, reservas_cliente;
    Reserva * estadia_atual;
    Cliente(string nome, int nif);
    Cliente(string nome, int nif, bool usual);
    Cliente(string nome, int nif, list <Reserva *> estadias_anteriores);
    ~Cliente() {};
    void Info() const;
    int ID() const {return nif;}
    bool operator==(const Cliente &c2) const{return (nif == c2.nif);}
    string getName() const {return nome;}
    int getNif() const {return nif;}
    void setPromo(int new_promo) {promo = new_promo;}
    float GetConta();

private:
    float conta;
};


#endif //HOTEL_CLIENTE_H
