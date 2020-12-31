#ifndef HOTEL_Frota_H
#define HOTEL_Frota_H
#include "bst.h"

class Veiculo {
string matricula;
double kms;
int lugares;
//can add brand and date and more
public:
    Veiculo(string p) : matricula(p) {}
    Veiculo(string p, double m, int l) : matricula(p), kms(m), lugares(l){}
    string getmatricula() const;
    double getkms() const;
    int getLugares() const;
    void setkms(double m) {kms = m;}
    void updatekms(double m); //to be called at the end of a trip
     //not implemented yet, devolve carro e remove da bst
    int info(ostream &o) const;
    bool operator < (const Veiculo & v) const;
    bool operator == (const Veiculo & v) const;
};

class Frota {
    static BST<Veiculo*> veiculos;
public:
    BST<Veiculo*> getVeiculos() const;
    int numVeiculos() const;
    void addVeiculo(Veiculo *v1);
    void rentFrota(const vector<Veiculo*>& rFrota);
    static void devolveVeiculo(string p);
    Veiculo* pesquisaVeiculo(string p);
    Veiculo* menorM(); //to be called at the start or before a trip
};

class VeiculoNotFound
{

};


#endif //HOTEL_Frota_H
