#include "Cliente.h"

Cliente::Cliente(string na, int n) {
    nome = na;
    nif = n;
}

void Cliente::Info() {
    cout << "<CLIENTE>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Nif: " << nif << " | ";
    if(cliente_usual) cout << "Cliente Usual";
    else cout << "Cliente Novo";
    cout << endl;
}

void Cliente::Reservar(int num, data di, data df, int lp, vector <Quarto> q) {
    Reserva r(num, di, df, lp, q);
    reservas_cliente.push_back(r);
    sort(reservas_cliente.begin(), reservas_cliente.end(), Reserva::DataIcomp_Cr);
}

void Cliente::Reservar(Reserva reserva) {
    reservas_cliente.push_back(reserva);
    sort(reservas_cliente.begin(), reservas_cliente.end(), Reserva::DataIcomp_Cr);
}