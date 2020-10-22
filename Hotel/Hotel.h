#ifndef HOTEL_HOTEL_H
#define HOTEL_HOTEL_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

union data {int dia; int mes; int ano;};
enum turno {dia = 0, noite = 1};
enum tipo_quarto {sem_vista = 12, com_vista = 8, suite = 5};
enum tipo_produto {restauracao = 0, limpeza = 1};
enum avaliacao {ma = 1, insuficiente = 2, razoavel = 3, boa = 4, excelente = 5};


class Produto{
public:
    tipo_produto tprod;
    avaliacao qualidade;
    float preco;
    Produto(tipo_produto tp, avaliacao q, float p);
    ~Produto() {};
};

class Reserva{
public:
    data data_inicio, data_fim;
    int lugaresp;
    Reserva(data i, data f, int lp);
    ~Reserva() {};
};

class Cliente{
public:
    string nome;
    int nif;
    vector <Reserva> estadias_anteriores;
    Cliente(string na, int n);
    ~Cliente() {};
    bool Cliente_Usual() {return estadias_anteriores.size() > 0;}
};

class Quarto{
public:
    tipo_quarto tquarto;
    int piso, numero, capacidade;
    float preco_base, promo;
    bool ocupado = false;
    Quarto(tipo_quarto tq, int p, int n, int c, float pb);
    ~Quarto() {};
};

class Funcionario{
public:
    string nome;
    int nif, anos_servico;
    float salario;
    Funcionario(string na, int n, int as, float s);
    ~Funcionario() {};
};

class F_Rececao : Funcionario{
public:
    F_Rececao(string na, int n, int as, float s);
};

class F_Responsavel : F_Rececao{
public:
    vector <int> pisos_resp;
    F_Responsavel(string na, int n, int as, float s);
    F_Responsavel(string na, int n, int as, float s, vector<int> pr);
};

class F_Limpeza : Funcionario{
public:
    turno fturno;
    F_Limpeza(string na, int n, int as, float s, turno t);
};

class F_Gestor : Funcionario{
public:
    avaliacao av_prestacao = razoavel;
    F_Gestor(string na, int n, int as, float s);
    F_Gestor(string na, int n, int as, float s, avaliacao av);
    void Promocoes(vector <Quarto> quartos_promo);
    Produto Escolher_Prod(vector <Produto> prods);
};


class Hotel{
public:
    Hotel() {};
    ~Hotel() {};
    void AddReserva(Reserva r);
    void AddCliente(Cliente c);
    void AddQuarto(Quarto q);
    void AddFuncionario(Funcionario f);

    const vector <Reserva> GetReservas() {return reservas;}
    const vector <Cliente> GetClientes() {return clientes;}
    const vector <Quarto> GetQuartos() {return quartos;}
    const vector <Funcionario> GetFuncionarios() {return funcionarios;}

    void Pesquisa_F_Salario();
    void Pesquisa_F_Cargo();
    void Pesquisa_Reservas();
    void Pesquisa_Reservas_Cnovos();
    int CustosTotais();
    int LucroTotal();

protected:
    vector <Reserva> reservas;
    vector <Cliente> clientes;
    vector <Quarto> quartos;
    vector <Funcionario> funcionarios;
};

#endif //HOTEL_HOTEL_H
