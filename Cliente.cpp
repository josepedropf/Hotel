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
    reserva_atual = &r;
}