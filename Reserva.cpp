#include "Reserva.h"

Reserva::Reserva(int idnumero, data data_inicio, data data_fim, int lugaresp, list <Quarto *> quartos_res){
    this->idnumero = abs(idnumero);
    this->data_inicio = data_inicio;
    this->data_fim = data_fim;
    duracao = data_fim - data_inicio + 1;
    this->lugaresp = lugaresp;
    this->quartos_res = quartos_res;
    int qsize = quartos_res.size();
    preco = 0;
    for (auto it = quartos_res.begin(); it != quartos_res.end(); it++){
        preco += (*it)->preco;
    }
}
Reserva::Reserva(int idnumero, data data_inicio, data data_fim, int lugaresp, list <Quarto *> quartos_res, bool primeiravez) {
    this->idnumero = abs(idnumero);
    this->primeiravez = primeiravez;
    this->data_inicio = data_inicio;
    this->data_fim = data_fim;
    duracao = data_fim - data_inicio + 1;
    this->lugaresp = lugaresp;
    this->quartos_res = quartos_res;
    int qsize = quartos_res.size();
    preco = 0;
    for (auto it = quartos_res.begin(); it != quartos_res.end(); it++){
        preco += (*it)->preco;
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
    for(auto it = quartos_res.begin(); it != quartos_res.end(); it++){
        cout << (*it)->numero << " ";
    }
    cout << endl;
}

bool Reserva::operator==(const Reserva &r2) const {
    if(idnumero == r2.idnumero) return true;
    bool quartoscom = false;
    for(auto it = quartos_res.begin(); it != quartos_res.end(); it++){
        for(auto itt = r2.quartos_res.begin(); itt != r2.quartos_res.end(); itt++){
            if((*it) == (*itt)){
                quartoscom = true;
                break;
            }
        }
    }
    if(!quartoscom) return false;
    return (data_inicio >= r2.data_inicio && data_inicio <= r2.data_fim) || (data_fim >= r2.data_inicio && data_fim <= r2.data_fim) || (data_inicio < r2.data_inicio && data_fim > r2.data_fim);
}