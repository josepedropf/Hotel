#include <sstream>
#include "Frota.h"

matricula transf_matricula(string s){
    bool ast = false;
    for(int i = 0; s.size() > i && !ast; i++){
        if(s[i] == '*') ast = true;
    }
    if(s.size() != 8 || s[2] != '-' || s[5] != '-' || ast){
        matricula m = {m.c1 = '*', m.c2 = '*', m.c3 = '*', m.c4 = '*', m.c5 = '*', m.c6 = '*'};
        return m;
    }
    else{
        matricula m = {m.c1 = s[0], m.c2 = s[1], m.c3 = s[3], m.c4 = s[4], m.c5 = s[6], m.c6 = s[7]};
        return m;
    }
}

bool Veiculo::operator < (const Veiculo &v) const {
    if (this->kms != v.getKms()) return this->kms < v.getKms();
    else if(this->lugares != v.getLugares()) return this->lugares > v.getLugares();
    else return false;
}

bool Veiculo::operator==(const Veiculo &v) const {
    return (this->getMatricula() == v.getMatricula());
}
/**
 * @return matricula do veículo
 */
matricula Veiculo::getMatricula() const {
    return vmatricula;
}
/**
 * @return os kilometros feitos desde o aluguer do veículo
 */
double Veiculo::getKms() const {
    return kms;
}
/**
 * @return lugares do veiculo
 */
int Veiculo::getLugares() const {
    return lugares;
}
/**
 * Esta função atualiza os kilometros percorridos pelo veiculo
 * Caso exceda 5000km chama a função devolveVeículo
 * @param m kms a acrescentar
 */
void Veiculo::updateKms(double kms_feitos) {
    kms += kms_feitos;
}
/**
 * Imprime as informações do veículo
 */
void Veiculo::Info() const {
    cout << "<VEICULO>" << endl;
    cout << "Matricula: " << vmatricula << " | ";
    cout << "Marca: " << marca << " | ";
    cout << "Kilometragem: " << kms << " | ";
    cout << "Lugares: " << lugares;
    cout << endl;
}

void Viagem::Info() const {
    cout << "<VIAGEM>" << endl;
    cout << "ID: " << id << " | ";
    cout << "Matricula do Veiculo: " << matricula << " | ";
    cout << "Distancia: " << distancia << " | ";
    cout << "Ponto de Partida: " << ponto_partida << " | ";
    cout << "Destino: " << destino;
    cout << endl;
}




