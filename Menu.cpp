#include <fstream>
#include <sstream>
#include "Menu.h"

void Menu::ImportarHotel(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        cout << endl << "O Ficheiro não abre!" << endl;
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    getline(inficheiro, line);
    if(line != "Hotel") throw FicheiroIncompativel(localizacao);
    inficheiro.close();
    H.ImportarQuartos(localizacao);
    H.ImportarProdutos(localizacao);
    H.ImportarClientes(localizacao);
    H.ImportarFuncionarios(localizacao);
    H.ImportarReservas(localizacao);
}

void Menu::ImprimeOp(vector <string> opcoes) {
    for(int i = 0; opcoes.size() > i; i++){
        cout << "[" << i << "] " << opcoes[i] << endl;
    }
    cout << "Escolha: ";
}

void Menu::Inicial() {
    vector<string> opcoes = {"Importar Hotel a partir de Ficheiro", "Criar Hotel do início"};
    int resposta;
    while (cin.fail() || (resposta != 0 && resposta != 1)){
        ImprimeOp(opcoes);
        cin >> resposta;
    }
    if(resposta == 0){
        string localizacao;
        ifstream inficheiro;
        cout<<"Introduza o nome do ficheiro: ";
        cin>>localizacao;
        if(localizacao.substr(localizacao.length() - 4) != ".txt") localizacao += ".txt";
        inficheiro.open(localizacao);
        while(inficheiro.fail())
        {
            inficheiro.clear();
            cout << "Nome do ficheiro incorreto." << endl;
            cout<<"Introduza o nome do ficheiro: ";
            cin>>localizacao;
            if(localizacao.substr(localizacao.length() - 4) != ".txt") localizacao += ".txt";
            inficheiro.open(localizacao);
        }
        inficheiro.close();
        ImportarHotel(localizacao);
    }
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
