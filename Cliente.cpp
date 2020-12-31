#include "Cliente.h"

/**
 * Construtor da classe Cliente
 * @param nome nome do Cliente
 * @param nif nif do Cliente
 */
Cliente::Cliente(string nome, int nif) {
    this->nome = nome;
    this->nif = abs(nif);
    cliente_usual = false;
    nohotel = false;
    estadia_atual = NULL;
    conta = 0;
    promo = 0;
}

/**
 * Construtor da classe Cliente
 * @param nome nome do Cliente
 * @param nif nif do Cliente
 * @param usual verdadeiro se o Cliente já tiver estado pelo menos uma vez no Hotel
 */
Cliente::Cliente(string nome, int nif, bool usual) {
    this->nome = nome;
    this->nif = abs(nif);
    cliente_usual = usual;
    nohotel = false;
    estadia_atual = NULL;
    conta = 0;
    promo = 0;
}

/**
 * Construtor da classe Cliente
 * @param nome nome do Cliente
 * @param nif nif do Cliente
 * @param estadias_anteriores lista de apontadores para Reservas que representam estadias anteriores do Cliente
 */
Cliente::Cliente(string nome, int nif, list <Reserva *> estadias_anteriores) {
    this->nome = nome;
    this->nif = abs(nif);
    this->estadias_anteriores = estadias_anteriores;
    cliente_usual = estadias_anteriores.size() > 0;
    estadia_atual = NULL;
    conta = 0;
    promo = 0;
}

/**
 * Imprime as Informações do Cliente
 */
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

/**
 * Calcula e devolve a conta do Cliente, que é um atriibuto privado
 * @return o valor da conta do Cliente em questão
 */
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
