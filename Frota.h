#ifndef HOTEL_Frota_H
#define HOTEL_Frota_H
#include "bst.h"
#include <math.h>

struct matricula{
    char c1, c2, c3, c4, c5, c6;
    int id = c1 * pow(10, 10) + c2 * pow(10, 8) + c3 * pow(10, 6) + c4 * pow(10, 4) + c5 * pow(10, 2) + c6;
    bool operator==(const matricula &m2)const;
};

inline ostream& operator<<(ostream &os, const matricula m){
    os << m.c1 << m.c2 << "-" << m.c3 << m.c4 << "-" << m.c5 << m.c6;
    return os;
}

inline bool matricula::operator==(const matricula &m2) const{
    return (this->id == m2.id);
}

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

class Veiculo {
matricula vmatricula;
double kms;
int lugares;
//can add brand and date and more
public:
    Veiculo(matricula vmatricula) : vmatricula(vmatricula) {}
    Veiculo(matricula vmatricula, double kms, int lugares) : vmatricula(vmatricula), kms(kms), lugares(lugares){}
    Veiculo(string matricula_string) : vmatricula(transf_matricula(matricula_string)) {}
    Veiculo(string matricula_string, double kms, int lugares) : vmatricula(transf_matricula(matricula_string)), kms(kms), lugares(lugares){}
    matricula getMatricula() const;
    double getKms() const;
    int getLugares() const;
    void setkms(double m) {kms = m;}
    void updateKms(double m); //to be called at the end of a trip
    int ID() {return vmatricula.id;}
    void Info() const;
    bool operator < (const Veiculo & v) const;
    bool operator == (const Veiculo & v) const;
};

class Frota {
    static BST<Veiculo*> veiculos;
public:
    BST<Veiculo*> getVeiculos() const;
    int numVeiculos() const;
    void addVeiculo(Veiculo *v1);
    void alugarFrota(const vector<Veiculo*>& rFrota);
    static void devolveVeiculo(matricula matricula);
    Veiculo* pesquisaVeiculo(matricula matricula);
    Veiculo* menorM(); //to be called at the start or before a trip
};

class VeiculoNotFound
{

};


#endif //HOTEL_Frota_H
