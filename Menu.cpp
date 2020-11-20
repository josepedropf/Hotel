#include <fstream>
#include <sstream>
#include "Menu.h"

void Menu::ImportarHotel(Hotel &H, string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        cout << endl << "O Ficheiro não abre!" << endl;
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    getline(inficheiro, line);
    if(line != "Hotel") throw FicheiroIncompativel(localizacao);
    getline(inficheiro, line);
    if(line != "") H.nome = line;
    inficheiro.close();
    H.ImportarQuartos(localizacao);
    H.ImportarProdutos(localizacao);
    H.ImportarClientes(localizacao);
    H.ImportarFuncionarios(localizacao);
    H.ImportarReservas(localizacao);
}

void Menu::ImprimeTit(string titulo) {
    string uptitulo = titulo;
    for (int i = 0; titulo.size() > i; i++){
        uptitulo[i] = toupper(titulo[i]);
    }
    cout << endl << endl << "|| " << uptitulo << " ||" << endl << endl;
}

void Menu::ImprimeOp(vector <string> opcoes) {
    for(int i = 0; opcoes.size() > i; i++){
        if(opcoes.size() <= 10) cout << "[" << i << "] " << opcoes[i] << endl;
        else{
            if(i <= 9) cout << "[0" << i << "] " << opcoes[i] << endl;
            else cout << "[" << i << "] " << opcoes[i] << endl;
        }
    }
    cout << "Escolha: ";
}

void Menu::Inicial() {
    vector<string> opcoes = {"Importar Hotel a partir de Ficheiro", "Criar Hotel do início"};
    int resposta;
    ImprimeOp(opcoes);
    cin >> resposta;
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
        ImportarHotel(H, localizacao);
    }
}

void Menu::Importar() {
    vector<string> opcoes = membros;
    opcoes.push_back("Hotel");
    for (int i = 0; opcoes.size() > i; i++){
        opcoes[i] = "Importar " + opcoes[i];
    }
    ImprimeOp(opcoes);
}

void Menu::Principal() {
    vector <string> opcoes = {"Importar...", "Ver Informação...", "Adicionar Membro...", "Apagar Membro...", "Reservar / Cancelar Reserva", "Contratar / Despedir", "Check-in / Check-out", "Finanças", "Outros", "Exportar"};
    ImprimeOp(opcoes);

}
