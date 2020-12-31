#ifndef HOTEL_HOTEL_H
#define HOTEL_HOTEL_H

#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>


#include "Reserva.h"
#include "Produto.h"
#include "Quarto.h"
#include "Funcionario.h"
#include "Cliente.h"
#include "Servico.h"
#include "Data.h"
#include "Exceptions.h"
#include "Frota.h"


using namespace std;

class Hotel {
protected:

    list <Produto> produtos;
    list <Reserva> reservas;
    list <Reserva> estadias;
    list <Reserva> reservas_atuais;
    list <Cliente> clientes;
    list <Quarto> quartos;
    list <Funcionario> funcionarios;
    list <F_Rececao> funcionarios_rececao;
    list <F_Responsavel> funcionarios_responsaveis;
    list <F_Limpeza> funcionarios_limpeza;
    list <F_Gestor> funcionarios_gestores;
    list <Servico> servicos;
    list <Reserva *> reservas_totais;
    list <viagem> viagens_realizadas;

public:
    Hotel(): frota(Veiculo()) {nome = "Grande Hotel Central";}
    Hotel(string nome);
    ~Hotel() {};
    string nome;


    const list <Produto> GetProdutos() {return produtos;}
    const list <Reserva> GetReservas() {return reservas;}
    const list <Reserva> GetReservasAtuais() {return reservas_atuais;}
    const list <Reserva> GetEstadias() {return estadias;}
    const list <Cliente> GetClientes() {return clientes;}
    const list <Quarto> GetQuartos() {return quartos;}
    const list <Funcionario> GetFuncionarios() {return funcionarios;}
    const list <F_Rececao> GetFuncionariosRececao() {return funcionarios_rececao;}
    const list <F_Responsavel> GetFuncionariosResponsaveis() {return funcionarios_responsaveis;}
    const list <F_Limpeza> GetFuncionariosLimpeza() {return funcionarios_limpeza;}
    const list <F_Gestor> GetFuncionariosGestores() {return funcionarios_gestores;}
    const list <Servico> GetServicos() {return servicos;}
    const list <viagem> GetViagens() {return viagens_realizadas;}
    const list <Cliente *> GetClientesnoHotel();

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
    bool AddServico(Servico servico);
    bool AddViagem(viagem viagem);


    bool Reservar(Cliente &cliente, int idnumero, data data_inicial, data data_final, int lugaresperados, vector <int> numquartos);
    bool Reservar(int nif, int idnumero, data data_inicial, data data_final, int lugaresperados, vector <int> numquartos);
    void CancelarReserva(Cliente &cliente, int idreserva);
    void CancelarReserva(int nif, int idreserva);
    void CheckIn(Cliente &cliente);
    void CheckIn(int nif);
    void CheckOut(Cliente &cliente);
    void CheckOut(int nif);

    const list <Funcionario> Pesquisa_F_Salario(bool inverso);
    const list <Funcionario> Pesquisa_F_Cargo();
    const list <Reserva> RestringirClientesNovos(bool clientes_novos);
    const list <Reserva> RestringirClientesNovos(bool clientes_novos, list<Reserva> creservas);
    const list <Reserva *> P_RestringirClientesNovos(bool clientes_novos, list<Reserva *> creservas);
    const list <Reserva> Pesquisa_Reservas_Duracao(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const list <Reserva> Pesquisa_Reservas_Preco(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const list <Reserva> Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const list <Reserva> Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, list <Reserva> creservas);
    const list<Reserva *> P_Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, list<Reserva *> creservas);
    const list <Reserva> Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const list <Reserva> Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, list <Reserva> creservas);
    const list <Reserva *> P_Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, list <Reserva *> creservas);

    list <Reserva *> ReservasSobrepostas(data datai, data dataf);
    list <Reserva *> Reservas_Fin(int mesp, int anop);
    list <Servico *> Servicos_Fin(int mesp, int anop);
    list <Quarto *> Quartos_Disponiveis(data data_inicial, data data_final);

    float CustosTotais(float impostos, float despesasfixas);
    data DiaFinal(int mesp, int anop);
    float RendimentosTotais(int mes, int ano);
    float BalancoFin(int mes, int ano, float impostos, float despesasfixas);

    tipo_cargo EscolherCargo();
    tipo_turno EscolherTurno();
    int EscolherPiso();
    void Contratar(string nome, int nif, tipo_cargo cargo);
    void Contratar(string nome, int nif);
    void Despedir(int nif);
    void AddAnoServico(int idf);
    void SetSalario(int idf, float novosalario);

    bool PrestarServico(Cliente &cliente, Servico servico);
    bool PrestarServico(int nif, Servico servico);
    bool PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa);
    bool PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa, vector <int> funcsnif);
    bool PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa, vector <int> numprods, float margem_lucro);
    bool PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa, vector <int> funcsnif, vector <int> numprods, float margem_lucro);

    void Promocoes(F_Gestor fgestor, vector<int> numquartos);
    Produto EscolherProduto(F_Gestor fgestor, vector<int> numprodutos);
    Produto EscolherProduto(F_Gestor fgestor, list<Produto *> lprodutos);


    void ImportarQuartos(string localizacao);
    void ImportarClientes(string localizacao);
    void ImportarFuncionarios(string localizacao);
    void ImportarProdutos(string localizacao);
    void ImportarReservas(string localizacao);
    void ImportarServicos(string localizacao);

    void EscreverHotel(string nomeficheiro);


    template <class T>
    int EncontrarIndex(vector <T> v, T elemento);
    template <class T>
    void ApagarElementoV(vector <T> v, int index) {v.erase(v.begin() + index);}
    template <class T>
    void ApagarElementoL(list <T> l, T elemento);

    template <class T>
    void ApagarElementoID(list <T> &l, int id){
        for(auto it = l.begin(); it != l.end(); it++){
            if((*it).ID() == id){
                it = l.erase(it);
                break;
            }
        }
    }

    void ApagarCliente(int id) {return ApagarElementoID(clientes, id);}
    void ApagarQuarto(int id) {return ApagarElementoID(quartos, id);}
    void ApagarProduto(int id) {return ApagarElementoID(produtos, id);}

    int EncontrarIndexReserva(vector <Reserva> vr, Reserva r);
    int EncontrarIndexReserva(vector <Reserva *> vr, Reserva *r);
    void ApagarReservaL(list <Reserva> &lr, Reserva r);
    void ApagarReservaL(list <Reserva *> &lr, Reserva r);

    template <class T>
    vector<T> LtoV(const list <T> &l);
    template <class T>
    list<T> VtoL(const vector <T> &v);

    list <Reserva *> PointerListReserva(list <Reserva> l);
    list <Funcionario *> PointerListFunc(list <Funcionario> l);
    list <Quarto *> PointerListQuarto(list <Quarto> l);
    list <Cliente *> PointerListCliente(list <Cliente> l);
    list <Produto *> PointerListProduto(list <Produto> l);
    list <Reserva> ListReserva(list <Reserva *> pl);
    list <Funcionario> ListFunc(list <Funcionario *> pl);
    list <Quarto> ListQuarto(list <Quarto *> pl);
    list <Cliente> ListCliente(list <Cliente *> pl);
    list <Produto> ListProduto(list <Produto *> pl);

    void UpdateReservasTotais();

    struct ClienteHash //new
    {
        int operator() (const Cliente& c) const
        {
            int v = 0;
            v = 37 * c.getName()[0];
            return v;
        }

        bool operator() (const Cliente& c1, const Cliente& c2) const
        {
            if (c1.getNif() == c2.getNif()) return true;
            else return false;
        }
    };

    typedef unordered_set<Cliente, ClienteHash, ClienteHash> tabHclientes;
    tabHclientes clientes_usuais;

    list <Cliente *> GetClientesInicial(char inicial);
    void PromoIniciais(char p_inicial, char s_inicial);

    BST<Veiculo> frota; //Init?
    BST<Veiculo> getFrota() const;
    int numVeiculos() const;
    void addVeiculo(Veiculo veiculo);
    void alugarFrota(const vector<Veiculo>& rFrota);
    void devolveVeiculo(matricula matricula);
    Veiculo* pesquisaVeiculo (matricula matricula);
    Veiculo* menorKm(); //to be called at the start or before a trip

    void Viajar(Cliente * cliente, double distancia, string ponto_partida, string destino, int id);
    void Viajar(Cliente * cliente, double distancia, int id);
};

#endif //HOTEL_HOTEL_H
