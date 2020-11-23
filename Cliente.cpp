#include "Cliente.h"

Cliente::Cliente(string nome, int nif) {
    this->nome = nome;
    this->nif = abs(nif);
    cliente_usual = false;
    nohotel = false;
    estadia_atual = NULL;
    conta = 0;
}

Cliente::Cliente(string nome, int nif, bool usual) {
    this->nome = nome;
    this->nif = abs(nif);
    cliente_usual = usual;
    nohotel = false;
    estadia_atual = NULL;
    conta = 0;
}

Cliente::Cliente(string nome, int nif, list <Reserva *> estadias_anteriores) {
    this->nome = nome;
    this->nif = abs(nif);
    this->estadias_anteriores = estadias_anteriores;
    cliente_usual = estadias_anteriores.size() > 0;
    estadia_atual = NULL;
    conta = 0;
}

void Cliente::Info() const{
    cout << "<CLIENTE>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Nif: " << nif << " | ";
    if(!estadias_anteriores.empty()){
        cout << "Estadias Anteriores do Cliente:";
        for(auto it = estadias_anteriores.begin(); it != estadias_anteriores.end(); it++){
            cout << " " << (*it)->idnumero;
        }
        cout << " | ";
    }
    if(!reservas_cliente.empty()){
        cout << "Reservas do Cliente:";
        for(auto it = reservas_cliente.begin(); it != reservas_cliente.end(); it++){
            cout << " " << (*it)->idnumero;
        }
        cout << " | ";
    }
    if(estadia_atual != NULL) cout << "Estadia Atual: " << estadia_atual->idnumero << " | ";
    if(cliente_usual) cout << "Cliente Usual";
    else cout << "Cliente Novo";
    cout << endl;
}


float Cliente::GetConta() {
    conta = 0;
    for(auto it = reservas_cliente.begin(); it != reservas_cliente.end(); it++){
        conta += (*it)->preco;
    }
    for(auto it = servicos_consumidos.begin(); it != servicos_consumidos.end(); it++){
        conta += (*it)->preco_consumidor;
    }
    return conta;
}
