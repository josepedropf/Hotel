#ifndef HOTEL_Frota_H
#define HOTEL_Frota_H
#include "bst.h"
#include <math.h>

struct matricula{
    char c1, c2, c3, c4, c5, c6;
    int id = c1 * pow(10, 10) + c2 * pow(10, 8) + c3 * pow(10, 6) + c4 * pow(10, 4) + c5 * pow(10, 2) + c6;
    bool operator==(const matricula &m2)const;
    int getID() const {return c1 * pow(10, 10) + c2 * pow(10, 8) + c3 * pow(10, 6) + c4 * pow(10, 4) + c5 * pow(10, 2) + c6;}
};

inline ostream& operator<<(ostream &os, const matricula m){
    os << m.c1 << m.c2 << "-" << m.c3 << m.c4 << "-" << m.c5 << m.c6;
    return os;
}

inline bool matricula::operator==(const matricula &m2) const{
    return (this->c1 == m2.c1 && this->c2 == m2.c2 && this->c3 == m2.c3 && this->c4 == m2.c4 && this->c5 == m2.c5 && this->c6 == m2.c6);
}

matricula transf_matricula(string s);


class Veiculo {
matricula vmatricula;
string marca = "Hotel Car";
double kms;
int lugares;
//can add brand and date and more
public:
    Veiculo() : vmatricula(transf_matricula(" ")), lugares(0), kms(0) {}
    Veiculo(matricula vmatricula) {this->vmatricula = vmatricula; lugares = 0; kms = 0;}
    Veiculo(matricula vmatricula, int lugares) {this->vmatricula = vmatricula; if(lugares < 1) this->lugares = 1; else this->lugares = lugares; kms = 0;}
    Veiculo(matricula vmatricula, double kms, int lugares) {this->vmatricula = vmatricula; if(lugares < 1) this->lugares = 1; else this->lugares = lugares; this->kms = kms;}
    Veiculo(matricula vmatricula, double kms, int lugares, string marca) {this->vmatricula = vmatricula; if(lugares < 1) this->lugares = 1; else this->lugares = lugares; this->kms = kms; this->marca = marca;}
    Veiculo(string matricula_string, int lugares) {vmatricula = transf_matricula(matricula_string); if(lugares < 1) this->lugares = 1; else this->lugares = lugares; kms = 0;}
    Veiculo(string matricula_string, double kms, int lugares) {vmatricula = transf_matricula(matricula_string); if(lugares < 1) this->lugares = 1; else this->lugares = lugares; this->kms = kms;}
    Veiculo(string matricula_string, double kms, int lugares, string marca) {vmatricula = transf_matricula(matricula_string); if(lugares < 1) this->lugares = 1; else this->lugares = lugares; this->kms = kms; this->marca = marca;}
    matricula getMatricula() const;
    string getMarca() const {return marca;}
    double getKms() const;
    int getLugares() const;
    void setkms(double new_kms) {kms = new_kms;}
    void updateKms(double kms_feitos); //to be called at the end of a trip
    int ID() const {return vmatricula.getID();}
    void Info() const;
    bool operator < (const Veiculo & v) const;
    bool operator == (const Veiculo & v) const;
};


class Viagem{
public:
    Viagem(double distancia, string ponto_partida, string destino, int id, matricula matricula) {this->distancia = distancia; this->ponto_partida = ponto_partida; this->destino = destino; this->id = id; this->matricula = matricula;}
    Viagem(double distancia, int id, matricula matricula) {this->distancia = distancia; this->ponto_partida = "Aeroporto"; this->destino = "Hotel"; this->id = id; this->matricula = matricula;}
    string ponto_partida = "Hotel", destino = "Aeroporto";
    double distancia;
    matricula matricula;
    int id;
    int ID() const {return id;}
    void Info() const;
    bool operator==(const Viagem &v2)const;
};

inline bool Viagem::operator==(const Viagem &v2) const {
    return (id == v2.ID());
}


#endif //HOTEL_Frota_H
