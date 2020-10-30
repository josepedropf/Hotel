#include <iostream>
#include "Hotel.h"


using namespace std;

int main() {
    Hotel H("da Marateca");

    Quarto Q205(suite, 2, 205, 3, 55.67);
    Quarto Q100(sem_vista, 1, 100, 2, 34.21);
    Quarto Q317(com_vista, 3, 317, 4, 44);

    Reserva R1({.dia = 20, .mes = 5, .ano= 2019}, {.dia = 25, .mes = 6, .ano= 2019}, 4, {Q317}, false, true);
    Reserva R2({.dia = 20, .mes = 5, .ano= 2019}, {.dia = 1, .mes = 7, .ano= 2021}, 8, {Q205, Q100});
    Reserva R3({.dia = 20, .mes = 5, .ano= 2019}, {.dia = 1, .mes = 7, .ano= 2019}, 8, {Q100, Q205, Q317});

    F_Rececao Alfredo("Alfredo", 123456798, 5, 832.78);
    F_Rececao Maria("Maria", 123256798, 3, 750.78);
    F_Rececao Antonio("António", 182886798, 8, 900);
    F_Responsavel Manuel("Manuel", 123555598, 2, 1005.12);
    F_Responsavel Tito("Tito", 123555598, 2, 1005.12, vector <int> {1, 3});
    F_Responsavel Carlota("Carlota Madeira", 696969696, 1, 500.01, vector <int> {2});
    F_Limpeza Fred("Fred", 420420420, 2, 100000.99, noite);
    F_Limpeza Duarte("Duarte", 420420420, 2, 100000.99, dia);
    F_Limpeza Tina("Tina", 420441990, 10, 100, noite);
    F_Gestor Ze("Zé", 999999999, 20, 999999.99, excelente);
    F_Gestor Marta("Marta", 999999779, 2, 999.99);
    F_Gestor Erica("Érica", 991234999, 12, 5000.50, razoavel);

    data d1 = {.dia = 20, .mes = 5, .ano= 2019};
    data d2 = {.dia = 21, .mes = 5, .ano= 2019};
    data d3 = {.dia = 2, .mes = 1, .ano= 2020};
    data d4 = {.dia = 21, .mes = 6, .ano= 2019};
    data d5 = {.dia = 21, .mes = 6, .ano= 2019};
    data d6 = {.dia = 21, .mes = 6, .ano= 2020};


    /*
    cout << endl << "d2-d1 = 1  " << d2-d1 << endl;
    if(d2>d1) cout << endl << "d2>d1 = true" << endl;
    else cout << endl << "Wrong" << endl;
    cout << endl << "d6-d5 = 365  " << d6-d5 << endl;
    if(d4<d3) cout << endl << "d4<d3 = true" << endl;
    else cout << endl << "Wrong" << endl;
    if(d4==d5) cout << endl << "d4==d5 = true" << endl;
    else cout << endl << "Wrong" << endl;
    cout << endl << "d6-d1 = 396  " << d6-d1 << endl;
    cout << endl << "d1-d6 = -396  " << d1-d6 << endl;
    */


    H.AddReserva(R1);
    H.AddReserva(R2);
    H.AddReserva(R3);
    vector<Reserva> r = H.GetReservas();
    H.PrintV(r);

    H.AddFuncionario(Ze);
    H.AddFuncionario(Duarte);
    H.AddFuncionario(Antonio);
    H.AddFuncionario(Manuel);
    H.AddFuncionario(Tito);
    H.AddFuncionario(Carlota);
    H.AddFuncionario(Fred);
    H.AddFuncionario(Alfredo);
    H.AddFuncionario(Marta);
    H.AddFuncionario(Maria);
    H.AddFuncionario(Erica);
    H.AddFuncionario(Tina);


    H.Pesquisa_F_Cargo();
    H.Pesquisa_F_Salario(0);
    H.Pesquisa_F_Salario(1);

}
