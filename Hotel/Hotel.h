#ifndef HOTEL_HOTEL_H
#define HOTEL_HOTEL_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

union data {int dia; int mes; int ano;};
enum turno {dia = 0, noite = 1};
enum tipo_quarto {sem_vista = 12, com_vista = 8, suite = 5};
enum tipo_produto {restauracao = 0, limpeza = 1};
enum avaliacao {ma = 1, insuficiente = 2, razoavel = 3, boa = 4, excelente = 5};
inline ostream& operator<<(ostream &os, const data d){
    os << d.dia << "-" << d.mes << "-" << d.ano;
    return os;
}


class Produto{
public:
    tipo_produto tprod;
    avaliacao qualidade;
    float preco;
    Produto(tipo_produto tp, avaliacao q, float p);
    ~Produto() {};
    void Info();
};

class Quarto{
public:
    tipo_quarto tquarto;
    int piso, numero, capacidade;
    float preco_base, promo;
    bool ocupado = false;
    Quarto(tipo_quarto tq, int p, int n, int c, float pb);
    ~Quarto() {};
    void Info();
};

class Reserva{
public:
    data data_inicio, data_fim;
    int lugaresp;
    Reserva(data i, data f, int lp);
    ~Reserva() {};
    void Info();
};

class Cliente{
public:
    string nome;
    int nif;
    vector <Reserva> estadias_anteriores;
    Cliente(string na, int n);
    ~Cliente() {};
    void Info();
    bool Cliente_Usual() {return estadias_anteriores.size() > 0;}
};

class Funcionario{
public:
    string cargo = "Geral";
    string nome;
    int nif, anos_servico;
    float salario;
    static bool Cargocomp(Funcionario f1, Funcionario f2) {return f1.cargo > f2.cargo;}
    static bool Salariocomp_Decr(Funcionario f1, Funcionario f2) {return f1.salario > f2.salario;}
    static bool Salariocomp_Cr(Funcionario f1, Funcionario f2) {return f1.salario < f2.salario;}
    Funcionario() {};
    Funcionario(string na, int n, int as, float s);
    Funcionario(string na, int n, int as, float s, string c);
    ~Funcionario() {};
    void Info();
};

class F_Rececao : public Funcionario{
public:
    F_Rececao(string na, int n, int as, float s);
    F_Rececao(string na, int n, int as, float s, string c);
};

class F_Responsavel : public F_Rececao{
public:
    vector <int> pisos_resp;
    F_Responsavel(string na, int n, int as, float s);
    F_Responsavel(string na, int n, int as, float s, vector<int> pr);
};

class F_Limpeza : public Funcionario{
public:
    turno fturno;
    F_Limpeza(string na, int n, int as, float s, turno t);
};

class F_Gestor : public Funcionario{
public:
    avaliacao av_prestacao = razoavel;
    F_Gestor(string na, int n, int as, float s);
    F_Gestor(string na, int n, int as, float s, avaliacao av);
    void Promocoes(vector <Quarto> quartos_promo);
    Produto Escolher_Prod(vector <Produto> prods);
};


class Hotel{
protected:
    string nome;
    vector <Reserva> reservas;
    vector <Cliente> clientes;
    vector <Quarto> quartos;
    vector <Funcionario> funcionarios;

public:
    Hotel(string n);
    ~Hotel() {};

    template<class T>
    void PrintV(vector<T> v);

    void AddReserva(Reserva r);
    void AddCliente(Cliente c);
    void AddQuarto(Quarto q);
    void AddFuncionario(Funcionario f);

    const vector <Reserva> GetReservas() {return reservas;}
    const vector <Cliente> GetClientes() {return clientes;}
    const vector <Quarto> GetQuartos() {return quartos;}
    const vector <Funcionario> GetFuncionarios() {return funcionarios;}

    const vector <Funcionario> Pesquisa_F_Salario(bool inverso);
    const vector <Funcionario> Pesquisa_F_Cargo();
    const vector <Reserva> Pesquisa_Reservas();
    const vector <Reserva> Pesquisa_Reservas_Cnovos();
    int CustosTotais();
    int LucroTotal();
};

#endif //HOTEL_HOTEL_H
