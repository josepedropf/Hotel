#include "Frota.h"

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






