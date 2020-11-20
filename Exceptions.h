#ifndef HOTEL_EXCEPTIONS_H
#define HOTEL_EXCEPTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FicheiroIncompativel: public exception{
public:
    FicheiroIncompativel(string nomeficheiro);
    ~FicheiroIncompativel() {};
};

class Repetido: public exception{
public:
    Repetido(string nome);
    Repetido(int id);
    ~Repetido() {};
};


#endif //HOTEL_EXCEPTIONS_H
