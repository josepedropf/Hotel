#include <iostream>
#include "Hotel.h"


using namespace std;

int main() {
    Hotel H("da Marateca");
    Quarto Q205(suite, 2, 205, 3, 55.67);
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
