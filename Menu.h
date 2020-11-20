#ifndef HOTEL_MENU_H
#define HOTEL_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Exceptions.h"
#include "Hotel.h"

using namespace std;

class Menu{
private:
    Hotel H;
    vector <string> membros = {"Cliente", "Funcionário", "Produto", "Quarto", "Reserva", "Servico"};
    vector <string> membros_semRes = {"Cliente", "Funcionário", "Produto", "Quarto", "Servico"};
public:
    Menu() {};

    template<class T>
    void PrintV(const vector<T>& v);

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
