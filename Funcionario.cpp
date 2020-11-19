#include "Funcionario.h"


Funcionario::Funcionario(string na, int n, int as, float s) {
    nome = na;
    nif = n;
    anos_servico = as;
    salario = s;
    cargo = naodef;
}

Funcionario::Funcionario(string na, int n, int as, float s, tipo_cargo c) {
    nome = na;
    nif = n;
    anos_servico = as;
    salario = s;
    cargo = c;
}

F_Rececao::F_Rececao(string na, int n, int as, float s): Funcionario(na, n, as, s, frececao) {}
F_Rececao::F_Rececao(string na, int n, int as, float s, tipo_cargo c): Funcionario(na, n, as, s, c) {}

F_Responsavel::F_Responsavel(string na, int n, int as, float s): F_Rececao(na, n, as, s, fresponsavel) {}
F_Responsavel::F_Responsavel(string na, int n, int as, float s, vector<int> pr): F_Rececao(na, n, as, s, fresponsavel) {
    pisos_resp = pr;
}

F_Limpeza::F_Limpeza(string na, int n, int as, float s, tipo_turno t): Funcionario(na, n, as, s, flimpeza) {
    fturno = t;
}

F_Gestor::F_Gestor(string na, int n, int as, float s): Funcionario(na, n, as, s, fgestor) {}
F_Gestor::F_Gestor(string na, int n, int as, float s, nota_avaliacao av): Funcionario(na, n, as, s, fgestor) {
    av_prestacao = av;
}


void Funcionario::Info() const{
    string scargo = "";
    switch(cargo){
        case naodef:
            break;
        case frececao:
            scargo = " RECEÇÃO";
            break;
        case fresponsavel:
            scargo = " RESPONSÁVEL";
            break;
        case flimpeza:
            scargo = " LIMPEZA";
            break;
        case fgestor:
            scargo = " GESTOR";
            break;
        default:
            break;
    }
    cout << "<FUNCIONÁRIO" << scargo << ">" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Nif: " << nif << " | ";
    cout << "Anos de Serviço: " << anos_servico << " | ";
    cout << "Salário: " << salario << endl;
}

void F_Rececao::Info() const {Funcionario::Info(); cout << endl;}
void F_Responsavel::Info() const {
    Funcionario::Info();
    string pisos = "";
    if(!pisos_resp.empty()){
        int prsize = pisos_resp.size();
        for(int i = 0; prsize > i; i++){
            pisos += " " + to_string(pisos_resp[i]);
        }
    }
    cout << " | Pisos da sua Responsabilidade: " << pisos;
    cout << endl;
}

void F_Limpeza::Info() const{
    Funcionario::Info();
    if(fturno == dia) cout << " | Turno: dia";
    else cout << " | Turno: noite";
    cout << endl;
}

void F_Gestor::Info() const{
    cout << " | Avaliação: " << av_prestacao;
    cout << endl;
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
