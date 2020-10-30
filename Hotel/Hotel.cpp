#ifndef HOTEL_HOTEL_H
#define HOTEL_HOTEL_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct data {
    int dia, mes, ano;
    data operator+=(const int duracao);
    int operator-(const data &d2)const;
    bool operator<(const data &d2)const; bool operator>(const data &d2)const;
    bool operator==(const data &d2)const;
    bool operator<=(const data &d2)const; bool operator>=(const data &d2)const;
};
enum turno {dia = 0, noite = 1};
enum tipo_quarto {sem_vista = 12, com_vista = 8, suite = 5};
enum tipo_produto {restauracao = 0, limpeza = 1};
enum avaliacao {ma = 1, insuficiente = 2, razoavel = 3, boa = 4, excelente = 5};
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



class Produto{
public:
    tipo_produto tprod;
    avaliacao qualidade;
    float preco;
    Produto(tipo_produto tp, avaliacao q, float p);
    ~Produto() {};
    void Info();
};

class Quarto{
public:
    tipo_quarto tquarto;
    int piso, numero, capacidade;
    float preco_base, promo;
    bool ocupado = false;
    Quarto(tipo_quarto tq, int p, int n, int c, float pb);
    ~Quarto() {};
    void Info();
    bool operator==(const Quarto &q2) const{return numero == q2.numero;}
};

class Reserva{
public:
    data data_inicio, data_fim;
    int lugaresp, duracao = data_fim - data_inicio, preco;
    vector <Quarto> quartos_res;
    bool vazia = false, primeiravez = true;
    static bool PrimeiraReserva(Reserva r1, Reserva r2) {return r1.primeiravez > r2.primeiravez;}
    static bool Duracaocomp_Decr(Reserva r1, Reserva r2) {return r1.duracao > r2.duracao;}
    static bool Duracaocomp_Cr(Reserva r1, Reserva r2) {return r1.duracao < r2.duracao;}
    static bool Precocomp_Decr(Reserva r1, Reserva r2) {return r1.preco > r2.preco;}
    static bool Precocomp_Cr(Reserva r1, Reserva r2) {return r1.preco < r2.preco;}
    static bool Datacomp_Decr(Reserva r1, Reserva r2) {return r1.data_inicio > r2.data_inicio;}
    static bool Datacomp_Cr(Reserva r1, Reserva r2) {return r1.data_inicio < r2.data_inicio;}
    Reserva(data i, data f, int lp, vector <Quarto> q);
    Reserva(data i, data f, int lp, vector <Quarto> q, bool v, bool pr);
    Reserva() {vazia = true;}
    ~Reserva() {};
    bool operator==(const Reserva &r2) const{return (quartos_res == r2.quartos_res && data_inicio == r2.data_inicio && data_fim == r2.data_fim);}
    void Info();
};

class Cliente{
public:
    string nome;
    int nif;
    bool cliente_usual = estadias_anteriores.size() > 0, nohotel = false;
    vector <Reserva> estadias_anteriores;
    Reserva *reserva_atual, *estadia_atual;
    Cliente(string na, int n);
    ~Cliente() {};
    void Info();
    bool operator==(const Cliente &c2) const{return (nome == c2.nome && nif == c2.nif);}

    void Reservar(data di, data df, int lp, vector <Quarto> q);
};

class Funcionario{
public:
    string cargo = "Geral";
    string nome;
    int nif, anos_servico;
    float salario;
    static bool Cargocomp(Funcionario f1, Funcionario f2) {return f1.cargo > f2.cargo;}
    static bool Salariocomp_Decr(Funcionario f1, Funcionario f2) {return f1.salario > f2.salario;}
    static bool Salariocomp_Cr(Funcionario f1, Funcionario f2) {return f1.salario < f2.salario;}
    Funcionario() {};
    Funcionario(string na, int n, int as, float s);
    Funcionario(string na, int n, int as, float s, string c);
    ~Funcionario() {};
    void Info();
    bool operator==(Funcionario f2);
};

class F_Rececao : public Funcionario{
public:
    F_Rececao(string na, int n, int as, float s);
    F_Rececao(string na, int n, int as, float s, string c);
};

class F_Responsavel : public F_Rececao{
public:
    vector <int> pisos_resp;
    F_Responsavel(string na, int n, int as, float s);
    F_Responsavel(string na, int n, int as, float s, vector<int> pr);
};

class F_Limpeza : public Funcionario{
public:
    turno fturno;
    F_Limpeza(string na, int n, int as, float s, turno t);
};

class F_Gestor : public Funcionario{
public:
    avaliacao av_prestacao = razoavel;
    F_Gestor(string na, int n, int as, float s);
    F_Gestor(string na, int n, int as, float s, avaliacao av);
    void Promocoes(vector <Quarto> quartos_promo);
    Produto Escolher_Prod(vector <Produto> prods);
};


class Hotel{
protected:
    string nome;
    vector <Produto> produtos;
    vector <Reserva> reservas;
    vector <Reserva> estadias;
    vector <Reserva> quartos_ocupados;
    vector <Cliente> clientes;
    vector <Quarto> quartos;
    vector <Funcionario> funcionarios;

public:
    Hotel(string n);
    ~Hotel() {};

    template<class T>
    void PrintV(vector<T> v){
        int vsize = v.size();
        cout << endl << "PRINT" << endl;
        cout << "|||-> " << endl;
        for (int i = 0; vsize > i; i++){
            v[i].Info();
            cout << endl;
        }
        cout << "<-||| " << endl;
    }

    template <class T>
    int FindIndex(vector <T> v, T element){
        int vsize = v.size();
        for(int i = 0; vsize > i; i++){
            if (v[i] == element) return i;
        }
        return 0;
    }


    bool AddReserva(Reserva r);
    void AddQuartoOcupado(Reserva r);
    void AddEstadia(Reserva r);
    void AddCliente(Cliente c);
    void AddQuarto(Quarto q);
    void AddFuncionario(Funcionario f);

    bool ValidarReserva(Cliente c);
    void CheckIn(Cliente c);
    void CheckOut(Cliente c);

    const vector <Reserva> GetReservas() {return reservas;}
    const vector <Reserva> GetQuartosOcupados() {return quartos_ocupados;}
    const vector <Reserva> GetEstadias() {return estadias;}
    const vector <Cliente> GetClientes() {return clientes;}
    const vector <Quarto> GetQuartos() {return quartos;}
    const vector <Funcionario> GetFuncionarios() {return funcionarios;}

    const vector <Funcionario> Pesquisa_F_Salario(bool inverso);
    const vector <Funcionario> Pesquisa_F_Cargo();
    const vector <Reserva> Pesquisa_Reservas_Duracao(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_Preco(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    const vector <Reserva> Pesquisa_Reservas_Data(bool inverso, bool clientes_novos, bool clientes_novos_primeiro);
    float CustosTotais(float impostos, float despesasfixas);
    float RendimentosTotais(int mes, int ano);
    float BalancoFin();
};

#endif //HOTEL_HOTEL_H
