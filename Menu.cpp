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

void Menu::PrintPointerListCliente(list<Cliente *> pl) {
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
        if(localizacao.size() < 4 || localizacao.substr(localizacao.length() - 4) != ".txt") localizacao += ".txt";
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
    while (cin.fail() || resp >= 0 || respostas.size() < lim){
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
    cout << endl << "[-X] para parar de introduzir mais inputs à coleção de " << colecao_plural << endl;
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
        if(resp >= 0 && !pertence) cout << endl << "Membro Inexistente! Insira um ID Válido para um membro que exista." << endl;
        if(resp < 0 && respostas.size() < lim) cout << endl << "Coleção Insuficiente! Insira umais inputs até atingir o mínimo de " << lim << endl;
        cout << endl <<  "[-X] para parar de introduzir mais inputs à coleção de " << colecao_plural << endl;
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
    PrintList(l);
    cout << "[-X] Voltar" << endl;
    cout << "[-1] Ver Info" << endl;
    cout << "[+X] O ID do Elemento que Procura" << endl;
    cout << "Escolha: ";
    cin >> resposta;
    while(cin.fail() || resposta == -1 || (resposta >= 0 && !ProcuraValida(resposta, l))){
        cin.clear();
        cin.ignore(1000, '\n');
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
    cin.clear();
    cin.ignore(1000, '\n');
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
    cin.clear();
    cin.ignore(1000, '\n');
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
        PrintList(H.GetClientes());
        int nif = InputRestrito<int>("Insira o NIF do Cliente: ");
        string nome = InputNome("Insira o nome do Cliente: ");
        bool usual = InputRestrito<bool>("Insira [1] se o Cliente for usual ou [0] caso não o seja: ");
        while(!H.AddCliente(Cliente(nome, nif, usual))){
            PrintList(H.GetClientes());
            cout << "O Cliente que inseriu já existe!" << endl;
            InputRestrito<int>("Insira o NIF do Cliente");
            InputNome("Insira o nome do Cliente");
            InputRestrito<bool>("Insira [1] se o Cliente for usual ou [0] caso não o seja: ");
        }
        EfetuarProcura(nif, H.GetClientes()).Info();
        return Adicionar();
    }
    if(resposta == 1){
        PrintList(H.GetProdutos());
        int numero = InputRestrito<int>("Insira o Número do Produto: ");
        string nome = InputNome("Insira o nome do Produto: ");
        tipo_produto tp = InputTProd("Insira o Tipo do Produto: ");
        nota_avaliacao nav = InputNota("Insira a Qualidade do Produto: ");
        float preco = InputRestrito<float>("Insira o Preço do Produto: ");
        while(!H.AddProduto(Produto(nome, numero, tp, nav, preco))){
            PrintList(H.GetProdutos());
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
        PrintList(H.GetQuartos());
        int numero = InputRestrito<int>("Insira o Número do Quarto: ");
        tipo_quarto tq = InputTQuarto("Insira o Tipo de Quarto: ");
        int piso = InputRestrito<int>("Insira o Piso do Quarto: ");
        int capacidade = InputRestrito<int>("Insira a Capacidade do Quarto: ");
        float preco = InputRestrito<float>("Insira o Preço do Quarto: ");
        while(!H.AddQuarto(Quarto(tq, piso, numero, capacidade, preco))){
            PrintList(H.GetQuartos());
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
        PrintList(H.GetClientes());
        id = InputRestrito<int>(mensagem);
        H.ApagarCliente(id);
        PrintList(H.GetClientes());
        return Apagar();
    }
    if(resposta == 1){
        PrintList(H.GetProdutos());
        id = InputRestrito<int>(mensagem);
        H.ApagarProduto(id);
        PrintList(H.GetProdutos());
        return Apagar();
    }
    if(resposta == 2){
        PrintList(H.GetQuartos());
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
        PrintList(H.GetClientes());
        int nifcliente  = ProcessarInputProcura("Reservar", H.GetClientes());
        if(nifcliente < 0) return MReserva();
        else{
            EfetuarProcura(nifcliente, H.GetClientes()).Info();
            int idnumero = InputRestrito<int>("Insira o ID da Reserva: ");
            data datai = InputData("Insira a Data de Início da Reserva: ");
            data dataf = InputData("Insira a Data de Fim da Reserva: ");
            int lugares = InputRestrito<int>("Insira o Número de Lugares Esperados: ");
            PrintList(H.GetQuartos());
            vector <int> nquartos = ProcessarIntIndef("o número do quarto a reservar", "Números de Quartos a Reservar", 1, H.GetQuartos());
            while(!H.Reservar(nifcliente, idnumero, datai, dataf, lugares, nquartos)){
                cout << "Impossível Realizar a Reserva pretendida" << endl;
                EfetuarProcura(nifcliente, H.GetClientes()).Info();
                idnumero = InputRestrito<int>("Insira o ID da Reserva: ");
                datai = InputData("Insira a Data de Início da Reserva: ");
                dataf = InputData("Insira a Data de Fim da Reserva: ");
                lugares = InputRestrito<int>("Insira o Número de Lugares Esperados: ");
                PrintList(H.GetQuartos());
                nquartos = ProcessarIntIndef("o número do quarto a reservar", "Números de Quartos a Reservar", 1, H.GetQuartos());
            }
            PrintList(H.GetReservas());
            return MReserva();
        }
    }
    if (resposta == 1){
        PrintList(H.GetClientes());
        int nifcliente  = ProcessarInputProcura("Cancelar Reserva", H.GetClientes());
        if(nifcliente < 0) return MReserva();
        else{
            EfetuarProcura(nifcliente, H.GetClientes()).Info();
            int idnumero = InputRestrito<int>("Insira o ID da Reserva: ");
            H.CancelarReserva(nifcliente, idnumero);
            PrintList(H.GetReservas());
            return MReserva();
        }
    }
    if (resposta == 2) return Principal();
    return MReserva();
}

void Menu::MGerirFunc() {
    string titulo = "Gerir Funcionários";
    vector<string> opcoes = {"Contratar", "Selecionar Funcionário", "Voltar"};
    unsigned resposta;
    resposta = ProcessarInputInt(opcoes, titulo);
    if (resposta == 0) {
        int nif = InputRestrito<int>("Insira o NIF do Novo Funcionário: ");
        string nome = InputNome("Insira o nome do Novo Funcionário: ");
        bool escolhercargo = InputRestrito<bool>(
                "Insira [1] se quiser esolher um cargo específico ou [0] se quiser que este seja escolhido automaticamente de acordo com as necessidades atuais do Hotel: ");
        if (escolhercargo) {
            tipo_cargo cargo = InputCargo("Escolha o cargo que o novo funcionário irá exercer: ");
            H.Contratar(nome, nif, cargo);
        }
        else H.Contratar(nome, nif);
        bool escolhersalario = InputRestrito<bool>(
                "Deseja atribuir um salário diferente ao Novo Funcionário [1 = sim | 0 = não]: ");
        if (escolhersalario) {
            float salario = InputRestrito<float>("Insere o salário a ser atribuido ao Novo Funcionário: ");
            H.SetSalario(nif, salario);
        }
        PrintList(H.GetFuncionarios());
        return MGerirFunc();
    }
    if (resposta == 1){
        int idfunc = ProcessarInputProcura("Selecionar Funcionário", H.GetFuncionarios());
        if(idfunc == -1) return MGerirFunc();
        vector<string> topcoes = {"Despedir", "Definir Salário", "Aumentar um Ano de Serviço", "Voltar", "Voltar ao Menu Principal"};
        unsigned tresposta = ProcessarInputInt(topcoes, EfetuarProcura(idfunc, H.GetFuncionarios()).nome);
        if(tresposta == 3) return MGerirFunc();
        if(tresposta > 3) return Principal();
        if(tresposta == 0) H.Despedir(idfunc);
        if(tresposta == 1){
            float salario = InputRestrito<float>("Insere o salário a ser atribuido ao Funcionário Selecionado: ");
            H.SetSalario(idfunc, salario);
        }
        if(tresposta == 2) H.AddAnoServico(idfunc);
        PrintList(H.GetFuncionarios());
        return MGerirFunc();
    }
    if (resposta == 2) return Principal();
    return MGerirFunc();
}

void Menu::Checks() {
    string titulo = "Check-In / Check-Out";
    vector<string> opcoes = {"Check-In", "Check-Out", "Voltar"};
    unsigned resposta = ProcessarInputInt(opcoes, titulo);
    if (resposta == 0) {
        PrintList(H.GetClientes());
        int idc = ProcessarInputProcura("Check-In", H.GetClientes());
        if (idc == -1) return Checks();
        else H.CheckIn(idc);
        PrintList(H.GetClientes());
        PrintList(H.GetReservas());
        return Checks();
    }
    if (resposta == 1) {
        if (H.GetClientesnoHotel().empty()) {
            cout << endl << "Não há clientes no hotel, por isso não é possível fazer nenhum Check-Out!" << endl;
        }
        else {
            list<Cliente *> lc = H.GetClientesnoHotel();
            PrintPointerListCliente(lc);
            bool valida = false;
            int nifcliente;
            cout << endl << "Insere o NIF do cliente que pretende fazer Check-Out: ";
            cin >> nifcliente;
            if (!cin.fail()) {
                for (auto it = lc.begin(); it != lc.end(); it++) {
                    if ((*it)->nif == nifcliente) {
                        valida = true;
                        break;
                    }
                }
            }
            while (cin.fail() || !valida) {
                valida = false;
                PrintPointerListCliente(lc);
                cout << endl << "Input inválido. Tem de ser um NIF de um cliente que estaja no Hotel.";
                cout << endl << "Insere o NIF do cliente que pretende fazer Check-Out: ";
                cin >> nifcliente;
                if (!cin.fail()) {
                    for (auto it = lc.begin(); it != lc.end(); it++) {
                        if ((*it)->nif == nifcliente) {
                            valida = true;
                            break;
                        }
                    }
                }
            }
            H.CheckOut(nifcliente);
            PrintList(H.GetClientes());
            PrintList(H.GetReservas());
        }
        return Checks();
    }
    if (resposta == 2) return Principal();
    return Checks();
}

void Menu::FinancasSelect() {
    string titulo = "Finanças";
    ImprimeTit(titulo);
    int mes, ano;
    cout << endl << "Insira o mês que pretende analisar: ";
    cin >> mes;
    while (cin.fail() || mes < 1 || mes > 12){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Insira o mês que pretende analisar: ";
        cin >> mes;
    }
    cout << endl << "Insira o ano que pretende analisar: ";
    cin >> ano;
    while (cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl << "Insira o ano que pretende analisar: ";
        cin >> ano;
    }
    return Financas(mes, ano);
}

void Menu::Financas(int mes, int ano) {
    string titulo = "Finanças " + to_string(mes) + "-" + to_string(ano);
    vector<string> opcoes = {"Custos", "Rendimentos", "Balanço", "Voltar", "Voltar ao Menu Principal"};
    unsigned resposta = ProcessarInputInt(opcoes, titulo);
    if (resposta == 0) {
        float impostos = InputRestrito<float>("Insira o custo mensal dos impostos: ");
        float despesas = InputRestrito<float>("Insira o total gasto em Despesas Fixas (água, eletricidade...) pelo Hotel mensalmente: ");
        cout << endl << "FOLHA SALARIAL" << endl;
        for (auto it = H.GetFuncionarios().begin(); it != H.GetFuncionarios().end(); it++) {
            cout << endl << (*it).nome << " ---> Salário: " << (*it).salario;
        }
        cout << endl << endl << "STOCK" << endl;
        for (auto it = H.GetProdutos().begin(); it != H.GetProdutos().end(); it++) {
            cout << endl << (*it).nome << " ---> Preço: " << (*it).preco;
        }
        cout << endl << endl << "CUSTOS NO MÊS " << mes << "-" << ano << " :  " << H.CustosTotais(impostos, despesas);
        return Financas(mes, ano);
    }
    if (resposta == 1) {
        list <Servico *> sf = H.Servicos_Fin(mes, ano);
        list <Reserva *> rf = H.Reservas_Fin(mes, ano);
        if(!sf.empty()){
            cout << endl << "LUCRO SERVIÇOS PRESTADOS ESTE MÊS" << endl;
            for (auto it = sf.begin(); it != sf.end(); it++) {
                cout << endl << (*it)->nome << " ---> Lucro para o Hotel: " << (*it)->lucro;
            }
        }
        if(!rf.empty()){
            cout << endl << endl << "RESERVAS FEITAS (parcial ou totalmente) PARA ESTE MÊS" << endl;
            for (auto it = rf.begin(); it != rf.end(); it++) {
                cout << endl << (*it)->idnumero << "---> Preço/dia: " << (*it)->preco;
            }
        }
        cout << endl << endl << "RENDIMENTOS NO MÊS " << mes << "-" << ano << " :  " << H.RendimentosTotais(mes, ano);
        return Financas(mes, ano);
    }
    if (resposta == 2){
        float impostos = InputRestrito<float>("Insira o custo mensal dos impostos: ");
        float despesas = InputRestrito<float>("Insira o total gasto em Despesas Fixas (água, eletricidade...) pelo Hotel mensalmente: ");
        cout << endl << "CUSTOS NO MÊS " << mes << "-" << ano << " :  " << H.CustosTotais(impostos, despesas);
        cout << endl << "RENDIMENTOS NO MÊS " << mes << "-" << ano << " :  " << H.RendimentosTotais(mes, ano);
        cout << endl << endl << "BALANÇO FINANCEIRO NO MÊS " << mes << "-" << ano << " :  " << H.BalancoFin(mes, ano, impostos, despesas);
        return Financas(mes, ano);
    }
    if(resposta == 3) return FinancasSelect();
    if(resposta > 3) return Principal();
    return Financas(mes, ano);
}

void Menu::Outros() {
    string titulo = "Outros";
    vector<string> opcoes = {"Prestar Serviço", "Promoções", "Escolher Produto", "Fazer Pesquisas", "Voltar"};
    unsigned resposta = ProcessarInputInt(opcoes, titulo);
    if (resposta == 0){
        int nifcliente = ProcessarInputProcura("Prestar Serviço", H.GetClientes());
        if (nifcliente == -1) return Outros();
        bool done = false;
        float margemlucro;
        string nome = InputNome("Insira o nome do Serviço: ");
        int sid = InputRestrito<int>("Insira o número do Serviço: ");
        data dr = InputData("Insira a data de realização do Serviço: ");
        float taxa = InputRestrito<float>("Insira a taxa aplicada ao Serviço: ");
        PrintList(H.GetFuncionarios());
        vector<int> fnum = ProcessarIntIndef("NIF de Funcionário Ocupado", "NIFS de Funcionários Ocupados", 0, H.GetFuncionarios());
        PrintList(H.GetProdutos());
        vector<int> pnum = ProcessarIntIndef("Número do Produto Consumido", "Números dos Produtos Consumidos", 0, H.GetProdutos());
        if (!pnum.empty()) margemlucro = InputRestrito<float>("Insira a margem de lucro do Hotel sobre os Produtos (em %): ");
        if (!fnum.empty()){
            if(!pnum.empty()) done = H.PrestarServico(nifcliente, nome, sid, dr, taxa, fnum, pnum, margemlucro);
            else done = H.PrestarServico(nifcliente, nome, sid, dr, taxa, fnum);
        }
        else{
            if(!pnum.empty()) done = H.PrestarServico(nifcliente, nome, sid, dr, taxa, pnum, margemlucro);
            else done = H.PrestarServico(nifcliente, nome, sid, dr, taxa);
        }
        while(!done){
            cout << endl << "Serviço Impossível de prestar, porque já existe!" << endl;
            fnum.clear();
            pnum.clear();
            nome = InputNome("Insira o nome do Serviço: ");
            sid = InputRestrito<int>("Insira o número do Serviço: ");
            dr = InputData("Insira a data de realização do Serviço: ");
            taxa = InputRestrito<float>("Insira a taxa aplicada ao Serviço: ");
            PrintList(H.GetFuncionarios());
            fnum = ProcessarIntIndef("NIF de Funcionário Ocupado", "NIFS de Funcionários Ocupados", 0, H.GetFuncionarios());
            PrintList(H.GetProdutos());
            pnum = ProcessarIntIndef("Número do Produto Consumido", "Números dos Produtos Consumidos", 0, H.GetProdutos());
            if (!pnum.empty()) margemlucro = InputRestrito<float>("Insira a margem de lucro do Hotel sobre os Produtos (em %): ");
            if (!fnum.empty()){
                if(!pnum.empty()) done = H.PrestarServico(nifcliente, nome, sid, dr, taxa, fnum, pnum, margemlucro);
                else done = H.PrestarServico(nifcliente, nome, sid, dr, taxa, fnum);
            }
            else{
                if(!pnum.empty()) done = H.PrestarServico(nifcliente, nome, sid, dr, taxa, pnum, margemlucro);
                else done = H.PrestarServico(nifcliente, nome, sid, dr, taxa);
            }
        }
        PrintList(H.GetClientes());
        PrintList(H.GetServicos());
        return Outros();
    }
    if (resposta == 1){
        if (H.GetFuncionariosGestores().empty()){
            cout << endl << "Não há Funcionários Gestores para realizarem a Promoção!" << endl;
            return Outros();
        }
        if (H.GetQuartos().empty()){
            cout << endl << "Não há Quartos a incluir na Promoção!" << endl;
            return Outros();
        }
        int fid = ProcessarInputProcura("Promoção", H.GetFuncionariosGestores());
        if (fid == -1) return Outros();
        vector<int> nquartos = ProcessarIntIndef("Número do Quarto a incluir na Promoção", "Números dos Quartos a incluir na Promoção", 1, H.GetQuartos());
        H.Promocoes(EfetuarProcura(fid, H.GetFuncionariosGestores()), nquartos);
        PrintList(H.GetQuartos());
        return Outros();
    }
    if (resposta == 2){
        if (H.GetFuncionariosGestores().empty()){
            cout << endl << "Não há Funcionários Gestores para escolherem o Produto!" << endl;
            return Outros();
        }
        if (H.GetProdutos().empty()){
            cout << endl << "Não há Produtos para escolher!" << endl;
            return Outros();
        }
        int fid = ProcessarInputProcura("Escolha do Melhor Produto", H.GetFuncionariosGestores());
        if (fid == -1) return Outros();
        vector<int> nprod = ProcessarIntIndef("Número do Produto a incluir na lista", "Números dos Produtos a incluir na lista", 1, H.GetProdutos());
        cout << endl << "Produto Escolhido: " << endl;
        (H.EscolherProduto(EfetuarProcura(fid, H.GetFuncionariosGestores()), nprod)).Info();
        return Outros();
    }
    if (resposta == 3){
        vector<string> topcoes = {"Quartos", "Funcionários", "Reservas", "Voltar", "Voltar ao Menu Principal"};
        unsigned membro_ordenar = ProcessarInputInt(topcoes, "Pesquisas");
        unsigned criterio;
        if (membro_ordenar == 4) return Outros();
        if (membro_ordenar > 4) return Principal();
        if (membro_ordenar == 0){
            vector<string> q_opcoes = {"Número Crescente", "Número Decrescente", "Preço Crescente", "Preço Decrescente", "Voltar", "Voltar ao Menu Principal"};
            criterio = ProcessarInputInt(q_opcoes, "Pesquisa Quartos");
            if (criterio == 4) return Outros();
            if (criterio > 4) return Principal();
            list <Quarto> lq = H.GetQuartos();
            if (criterio == 0){
                lq.sort(Quarto::Numcomp_Cr);
            }
            if (criterio == 1){
                lq.sort(Quarto::Numcomp_Decr);
            }
            if (criterio == 2){
                lq.sort(Quarto::Preco_Cr);
            }
            if (criterio == 3){
                lq.sort(Quarto::Preco_Decr);
            }
            PrintList(lq);
            return Outros();
        }
        if (membro_ordenar == 1){
            vector<string> f_opcoes = {"Cargo", "Salário Crescente", "Salário Decrescente", "Voltar", "Voltar ao Menu Principal"};
            criterio = ProcessarInputInt(f_opcoes, "Pesquisa Funcionários");
            if (criterio == 3) return Outros();
            if (criterio > 3) return Principal();
            list <Funcionario> lf = H.GetFuncionarios();
            if (criterio == 0){
                lf.sort(Funcionario::Cargocomp);
            }
            if (criterio == 1){
                lf.sort(Funcionario::Salariocomp_Cr);
            }
            if (criterio == 2){
                lf.sort(Funcionario::Salariocomp_Decr);
            }
            PrintList(lf);
            return Outros();
        }
        if (membro_ordenar == 2){
            vector<string> r_opcoes = {"Primeira Vez", "Preço Crescente", "Preço Decrescente", "Duração Crescente", "Duração Decrescente", "Data Inicial Crescente", "Data Inicial Decrescente", "Data Final Crescente", "Data Final Decrescente", "Voltar", "Voltar ao Menu Principal"};
            criterio = ProcessarInputInt(r_opcoes, "Pesquisa Reservas");
            if (criterio == 9) return Outros();
            if (criterio > 9) return Principal();
            list <Reserva> lr = H.GetReservas();
            if (criterio == 0){
                lr.sort(Reserva::PrimeiraReserva);
            }
            if (criterio == 1){
                lr.sort(Reserva::Precocomp_Cr);
            }
            if (criterio == 2){
                lr.sort(Reserva::Precocomp_Decr);
            }
            if (criterio == 3){
                lr.sort(Reserva::Duracaocomp_Cr);
            }
            if (criterio == 4){
                lr.sort(Reserva::Duracaocomp_Decr);
            }
            if (criterio == 5){
                lr.sort(Reserva::DataIcomp_Cr);
            }
            if (criterio == 6){
                lr.sort(Reserva::DataIcomp_Decr);
            }
            if (criterio == 7){
                lr.sort(Reserva::DataFcomp_Cr);
            }
            if (criterio == 8){
                lr.sort(Reserva::DataFcomp_Decr);
            }
            PrintList(lr);
            return Outros();
        }
    }
    if (resposta > 3) return Principal();
    return Outros();
}

void Menu::Exportar() {
    string localizacao, titulo = "Exportar Hotel";
    ImprimeTit(titulo);
    cout << endl << "Introduza a Localização do Ficheiro par onde quer Exportar o Hotel: ";
    cin >> localizacao;
    H.EscreverHotel(localizacao);
    return Principal();
}

void Menu::Principal() {
    unsigned resposta;
    string titulo = "Bem-vindo ao grande Hotel " + H.nome;
    vector <string> opcoes = {"Importar...", "Ver Informação...", "Adicionar Membro...", "Apagar Membro...", "Reservar / Cancelar Reserva", "Gerir Funcionários", "Check-in / Check-out", "Finanças", "Outros", "Exportar", "Sair"};
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
            return MGerirFunc();
        case 6:
            return Checks();
        case 7:
            return FinancasSelect();
        case 8:
            return Outros();
        case 9:
            return Exportar();
        case 10:
            cout << endl << "THE END" << endl;
            return;
        default:
            return Principal();
    }
    return Principal();
}
