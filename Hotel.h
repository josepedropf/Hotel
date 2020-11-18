#ifndef HOTEL_HOTEL_H
#define HOTEL_HOTEL_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Reserva.h"
#include "Produto.h"
#include "Quarto.h"
#include "Funcionario.h"
#include "Cliente.h"
#include "Data.h"

using namespace std;

class Hotel{
protected:
    string nome;
    vector <Produto> produtos;
    vector <Reserva> reservas;
    vector <Reserva> estadias;
    vector <Reserva> reservas_atuais;
    vector <Cliente> clientes;
    vector <Quarto> quartos;
    vector <Funcionario> funcionarios;

public:
    Hotel(string nome);
    ~Hotel() {};

    template<class T>
    void PrintV(vector<T> v){
        int vsize = v.size();
        cout << endl;
        cout << "|||-> " << endl << endl;
        for (int i = 0; vsize > i; i++){
            v[i].Info();
            cout << endl;
        }
        cout << "<-||| " << endl;
    }

    template <class T>
    int FindIndex(vector <T> v, T element){
        int vsize = v.size();
        for(int i = 0; vsize > i; i++){
            if (v[i] == element) return i;
        }
        return 0;
    }


    bool AddReserva(Reserva reserva);
    void AddReservasAtuais(Reserva reserva);
    void AddEstadia(Reserva reserva);
    void AddCliente(Cliente cliente);
    void AddQuarto(Quarto quarto);
    void AddFuncionario(Funcionario funcionario);

    bool ValidarReserva(Cliente cliente, Reserva reserva);
    void CheckIn(Cliente cliente);
    void CheckOut(Cliente cliente);

    const vector <Reserva> GetReservas() {return reservas;}
    const vector <Reserva> GetReservasAtuais() {return reservas_atuais;}
    const vector <Reserva> GetEstadias() {return estadias;}
    const vector <Cliente> GetClientes() {return clientes;}
    const vector <Quarto> GetQuartos() {return quartos;}
    const vector <Funcionario> GetFuncionarios() {return funcionarios;}

    data DiaFinal(int mesp, int anop);
    const vector <Funcionario> Pesquisa_F_Salario(bool inverso);
    const vector <Funcionario> Pesquisa_F_Cargo();
    const vector <Reserva> Pesquisa_Reservas_Duracao(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_Preco(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, vector <Reserva> reserva);
    const vector <Reserva> Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, vector <Reserva> reserva);
    const vector <Reserva> Quartos_Fin(int mesp, int anop);
    float CustosTotais(float impostos, float despesasfixas);
    float RendimentosTotais(int mes, int ano);
    float BalancoFin(int mes, int ano, float impostos, float despesasfixas);
};

#endif //HOTEL_HOTEL_H
