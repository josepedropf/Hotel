#ifndef HOTEL_RESERVA_H
#define HOTEL_RESERVA_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Data.h"
#include "Quarto.h"

using namespace std;

class Reserva{
public:
    data data_inicio, data_fim;
    int lugaresp, duracao, preco, idnumero;
    vector <Quarto> quartos_res;
    bool vazia = false, primeiravez = true;
    static bool PrimeiraReserva(Reserva r1, Reserva r2) {return r1.primeiravez > r2.primeiravez;}
    static bool Duracaocomp_Decr(Reserva r1, Reserva r2) {return r1.duracao > r2.duracao;}
    static bool Duracaocomp_Cr(Reserva r1, Reserva r2) {return r1.duracao < r2.duracao;}
    static bool Precocomp_Decr(Reserva r1, Reserva r2) {return r1.preco > r2.preco;}
    static bool Precocomp_Cr(Reserva r1, Reserva r2) {return r1.preco < r2.preco;}
    static bool DataIcomp_Decr(Reserva r1, Reserva r2) {return r1.data_inicio > r2.data_inicio;}
    static bool DataIcomp_Cr(Reserva r1, Reserva r2) {return r1.data_inicio < r2.data_inicio;}
    static bool DataFcomp_Decr(Reserva r1, Reserva r2) {return r1.data_fim > r2.data_fim;}
    static bool DataFcomp_Cr(Reserva r1, Reserva r2) {return r1.data_fim < r2.data_fim;}
    Reserva(int num, data i, data f, int lp, vector <Quarto> q);
    Reserva(int num, data i, data f, int lp, vector <Quarto> q, bool v, bool pr);
    Reserva() {vazia = true;}
    ~Reserva() {};
    bool operator==(const Reserva &r2) const;
    void Info();
};



#endif //HOTEL_RESERVA_H
