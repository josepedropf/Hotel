#include "Funcionario.h"


Funcionario::Funcionario(string nome, int nif, int anos_servico, float salario) {
    this->nome = nome;
    this->nif = nif;
    this->anos_servico = anos_servico;
    this->salario = salario;
    cargo = naodef;
}

Funcionario::Funcionario(string nome, int nif, int anos_servico, float salario, tipo_cargo c) {
    this->nome = nome;
    this->nif = nif;
    this->anos_servico = anos_servico;
    this->salario = salario;
    cargo = c;
}

F_Rececao::F_Rececao(string nome, int nif, int anos_servico, float salario): Funcionario(nome, nif, anos_servico, salario, frececao) {}
F_Rececao::F_Rececao(string nome, int nif, int anos_servico, float salario, tipo_cargo c): Funcionario(nome, nif, anos_servico, salario, c) {}

F_Responsavel::F_Responsavel(string nome, int nif, int anos_servico, float salario): F_Rececao(nome, nif, anos_servico, salario, fresponsavel) {}
F_Responsavel::F_Responsavel(string nome, int nif, int anos_servico, float salario, vector<int> pisos_resp): F_Rececao(nome, nif, anos_servico, salario, fresponsavel) {
    this->pisos_resp = pisos_resp;
}

F_Limpeza::F_Limpeza(string nome, int nif, int anos_servico, float salario, tipo_turno turno): Funcionario(nome, nif, anos_servico, salario, flimpeza) {
    this->turno = turno;
}

F_Gestor::F_Gestor(string nome, int nif, int anos_servico, float salario): Funcionario(nome, nif, anos_servico, salario, fgestor) {}
F_Gestor::F_Gestor(string nome, int nif, int anos_servico, float salario, nota_avaliacao av_prestacao): Funcionario(nome, nif, anos_servico, salario, fgestor) {
    this->av_prestacao = av_prestacao;
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
    if(turno == dia) cout << " | Turno: dia";
    else cout << " | Turno: noite";
    cout << endl;
}

void F_Gestor::Info() const{
    cout << " | Avaliação: " << av_prestacao;
    cout << endl;
}

// Gestor Funcs
void F_Gestor::Promocoes(vector<Quarto> &quartos_promo) {
    int qsize = quartos_promo.size();
    for(int i = 0; qsize > i; i++){
        Quarto quarto = quartos_promo[i];
        quarto.preco *= float(float(100 - quarto.promo)/ 100);
    }
}

Produto F_Gestor::Escolher_Prod(vector<Produto *> prods) {
    int prodsize = prods.size();
    Produto escolhido = *prods[0];
    for (int i = 0; prodsize > i; i++){
        if(prods[i]->preco < escolhido.preco) escolhido = *prods[i];
        else if(prods[i]->preco == escolhido.preco){
            if(prods[i]->qualidade > escolhido.qualidade) escolhido = *prods[i];
        }
    }
    return escolhido;
}
