#ifndef HOTEL_FUNCIONARIO_H
#define HOTEL_FUNCIONARIO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Quarto.h"
#include "Produto.h"

using namespace std;

enum tipo_cargo {naodef = 0, frececao = 1, fresponsavel = 2, flimpeza = 3, fgestor = 4};

class Funcionario{
public:
    tipo_cargo cargo;
    string nome;
    int nif, anos_servico;
    float salario;
    static bool Cargocomp(Funcionario f1, Funcionario f2) {return f1.cargo > f2.cargo;}
    static bool Salariocomp_Decr(Funcionario f1, Funcionario f2) {return f1.salario > f2.salario;}
    static bool Salariocomp_Cr(Funcionario f1, Funcionario f2) {return f1.salario < f2.salario;}
    Funcionario() {};
    Funcionario(string na, int n, int as, float s);
    Funcionario(string na, int n, int as, float s, tipo_cargo c);
    ~Funcionario() {};
    virtual void Info() const;
    bool operator==(Funcionario f2);
};

class F_Rececao : public Funcionario{
public:
    F_Rececao(string na, int n, int as, float s);
    F_Rececao(string na, int n, int as, float s, tipo_cargo c);
    virtual void Info() const;
};

class F_Responsavel : public F_Rececao{
public:
    vector <int> pisos_resp;
    F_Responsavel(string na, int n, int as, float s);
    F_Responsavel(string na, int n, int as, float s, vector<int> pr);
    virtual void Info() const;
};

enum turno {dia = 0, noite = 1};

class F_Limpeza : public Funcionario{
public:
    turno fturno;
    F_Limpeza(string na, int n, int as, float s, turno t);
    virtual void Info() const;
};

class F_Gestor : public Funcionario{
public:
    avaliacao av_prestacao = razoavel;
    F_Gestor(string na, int n, int as, float s);
    F_Gestor(string na, int n, int as, float s, avaliacao av);
    void Promocoes(vector <Quarto> quartos_promo);
    Produto Escolher_Prod(vector <Produto> prods);
    virtual void Info() const;
};


#endif //HOTEL_FUNCIONARIO_H
