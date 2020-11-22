#ifndef HOTEL_QUARTO_H
#define HOTEL_QUARTO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum tipo_quarto {sem_vista = 12, com_vista = 8, suite = 5};

class Quarto{
public:
    tipo_quarto tquarto;
    int piso, numero, capacidade;
    float preco, promo;
    bool ocupado = false;
    Quarto(tipo_quarto tquarto, int piso, int numero, int capacidade, float preco);
    ~Quarto() {};
    void Info() const;
    int ID() const {return numero;}
    bool operator==(const Quarto &q2) const{return numero == q2.numero;}
    static bool Numcomp_Decr(Quarto q1, Quarto q2) {return q1.numero > q2.numero;}
    static bool Numcomp_Cr(Quarto q1, Quarto q2) {return q1.numero < q2.numero;}
};

#endif //HOTEL_QUARTO_H
