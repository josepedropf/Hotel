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
    Funcionario(string nome, int nif, int anos_servico, float salario);
    Funcionario(string nome, int nif, int anos_servico, float salario, tipo_cargo cargo);
    ~Funcionario() {};
    virtual void Info() const;
    bool operator==(Funcionario & f2) {return nif == f2.nif;}
};

class F_Rececao : public Funcionario{
public:
    F_Rececao(string nome, int nif, int anos_servico, float salario);
    F_Rececao(string nome, int nif, int anos_servico, float salario, tipo_cargo cargo);
    virtual void Info() const;
};

class F_Responsavel : public F_Rececao{
public:
    vector <int> pisos_resp;
    F_Responsavel(string nome, int nif, int anos_servico, float salario);
    F_Responsavel(string nome, int nif, int anos_servico, float salario, vector<int> pisos_resp);
    virtual void Info() const;
};

enum tipo_turno {dia = 0, noite = 1};

class F_Limpeza : public Funcionario{
public:
    tipo_turno turno;
    F_Limpeza(string nome, int nif, int anos_servico, float salario, tipo_turno turno);
    virtual void Info() const;
};

class F_Gestor : public Funcionario{
public:
    nota_avaliacao av_prestacao = razoavel;
    F_Gestor(string nome, int nif, int anos_servico, float salario);
    F_Gestor(string nome, int nif, int anos_servico, float salario, nota_avaliacao av_prestacao);
    void Promocoes(vector <Quarto> &quartos_promo);
    Produto Escolher_Prod(vector <Produto *> prods);
    virtual void Info() const;
};


#endif //HOTEL_FUNCIONARIO_H
