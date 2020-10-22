#include "Hotel.h"


// Inicializações
Produto::Produto(tipo_produto tp, avaliacao q, float p){
    tprod = tp;
    qualidade = q;
    preco = p;
}

Reserva::Reserva(data i, data f, int lp){
    data_inicio = i;
    data_fim = f;
    lugaresp = lp;
}

Cliente::Cliente(string na, int n) {
    nome = na;
    nif = n;
}

Quarto::Quarto(tipo_quarto tq, int p, int n, int c, float pb) {
    tquarto = tq;
    piso = p;
    numero = n;
    capacidade = c;
    preco_base = pb;
    promo = tquarto;
    cout << "Tipo de Quarto: " << tquarto << endl << "Promo: " << promo << endl;
}

Funcionario::Funcionario(string na, int n, int as, float s) {
    nome = na;
    nif = n;
    anos_servico = as;
    salario = s;
}

F_Rececao::F_Rececao(string na, int n, int as, float s): Funcionario(na, n, as, s) {}

F_Responsavel::F_Responsavel(string na, int n, int as, float s): F_Rececao(na, n, as, s) {}

F_Responsavel::F_Responsavel(string na, int n, int as, float s, vector<int> pr): F_Rececao(na, n, as, s) {
    pisos_resp = pr;
}

F_Limpeza::F_Limpeza(string na, int n, int as, float s, turno t): Funcionario(na, n, as, s) {
    fturno = t;
}

F_Gestor::F_Gestor(string na, int n, int as, float s): Funcionario(na, n, as, s) {}

F_Gestor::F_Gestor(string na, int n, int as, float s, avaliacao av): Funcionario(na, n, as, s) {
    av_prestacao = av;
}


// Hotel Add
void Hotel::AddReserva(Reserva r) {
    reservas.push_back(r);
}

void Hotel::AddCliente(Cliente c) {
    clientes.push_back(c);
}

void Hotel::AddQuarto(Quarto q) {
    quartos.push_back(q);
}

void Hotel::AddFuncionario(Funcionario f) {
    funcionarios.push_back(f);
}

// Gestor Funcs
void F_Gestor::Promocoes(vector<Quarto> quartos_promo) {
    int qsize = quartos_promo.size();
    for(int i = 0; qsize > i; i++){
        Quarto quarto = quartos_promo[i];
        quarto.preco_base *= float(float(100 - quarto.promo)/ 100);
    }
}
