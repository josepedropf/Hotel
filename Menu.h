#ifndef HOTEL_MENU_H
#define HOTEL_MENU_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

#include "Hotel.h"

using namespace std;

class Menu{
private:
    Hotel H;
    vector <string> membros = {"Cliente", "Funcionário", "Produto", "Quarto", "Reserva", "Servico"};
    vector <string> membros_semRes = {"Cliente", "Funcionário", "Produto", "Quarto", "Servico"};
public:
    Menu() {};
    ~Menu() {};

    template<class T>
    void PrintV(const vector<T>& v);
    template<class T>
    void PrintList(const list<T>& l);

    void PrintPointerListReserva(list<Reserva *> pl);
    void PrintPointerListFunc(list <Funcionario *> pl);

    void ImportarHotel(Hotel &H, string localizacao);

    string NomeFicheiro();
    void ImprimeTit(string titulo);
    void ImprimeOp(vector <string> opcoes, bool aviso);
    unsigned ProcessarInputInt(vector <string> opcoes, string titulo, unsigned liminf, unsigned limsup);
    unsigned ProcessarInputInt(vector <string> opcoes, string titulo);

    void Inicial();

    void Importar();
    void VerInfo();

    void Principal();

};

#endif //HOTEL_MENU_H
