#include "Frota.h"

matricula transf_matricula(string s){
    if(s.size() != 8 || s[2] != '-' || s[5] != '-'){
        matricula m = {m.c1 = 'A', m.c2 = 'A', m.c3 = '1', m.c4 = '1', m.c5 = 'A', m.c6 = 'A'};
        return m;
    }
    else{
        matricula m = {m.c1 = s[0], m.c2 = s[1], m.c3 = s[3], m.c4 = s[4], m.c5 = s[6], m.c6 = s[7]};
        return m;
    }
}

bool Veiculo::operator<(const Veiculo &v) const {
    if (kms < v.getKms()) {
        return true;
    }
    else return lugares < v.getLugares();
}

bool Veiculo::operator==(const Veiculo &v) const {
    return getMatricula() == v.getMatricula();
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
    cout << "Kilometragem: " << kms << " | ";
    cout << "Lugares: " << lugares;
    cout << endl;
}






