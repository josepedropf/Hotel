#ifndef HOTEL_MENU_H
#define HOTEL_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Exceptions.h"
#include "Data.h"
#include "Hotel.h"

using namespace std;

class Menu{
private:
    Hotel H;
    vector <string> membros = {"Cliente", "Funcionário", "Produto", "Quarto", "Reserva", "Servico"};
    vector <string> membros_semRes = {"Cliente", "Funcionário", "Produto", "Quarto", "Servico"};
public:
    Menu() {};
    void ImportarHotel(Hotel &H, string localizacao);
    void ImprimeTit(string titulo);
    void ImprimeOp(vector <string> opcoes);
    void Inicial();
    void Importar();

    void Principal();
};

#endif //HOTEL_MENU_H
