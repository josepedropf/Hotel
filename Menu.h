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
public:
    Menu() {};
    void ImportarHotel(string localizacao);
    void ImprimeOp(vector <string> opcoes);
    void Inicial();
    void Coisas();
};

#endif //HOTEL_MENU_H
