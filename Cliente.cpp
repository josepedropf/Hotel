#include "Cliente.h"

Cliente::Cliente(string nome, int nif) {
    this->nome = nome;
    this->nif = nif;
    cliente_usual = false;
    nohotel = false;
    estadia_atual = NULL;
    conta = 0;
}

Cliente::Cliente(string nome, int nif, bool usual) {
    this->nome = nome;
    this->nif = nif;
    cliente_usual = usual;
    nohotel = false;
    estadia_atual = NULL;
    conta = 0;
}

Cliente::Cliente(string nome, int nif, vector<Reserva> estadias_anteriores) {
    this->nome = nome;
    this->nif = nif;
    this->estadias_anteriores = estadias_anteriores;
    cliente_usual = estadias_anteriores.size() > 0;
    estadia_atual = NULL;
    conta = 0;
}

void Cliente::Info() const{
    cout << "<CLIENTE>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Nif: " << nif << " | ";
    if(cliente_usual) cout << "Cliente Usual";
    else cout << "Cliente Novo";
    cout << endl;
}


float Cliente::GetConta() {
    conta = 0;
    int rsize = reservas_cliente.size();
    for(int i = 0; rsize > i; i++){
        conta += reservas_cliente[i].preco;
    }
    return conta;
}
