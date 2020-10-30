#include "Hotel.h"


// Inicializações
Hotel::Hotel(string n) {
    nome = n;
    cout << "Bem Vindo ao Grande Hotel " << nome << "!" << endl;
}

Produto::Produto(tipo_produto tp, avaliacao q, float p){
    tprod = tp;
    qualidade = q;
    preco = p;
}

Reserva::Reserva(data i, data f, int lp, vector <Quarto> q){
    data_inicio = i;
    data_fim = f;
    lugaresp = lp;
    quartos_res = q;
    int qsize = quartos_res.size();
    preco = 0;
    for (int i = 0; qsize > i; i++){
        preco += quartos_res[i].preco_base;
    }
}
Reserva::Reserva(data i, data f, int lp, vector<Quarto> q, bool v, bool pr) {
    vazia = v;
    primeiravez = pr;
    data_inicio = i;
    data_fim = f;
    lugaresp = lp;
    quartos_res = q;
    int qsize = quartos_res.size();
    preco = 0;
    for (int i = 0; qsize > i; i++){
        preco += quartos_res[i].preco_base;
    }
}

Cliente::Cliente(string na, int n) {
    nome = na;
    nif = n;
}

Quarto::Quarto(tipo_quarto tq, int p, int n, int c, float pb) {
    tquarto = tq;
    piso = p;
    numero = n;
    capacidade = c;
    preco_base = pb;
    promo = tquarto;
}

Funcionario::Funcionario(string na, int n, int as, float s) {
    nome = na;
    nif = n;
    anos_servico = as;
    salario = s;
}

Funcionario::Funcionario(string na, int n, int as, float s, string c) {
    nome = na;
    nif = n;
    anos_servico = as;
    salario = s;
    cargo = c;
}

F_Rececao::F_Rececao(string na, int n, int as, float s): Funcionario(na, n, as, s, "Receção") {}
F_Rececao::F_Rececao(string na, int n, int as, float s, string c): Funcionario(na, n, as, s, c) {}


F_Responsavel::F_Responsavel(string na, int n, int as, float s): F_Rececao(na, n, as, s, "Responsável") {}
F_Responsavel::F_Responsavel(string na, int n, int as, float s, vector<int> pr): F_Rececao(na, n, as, s, "Responsável") {
    pisos_resp = pr;
}

F_Limpeza::F_Limpeza(string na, int n, int as, float s, turno t): Funcionario(na, n, as, s, "Limpeza") {
    fturno = t;
}

F_Gestor::F_Gestor(string na, int n, int as, float s): Funcionario(na, n, as, s, "Gestor") {}

F_Gestor::F_Gestor(string na, int n, int as, float s, avaliacao av): Funcionario(na, n, as, s, "Gestor") {
    av_prestacao = av;
}


//Infos
void Produto::Info() {
    cout << "<PRODUTO>" << endl;
    cout << "Tipo de Produto: " << tprod << " | ";
    cout << "Preço: " << preco << " | ";
    cout << "Qualidade: " << qualidade;
    cout << endl;
}

void Reserva::Info() {
    cout << "<RESERVA>" << endl;
    cout << "Data de Início: " << data_inicio << " | ";
    cout << "Data de Fim: " << data_fim << " | ";
    cout << "Duração: " << duracao << " | ";
    cout << "Lugares Esperados: " << lugaresp;
    cout << endl;
}

void Cliente::Info() {
    cout << "<CLIENTE>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Nif: " << nif << " | ";
    if(cliente_usual) cout << "Cliente Usual";
    else cout << "Cliente Novo";
    cout << endl;
}

void Funcionario::Info() {
    string cargo_upper = cargo;
    transform(cargo_upper.begin(), cargo_upper.end(),cargo_upper.begin(), ::toupper);
    cout << "<FUNCIONÁRIO " << cargo_upper << ">" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Nif: " << nif << " | ";
    cout << "Anos de Serviço: " << anos_servico << " | ";
    cout << "Salário: " << salario;
    cout << endl;
}


// Hotel Database Add
bool Hotel::AddReserva(Reserva r) {
    int capacidadetotal = 0;
    int qsize = r.quartos_res.size();
    for (int i = 0; qsize > i; i++){
        capacidadetotal += r.quartos_res[i].capacidade;
    }
    if(r.lugaresp <= capacidadetotal && (r.data_fim - r.data_inicio > 0)) reservas.push_back(r);
    else{
        cout << endl << "Reserva Impossível" << endl;
        cout << "Razão: Lugares Esperados excedem a capacidade total dos Quartos selecionados!" << endl;
        return false;
    }
    return true;
}

void Hotel::AddQuartoOcupado(Reserva r) {
    quartos_ocupados.push_back(r);
}

void Hotel::AddEstadia(Reserva r) {
    estadias.push_back(r);
}

void Hotel::AddCliente(Cliente c) {
    clientes.push_back(c);
}

void Hotel::AddQuarto(Quarto q) {
    quartos.push_back(q);
}

void Hotel::AddFuncionario(Funcionario f) {
    funcionarios.push_back(f);
}

//  |Cliente Func|
void Cliente::Reservar(data di, data df, int lp, vector <Quarto> q) {
    Reserva r(di, df, lp, q);
    reserva_atual = &r;
}
//  |Cliente Func|

bool Hotel::ValidarReserva(Cliente c) {
    Reserva r = *c.reserva_atual;
    if (r.vazia == true && AddReserva(r)) {
        r.vazia = false;
        if (!c.cliente_usual) {
            AddCliente(c);
            r.primeiravez = true;
        }
        else r.primeiravez = false;
        return true;
    }
    else{
        cout << endl << "Reserva Inválida!!!" << endl;
        return false;
    }
}

void Hotel::CheckIn(Cliente c) {
    Reserva r = *c.reserva_atual;
    c.estadia_atual = &r;
    c.reserva_atual = NULL;
    c.nohotel = true;
    int rindex = FindIndex(reservas, r);
    reservas.erase(reservas.begin() + rindex);
    AddQuartoOcupado(r);
}

void Hotel::CheckOut(Cliente c) {
    Reserva r = *c.reserva_atual;
    c.estadias_anteriores.push_back(r);
    c.estadia_atual = NULL;
    AddEstadia(r);
    r.vazia = true;
    int rindex = FindIndex(reservas, r);
    quartos_ocupados.erase(reservas.begin() + rindex);
    c.nohotel = false;
}


// Gestor Funcs
void F_Gestor::Promocoes(vector<Quarto> quartos_promo) {
    int qsize = quartos_promo.size();
    for(int i = 0; qsize > i; i++){
        Quarto quarto = quartos_promo[i];
        quarto.preco_base *= float(float(100 - quarto.promo)/ 100);
    }
}

Produto F_Gestor::Escolher_Prod(vector<Produto> prods) {
    int prodsize = prods.size();
    Produto escolhido = prods[0];
    for (int i = 0; prodsize > i; i++){
        if(prods[i].preco < escolhido.preco) escolhido = prods[i];
        else if(prods[i].preco == escolhido.preco){
            if(prods[i].qualidade > escolhido.qualidade) escolhido = prods[i];
        }
    }
    return escolhido;
}


//Hotel Database Funcs
const vector<Funcionario> Hotel::Pesquisa_F_Salario(bool inverso) {
    vector <Funcionario> pesquisa_salario = funcionarios;
    if(inverso) sort(pesquisa_salario.begin(), pesquisa_salario.end(), Funcionario::Salariocomp_Decr);
    else sort(pesquisa_salario.begin(), pesquisa_salario.end(), Funcionario::Salariocomp_Cr);
    PrintV(pesquisa_salario);
    return pesquisa_salario;
}

const vector<Funcionario> Hotel::Pesquisa_F_Cargo() {
    vector <Funcionario> pesquisa_cargo = funcionarios;
    sort(pesquisa_cargo.begin(), pesquisa_cargo.end(), Funcionario::Cargocomp);
    PrintV(pesquisa_cargo);
    return pesquisa_cargo;
}

const vector<Reserva> Hotel::Pesquisa_Reservas_Duracao(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    vector <Reserva> pesquisa_duracao;
    int rsize = reservas.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (reservas[i].primeiravez) pesquisa_duracao.push_back(reservas[i]);
        }
    }
    else pesquisa_duracao = reservas;
    if(inverso) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Duracaocomp_Decr);
    else sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Duracaocomp_Cr);
    if(clientes_novos_primeiro) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const vector<Reserva> Hotel::Pesquisa_Reservas_Data(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    vector <Reserva> pesquisa_duracao;
    int rsize = reservas.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (reservas[i].primeiravez) pesquisa_duracao.push_back(reservas[i]);
        }
    }
    else pesquisa_duracao = reservas;
    if(inverso) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Datacomp_Decr);
    else sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Datacomp_Cr);
    if(clientes_novos_primeiro) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const vector<Reserva> Hotel::Pesquisa_Reservas_Preco(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    vector <Reserva> pesquisa_duracao;
    int rsize = reservas.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (reservas[i].primeiravez) pesquisa_duracao.push_back(reservas[i]);
        }
    }
    else pesquisa_duracao = reservas;
    if(inverso) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Precocomp_Decr);
    else sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Precocomp_Cr);
    if(clientes_novos_primeiro) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}


// Hotel Finances Functions

float Hotel::CustosTotais(float impostos, float despesasfixas) {
    int fsize = funcionarios.size();
    int psize = produtos.size();
    float salarios = 0;
    float preco_produtos = 0;
    for (int i = 0; fsize > i; i++){
        salarios += funcionarios[i].salario;
    }
    for (int i = 0; psize > i; i++){
        preco_produtos +=  produtos[i].preco;
    }
    return impostos + despesasfixas + preco_produtos + salarios;
}

float Hotel::RendimentosTotais(int mes, int ano) {
    data data_inicial = {.dia = 1, .mes = mes, .ano = ano};
    int diaf = 31, ndias = 0;
    if (mes == 2) diaf = 28;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) diaf = 30;
    data data_final = {.dia = diaf, .mes = mes, .ano = ano};
    vector<Reserva> reservas_totais = quartos_ocupados;
    int rsize = reservas.size();
    int estsize = estadias.size();
    //Search Alg!!!!!!!!!!!!!
    for (int i = 0; rsize > i; i++){


    }
}
