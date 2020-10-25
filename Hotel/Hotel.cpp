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

Reserva::Reserva(data i, data f, int lp){
    data_inicio = i;
    data_fim = f;
    lugaresp = lp;
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
    //cout << "Tipo de Quarto: " << tquarto << endl << "Promo: " << promo << endl;
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
    cout << "Lugares Esperados: " << lugaresp;
    cout << endl;
}

void Cliente::Info() {
    cout << "<CLIENTE>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Nif: " << nif << " | ";
    if(Cliente_Usual()) cout << "Cliente Usual";
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
template <class T>
void Hotel::PrintV(vector<T> v) {
    int vsize = v.size();
    cout << endl << "PRINT" << endl;
    cout << "|||-> " << endl;
    for (int i = 0; vsize > i; i++){
        v[i].Info();
        cout << endl;
    }
    cout << "<-||| " << endl;
}

void Hotel::AddReserva(Reserva r) {
    reservas.push_back(r);
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
