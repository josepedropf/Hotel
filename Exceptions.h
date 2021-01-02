#ifndef HOTEL_EXCEPTIONS_H
#define HOTEL_EXCEPTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FicheiroIncompativel: public exception{
public:
    string nomeficheiro;
    FicheiroIncompativel() {};
    FicheiroIncompativel(string nficheiro) {nomeficheiro = nficheiro;}
    ~FicheiroIncompativel() {};
};

class MembroRepetido: public exception{
public:
    int id;
    string tipo;
    MembroRepetido() {};
    MembroRepetido(string tipo, int id) {this->tipo = tipo; this->id = id;};
    ~MembroRepetido() {};
};

class MembroFalta: public exception{
public:
    int id;
    string tipo;
    MembroFalta() {};
    MembroFalta(string tipo, int id) {this->tipo = tipo; this->id = id;};
    ~MembroFalta() {};
};

class CapacidadeExcesso: public exception{
public:
    int capacidade;
    CapacidadeExcesso() {};
    CapacidadeExcesso(int cp) {capacidade = cp;};
    ~CapacidadeExcesso() {};
};

class DiaInvalido: public exception{
public:
    int dia;
    DiaInvalido() {};
    DiaInvalido(int d) {dia = d;};
    ~DiaInvalido() {};

};

class MesInvalido: public exception{
public:
    int mes;
    MesInvalido() {};
    MesInvalido(int m) {mes = m;};
    ~MesInvalido() {};

};

class InputInvalido: public exception{
public:
    string input;
    InputInvalido() {};
    InputInvalido(string input) {this->input = input;};
    ~InputInvalido() {};
};

class VeiculoInexistente: public exception{
public:


};


#endif //HOTEL_EXCEPTIONS_H
