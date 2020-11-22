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
    if(!cin.fail()){
        if(localizacao.substr(localizacao.size() < 4 || localizacao.length() - 4) != ".txt") localizacao += ".txt";
    }
    inficheiro.open(localizacao);
    while(cin.fail() || inficheiro.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        inficheiro.clear();
        cout << "Nome do ficheiro incorreto." << endl;
        cout<<"Introduza o nome do ficheiro: ";
        cin>>localizacao;
        if(!cin.fail()){
            if(localizacao.substr(localizacao.size() < 4 || localizacao.length() - 4) != ".txt") localizacao += ".txt";
        }
        inficheiro.open(localizacao);
    }
    cin.clear();
    cin.ignore(1000, '\n');
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

void Menu::ImprimeOp(vector <string> opcoes, bool aviso, bool enm) {
    for(int i = 0; opcoes.size() > i; i++) {
        if (opcoes.size() <= 10) cout << "[" << i << "] " << opcoes[i] << endl;
        else {
            if (i <= 9) cout << "[0" << i << "] " << opcoes[i] << endl;
            else cout << "[" << i << "] " << opcoes[i] << endl;
        }
    }
    if(aviso) cout << "Input inválido. Insira um número entre 0 e " << opcoes.size() - 1 << "." << endl;
    if(!enm) cout << "Escolha: ";
}

unsigned Menu::ProcessarInputInt(vector<string> opcoes, string titulo, unsigned liminf, unsigned limsup) {
    unsigned resposta;
    ImprimeTit(titulo);
    ImprimeOp(opcoes, false, false);
    cin >> resposta;
    while (cin.fail() || resposta < liminf || resposta > limsup){
        cin.clear();
        cin.ignore(1000, '\n');
        ImprimeTit(titulo);
        ImprimeOp(opcoes, true, false);
        cin >> resposta;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return resposta;
}

unsigned Menu::ProcessarInputInt(vector<string> opcoes, string titulo) {
    unsigned liminf = 0, limsup = opcoes.size() - 1, resposta;
    ImprimeTit(titulo);
    ImprimeOp(opcoes, false, false);
    cin >> resposta;
    while (cin.fail() || resposta < liminf || resposta > limsup){
        cin.clear();
        cin.ignore(1000, '\n');
        ImprimeTit(titulo);
        ImprimeOp(opcoes, true, false);
        cin >> resposta;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return resposta;
}

vector <int> Menu::ProcessarIntIndef(string colecao_sing, string colecao_plural, int lim) {
    vector <int> respostas;
    int resp;
    bool repetido = false;
    cout << "[-X] para parar de introduzir mais inputs à coleção de " << colecao_plural << endl;
    cout << "[+X] para adicionar input à coleção de " << colecao_plural << endl;
    cout << "Introduza [-X] ou " << colecao_sing << ": ";
    cin >> resp;
    if(resp >= 0){
        repetido = false;
        for(int i = 0; respostas.size() > i; i++){
            if(respostas[i] == resp){
                repetido = true;
                break;
            }
        }
        if(!repetido) respostas.push_back(resp);
    }
    while (cin.fail() || resp >= 0 || respostas.size() >= lim){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "[-X] para parar de introduzir mais inputs à coleção de " << colecao_plural << endl;
        cout << "[+X] para adicionar input à coleção de " << colecao_plural << endl;
        cout << "Introduza [-X] ou " << colecao_sing << ": ";
        cin >> resp;
        if(resp >= 0){
            repetido = false;
            for(int i = 0; respostas.size() > i; i++){
                if(respostas[i] == resp){
                    repetido = true;
                    break;
                }
            }
            if(!repetido) respostas.push_back(resp);
        }
    }
    return respostas;
}

template<class T>
vector <int> Menu::ProcessarIntIndef(string colecao_sing, string colecao_plural, int lim, list <T> l){
    vector <int> respostas;
    int resp;
    bool repetido = false, pertence = false;
    cout << "[-X] para parar de introduzir mais inputs à coleção de " << colecao_plural << endl;
    cout << "[+X] para adicionar input à coleção de " << colecao_plural << endl;
    cout << "Introduza [-X] ou " << colecao_sing << ": ";
    cin >> resp;
    if(resp >= 0){
        repetido = false;
        pertence = false;
        for(int i = 0; respostas.size() > i; i++){
            if(respostas[i] == resp){
                repetido = true;
                break;
            }
        }
        for(auto it = l.begin(); it != l.end(); it++){
            if((*it).ID() == resp){
                pertence = true;
                break;
            }
        }
        if(!repetido && pertence) respostas.push_back(resp);
    }
    while (cin.fail() || resp >= 0 || respostas.size() < lim){
        cin.clear();
        cin.ignore(1000, '\n');
        if(resp >= 0 && !pertence) cout << "Membro Inexistente! Insira um ID Válido para um membro que exista." << endl;
        if(resp < 0 && respostas.size() < lim) cout << "Coleção Insuficiente! Insira umais inputs até atingir o mínimo de " << lim << endl;
        cout << "[-X] para parar de introduzir mais inputs à coleção de " << colecao_plural << endl;
        cout << "[+X] para adicionar input à coleção de " << colecao_plural << endl;
        cout << "Introduza [-X] ou " << colecao_sing << ": ";
        cin >> resp;
        if(resp >= 0){
            repetido = false;
            pertence = false;
            for(int i = 0; respostas.size() > i; i++){
                if(respostas[i] == resp){
                    repetido = true;
                    break;
                }
            }
            for(auto it = l.begin(); it != l.end(); it++){
                if((*it).ID() == resp){
                    pertence = true;
                    break;
                }
            }
            if(!repetido && pertence) respostas.push_back(resp);
        }
    }
    return respostas;
}


template<class T>
T Menu::InputRestrito(string texto) {
    T resposta;
    cout << endl << texto;
    cin >> resposta;
    while (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << texto;
        cin >> resposta;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return resposta;
}

string Menu::InputNome(string texto) {
    string resposta;
    cout << endl << texto;
    getline(cin, resposta);
    while (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << texto;
        getline(cin, resposta);
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return resposta;
}

data Menu::InputData(string texto) {
    data resposta;
    int dia, mes, ano;
    bool mespr = false;
    vector <int> mesproibido;
    cout << endl << texto << endl << "Introduza o dia: ";
    cin >> dia;
    while (cin.fail() || dia < 1 || dia > 31){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << texto << endl << "Introduza o dia: ";
        cin >> dia;
    }
    if(dia > 28) mesproibido.push_back(2);
    if(dia > 30){
        mesproibido.push_back(4);
        mesproibido.push_back(6);
        mesproibido.push_back(9);
        mesproibido.push_back(11);
    }
    cout << endl << texto << endl << "Introduza o mês: ";
    cin >> mes;
    if(!cin.fail() && mes >= 1 && mes <= 12){
        for(int i = 0; mesproibido.size() > i; i++){
            if(mesproibido[i] == mes) {
                mespr = true;
                break;
            }
        }
    }
    while (cin.fail() || mes < 1 || mes > 12 || mespr){
        mespr = false;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << texto << endl << "Introduza o mês: ";
        cin >> mes;
        if(!cin.fail() && mes >= 1 && mes <= 12){
            for(int i = 0; mesproibido.size() > i; i++){
                if(mesproibido[i] == mes) {
                    mespr = true;
                    break;
                }
            }
        }
    }
    cout << endl << texto << endl << "Introduza o ano: ";
    cin >> ano;
    while (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << texto << endl << "Introduza o ano: ";
        cin >> ano;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    resposta = {.dia = dia, .mes = mes, .ano = ano};
    return resposta;
}

nota_avaliacao Menu::InputNota(string texto){
    int respint;
    nota_avaliacao resposta;
    vector<string> opcoes = {"Má" , "Insuficiente", "Razoável", "Boa", "Excelente"};
    ImprimeOp(opcoes, false, true);
    cout << texto;
    cin >> respint;
    while(cin.fail() || respint < 0 || respint > 4){
        cin.clear();
        cin.ignore(1000, '\n');
        ImprimeOp(opcoes, true, true);
        cout << texto;
        cin >> respint;
    }
    switch (respint){
        case 0:
            resposta = ma;
            break;
        case 1:
            resposta = insuficiente;
            break;
        case 2:
            resposta = razoavel;
            break;
        case 3:
            resposta = boa;
            break;
        case 4:
            resposta = excelente;
            break;
        default:
            resposta = razoavel;
            break;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return resposta;
}

tipo_cargo Menu::InputCargo(string texto) {
    int respint;
    tipo_cargo resposta;
    vector<string> opcoes = {"Normal" , "Receção", "Responsável", "Limpeza", "Gestor"};
    ImprimeOp(opcoes, false, true);
    cout << texto;
    cin >> respint;
    while(cin.fail() || respint < 0 || respint > 4){
        cin.clear();
        cin.ignore(1000, '\n');
        ImprimeOp(opcoes, true, true);
        cout << texto;
        cin >> respint;
    }
    switch (respint){
        case 0:
            resposta = naodef;
            break;
        case 1:
            resposta = frececao;
            break;
        case 2:
            resposta = fresponsavel;
            break;
        case 3:
            resposta = flimpeza;
            break;
        case 4:
            resposta = fgestor;
            break;
        default:
            resposta = naodef;
            break;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return resposta;
}

tipo_turno Menu::InputTurno(string texto) {
    int respint;
    tipo_turno resposta;
    vector<string> opcoes = {"Dia" , "Noite"};
    ImprimeOp(opcoes, false, true);
    cout << texto;
    cin >> respint;
    while(cin.fail() || respint < 0 || respint > 1){
        cin.clear();
        cin.ignore(1000, '\n');
        ImprimeOp(opcoes, true, true);
        cout << texto;
        cin >> respint;
    }
    switch (respint){
        case 0:
            resposta = dia;
            break;
        case 1:
            resposta = noite;
            break;
        default:
            resposta = dia;
            break;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return resposta;
}

tipo_produto Menu::InputTProd(string texto) {
    int respint;
    tipo_produto resposta;
    vector<string> opcoes = {"Restauração" , "Limpeza", "Souvenir"};
    ImprimeOp(opcoes, false, true);
    cout << texto;
    cin >> respint;
    while(cin.fail() || respint < 0 || respint > 2){
        cin.clear();
        cin.ignore(1000, '\n');
        ImprimeOp(opcoes, true, true);
        cout << texto;
        cin >> respint;
    }
    switch (respint){
        case 0:
            resposta = restauracao;
            break;
        case 1:
            resposta = limpeza;
            break;
        case 2:
            resposta = souvenir;
            break;
        default:
            resposta = souvenir;
            break;
    }
    cin.clear();
    cin.ignore(1000, '\n');
    return resposta;
}

tipo_quarto Menu::InputTQuarto(string texto) {
    int respint;
    tipo_quarto resposta;
    vector<string> opcoes = {"Sem Vista" , "Com Vista", "Suíte"};
    ImprimeOp(opcoes, false, true);
    cout << texto;
    cin >> respint;
    while(cin.fail() || respint < 0 || respint > 2){
        cin.clear();
        cin.ignore(1000, '\n');
        ImprimeOp(opcoes, true, true);
        cout << texto;
        cin >> respint;
    }
    switch (respint){
        case 0:
            resposta = sem_vista;
            break;
        case 1:
            resposta = com_vista;
            break;
        case 2:
            resposta = suite;
            break;
        default:
            resposta = sem_vista;
            break;
    }
    cin.clear();
    cin.ignore(1000, '\n');
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
    string titulo = "Importar";
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
    resposta = ProcessarInputInt(opcoes, titulo);
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
    string titulo = "Ver Informação";
    unsigned resposta, segresp;
    vector<string> opcoes = membros;
    opcoes.push_back("Hotel");
    for (int i = 0; opcoes.size() > i; i++) {
        opcoes[i] = "Ver Info " + opcoes[i];
    }
    opcoes.push_back("Voltar");
    resposta = ProcessarInputInt(opcoes, titulo);
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

void Menu::Adicionar() {
    unsigned resposta;
    string titulo = "Adicionar";
    vector <string> opcoes = {"Cliente", "Produto", "Quarto"};
    for(int i = 0; opcoes.size() > i; i++){
        opcoes[i] = "Adicionar " + opcoes[i];
    }
    opcoes.push_back("Voltar");
    resposta = ProcessarInputInt(opcoes, titulo);
    if(resposta == 0){
        int nif = InputRestrito<int>("Insira o NIF do Cliente: ");
        string nome = InputNome("Insira o nome do Cliente: ");
        bool usual = InputRestrito<bool>("Insira [1] se o Cliente for usual ou [0] caso não o seja: ");
        while(!H.AddCliente(Cliente(nome, nif, usual))){
            cout << "O Cliente que inseriu já existe!" << endl;
            InputRestrito<int>("Insira o NIF do Cliente");
            InputNome("Insira o nome do Cliente");
            InputRestrito<bool>("Insira [1] se o Cliente for usual ou [0] caso não o seja: ");
        }
        EfetuarProcura(nif, H.GetClientes()).Info();
        return Adicionar();
    }
    if(resposta == 1){
        int numero = InputRestrito<int>("Insira o Número do Produto: ");
        string nome = InputNome("Insira o nome do Produto: ");
        tipo_produto tp = InputTProd("Insira o Tipo do Produto: ");
        nota_avaliacao nav = InputNota("Insira a Qualidade do Produto: ");
        float preco = InputRestrito<float>("Insira o Preço do Produto: ");
        while(!H.AddProduto(Produto(nome, numero, tp, nav, preco))){
            cout << "O Produto que inseriu já existe!" << endl;
            numero = InputRestrito<int>("Insira o Número do Produto: ");
            nome = InputNome("Insira o nome do Produto: ");
            tp = InputTProd("Insira o Tipo do Produto: ");
            nav = InputNota("Insira a Qualidade do Produto: ");
            preco = InputRestrito<float>("Insira o Preço do Produto: ");
        }
        EfetuarProcura(numero, H.GetProdutos()).Info();
        return Adicionar();
    }
    if(resposta == 2){
        int numero = InputRestrito<int>("Insira o Número do Quarto: ");
        tipo_quarto tq = InputTQuarto("Insira o Tipo de Quarto: ");
        int piso = InputRestrito<int>("Insira o Piso do Quarto: ");
        int capacidade = InputRestrito<int>("Insira a Capacidade do Quarto: ");
        float preco = InputRestrito<float>("Insira o Preço do Quarto: ");
        while(!H.AddQuarto(Quarto(tq, piso, numero, capacidade, preco))){
            cout << "O Quarto que inseriu já existe!" << endl;
            numero = InputRestrito<int>("Insira o Número do Quarto: ");
            tq = InputTQuarto("Insira o Tipo de Quarto: ");
            piso = InputRestrito<int>("Insira o Piso do Quarto: ");
            capacidade = InputRestrito<int>("Insira a Capacidade do Quarto: ");
            preco = InputRestrito<float>("Insira o Preço do Quarto: ");
        }
        EfetuarProcura(numero, H.GetQuartos()).Info();
        return Adicionar();
    }
    if(resposta == 3) return Principal();
    return Adicionar();
}


void Menu::Apagar() {
    unsigned resposta;
    int id;
    string titulo = "Apagar", mensagem = "Insira o ID do membro que pretende apagar: ";
    vector <string> opcoes = {"Cliente", "Produto", "Quarto"};
    for(int i = 0; opcoes.size() > i; i++){
        opcoes[i] = "Apagar " + opcoes[i];
    }
    opcoes.push_back("Voltar");
    resposta = ProcessarInputInt(opcoes, titulo);
    if(resposta == 0){
        id = InputRestrito<int>(mensagem);
        H.ApagarCliente(id);
        PrintList(H.GetClientes());
        return Apagar();
    }
    if(resposta == 1){
        id = InputRestrito<int>(mensagem);
        H.ApagarProduto(id);
        PrintList(H.GetProdutos());
        return Apagar();
    }
    if(resposta == 2){
        id = InputRestrito<int>(mensagem);
        H.ApagarQuarto(id);
        PrintList(H.GetQuartos());
        return Apagar();
    }
    if(resposta == 3) return Principal();
    return Apagar();
}

void Menu::MReserva() {
    string titulo = "Reservar / Cancelar Reserva";
    unsigned resposta;
    vector <string> opcoes = {"Reservar", "Cancelar Reserva", "Voltar"};
    resposta = ProcessarInputInt(opcoes, titulo);
    if(resposta == 0){
        int nifcliente  = ProcessarInputProcura("Reservar", H.GetClientes());
        if(nifcliente < 0) return MReserva();
        else{
            int idnumero = InputRestrito<int>("Insira o ID da Reserva: ");
            data datai = InputData("Insira a Data de Início da Reserva: ");
            data dataf = InputData("Insira a Data de Fim da Reserva: ");
            int lugares = InputRestrito<int>("Insira o Número de Lugares Esperados: ");
            vector <int> nquartos = ProcessarIntIndef("o número do quarto a reservar", "Números de Quartos a Reservar", 1, H.GetQuartos());
            while(!H.Reservar(nifcliente, idnumero, datai, dataf, lugares, nquartos)){
                cout << "Impossível Realizar a Reserva pretendida" << endl;
                idnumero = InputRestrito<int>("Insira o ID da Reserva: ");
                datai = InputData("Insira a Data de Início da Reserva: ");
                dataf = InputData("Insira a Data de Fim da Reserva: ");
                lugares = InputRestrito<int>("Insira o Número de Lugares Esperados: ");
                nquartos = ProcessarIntIndef("o número do quarto a reservar", "Números de Quartos a Reservar", 1, H.GetQuartos());
            }
            PrintList(H.GetReservas());
            return MReserva();
        }
    }
    if (resposta == 1){
        int nifcliente  = ProcessarInputProcura("Reservar", H.GetClientes());
        if(nifcliente < 0) return MReserva();
        else{
            int idnumero = InputRestrito<int>("Insira o ID da Reserva: ");
            H.CancelarReserva(nifcliente, idnumero);
            PrintList(H.GetReservas());
            return MReserva();
        }
    }
    if (resposta == 2) return Principal();
    return MReserva();
}


void Menu::Principal() {
    unsigned resposta;
    string titulo = "Bem-vindo ao grande Hotel " + H.nome;
    vector <string> opcoes = {"Importar...", "Ver Informação...", "Adicionar Membro...", "Apagar Membro...", "Reservar / Cancelar Reserva", "Contratar / Despedir", "Check-in / Check-out", "Finanças", "Outros", "Exportar"};
    resposta = ProcessarInputInt(opcoes, titulo);
    switch (resposta){
        case 0:
            return Importar();
        case 1:
            return VerInfo();
        case 2:
            return Adicionar();
        case 3:
            return Apagar();
        case 4:
            return MReserva();
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
