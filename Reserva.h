#ifndef HOTEL_RESERVA_H
#define HOTEL_RESERVA_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

#include "Data.h"
#include "Quarto.h"

using namespace std;

class Reserva{
public:
    data data_inicio, data_fim;
    int lugaresp, duracao, idnumero;
    float preco;
    list <Quarto *> quartos_res;
    bool primeiravez = true;
    static bool PrimeiraReserva(Reserva r1, Reserva r2) {return r1.primeiravez > r2.primeiravez;}
    static bool P_PrimeiraReserva(Reserva *r1, Reserva *r2) {return r1->primeiravez > r2->primeiravez;}
    static bool Duracaocomp_Decr(Reserva r1, Reserva r2) {return r1.duracao > r2.duracao;}
    static bool Duracaocomp_Cr(Reserva r1, Reserva r2) {return r1.duracao < r2.duracao;}
    static bool Precocomp_Decr(Reserva r1, Reserva r2) {return r1.preco > r2.preco;}
    static bool Precocomp_Cr(Reserva r1, Reserva r2) {return r1.preco < r2.preco;}
    static bool DataIcomp_Decr(Reserva r1, Reserva r2) {return r1.data_inicio > r2.data_inicio;}
    static bool P_DataIcomp_Decr(Reserva *r1, Reserva *r2) {return r1->data_inicio > r2->data_inicio;}
    static bool DataIcomp_Cr(Reserva r1, Reserva r2) {return r1.data_inicio < r2.data_inicio;}
    static bool P_DataIcomp_Cr(Reserva *r1, Reserva *r2) {return r1->data_inicio < r2->data_inicio;}
    static bool DataFcomp_Decr(Reserva r1, Reserva r2) {return r1.data_fim > r2.data_fim;}
    static bool P_DataFcomp_Decr(Reserva *r1, Reserva *r2) {return r1->data_fim > r2->data_fim;}
    static bool DataFcomp_Cr(Reserva r1, Reserva r2) {return r1.data_fim < r2.data_fim;}
    static bool P_DataFcomp_Cr(Reserva *r1, Reserva *r2) {return r1->data_fim < r2->data_fim;}
    Reserva(int idnumero, data data_inicio, data data_fim, int lugaresp, list <Quarto *> quartos_res, int promo);
    Reserva(int idnumero, data data_inicio, data data_fim, int lugaresp, list <Quarto *> quartos_res, bool primeiravez, int promo);
    ~Reserva() {};
    bool operator==(const Reserva &r2) const;
    void Info() const;
    int ID() const {return idnumero;}
};



#endif //HOTEL_RESERVA_H
