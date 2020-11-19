#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Exceptions.h"

ifstream Menu::OpenFicheiro(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(!inficheiro){
        cout << endl << "O Ficheiro não abre!" << endl;
        throw FicheiroIncompativel(localizacao);
    }
    return inficheiro;
}


bool Menu::ImportarHotel(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(!inficheiro){
        cout << endl << "O Ficheiro não abre!" << endl;
        return false;
    }
    string line, nomehotel;
    getline(cin, line);
    //if(line != "Hotel")
    getline(cin, line);
    nomehotel = line;
    while(inficheiro){
        getline(cin, line);
    }
    return true;
}

void Menu::Coisas() {
    cout << endl << "LISTA DE AÇÕES" << endl;
    cout << "Para CLIENTES" << endl;
    cout << "[0] Pesquisar Reservas" << endl;
    cout << "[1] Fazer uma Reserva" << endl;
    cout << "[2] Fazer Check-In" << endl;
    cout << "[3] Fazer Check-Out" << endl;
    cout << "Para FUNCIONÁRIOS GESTORES" << endl;
    cout << "[0] Pesquisar Reservas" << endl;
    cout << "[4] Pesquisar Funcionários" << endl;
    cout << "[5] Aplicar uma Promoção" << endl;
    cout << "[6] Escolher um Produto" << endl;
    cout << "[7] Contratar um Funcionário" << endl;
    cout << "[8] Ver Balanço Financeiro" << endl;
}
