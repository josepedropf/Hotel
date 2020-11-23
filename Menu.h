#ifndef HOTEL_MENU_H
#define HOTEL_MENU_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <cmath>
#include <string>
#include <algorithm>

#include "Hotel.h"

using namespace std;

class Menu{
private:
    Hotel H;
    vector <string> membros = {"Cliente", "Funcionário", "Produto", "Quarto", "Reserva", "Servico"};
    vector <string> tfuncionarios = {"Normais", "Rececão", "Responsáveis", "Limpeza", "Gestores"};
    vector <string> membros_semRes = {"Cliente", "Funcionário", "Produto", "Quarto", "Servico"};
public:
    Menu() {};
    ~Menu() {};

    template<class T>
    void PrintV(const vector<T> &v) {
        int vsize = v.size();
        cout << endl;
        cout << "|||-> " << endl << endl;
        for (int i = 0; vsize > i; i++){
            v[i].Info();
            cout << endl;
        }
        cout << "<-||| " << endl;
    }

    template<class T>
    void PrintList(const list<T> &l) {
        cout << endl;
        cout << "|||-> " << endl << endl;
        for (auto it = l.begin(); it != l.end(); it++){
            (*it).Info();
            cout << endl;
        }
        cout << "<-||| " << endl;
    }

    void PrintPointerListReserva(list <Reserva *> pl);
    void PrintPointerListFunc(list <Funcionario *> pl);
    void PrintPointerListCliente(list <Cliente *> pl);

    void ImportarHotel(Hotel &H, string localizacao);
    void PrintHotel();

    string NomeFicheiro();
    void ImprimeTit(string titulo);
    void ImprimeOp(vector <string> opcoes, bool aviso, bool enm);

    unsigned ProcessarInputInt(vector <string> opcoes, string titulo, unsigned liminf, unsigned limsup);
    unsigned ProcessarInputInt(vector <string> opcoes, string titulo);

    vector <int> ProcessarIntIndef(string colecao_sing, string colecao_plural, int lim);
    template<class T>
    vector <int> ProcessarIntIndef(string colecao_sing, string colecao_plural, int lim, list <T> l);

    template<class T>
    T InputRestrito(string texto);
    string InputNome(string texto);
    data InputData(string texto);
    nota_avaliacao InputNota(string texto);
    tipo_cargo InputCargo(string texto);
    tipo_turno InputTurno(string texto);
    tipo_produto InputTProd(string texto);
    tipo_quarto InputTQuarto(string texto);

    template<class T>
    bool ProcuraValida(int id, list <T> l);
    template<class T>
    T EfetuarProcura(int id, list <T> l);

    template<class T>
    int ProcessarInputProcura(string titulo, list <T> l);


    void Inicial();

    void Importar();
    void VerInfo();
    void Adicionar();
    void Apagar();
    void MReserva();
    void MGerirFunc();
    void Checks();
    void FinancasSelect();
    void Financas(int mes, int ano);
    void Outros();
    void Exportar();

    void Principal();

};

#endif //HOTEL_MENU_H
