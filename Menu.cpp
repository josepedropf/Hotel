#include "Menu.h"


void Menu::PrintPointerListReserva(list<Reserva *> pl) {
    cout << endl;
    cout << "|||-> " << endl << endl;
    for (auto it = pl.begin(); it != pl.end(); it++){
        (*(*it)).Info();
        cout << endl;
    }
    cout << "<-||| " << endl;
}

void Menu::PrintPointerListFunc(list<Funcionario *> pl) {
    cout << endl;
    cout << "|||-> " << endl << endl;
    for (auto it = pl.begin(); it != pl.end(); it++){
        (*(*it)).Info();
        cout << endl;
    }
    cout << "<-||| " << endl;
}

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
    H.ImportarServicos(localizacao);
}

string Menu::NomeFicheiro(){
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
    return localizacao;
}

void Menu::ImprimeTit(string titulo) {
    string uptitulo = titulo;
    for (int i = 0; titulo.size() > i; i++){
        uptitulo[i] = toupper(titulo[i]);
    }
    cout << endl << endl << "|| " << uptitulo << " ||" << endl << endl;
}

void Menu::ImprimeOp(vector <string> opcoes, bool aviso) {
    for(int i = 0; opcoes.size() > i; i++) {
        if (opcoes.size() <= 10) cout << "[" << i << "] " << opcoes[i] << endl;
        else {
            if (i <= 9) cout << "[0" << i << "] " << opcoes[i] << endl;
            else cout << "[" << i << "] " << opcoes[i] << endl;
        }
    }
    if(aviso) cout << "Input inválido. Insira um número entre 0 e " << opcoes.size() - 1 << "." << endl;
    cout << "Escolha: ";
}

unsigned Menu::ProcessarInputInt(vector<string> opcoes, string titulo, unsigned liminf, unsigned limsup) {
    unsigned resposta;
    ImprimeTit(titulo);
    ImprimeOp(opcoes, false);
    cin >> resposta;
    while (cin.fail() || resposta < liminf || resposta > limsup){
        ImprimeTit(titulo);
        ImprimeOp(opcoes, true);
        cin >> resposta;
    }
    return resposta;
}

unsigned Menu::ProcessarInputInt(vector<string> opcoes, string titulo) {
    unsigned liminf = 0, limsup = opcoes.size() - 1, resposta;
    ImprimeTit(titulo);
    ImprimeOp(opcoes, false);
    cin >> resposta;
    while (cin.fail() || resposta < liminf || resposta > limsup){
        ImprimeTit(titulo);
        ImprimeOp(opcoes, true);
        cin >> resposta;
    }
    return resposta;
}

void Menu::Inicial() {
    string titulo = "Início";
    vector<string> opcoes = {"Importar Hotel a partir de Ficheiro", "Criar Hotel do Início"};
    unsigned resposta;
    resposta = ProcessarInputInt(opcoes, titulo, 0, 1);
    if(resposta == 0){
        string localizacao = NomeFicheiro();
        ImportarHotel(H, localizacao);
    }
    return Principal();
}

void Menu::Importar() {
    unsigned resposta;
    vector<string> opcoes = membros;
    for (int i = 0; opcoes.size() > i; i++){
        opcoes[i] = opcoes[i] + "s";
    }
    opcoes.push_back("Hotel");
    for (int i = 0; opcoes.size() > i; i++){
        opcoes[i] = "Importar " + opcoes[i];
    }
    opcoes.push_back("Voltar");
    resposta = ProcessarInputInt(opcoes, "Importar");
    string localizacao;
    if(resposta != 7) localizacao = NomeFicheiro();
        switch (resposta) {
            case 0:
                H.ImportarClientes(localizacao);
                PrintList(H.GetClientes());
                break;
            case 1:
                H.ImportarFuncionarios(localizacao);
                PrintList(H.GetFuncionariosRececao());
                PrintList(H.GetFuncionariosResponsaveis());
                PrintList(H.GetFuncionariosLimpeza());
                PrintList(H.GetFuncionariosGestores());
                PrintList(H.GetFuncionarios());
                break;
            case 2:
                H.ImportarProdutos(localizacao);
                PrintList(H.GetProdutos());
                break;
            case 3:
                H.ImportarQuartos(localizacao);
                PrintList(H.GetQuartos());
                break;
            case 4:
                H.ImportarReservas(localizacao);
                PrintList(H.GetReservas());
                break;
            case 5:
                //Importar Servicos;
                break;
            case 6:
                ImportarHotel(H, localizacao);
                //PrintHotel;
                break;
            case 7:
                return Principal();
            default:
                return Importar();
        }
        return Importar();
}

void Menu::VerInfo() {
    unsigned resposta, segresp;
    vector<string> opcoes = membros;
    opcoes.push_back("Hotel");
    for (int i = 0; opcoes.size() > i; i++){
        opcoes[i] = "Ver Info " + opcoes[i];
    }
    opcoes.push_back("Voltar");
    resposta = ProcessarInputInt(opcoes, "Ver Informação");
    if(resposta == 7) return Principal();
    if (resposta == 6){
        //PrintHotel
        return VerInfo();
    }
    vector<string> segopcoes = {"Ver Informação de Todos", "Ver Informação de 1 em Específico", "Voltar", "Voltar ao Menu Principal"};
    segresp = ProcessarInputInt(segopcoes, opcoes[resposta]);
    if(segresp == 3) return Principal();
    if(segresp == 2) return VerInfo();

}

void Menu::Principal() {
    string titulo = "Bem-vindo ao " + H.nome;
    ImprimeTit(titulo);
    vector <string> opcoes = {"Importar...", "Ver Informação...", "Adicionar Membro...", "Apagar Membro...", "Reservar / Cancelar Reserva", "Contratar / Despedir", "Check-in / Check-out", "Finanças", "Outros", "Exportar"};
    //ImprimeOp(opcoes);

}
