#ifndef HOTEL_FUNCIONARIO_H
#define HOTEL_FUNCIONARIO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

#include "Quarto.h"
#include "Produto.h"
#include "Cliente.h" //new 

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
    int ID() const {return nif;}
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
    void AddPiso(int piso) {pisos_resp.push_back(piso);}
    virtual void Info() const;
};

enum tipo_turno {dia = 0, noite = 1};

class F_Limpeza : public Funcionario{
public:
    tipo_turno turno;
    F_Limpeza(string nome, int nif, int anos_servico, float salario, tipo_turno turno);
    void SetTurno(tipo_turno novoturno) {turno = novoturno;}
    virtual void Info() const;
};

struct clienteHash //new
{
    int operator() (const Cliente& c) const
    {
        int v=0;
        for (auto it = c.getName()[0].begin(); it != c.getName()[0].end(); it++) {
            v = 37*v+(*it);
        }
        return v;
    }

    bool operator() (const Cliente& c1, const Cliente& c2) const
    {
        if (c1.getNif() == c2.getNif()) return true;
        else return false;
    }
};

typedef unordered_set<Cliente, clienteHash, clienteHash> tabHCliente;

class F_Gestor : public Funcionario{
public:
    tabHCliente clientesUsuais; // new
    nota_avaliacao av_prestacao = razoavel;
    F_Gestor(string nome, int nif, int anos_servico, float salario);
    F_Gestor(string nome, int nif, int anos_servico, float salario, nota_avaliacao av_prestacao);
    void Promocoes(list <Quarto *> &quartos_promo);
    Produto Escolher_Prod(list <Produto *> prods);
    void SetAvaliacao(nota_avaliacao nova_avaliacao) {av_prestacao = nova_avaliacao;}
    virtual void Info() const;
};


#endif //HOTEL_FUNCIONARIO_H
