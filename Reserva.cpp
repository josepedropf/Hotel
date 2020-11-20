#include "Reserva.h"

Reserva::Reserva(int idnumero, data data_inicio, data data_fim, int lugaresp, vector <Quarto> quartos_res){
    this->idnumero = idnumero;
    this->data_inicio = data_inicio;
    this->data_fim = data_fim;
    duracao = data_fim - data_inicio + 1;
    this->lugaresp = lugaresp;
    this->quartos_res = quartos_res;
    int qsize = quartos_res.size();
    preco = 0;
    for (int i = 0; qsize > i; i++){
        preco += quartos_res[i].preco;
    }
}
Reserva::Reserva(int idnumero, data data_inicio, data data_fim, int lugaresp, vector <Quarto> quartos_res, bool primeiravez) {
    this->idnumero = idnumero;
    this->primeiravez = primeiravez;
    this->data_inicio = data_inicio;
    this->data_fim = data_fim;
    duracao = data_fim - data_inicio + 1;
    this->lugaresp = lugaresp;
    this->quartos_res = quartos_res;
    int qsize = quartos_res.size();
    preco = 0;
    for (int i = 0; qsize > i; i++){
        preco += quartos_res[i].preco;
    }
}

void Reserva::Info() const{
    cout << "<RESERVA>" << endl;
    cout << "Número ID: " << idnumero << " | ";
    cout << "Data de Início: " << data_inicio << " | ";
    cout << "Data de Fim: " << data_fim << " | ";
    cout << "Duração: " << duracao << " | ";
    cout << "Lugares Esperados: " << lugaresp << " | ";
    cout << "Quartos Reservados: ";
    int qsize = quartos_res.size();
    for(int i = 0; qsize > i; i++){
        cout << quartos_res[i].numero << " ";
    }
    cout << endl;
}

bool Reserva::operator==(const Reserva &r2) const {
    if(idnumero == r2.idnumero) return true;
    bool quartoscom = false;
    int q1size = quartos_res.size(), q2size = r2.quartos_res.size();
    for(int a = 0; q1size > a; a++){
        for(int b = 0; q2size > b; b++){
            if(quartos_res[a] == r2.quartos_res[b]){
                quartoscom = true;
                break;
            }
        }
    }
    if(!quartoscom) return false;
    return (data_inicio >= r2.data_inicio && data_inicio <= r2.data_fim) || (data_fim >= r2.data_inicio && data_fim <= r2.data_fim) || (data_inicio < r2.data_inicio && data_fim > r2.data_fim);
}