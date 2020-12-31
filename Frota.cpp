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

matricula Veiculo::getMatricula() const {
    return vmatricula;
}

double Veiculo::getKms() const {
    return kms;
}

int Veiculo::getLugares() const {
    return lugares;
}

void Veiculo::updateKms(double kms_feitos) {
    kms += kms_feitos;
}

void Veiculo::Info() const {
    cout << "<VEICULO>" << endl;
    cout << "Matricula: " << vmatricula << " | ";
    cout << "Kilometragem: " << kms << " | ";
    cout << "Lugares: " << lugares;
    cout << endl;
}






