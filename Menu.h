#ifndef HOTEL_MENU_H
#define HOTEL_MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Data.h"
#include "Hotel.h"

using namespace std;

class Menu{
public:
    bool voltar;
    Menu() {};
    ifstream OpenFicheiro(string localizacao);
    bool ImportarHotel(string localizacao);
    void Coisas();
};

#endif //HOTEL_MENU_H
