#include "Exceptions.h"

FicheiroIncompativel::FicheiroIncompativel(string nomeficheiro){
    cout << endl << "O Ficheiro " << nomeficheiro << " não é compatível para ser importado!" << endl;
}