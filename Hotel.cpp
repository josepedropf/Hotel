#include "Hotel.h"


// Inicializações
/**
 * Construtor da Classe Hotel
 * @param nome nome do Hotel
 */
Hotel::Hotel(string nome) {
    nome = nome;
    cout << "Bem Vindo ao Grande Hotel " << nome << "!" << endl;
}


// Hotel Database Add
/**
 * Adiciona uma Reserva à base de dados do Hotel (vetor reservas), se esta for válida, isto é,
 * se não for sobreposta a outras já existentes e a capacidade desejada for igual ou inferior á dos quartos requeridos
 * @param reserva Reserva a ser adicionada
 * @return true se a reserva for válida e portanto adicionada, false caso contrário
 */
bool Hotel::AddReserva(Reserva reserva) {
    bool sobreposta = false;
    int capacidadetotal = 0;
    int qsize = reserva.quartos_res.size();
    int rsize = reservas.size();
    for (int i = 0; rsize > i; i++){
        if(reservas[i] == reserva){
            sobreposta = true;
            break;
        }
    }
    if(sobreposta){
        cout << endl << "Reserva Impossível" << endl;
        cout << "Razão: A Reserva já existe ou sobrepõe-se a uma já existente!" << endl;
        return false;
    }
    for (int i = 0; qsize > i; i++){
        capacidadetotal += reserva.quartos_res[i].capacidade;
    }
    if(reserva.lugaresp <= capacidadetotal && (reserva.data_fim - reserva.data_inicio > 0)) reservas.push_back(reserva);
    else{
        cout << endl << "Reserva Impossível" << endl;
        cout << "Razão: Lugares Esperados excedem a capacidade total dos Quartos selecionados!" << endl;
        return false;
    }
    return true;
}

/**
 * Adiciona uma Reserva ao conjunto de reservas atuais do Hotel, ou seja,
 * aquelas que estão a ser usufruídas no momento (vetor reservas_atuais)
 * @param reserva Reserva a ser adicionada ao vetor reservas_atuais
 */
void Hotel::AddReservasAtuais(Reserva reserva) {
    reservas_atuais.push_back(reserva);
}

/**
 * Adiciona uma Reserva ao conjunto de estadias anteriores efetuadas no Hotel, isto é,
 * que já foram usufruídas pelos clientes (vetor estadias)
 * @param reserva Reserva a ser adicionada ao vetor estadias
 */
void Hotel::AddEstadia(Reserva reserva) {
    estadias.push_back(reserva);
}

/**
 * Adiciona um Cliente à base de dados do Hotel (um perfil que se mantem se o mesmo fizer reservas no futuro)
 * (vetor clientes)
 * @param cliente Cliente a ser adicionado ao vetor clientes
 */
void Hotel::AddCliente(Cliente cliente) {
    clientes.push_back(cliente);
}

/**
 * Adiciona um Quarto à base de dados do Hotel (vetor quartos)
 * @param quarto Quarto a ser adicionado ao vetor quartos
 */
void Hotel::AddQuarto(Quarto quarto) {
    quartos.push_back(quarto);
}

/**
 * Adiciona um Funcionário à base de dados do Hotel (vetor funcionários)
 * @param funcionario Funcionário a ser adicionado ao vetor funcionários
 */
void Hotel::AddFuncionario(Funcionario funcionario) {
    funcionarios.push_back(funcionario);
}


 /**
  * Valida a Reserva feita pelo cliente, certeficando-se que esta não se sobrepõe a outras feitas pelo mesmo cliente.
  * Além disso adiciona o cliente à base de dados chamando a AddCliente caso seja a primeira reserva deste.
  * @param cliente Cliente que efetuou a reserva que queremos validar
  * @param reserva Reserva que se pretende validar
  * @return true se a Reserva for válida, false caso contrário
  */
bool Hotel::ValidarReserva(Cliente cliente, Reserva reserva) {
    bool exist = false;
    int crsize = cliente.reservas_cliente.size();
    vector<Reserva> outras_reservas_cliente;
    for(int i = 0; crsize > i; i++){
        if(reserva.idnumero == cliente.reservas_cliente[i].idnumero) exist = true;
        else outras_reservas_cliente.push_back(cliente.reservas_cliente[i]);
    }
    if(!exist) return false;
    int outrasrsize = outras_reservas_cliente.size();
    for(int i = 0; outrasrsize > i; i++){
        if(reserva == outras_reservas_cliente[i]) return false;
    }
    if(*cliente.estadia_atual == reserva) return false;
    if (AddReserva(reserva)) {
        if (!cliente.cliente_usual) {
            AddCliente(cliente);
            reserva.primeiravez = true;
        }
        else reserva.primeiravez = false;
        return true;
    }
    else{
        cout << endl << "Reserva Inválida!!!" << endl;
        return false;
    }
}

/**
 * Realiza o Check-In, a reserva mais recente do cliente deixa de pertencer ao seu vetor reservas_cliente
 * e passa a ser a sua estadia atual, visto que este entra no hotel
 * Atualiza também outras informações como por exemplo o facto de o cliente se encontrar no hotel passando nohotel a true
 * @param cliente Cliente que está a realizar o Check-In
 */
void Hotel::CheckIn(Cliente cliente) {
    Reserva reserva = cliente.reservas_cliente[0];
    cliente.estadia_atual = &reserva;
    int rindex = FindIndex(cliente.reservas_cliente, reserva);
    cliente.reservas_cliente.erase(cliente.reservas_cliente.begin() + rindex);
    cliente.nohotel = true;
    rindex = FindIndex(reservas, reserva);
    reservas.erase(reservas.begin() + rindex);
    AddReservasAtuais(reserva);
}

/**
 * Realiza o Check-Out, a estadia atual do cliente em questão passa a pertencer às suas estadias_anteriores
 * Atualiza outras informações: o facto do cliente já não estar no hotel passando nohotel a false
 * @param cliente Cliente que está a realizar o Check-Out
 */
void Hotel::CheckOut(Cliente cliente) {
    Reserva reserva = *cliente.estadia_atual;
    cliente.estadias_anteriores.push_back(reserva);
    cliente.estadia_atual = NULL;
    AddEstadia(reserva);
    int rindex = FindIndex(reservas, reserva);
    reservas_atuais.erase(reservas.begin() + rindex);
    cliente.nohotel = false;
    if(!cliente.cliente_usual) cliente.cliente_usual = true;
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

const vector<Reserva> Hotel::Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, vector<Reserva> reserva) {
    vector <Reserva> pesquisa_duracao;
    int rsize = reserva.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (reserva[i].primeiravez) pesquisa_duracao.push_back(reserva[i]);
        }
    }
    else pesquisa_duracao = reserva;
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

const vector<Reserva> Hotel::Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, vector<Reserva> reserva) {
    vector <Reserva> pesquisa_duracao;
    int rsize = reserva.size();
    if(clientes_novos) {
        for (int i = 0; rsize > i; i++){
            if (reserva[i].primeiravez) pesquisa_duracao.push_back(reserva[i]);
        }
    }
    else pesquisa_duracao = reserva;
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
    bool done = false;
    data dataf = DiaFinal(mesp, anop);
    data datai = {.dia = 1, .mes = mesp, .ano = anop};
    vector <Reserva> reservastotais = reservas;
    reservastotais.insert(reservastotais.end(), reservas_atuais.begin(), reservas_atuais.end());
    reservastotais.insert(reservastotais.end(), estadias.begin(), estadias.end());
    vector <Reserva> ri = Pesquisa_Reservas_DataI(0, 0, 0, reservastotais);
    int risize = ri.size();
    int vmin = 0, vmax = ri.size();
    int vmedio = vmax/2;
    int vmedioant = 0;
    //cout << endl << "1) vm " << vmedio << endl << "vmin " << vmin << endl << "vmax " << vmax << endl;
    while(vmedio != vmax || vmedio != vmin){
        //cout << endl << "1) vm " << vmedio << endl << "vmin " << vmin << endl << "vmax " << vmax << endl << "vmedioant " << vmedioant << endl;
        if(ri[vmedio].data_inicio <= dataf) vmin = vmedio;
        if(ri[vmedio].data_inicio > dataf) vmax = vmedio;
        vmedioant = vmedio;
        vmedio = vmin + (vmax - vmin)/2;
        if(done) break;
        if (vmedio == vmedioant){
            vmedio = vmin + (vmax - vmin)/2 + (vmax - vmin);
            done = true;
        }
    }
    ri.erase(ri.begin() + min(vmax, risize), ri.end());
    vector <Reserva> rf = Pesquisa_Reservas_DataF(0, 0, 0, ri);
    int rfsize = rf.size();
    vmin = 0, vmax = rf.size();
    vmedio = vmax/2;
    vmedioant = 0;
    done = false;
    //cout << endl << "2) vm " << vmedio << endl << "vmin " << vmin << endl << "vmax " << vmax << endl;
    while(vmedio != vmax || vmedio != vmin){
        //cout << endl << "2) vm " << vmedio << endl << "vmin " << vmin << endl << "vmax " << vmax << endl << "vmedioant " << vmedioant << endl << endl;
        if(ri[vmedio].data_fim < datai) vmin = vmedio;
        if(ri[vmedio].data_fim >= datai) vmax = vmedio;
        vmedioant = vmedio;
        vmedio = vmin + (vmax - vmin)/2;
        if(done) break;
        if (vmedio == vmedioant){
            vmedio = vmin + (vmax - vmin)/2 + (vmax - vmin);
            done = true;
        }
    }
    int maxr = max(0, vmin + 1);
    rf.erase(rf.begin(), rf.begin() + min(maxr, rfsize));
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
    cout << endl << "Quartos Reservados (Total ou Parcialmente) neste mês fiscal (" << mes << "-" << ano <<"): ";
    PrintV(reservas_totais);
    int realdur;
    float preco_res;
    float count_rquartos = 0, rendimento = 0;
    int rsize = reservas_totais.size();
    for (int i = 0; rsize > i; i++){
        preco_res = reservas_totais[i].preco;

        if(reservas_totais[i].data_inicio >= data_inicial && reservas_totais[i].data_fim <= data_final) realdur = reservas_totais[i].duracao;
        if(reservas_totais[i].data_inicio >= data_inicial && reservas_totais[i].data_fim > data_final) realdur = data_final - reservas_totais[i].data_inicio + 1;
        if(reservas_totais[i].data_inicio < data_inicial && reservas_totais[i].data_fim <= data_final) realdur = reservas_totais[i].data_fim - data_inicial + 1;
        if(reservas_totais[i].data_inicio < data_inicial && reservas_totais[i].data_fim > data_final) realdur = data_final - data_inicial + 1;

        count_rquartos += preco_res * realdur;

        cout << "A Reserva " << reservas_totais[i].idnumero << " tem uma duração neste mês de " << realdur << " dias e tem um custo de " << preco_res << " euros." << " (Preço Total de " << preco_res * realdur << ")" << endl;
        }
    rendimento += count_rquartos;
    return rendimento;
    }

float Hotel::BalancoFin(int mes, int ano, float impostos, float despesasfixas) {
    return RendimentosTotais(mes, ano) - CustosTotais(impostos, despesasfixas);
}

