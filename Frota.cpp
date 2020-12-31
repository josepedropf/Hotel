#include "Frota.h"

bool Veiculo::operator<(const Veiculo &v) const {
    if (kms < v.getkms()) {
        return true;
    }
    else return lugares < v.getLugares();
}

bool Veiculo::operator==(const Veiculo &v) const {
    return getmatricula() == v.getmatricula();
}

string Veiculo::getmatricula() const {
    return matricula;
}

double Veiculo::getkms() const {
    return kms;
}

int Veiculo::getLugares() const {
    return lugares;
}

void Veiculo::updatekms(double m) {
    if (m + kms >= 5000) {
        Frota::devolveVeiculo(getmatricula());
    }
    else {
        kms += m;
    }
}

int Veiculo::info(ostream &o) const {
    o << "matricula: " << matricula << endl;
    o << "kms: " << kms << endl;
    o << "Seats: " << lugares << endl;
    return 3;
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

void Frota::rentFrota(const vector <Veiculo*>& rFrota) {
    veiculos.makeEmpty();
    for (auto & i : rFrota) {
        addVeiculo(i);
    }
}

Veiculo* Frota::pesquisaVeiculo(string p) {
    BSTItrIn<Veiculo*> it(veiculos);
    for (; !it.isAtEnd();it.advance()) {
        if (p == it.retrieve()->getmatricula()) return it.retrieve();
    }
    throw VeiculoNotFound(); //not implemented yet
}

Veiculo* Frota::menorM() {
    return veiculos.findMin(); //n sei se funciona assim
}

void Frota::devolveVeiculo(string p) {
    Veiculo* toreturn;
    BSTItrIn<Veiculo*> it(veiculos);
    for (; !it.isAtEnd();it.advance()) {
        if (p == it.retrieve()->getmatricula()) {
            veiculos.remove(it.retrieve());
            break;
        }
    }

    /*toreturn = pesquisaVeiculo(p);
    veiculos.remove(toreturn);*/
}


