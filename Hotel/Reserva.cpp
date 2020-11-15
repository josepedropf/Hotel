#include "Reserva.h"

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

void Reserva::Info() {
    cout << "<RESERVA>" << endl;
    cout << "Data de Início: " << data_inicio << " | ";
    cout << "Data de Fim: " << data_fim << " | ";
    cout << "Duração: " << duracao << " | ";
    cout << "Lugares Esperados: " << lugaresp;
    cout << endl;
}