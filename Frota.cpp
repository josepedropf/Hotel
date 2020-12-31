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

void Veiculo::updateKms(double m) {
    if (m + kms >= 5000) {
        Frota::devolveVeiculo(getMatricula());
    }
    else {
        kms += m;
    }
}

void Veiculo::Info() const {
    cout << "<VEICULO>" << endl;
    cout << "Matricula: " << vmatricula << " | ";
    cout << "Kilometragem: " << kms << " | ";
    cout << "Lugares: " << lugares;
    cout << endl;
}

BST<Veiculo*> Frota::getVeiculos() const {
    return veiculos;
}

int Frota::numVeiculos() const {
    int result = 0;
    BSTItrIn<Veiculo*> it(veiculos);
    for (; !it.isAtEnd();it.advance()) {
        result++;
    }
    return result;
}

void Frota::addVeiculo(Veiculo *v1) {
    veiculos.insert(v1);
}

void Frota::alugarFrota(const vector <Veiculo*>& rFrota) {
    veiculos.makeEmpty();
    for (auto & i : rFrota) {
        addVeiculo(i);
    }
}

Veiculo* Frota::pesquisaVeiculo(matricula matricula) {
    BSTItrIn<Veiculo*> it(veiculos);
    for (; !it.isAtEnd();it.advance()) {
        if (matricula == it.retrieve()->getMatricula()) return it.retrieve();
    }
    throw VeiculoNotFound(); //not implemented yet
}

Veiculo* Frota::menorM() {
    return veiculos.findMin(); //n sei se funciona assim
}

void Frota::devolveVeiculo(matricula matricula) {
    Veiculo* toreturn;
    BSTItrIn<Veiculo*> it(veiculos);
    for (; !it.isAtEnd();it.advance()) {
        if (matricula == it.retrieve()->getMatricula()) {
            veiculos.remove(it.retrieve());
            break;
        }
    }

    /*toreturn = pesquisaVeiculo(p);
    veiculos.remove(toreturn);*/
}


