#include "Hotel.h"


// Inicializações

Hotel::Hotel(string n) {
    nome = n;
    cout << "Bem Vindo ao Grande Hotel " << nome << "!" << endl;
}


// Hotel Database Add
bool Hotel::AddReserva(Reserva r) {
    int capacidadetotal = 0;
    int qsize = r.quartos_res.size();
    for (int i = 0; qsize > i; i++){
        capacidadetotal += r.quartos_res[i].capacidade;
    }
    if(r.lugaresp <= capacidadetotal && (r.data_fim - r.data_inicio > 0)) reservas.push_back(r);
    else{
        cout << endl << "Reserva Impossível" << endl;
        cout << "Razão: Lugares Esperados excedem a capacidade total dos Quartos selecionados!" << endl;
        return false;
    }
    return true;
}

void Hotel::AddQuartoOcupado(Reserva r) {
    quartos_ocupados.push_back(r);
}

void Hotel::AddEstadia(Reserva r) {
    estadias.push_back(r);
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

bool Hotel::ValidarReserva(Cliente c) {
    Reserva r = *c.reserva_atual;
    if (r.vazia == true && AddReserva(r)) {
        r.vazia = false;
        if (!c.cliente_usual) {
            AddCliente(c);
            r.primeiravez = true;
        }
        else r.primeiravez = false;
        return true;
    }
    else{
        cout << endl << "Reserva Inválida!!!" << endl;
        return false;
    }
}

void Hotel::CheckIn(Cliente c) {
    Reserva r = *c.reserva_atual;
    c.estadia_atual = &r;
    c.reserva_atual = NULL;
    c.nohotel = true;
    int rindex = FindIndex(reservas, r);
    reservas.erase(reservas.begin() + rindex);
    AddQuartoOcupado(r);
}

void Hotel::CheckOut(Cliente c) {
    Reserva r = *c.reserva_atual;
    c.estadias_anteriores.push_back(r);
    c.estadia_atual = NULL;
    AddEstadia(r);
    r.vazia = true;
    int rindex = FindIndex(reservas, r);
    quartos_ocupados.erase(reservas.begin() + rindex);
    c.nohotel = false;
}


//Hotel Database Funcs
const vector<Funcionario> Hotel::Pesquisa_F_Salario(bool inverso) {
    vector <Funcionario> pesquisa_salario = funcionarios;
    if(inverso) sort(pesquisa_salario.begin(), pesquisa_salario.end(), Funcionario::Salariocomp_Decr);
    else sort(pesquisa_salario.begin(), pesquisa_salario.end(), Funcionario::Salariocomp_Cr);
    PrintV(pesquisa_salario);
    return pesquisa_salario;
}

const vector<Funcionario> Hotel::Pesquisa_F_Cargo() {
    vector <Funcionario> pesquisa_cargo = funcionarios;
    sort(pesquisa_cargo.begin(), pesquisa_cargo.end(), Funcionario::Cargocomp);
    PrintV(pesquisa_cargo);
    return pesquisa_cargo;
}

const vector<Reserva> Hotel::Pesquisa_Reservas_Duracao(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    vector <Reserva> pesquisa_duracao;
    int rsize = reservas.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (reservas[i].primeiravez) pesquisa_duracao.push_back(reservas[i]);
        }
    }
    else pesquisa_duracao = reservas;
    if(inverso) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Duracaocomp_Decr);
    else sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Duracaocomp_Cr);
    if(clientes_novos_primeiro) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const vector<Reserva> Hotel::Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    vector <Reserva> pesquisa_duracao;
    int rsize = reservas.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (reservas[i].primeiravez) pesquisa_duracao.push_back(reservas[i]);
        }
    }
    else pesquisa_duracao = reservas;
    if(inverso) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::DataIcomp_Decr);
    else sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::DataIcomp_Cr);
    if(clientes_novos_primeiro) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const vector<Reserva> Hotel::Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, vector<Reserva> r) {
    vector <Reserva> pesquisa_duracao;
    int rsize = r.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (r[i].primeiravez) pesquisa_duracao.push_back(r[i]);
        }
    }
    else pesquisa_duracao = r;
    if(inverso) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::DataIcomp_Decr);
    else sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::DataIcomp_Cr);
    if(clientes_novos_primeiro) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const vector<Reserva> Hotel::Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    vector <Reserva> pesquisa_duracao;
    int rsize = reservas.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (reservas[i].primeiravez) pesquisa_duracao.push_back(reservas[i]);
        }
    }
    else pesquisa_duracao = reservas;
    if(inverso) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::DataFcomp_Decr);
    else sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::DataFcomp_Cr);
    if(clientes_novos_primeiro) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const vector<Reserva> Hotel::Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, vector<Reserva> r) {
    vector <Reserva> pesquisa_duracao;
    int rsize = r.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (r[i].primeiravez) pesquisa_duracao.push_back(r[i]);
        }
    }
    else pesquisa_duracao = r;
    if(inverso) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::DataFcomp_Decr);
    else sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::DataFcomp_Cr);
    if(clientes_novos_primeiro) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const vector<Reserva> Hotel::Pesquisa_Reservas_Preco(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    vector <Reserva> pesquisa_duracao;
    int rsize = reservas.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (reservas[i].primeiravez) pesquisa_duracao.push_back(reservas[i]);
        }
    }
    else pesquisa_duracao = reservas;
    if(inverso) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Precocomp_Decr);
    else sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::Precocomp_Cr);
    if(clientes_novos_primeiro) sort(pesquisa_duracao.begin(), pesquisa_duracao.end(), Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const vector <Reserva> Hotel::Quartos_Fin(int mesp, int anop){
    bool check = false, checking = false;
    data dataf = DiaFinal(mesp, anop);
    data datai = {.dia = 1, .mes = mesp, .ano = anop};
    vector <Reserva> reservastotais = reservas;
    reservastotais.insert(reservastotais.end(), quartos_ocupados.begin(), quartos_ocupados.end());
    reservastotais.insert(reservastotais.end(), estadias.begin(), estadias.end());
    vector <Reserva> ri = Pesquisa_Reservas_DataI(0, 0, 0, reservastotais);
    int risize = ri.size();
    cout << endl << "SIZE: " << risize << endl;
    int vmin = 0, vmax = ri.size() - 1;
    int vmedio = vmax/2;
    cout << endl << "1) vm " << vmedio << endl << "vmin " << vmin << endl << "vmax " << vmax << endl;
    while(!check){
        if(ri[vmedio].data_inicio <= dataf) vmin = vmedio;
        if(ri[vmedio].data_inicio > dataf) vmax = vmedio;
        if(!checking) vmedio = vmin + (vmax - vmin)/2;
        else check = true;
        if(!check){
            if(vmedio == vmin) vmedio = vmax;
            if(vmedio == vmax) vmedio = vmin;
            checking = true;
        }
        cout << endl << "1) vm " << vmedio << endl << "vmin " << vmin << endl << "vmax " << vmax << endl;
    }
    cout << endl << "VMAX: " << vmax << endl;
    ri.erase(ri.begin() + min(vmax, risize - 1), ri.end());
    vector <Reserva> rf = Pesquisa_Reservas_DataF(0, 0, 0, ri);
    vmin = 0, vmax = rf.size() - 1;
    vmedio = vmax/2;
    check = false;
    checking = false;
    cout << endl << "2) vm " << vmedio << endl << "vmin " << vmin << endl << "vmax " << vmax << endl;
    while(!check){
        if(ri[vmedio].data_fim < datai) vmin = vmedio;
        if(ri[vmedio].data_fim >= datai) vmax = vmedio;
        if(!checking) vmedio = vmin + (vmax - vmin)/2;
        else check = true;
        if(!check) {
            if (vmedio == vmin) vmedio = vmax;
            if (vmedio == vmax) vmedio = vmin;
            checking = true;
        }
        cout << endl << "2) vm " << vmedio << endl << "vmin " << vmin << endl << "vmax " << vmax << endl;
    }
    cout << endl << "VMIN: " << vmin << endl;
    rf.erase(rf.begin(), rf.begin() + max(0, vmin));
    return rf;
}

// Hotel Finances Functions

float Hotel::CustosTotais(float impostos, float despesasfixas) {
    int fsize = funcionarios.size();
    int psize = produtos.size();
    float salarios = 0;
    float preco_produtos = 0;
    for (int i = 0; fsize > i; i++){
        salarios += funcionarios[i].salario;
    }
    for (int i = 0; psize > i; i++){
        preco_produtos +=  produtos[i].preco;
    }
    return impostos + despesasfixas + preco_produtos + salarios;
}

data Hotel::DiaFinal(int mesp, int anop) {
    if (mesp == 2) return {.dia = 28, .mes = mesp, .ano= anop};
    else if (mesp == 4 || mesp == 6 || mesp == 9 || mesp == 11) return {.dia = 30, .mes = mesp, .ano= anop};
    else return {.dia = 31, .mes = mesp, .ano= anop};
}

float Hotel::RendimentosTotais(int mes, int ano) {
    data data_inicial = {.dia = 1, .mes = mes, .ano = ano};
    data data_final = DiaFinal(mes, ano);
    vector<Reserva> reservas_totais = Quartos_Fin(mes, ano);
    PrintV(reservas_totais);
    cout << endl << "HERE RT" << endl;
    int realdur;
    float count_rquartos = 0, rendimento = 0;
    int rsize = reservas_totais.size();
    for (int i = 0; rsize > i; i++){
        if(reservas_totais[i].data_inicio >= data_inicial && reservas_totais[i].data_fim <= data_final) count_rquartos += reservas_totais[i].duracao * reservas_totais[i].preco;
        if(reservas_totais[i].data_inicio >= data_inicial && reservas_totais[i].data_fim > data_final){
            realdur = data_final - reservas_totais[i].data_inicio;
            count_rquartos += reservas_totais[i].preco * realdur;
        }
        if(reservas_totais[i].data_inicio < data_inicial && reservas_totais[i].data_fim <= data_final){
            realdur = reservas_totais[i].data_fim - data_inicial;
            count_rquartos += reservas_totais[i].preco * realdur;
        }
        if(reservas_totais[i].data_inicio < data_inicial && reservas_totais[i].data_fim > data_final){
            realdur = data_final - data_inicial;
            count_rquartos += reservas_totais[i].preco * realdur;
        }
        }
    rendimento += count_rquartos;
    return rendimento;
    }

float Hotel::BalancoFin(int mes, int ano, float impostos, float despesasfixas) {
    return RendimentosTotais(mes, ano) - CustosTotais(impostos, despesasfixas);
}

