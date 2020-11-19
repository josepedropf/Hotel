#ifndef HOTEL_EXCEPTIONS_H
#define HOTEL_EXCEPTIONS_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class FicheiroIncompativel{
public:
    FicheiroIncompativel(string nomeficheiro);
    ~FicheiroIncompativel() {};
};
#endif //HOTEL_EXCEPTIONS_H
