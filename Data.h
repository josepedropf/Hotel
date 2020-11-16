#ifndef HOTEL_DATA_H
#define HOTEL_DATA_H

#include <string>
#include <iostream>

using namespace std;

struct data {
    int dia, mes, ano;
    data operator+=(const int duracao);
    int operator-(const data &d2)const;
    bool operator<(const data &d2)const; bool operator>(const data &d2)const;
    bool operator==(const data &d2)const;
    bool operator<=(const data &d2)const; bool operator>=(const data &d2)const;
};

inline ostream& operator<<(ostream &os, const data d){
    os << d.dia << "-" << d.mes << "-" << d.ano;
    return os;
}
inline data data::operator+=(const int duracao){
    dia += duracao;
    return *this;
}
inline int data::operator-(const data &d2) const{
    int result = ano*365 + mes*30 + dia;
    int dif = d2.ano*365 + d2.mes*30 + d2.dia;
    result-=dif;
    return result;
}
inline bool data::operator<(const data &d2) const{
    int n1 = ano*365 + mes*30 + dia;
    int n2 = d2.ano*365 + d2.mes*30 + d2.dia;
    return n1 < n2;
}
inline bool data::operator>(const data &d2) const{
    int n1 = ano*365 + mes*30 + dia;
    int n2 = d2.ano*365 + d2.mes*30 + d2.dia;
    return n1 > n2;
}
inline bool data::operator==(const data &d2) const{
    return (this->ano == d2.ano && this->mes == d2.mes && this->dia == d2.dia);
}
inline bool data::operator<=(const data &d2) const {return (*this == d2 || *this < d2);}
inline bool data::operator>=(const data &d2) const {return (*this == d2 || *this > d2);}



#endif //HOTEL_DATA_H
