#include "Cliente.h"

Cliente::Cliente(string nome, int nif) {
    nome = nome;
    nif = nif;
    cliente_usual = false;
    nohotel = false;
}

Cliente::Cliente(string nome, int nif, bool usual) {
    nome = nome;
    nif = nif;
    cliente_usual = usual;
    nohotel = false;
}

void Cliente::Info() const{
    cout << "<CLIENTE>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Nif: " << nif << " | ";
    if(cliente_usual) cout << "Cliente Usual";
    else cout << "Cliente Novo";
    cout << endl;
}

void Cliente::Reservar(vector <Quarto> quartos, int num, data di, data df, int lp, vector <int> numq) {
    int qsize = quartos.size(), nsize = numq.size();
    vector <Quarto *> vq;
    for (int a = 0; nsize > a; a++){
        for (int i = 0; qsize > i; i++){
            if(quartos[i].numero == numq[a]) vq.push_back(&quartos[i]);
        }
    }
    Reserva r(num, di, df, lp, vq);
    reservas_cliente.push_back(&r);
    sort(reservas_cliente.begin(), reservas_cliente.end(), Reserva::DataIcomp_Cr);
}

void Cliente::Reservar(Reserva reserva) {
    reservas_cliente.push_back(&reserva);
    sort(reservas_cliente.begin(), reservas_cliente.end(), Reserva::DataIcomp_Cr);
}