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

void Menu::PrintHotel() {
    cout << endl << endl << "||| " << "BEM-VINDO AO GRANDE HOTEL " << H.nome << " |||" << endl << endl;
    PrintList(H.GetQuartos());
    PrintList(H.GetProdutos());
    PrintList(H.GetFuncionariosGestores());
    PrintList(H.GetFuncionariosResponsaveis());
    PrintList(H.GetFuncionariosLimpeza());
    PrintList(H.GetFuncionariosGestores());
    PrintList(H.GetFuncionarios());
    PrintList(H.GetClientes());
    PrintList(H.GetServicos());
    PrintList(H.GetEstadias());
    PrintList(H.GetReservasAtuais());
    PrintList(H.GetReservas());
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


template<class T>
bool Menu::ProcuraValida(int id, list<T> l) {
    for(auto it = l.begin(); it != l.end(); it++){
        if((*it).ID() == id) return true;
    }
    return false;
}

template<class T>
T Menu::EfetuarProcura(int id, list<T> l) {
    for(auto it = l.begin(); it != l.end(); it++){
        if((*it).ID() == id) return (*it);
    }
}

template<class T>
int Menu::ProcessarInputProcura(string titulo, list<T> l) {
    int resposta;
    ImprimeTit(titulo);
    cout << "[-X] Voltar" << endl;
    cout << "[-1] Ver Info" << endl;
    cout << "[+X] O ID do Elemento que Procura" << endl;
    cout << "Escolha: ";
    cin >> resposta;
    while(cin.fail() || resposta == -1 || (resposta >= 0 && !ProcuraValida(resposta, l))){
        ImprimeTit(titulo);
        if(resposta == -1) PrintList(l);
        cout << "[-X] Voltar" << endl;
        cout << "[-1] Ver Info" << endl;
        cout << "[+X] O ID do Elemento que Procura" << endl;
        if(cin.fail()) cout << "Input Inválido! Tem de ser um número inteiro." << endl;
        else{
            cout << "Não foi encontrado nenhum elemento correspondente à sua Pesquisa." << endl;
            cout << "Escolha [-1] para a Informação dos elementos da Classe que escolheu ou tente pesquisar novamente." << endl;
        }
        cout << "Escolha: ";
        cin >> resposta;
    }
    if(resposta < -1) return -1;
    else return resposta;
}

void Menu::Inicial() {
    string titulo = "Início";
    vector<string> opcoes = {"Importar Hotel a partir de Ficheiro", "Criar Hotel do Início"};
    unsigned resposta;
    resposta = ProcessarInputInt(opcoes, titulo, 0, 1);
    if(resposta == 0){
        string localizacao = NomeFicheiro();
        ImportarHotel(H, localizacao);
        PrintHotel();
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
                H.ImportarServicos(localizacao);
                PrintList(H.GetServicos());
                break;
            case 6:
                ImportarHotel(H, localizacao);
                PrintHotel();
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
    for (int i = 0; opcoes.size() > i; i++) {
        opcoes[i] = "Ver Info " + opcoes[i];
    }
    opcoes.push_back("Voltar");
    resposta = ProcessarInputInt(opcoes, "Ver Informação");
    if (resposta == 7) return Principal();
    if (resposta == 6) {
        PrintHotel();
        return VerInfo();
    }
    vector<string> segopcoes = {"Ver Informação de Todos", "Ver Informação de 1 em Específico", "Voltar",
                                "Voltar ao Menu Principal"};
    segresp = ProcessarInputInt(segopcoes, opcoes[resposta]);
    unsigned tresposta;
    string sectit = segopcoes[segresp] + " " + opcoes[resposta];
    vector<string> topcoes;
    vector<string> resopcoes = {"Estadia", "Reserva Atual", "Reserva"};
    for (int i = 0; resopcoes.size() > i; i++) {
        resopcoes[i] = "Ver Info de " + resopcoes[i];
    }
    resopcoes.push_back("Voltar");
    resopcoes.push_back("Voltar ao Menu Principal");
    for (int i = 0; tfuncionarios.size() > i; i++) {
        topcoes.push_back("Ver Info Funcionários " + tfuncionarios[i]);
    }
    topcoes.push_back("Voltar");
    topcoes.push_back("Voltar ao Menu Principal");
    if (segresp == 3) return Principal();
    if (segresp == 2) return VerInfo();
    if (segresp == 0) {
        switch (resposta) {
            case 0:
                PrintList(H.GetClientes());
                return VerInfo();
            case 1:
                tresposta = ProcessarInputInt(topcoes, sectit);
                switch (tresposta) {
                    case 0:
                        PrintList(H.GetFuncionarios());
                        break;
                    case 1:
                        PrintList(H.GetFuncionariosRececao());
                        break;
                    case 2:
                        PrintList(H.GetFuncionariosResponsaveis());
                        break;
                    case 3:
                        PrintList(H.GetFuncionariosLimpeza());
                        break;
                    case 4:
                        PrintList(H.GetFuncionariosGestores());
                        break;
                    case 5:
                        return VerInfo();
                    case 6:
                        return Principal();
                    default:
                        break;
                }
                return VerInfo();
            case 2:
                PrintList(H.GetProdutos());
                return VerInfo();
            case 3:
                PrintList(H.GetQuartos());
                return VerInfo();
            case 4:
                PrintList(H.GetEstadias());
                PrintList(H.GetReservasAtuais());
                PrintList(H.GetReservas());
                return VerInfo();
            case 5:
                PrintList(H.GetServicos());
                return VerInfo();
            default:
                return VerInfo();
        }
    }
    int procurainput;
    if (segresp == 1) {
        switch (resposta) {
            case 0:
                procurainput = ProcessarInputProcura(sectit, H.GetClientes());
                if (procurainput == -1) return VerInfo();
                else EfetuarProcura(procurainput, H.GetClientes()).Info();
                break;
            case 1:
                tresposta = ProcessarInputInt(topcoes, sectit);
                switch (tresposta) {
                    case 0:
                        procurainput = ProcessarInputProcura(sectit, H.GetFuncionarios());
                        if (procurainput == -1) return VerInfo();
                        else EfetuarProcura(procurainput, H.GetFuncionarios()).Info();
                        break;
                    case 1:
                        procurainput = ProcessarInputProcura(sectit, H.GetFuncionariosRececao());
                        if (procurainput == -1) return VerInfo();
                        else EfetuarProcura(procurainput, H.GetFuncionariosRececao()).Info();
                        break;
                    case 2:
                        procurainput = ProcessarInputProcura(sectit, H.GetFuncionariosResponsaveis());
                        if (procurainput == -1) return VerInfo();
                        else EfetuarProcura(procurainput, H.GetFuncionariosResponsaveis()).Info();
                        break;
                    case 3:
                        procurainput = ProcessarInputProcura(sectit, H.GetFuncionariosLimpeza());
                        if (procurainput == -1) return VerInfo();
                        else EfetuarProcura(procurainput, H.GetFuncionariosLimpeza()).Info();
                        break;
                    case 4:
                        procurainput = ProcessarInputProcura(sectit, H.GetFuncionariosGestores());
                        if (procurainput == -1) return VerInfo();
                        else EfetuarProcura(procurainput, H.GetFuncionariosGestores()).Info();
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                procurainput = ProcessarInputProcura(sectit, H.GetProdutos());
                if (procurainput == -1) return VerInfo();
                else EfetuarProcura(procurainput, H.GetProdutos()).Info();
                break;
            case 3:
                procurainput = ProcessarInputProcura(sectit, H.GetQuartos());
                if (procurainput == -1) return VerInfo();
                else EfetuarProcura(procurainput, H.GetQuartos()).Info();
                break;
            case 4:
                tresposta = ProcessarInputInt(resopcoes, sectit);
                switch (tresposta) {
                    case 0:
                        procurainput = ProcessarInputProcura(sectit, H.GetEstadias());
                        if (procurainput == -1) return VerInfo();
                        else EfetuarProcura(procurainput, H.GetEstadias()).Info();
                        break;
                    case 1:
                        procurainput = ProcessarInputProcura(sectit, H.GetReservasAtuais());
                        if (procurainput == -1) return VerInfo();
                        else EfetuarProcura(procurainput, H.GetReservasAtuais()).Info();
                        break;
                    case 2:
                        procurainput = ProcessarInputProcura(sectit, H.GetReservas());
                        if (procurainput == -1) return VerInfo();
                        else EfetuarProcura(procurainput, H.GetReservas()).Info();
                        break;
                    case 3:
                        return VerInfo();
                    case 4:
                        return Principal();
                    default:
                        break;
                }
            case 5:
                procurainput = ProcessarInputProcura(sectit, H.GetServicos());
                if (procurainput == -1) return VerInfo();
                else EfetuarProcura(procurainput, H.GetServicos()).Info();
                break;
            default:
                break;
        }
    }
    return VerInfo();
}

void Menu::Principal() {
    unsigned resposta;
    string titulo = "Bem-vindo ao grande Hotel " + H.nome;
    ImprimeTit(titulo);
    vector <string> opcoes = {"Importar...", "Ver Informação...", "Adicionar Membro...", "Apagar Membro...", "Reservar / Cancelar Reserva", "Contratar / Despedir", "Check-in / Check-out", "Finanças", "Outros", "Exportar"};
    resposta = ProcessarInputInt(opcoes, titulo);
    switch (resposta){
        case 0:
            return Importar();
        case 1:
            return VerInfo();
        case 2:
            Importar();
            break;
        case 3:
            Importar();
            break;
        case 4:
            Importar();
            break;
        case 5:
            Importar();
            break;
        case 6:
            Importar();
            break;
        case 7:
            Importar();
            break;
        case 8:
            Importar();
            break;
        case 9:
            Importar();
            break;
        default:
            return Principal();
    }
    return Principal();
}
