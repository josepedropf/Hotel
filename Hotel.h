#ifndef HOTEL_HOTEL_H
#define HOTEL_HOTEL_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>


#include "Reserva.h"
#include "Produto.h"
#include "Quarto.h"
#include "Funcionario.h"
#include "Cliente.h"
#include "Data.h"
#include "Exceptions.h"


using namespace std;

class Hotel {
protected:

    vector <Produto> produtos;
    vector <Reserva> reservas;
    vector <Reserva> estadias;
    vector <Reserva> reservas_atuais;
    vector <Cliente> clientes;
    vector <Quarto> quartos;
    vector <Funcionario> funcionarios;
    vector <F_Rececao> funcionarios_rececao;
    vector <F_Responsavel> funcionarios_responsaveis;
    vector <F_Limpeza> funcionarios_limpeza;
    vector <F_Gestor> funcionarios_gestores;

public:
    Hotel() {};
    ~Hotel() {};

    template<class T>
    void PrintV(const vector<T>& v){
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
        return -1;
    }


    bool AddProduto(Produto produto);
    bool AddReserva(Reserva reserva);
    void PopReserva(int idnum);
    bool AddReservasAtuais(Reserva reserva);
    bool AddEstadia(Reserva reserva);
    bool AddCliente(Cliente cliente);
    bool AddQuarto(Quarto quarto);
    bool AddFuncionario(Funcionario funcionario);
    bool AddFuncionarioRececao(F_Rececao funcionario_rec);
    bool AddFuncionarioResponsavel(F_Responsavel funcionario_resp);
    bool AddFuncionarioLimpeza(F_Limpeza funcionario_limpeza);
    bool AddFuncionarioGestor(F_Gestor funcionario_gestor);


    void ImportarQuartos(string localizacao);
    void ImportarClientes(string localizacao);
    void ImportarFuncionarios(string localizacao);
    void ImportarProdutos(string localizacao);
    void ImportarReservas(string localizacao);

    void EscreverHotel(string nomeficheiro);

    bool Reservar(Cliente &cliente, int idnumero, data data_inicial, data data_final, int lugaresperados, vector <int> numerosquartos);
    void CancelarReserva(Cliente &cliente, int idreserva);
    void CheckIn(Cliente cliente);
    void CheckOut(Cliente cliente);

    tipo_cargo EscolherCargo();
    tipo_turno EscolherTurno();
    int EscolherPiso();
    Funcionario Contratar(string nome, int nif);
    Funcionario Contratar(string nome, int nif, tipo_cargo cargo);

    const vector<Produto> GetProdutos() {return produtos;}
    const vector <Reserva> GetReservas() {return reservas;}
    const vector <Reserva> GetReservasAtuais() {return reservas_atuais;}
    const vector <Reserva> GetEstadias() {return estadias;}
    const vector <Cliente> GetClientes() {return clientes;}
    const vector <Quarto> GetQuartos() {return quartos;}
    const vector <Funcionario> GetFuncionarios() {return funcionarios;}
    const vector <F_Rececao> GetFuncionariosRececao() {return funcionarios_rececao;}
    const vector <F_Responsavel> GetFuncionariosResponsaveis() {return funcionarios_responsaveis;}
    const vector <F_Limpeza> GetFuncionariosLimpeza() {return funcionarios_limpeza;}
    const vector <F_Gestor> GetFuncionariosGestores() {return funcionarios_gestores;}

    data DiaFinal(int mesp, int anop);
    const vector <Funcionario> Pesquisa_F_Salario(bool inverso);
    const vector <Funcionario> Pesquisa_F_Cargo();
    const vector <Reserva> Pesquisa_Reservas_Duracao(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_Preco(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, vector <Reserva> reserva);
    const vector <Reserva> Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, vector <Reserva> reserva);

    vector <Reserva> ReservasSobrepostas(vector <Reserva> reservastotais, data datai, data dataf);
    vector <Reserva> Reservas_Fin(int mesp, int anop);
    vector <Quarto> Quartos_Disponiveis(data data_inicial, data data_final);

    float CustosTotais(float impostos, float despesasfixas);
    float RendimentosTotais(int mes, int ano);
    float BalancoFin(int mes, int ano, float impostos, float despesasfixas);

};

#endif //HOTEL_HOTEL_H
