#include "Reserva.h"

Reserva::Reserva(int num, data i, data f, int lp, vector <Quarto> q){
    idnumero = num;
    data_inicio = i;
    data_fim = f;
    duracao = data_fim - data_inicio + 1;
    lugaresp = lp;
    quartos_res = q;
    int qsize = quartos_res.size();
    preco = 0;
    for (int i = 0; qsize > i; i++){
        preco += quartos_res[i].preco_base;
    }
}
Reserva::Reserva(int num, data i, data f, int lp, vector<Quarto> q, bool pr) {
    idnumero = num;
    primeiravez = pr;
    data_inicio = i;
    data_fim = f;
    duracao = data_fim - data_inicio + 1;
    lugaresp = lp;
    quartos_res = q;
    int qsize = quartos_res.size();
    preco = 0;
    for (int i = 0; qsize > i; i++){
        preco += quartos_res[i].preco_base;
    }
}

void Reserva::Info() {
    cout << "<RESERVA>" << endl;
    cout << "Número ID: " << idnumero << " | ";
    cout << "Data de Início: " << data_inicio << " | ";
    cout << "Data de Fim: " << data_fim << " | ";
    cout << "Duração: " << duracao << " | ";
    cout << "Lugares Esperados: " << lugaresp;
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