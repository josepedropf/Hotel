#include "Exceptions.h"

FicheiroIncompativel::FicheiroIncompativel(string nomeficheiro){
    cout << endl << "O Ficheiro " << nomeficheiro << " não é compatível para ser importado!" << endl;
}

Repetido::Repetido(string nome) {
    cout << endl << "O Objeto " << nome << "  é Repetido!" << endl;
}

Repetido::Repetido(int id) {
    cout << endl << "O Objeto de ID " << id << "  é Repetido!" << endl;
}