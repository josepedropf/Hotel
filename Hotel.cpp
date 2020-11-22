#include "Hotel.h"

Hotel::Hotel(string nome) {
    this->nome = nome;
}

// Hotel Database Add

bool Hotel::AddProduto(Produto produto) {
    for(auto it = produtos.begin(); it != produtos.end(); it++){
        if(*it == produto) return false ;
    }
    produtos.push_back(produto);
    return true;
}

/**
 * Adiciona uma Reserva à base de dados do Hotel (vetor reservas), se esta for válida, isto é,
 * se não for sobreposta a outras já existentes e a capacidade desejada for igual ou inferior á dos quartos requeridos
 * @param reserva Reserva a ser adicionada
 * @return true se a reserva for válida e portanto adicionada, false caso contrário
 */
bool Hotel::AddReserva(Reserva reserva) {
    bool sobreposta = false;
    int capacidadetotal = 0;
    for (auto it = reservas.begin(); it != reservas.end(); it++){
        if(*it == reserva){
            sobreposta = true;
            break;
        }
    }
    if(sobreposta){
        cout << endl << "Reserva Impossível" << endl;
        cout << "Razão: A Reserva já existe ou sobrepõe-se a uma já existente!" << endl;
        return false;
    }
    for (auto it = reserva.quartos_res.begin(); it != reserva.quartos_res.end(); it++){
        capacidadetotal += (*it)->capacidade;
    }
    if(reserva.lugaresp <= capacidadetotal && (reserva.data_fim - reserva.data_inicio > 0)) reservas.push_back(reserva);
    else{
        cout << endl << "Reserva Impossível" << endl;
        cout << "Razão: Lugares Esperados excedem a capacidade total dos Quartos selecionados!" << endl;
        return false;
    }
    return true;
}

void Hotel::PopReserva(int idnumero) {
    for (auto it = reservas.begin(); it != reservas.end(); it++){
        if((*it).idnumero == idnumero){
            it = reservas.erase(it);
            break;
        }
    }
}

/**
 * Adiciona uma Reserva ao conjunto de reservas atuais do Hotel, ou seja,
 * aquelas que estão a ser usufruídas no momento (vetor reservas_atuais)
 * @param reserva Reserva a ser adicionada ao vetor reservas_atuais
 */
bool Hotel::AddReservasAtuais(Reserva reserva) {
    for(auto it = reservas_atuais.begin(); it != reservas_atuais.end(); it++){
        if((*it) == reserva) return false ;
    }
    reservas_atuais.push_back(reserva);
    return true;
}

/**
 * Adiciona uma Reserva ao conjunto de estadias anteriores efetuadas no Hotel, isto é,
 * que já foram usufruídas pelos clientes (vetor estadias)
 * @param reserva Reserva a ser adicionada ao vetor estadias
 */
bool Hotel::AddEstadia(Reserva reserva) {
    for(auto it = estadias.begin(); it != estadias.end(); it++){
        if((*it) == reserva) return false ;
    }
    estadias.push_back(reserva);
    return true;
}

/**
 * Adiciona um Cliente à base de dados do Hotel (um perfil que se mantem se o mesmo fizer reservas no futuro)
 * (vetor clientes)
 * @param cliente Cliente a ser adicionado ao vetor clientes
 */
bool Hotel::AddCliente(Cliente cliente) {
    for(auto it = clientes.begin(); it != clientes.end(); it++){
        if((*it) == cliente) return false ;
    }
    clientes.push_back(cliente);
    return true;
}

/**
 * Adiciona um Quarto à base de dados do Hotel (vetor quartos)
 * @param quarto Quarto a ser adicionado ao vetor quartos
 */
bool Hotel::AddQuarto(Quarto quarto) {
    for(auto it = quartos.begin(); it != quartos.end(); it++){
        if((*it) == quarto) return false ;
    }
    quartos.push_back(quarto);
    return true;
}

/**
 * Adiciona um Funcionário à base de dados do Hotel (vetor funcionários)
 * @param funcionario Funcionário a ser adicionado ao vetor funcionários
 */
bool Hotel::AddFuncionario(Funcionario funcionario) {
    for(auto it = funcionarios.begin(); it != funcionarios.end(); it++){
        if((*it) == funcionario) return false ;
    }
    funcionarios.push_back(funcionario);
    return true;
}

bool Hotel::AddFuncionarioRececao(F_Rececao funcionario_rec) {
    for(auto it = funcionarios_rececao.begin(); it != funcionarios_rececao.end(); it++){
        if((*it) == funcionario_rec) return false ;
    }
    funcionarios_rececao.push_back(funcionario_rec);
    return true;
}

bool Hotel::AddFuncionarioResponsavel(F_Responsavel funcionario_resp) {
    for(auto it = funcionarios_responsaveis.begin(); it != funcionarios_responsaveis.end(); it++){
        if((*it) == funcionario_resp) return false ;
    }
    funcionarios_responsaveis.push_back(funcionario_resp);
    return true;
}

bool Hotel::AddFuncionarioLimpeza(F_Limpeza funcionario_limpeza) {
    for(auto it = funcionarios_limpeza.begin(); it != funcionarios_limpeza.end(); it++){
        if((*it) == funcionario_limpeza) return false ;
    }
    funcionarios_limpeza.push_back(funcionario_limpeza);
    return true;
}

bool Hotel::AddFuncionarioGestor(F_Gestor funcionario_gestor) {
    for(auto it = funcionarios_gestores.begin(); it != funcionarios_gestores.end(); it++){
        if((*it) == funcionario_gestor) return false ;
    }
    funcionarios_gestores.push_back(funcionario_gestor);
    return true;
}

bool Hotel::AddServico(Servico servico) {
    for(auto it = servicos.begin(); it != servicos.end(); it++){
        if((*it) == servico) return false ;
    }
    servicos.push_back(servico);
    return true;
}

 /**
  * Valida a Reserva feita pelo cliente, certeficando-se que esta não se sobrepõe a outras feitas pelo mesmo cliente.
  * Além disso adiciona o cliente à base de dados chamando a AddCliente caso seja a primeira reserva deste.
  * @param cliente Cliente que efetuou a reserva que queremos validar
  * @param reserva Reserva que se pretende validar
  * @return true se a Reserva for válida, false caso contrário
  */
bool Hotel::Reservar(Cliente &cliente, int idnumero, data data_inicial, data data_final, int lugaresperados, vector <int> numquartos) {
     int nsize = numquartos.size();
     list <Quarto *> vq;
     for (int i = 0; nsize > i; i++){
         for (auto it = quartos.begin(); it != quartos.end(); it++){
             if((*it).numero == numquartos[i]){
                 vq.push_back(&(*it));
                 break;
             }
         }
     }
     Reserva reserva(idnumero, data_inicial, data_final, lugaresperados, vq);
    if (AddReserva(reserva)) {
        for(auto it = reservas.begin(); it != reservas.end(); it++){
            if((*it).idnumero == idnumero){
                cliente.reservas_cliente.push_back(&(*it));
                break;
            }
        }
        cliente.reservas_cliente.sort(Reserva::P_DataIcomp_Cr);
        if (!cliente.cliente_usual) {
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

bool Hotel::Reservar(int nif, int idnumero, data data_inicial, data data_final, int lugaresperados, vector<int> numquartos) {
    auto it = clientes.begin();
    bool found = false;
    for (it; it != clientes.end(); it++){
        if((*it).nif == nif) {
            found = true;
            break;
        }
    }
    if(found) return Reservar((*it), idnumero, data_inicial, data_final, lugaresperados, numquartos);
    else return false;
}

void Hotel::CancelarReserva(Cliente &cliente, int idreserva) {
    for(auto it = cliente.reservas_cliente.begin(); it != cliente.reservas_cliente.end(); it++){
        if((*it)->idnumero == idreserva)  it = cliente.reservas_cliente.erase(it);
    }
    PopReserva(idreserva);
}

void Hotel::CancelarReserva(int nif, int idreserva) {
    auto it = clientes.begin();
    bool found = false;
    for (it; it != clientes.end(); it++){
        if((*it).nif == nif) {
            found = true;
            break;
        }
    }
    if(found) return CancelarReserva((*it), idreserva);
}

/**
 * Realiza o Check-In, a reserva mais recente do cliente deixa de pertencer ao seu vetor reservas_cliente
 * e passa a ser a sua estadia atual, visto que este entra no hotel
 * Atualiza também outras informações como por exemplo o facto de o cliente se encontrar no hotel passando nohotel a true
 * @param cliente Cliente que está a realizar o Check-In
 */
void Hotel::CheckIn(Cliente &cliente) {
    Reserva reserva = *cliente.reservas_cliente.front();
    cliente.estadia_atual = &reserva;
    ApagarReservaL(cliente.reservas_cliente, &reserva);
    cliente.nohotel = true;
    ApagarReservaL(reservas, reserva);
    AddReservasAtuais(reserva);
}

void Hotel::CheckIn(int nif) {
    auto it = clientes.begin();
    bool found = false;
    for (it; it != clientes.end(); it++){
        if((*it).nif == nif) {
            found = true;
            break;
        }
    }
    if(found) return CheckIn((*it));
}

/**
 * Realiza o Check-Out, a estadia atual do cliente em questão passa a pertencer às suas estadias_anteriores
 * Atualiza outras informações: o facto do cliente já não estar no hotel passando nohotel a false
 * @param cliente Cliente que está a realizar o Check-Out
 */
void Hotel::CheckOut(Cliente &cliente) {
    Reserva reserva = *cliente.estadia_atual;
    cliente.estadias_anteriores.push_back(&reserva);
    cliente.estadia_atual = NULL;
    AddEstadia(reserva);
    ApagarReservaL(reservas_atuais, reserva);
    cliente.nohotel = false;
    if(!cliente.cliente_usual) cliente.cliente_usual = true;
}

void Hotel::CheckOut(int nif) {
    auto it = clientes.begin();
    bool found = false;
    for (it; it != clientes.end(); it++){
        if((*it).nif == nif) {
            found = true;
            break;
        }
    }
    if(found) return CheckOut((*it));
}


//Hotel Database Funcs
const list<Funcionario> Hotel::Pesquisa_F_Salario(bool inverso) {
    list <Funcionario> pesquisa_salario = funcionarios;
    if(inverso) pesquisa_salario.sort(Funcionario::Salariocomp_Decr);
    else pesquisa_salario.sort(Funcionario::Salariocomp_Cr);
    return pesquisa_salario;
}

const list<Funcionario> Hotel::Pesquisa_F_Cargo() {
    list <Funcionario> pesquisa_cargo = funcionarios;
    pesquisa_cargo.sort(Funcionario::Cargocomp);
    return pesquisa_cargo;
}

const list<Reserva> Hotel::RestringirClientesNovos(bool clientes_novos){
    list<Reserva> resultado;
    if(clientes_novos) {
        for (auto it = reservas.begin(); it != reservas.end(); it++){
            if ((*it).primeiravez) resultado.push_back(*it);
        }
    }
    else resultado = reservas;
    return resultado;
}

const list<Reserva> Hotel::RestringirClientesNovos(bool clientes_novos, list<Reserva> creservas) {
    list<Reserva> resultado;
    if(clientes_novos) {
        for (auto it = creservas.begin(); it != creservas.end(); it++){
            if ((*it).primeiravez) resultado.push_back(*it);
        }
    }
    else resultado = creservas;
    return resultado;
}

const list<Reserva> Hotel::Pesquisa_Reservas_Duracao(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    list <Reserva> pesquisa_duracao = RestringirClientesNovos(clientes_novos);
    if(inverso) pesquisa_duracao.sort(Reserva::Duracaocomp_Decr);
    else pesquisa_duracao.sort(Reserva::Duracaocomp_Cr);
    if(clientes_novos_primeiro) pesquisa_duracao.sort(Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const list<Reserva> Hotel::Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    list <Reserva> pesquisa_duracao = RestringirClientesNovos(clientes_novos);
    if(inverso) pesquisa_duracao.sort(Reserva::DataIcomp_Decr);
    else pesquisa_duracao.sort(Reserva::DataIcomp_Cr);
    if(clientes_novos_primeiro) pesquisa_duracao.sort(Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const list<Reserva> Hotel::Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, list<Reserva> creservas) {
    list <Reserva> pesquisa_duracao = RestringirClientesNovos(clientes_novos, creservas);
    if(inverso) pesquisa_duracao.sort(Reserva::DataIcomp_Decr);
    else pesquisa_duracao.sort(Reserva::DataIcomp_Cr);
    if(clientes_novos_primeiro) pesquisa_duracao.sort(Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const list<Reserva> Hotel::Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    list <Reserva> pesquisa_duracao = RestringirClientesNovos(clientes_novos);
    if(inverso) pesquisa_duracao.sort(Reserva::DataFcomp_Decr);
    else pesquisa_duracao.sort(Reserva::DataFcomp_Cr);
    if(clientes_novos_primeiro) pesquisa_duracao.sort(Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const list<Reserva> Hotel::Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, list<Reserva> creservas) {
    list <Reserva> pesquisa_duracao = RestringirClientesNovos(clientes_novos, creservas);
    if(inverso) pesquisa_duracao.sort(Reserva::DataFcomp_Decr);
    else pesquisa_duracao.sort(Reserva::DataFcomp_Cr);
    if(clientes_novos_primeiro) pesquisa_duracao.sort(Reserva::PrimeiraReserva);
    return pesquisa_duracao;
}

const list<Reserva> Hotel::Pesquisa_Reservas_Preco(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    list <Reserva> pesquisa_preco = RestringirClientesNovos(clientes_novos);
    if(inverso) pesquisa_preco.sort(Reserva::Precocomp_Decr);
    else pesquisa_preco.sort(Reserva::Precocomp_Cr);
    if(clientes_novos_primeiro) pesquisa_preco.sort(Reserva::PrimeiraReserva);
    return pesquisa_preco;
}

list<Reserva *> Hotel::ReservasSobrepostas(list<Reserva> reservastotais, data datai, data dataf) {
    bool done = false;
    list <Reserva> lri = Pesquisa_Reservas_DataI(0, 0, 0, reservastotais);
    vector<Reserva> ri = LtoV(lri);
    int risize = ri.size();
    int vmin = 0, vmax = ri.size();
    int vmedio = vmax/2;
    int vmedioant = 0;
    while(vmedio != vmax || vmedio != vmin){
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
    lri = VtoL(ri);
    list <Reserva> lrf = Pesquisa_Reservas_DataF(0, 0, 0, lri);
    vector<Reserva> rf = LtoV(lrf);
    int rfsize = rf.size();
    vmin = 0, vmax = rf.size();
    vmedio = vmax/2;
    vmedioant = 0;
    done = false;
    while(vmedio != vmax || vmedio != vmin){
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
    lrf = VtoL(rf);
    list <Reserva *> resultado;
    for(auto it = lrf.begin(); it != lrf.end(); it++){
        for(auto itt = reservas.begin(); itt != reservas.end(); itt++){
            if((*it).idnumero == (*itt).idnumero){
                resultado.push_back(&(*itt));
                break;
            }
        }
    }
    return resultado;
}

list <Reserva *> Hotel::Reservas_Fin(int mesp, int anop){
    data dataf = DiaFinal(mesp, anop);
    data datai = {.dia = 1, .mes = mesp, .ano = anop};
    list <Reserva> reservastotais = reservas;
    reservastotais.insert(reservastotais.end(), reservas_atuais.begin(), reservas_atuais.end());
    reservastotais.insert(reservastotais.end(), estadias.begin(), estadias.end());
    return ReservasSobrepostas(reservastotais, datai, dataf);
}

list<Quarto *> Hotel::Quartos_Disponiveis(data data_inicial, data data_final) {
    list <Quarto > quartos_disponiveis = quartos;
    list <Reserva> reservas_analise = reservas;
    reservas_analise.insert(reservas_analise.end(), reservas_atuais.begin(), reservas_atuais.end());
    list <Reserva *> reservas_sobrepostas = ReservasSobrepostas(reservas_analise, data_inicial, data_final);
    for(auto it = reservas_sobrepostas.begin(); it != reservas_sobrepostas.end(); it++){
        for(auto itt = (*it)->quartos_res.begin(); itt != (*it)->quartos_res.end(); itt++){
            ApagarElementoL(quartos_disponiveis, *(*itt));
        }
    }
    quartos_disponiveis.sort(Quarto::Numcomp_Cr);
    list<Quarto *> resultado;
    for(auto it = quartos_disponiveis.begin(); it != quartos_disponiveis.end(); it++){
        for(auto itt = quartos.begin(); itt != quartos.end(); itt++){
            if((*it).numero == (*itt).numero){
                resultado.push_back(&(*itt));
                break;
            }
        }
    }
    return resultado;
}

// Hotel Finances Functions

float Hotel::CustosTotais(float impostos, float despesasfixas) {
    float salarios = 0;
    float preco_produtos = 0;
    for (auto it = funcionarios.begin(); it != funcionarios.end(); it++){
        salarios += (*it).salario;
    }
    for (auto it = produtos.begin(); it != produtos.end(); it++){
        preco_produtos +=  (*it).preco;
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
    list <Reserva *> reservas_totais = Reservas_Fin(mes, ano);
    cout << endl << "Quartos Reservados (Total ou Parcialmente) neste mês fiscal (" << mes << "-" << ano <<"): ";
    int realdur;
    float preco_res;
    float count_rquartos = 0, rendimento = 0;
    for (auto it = reservas_totais.begin(); it != reservas_totais.end(); it++){
        preco_res = (*it)->preco;

        if((*it)->data_inicio >= data_inicial && (*it)->data_fim <= data_final) realdur = (*it)->duracao;
        if((*it)->data_inicio >= data_inicial && (*it)->data_fim > data_final) realdur = data_final - (*it)->data_inicio + 1;
        if((*it)->data_inicio < data_inicial && (*it)->data_fim <= data_final) realdur = (*it)->data_fim - data_inicial + 1;
        if((*it)->data_inicio < data_inicial && (*it)->data_fim > data_final) realdur = data_final - data_inicial + 1;

        count_rquartos += preco_res * realdur;

        cout << "A Reserva " << (*it)->idnumero << " tem uma duração neste mês de " << realdur << " dias e tem um custo de " << preco_res << " euros." << " (Preço Total de " << preco_res * realdur << ")" << endl;
        }
    rendimento += count_rquartos;
    for (auto it = servicos.begin(); it != servicos.end(); it++){
        if((*it).data_realizacao >= data_inicial && (*it).data_realizacao <= data_final) rendimento += (*it).lucro;
    }
    return rendimento;
    }

float Hotel::BalancoFin(int mes, int ano, float impostos, float despesasfixas) {
    return RendimentosTotais(mes, ano) - CustosTotais(impostos, despesasfixas);
}

tipo_cargo Hotel::EscolherCargo() {
    tipo_cargo cargo;
    int n_rececaosimples = 0, n_rececaoresp = 0, n_limpeza = 0, n_gestor = 0;
    for (auto it = funcionarios.begin(); it != funcionarios.end(); it++){
        switch((*it).cargo){
            case naodef:
                break;
            case frececao:
                n_rececaosimples++;
                break;
            case fresponsavel:
                n_rececaoresp++;
                break;
            case flimpeza:
                n_limpeza++;
                break;
            case fgestor:
                n_gestor++;
                break;
            default:
                break;
        }
    }
    int menor = n_rececaosimples;
    tipo_cargo cmenor = frececao;
    if(menor > n_rececaoresp){
        menor = n_rececaoresp;
        cmenor = fresponsavel;
    }
    if(menor > n_limpeza){
        menor = n_limpeza;
        cmenor = flimpeza;
    }
    if(menor > n_gestor){
        menor = n_gestor;
        cmenor = fgestor;
    }
    cargo = cmenor;
    return cargo;
}

tipo_turno Hotel::EscolherTurno() {
    int countdia = 0, countnoite = 0;
    for (auto it = funcionarios_limpeza.begin(); it != funcionarios_limpeza.end(); it++){
        if((*it).turno == dia) countdia++;
        else countnoite++;
    }
    if(countdia > countnoite) return noite;
    else return dia;
}

int Hotel::EscolherPiso() {
    vector <int> pisos, pvigiados;
    vector <pair<int, int>> pcounter;
    for (auto it = quartos.begin(); it != quartos.end(); it++){
        pisos.push_back((*it).piso);
    }
    sort(pisos.begin(), pisos.end());
    sort(unique(pisos.begin(), pisos.end()), pisos.end());
    int psize = pisos.size();
    for(int i = 0; psize > i; i++) pcounter.push_back(make_pair(pisos[i], 0));
    for(auto it = funcionarios_responsaveis.begin(); it != funcionarios_responsaveis.end(); it++) {
        int pvsize = (*it).pisos_resp.size();
        for(int a = 0; pvsize > a; a++){
            pvigiados.push_back((*it).pisos_resp[a]);
        }
    }
    sort(pcounter.begin(), pcounter.end());
    int pcindex, pcsize = pcounter.size();
    int pvigsize = pvigiados.size(), pisoesc;
    for(int i = 0; pvigsize > i; i++){
        pcindex = pvigiados[i] - pcounter[0].first;
        pcounter[pcindex].second++;
    }
    pisoesc = pcounter[0].first;
    int counter = pcounter[0].second;
    for(int i = 1; pcindex > i; i++){
        if(pcounter[i].second < counter){
            pisoesc = pcounter[i].first;
            counter = pcounter[i].second;
        }
    }
    return pisoesc;
}


void Hotel::Contratar(string nome, int nif, tipo_cargo cargo) {
    if(cargo == frececao){
        F_Rececao FR(nome, nif, 0, 800);
        AddFuncionario(FR);
        AddFuncionarioRececao(FR);
    }
    if(cargo == fresponsavel){
        vector <int> pisos;
        pisos.push_back(EscolherPiso());
        F_Responsavel FRR(nome, nif, 0, 1200, pisos);
        AddFuncionario(FRR);
        AddFuncionarioResponsavel(FRR);
    }
    if(cargo == flimpeza){
        tipo_turno turno = EscolherTurno();
        F_Limpeza FL(nome, nif, 0, 800, turno);
        AddFuncionario(FL);
        AddFuncionarioLimpeza(FL);
    }
    if(cargo == fgestor){
        F_Gestor FG(nome, nif, 0, 2000);
        AddFuncionario(FG);
    }
    Funcionario F(nome, nif, 0, 600);
    AddFuncionario(F);
}

void Hotel::Contratar(string nome, int nif){
    tipo_cargo cargo = EscolherCargo();
    return Contratar(nome, nif, cargo);
}

void Hotel::Despedir(int nif, tipo_cargo cargo){
    switch (cargo){
        case frececao:
            for(auto it = funcionarios_rececao.begin(); it != funcionarios_rececao.end(); it++){
                if((*it).nif == nif){
                    it = funcionarios_rececao.erase(it);
                    break;
                }
            }
            break;
        case fresponsavel:
            for(auto it = funcionarios_responsaveis.begin(); it != funcionarios_responsaveis.end(); it++){
                if((*it).nif == nif){
                    it = funcionarios_responsaveis.erase(it);
                    break;
                }
            }
            break;
        case flimpeza:
            for(auto it = funcionarios_limpeza.begin(); it != funcionarios_limpeza.end(); it++){
                if((*it).nif == nif){
                    it = funcionarios_limpeza.erase(it);
                    break;
                }
            }
            break;
        case fgestor:
            for(auto it = funcionarios_gestores.begin(); it != funcionarios_gestores.end(); it++){
                if((*it).nif == nif){
                    it = funcionarios_gestores.erase(it);
                    break;
                }
            }
            break;
        default:
            break;
    }
    for(auto it = funcionarios.begin(); it != funcionarios.end(); it++){
        if((*it).nif == nif){
            it = funcionarios.erase(it);
            break;
        }
    }
}

void Hotel::Despedir(int nif) {
    int cmaior = funcionarios_rececao.size();
    tipo_cargo cargoesc = frececao;
    if(funcionarios_responsaveis.size() > cmaior){
        cargoesc = fresponsavel;
        cmaior = funcionarios_responsaveis.size();
    }
    if(funcionarios_limpeza.size() > cmaior){
        cargoesc = flimpeza;
        cmaior = funcionarios_limpeza.size();
    }
    if(funcionarios_gestores.size() > cmaior){
        cargoesc = fgestor;
        cmaior = funcionarios_gestores.size();
    }

    Despedir(nif, cargoesc);
}

void Hotel::PrestarServico(Cliente &cliente, Servico servico) {
    AddServico(servico);
    for(auto it = servicos.begin(); it != servicos.end(); it++){
        if((*it) == servico){
            cliente.servicos_consumidos.push_back(&(*it));
            break;
        }
    }
}

void Hotel::PrestarServico(int nif, Servico servico) {
    auto it = clientes.begin();
    bool found = false;
    for (it; it != clientes.end(); it++){
        if((*it).nif == nif) {
            found = true;
            break;
        }
    }
    if(found) return PrestarServico((*it), servico);
}

void Hotel::PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa){
    return PrestarServico(nif, Servico(nome, idnumero, data_realizacao, taxa));
}

void Hotel::PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa, vector <int> funcsnif){
    list <Funcionario *> lpf;
    int fnsize = funcsnif.size();
    for(int i = 0; fnsize > i; i++){
        for(auto it = funcionarios.begin(); it != funcionarios.end(); it++){
            if((*it).nif == funcsnif[i]){
                lpf.push_back(&(*it));
                break;
            }
        }
    }
    return PrestarServico(nif, Servico(nome, idnumero, data_realizacao, taxa, lpf));
}

void Hotel::PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa, vector <int> numprods, float margem_lucro){
    list <Produto *> lpp;
    int npsize = numprods.size();
    for(int i = 0; npsize > i; i++){
        for(auto it = produtos.begin(); it != produtos.end(); it++){
            if((*it).numero == numprods[i]){
                lpp.push_back(&(*it));
                break;
            }
        }
    }
    return PrestarServico(nif, Servico(nome, idnumero, data_realizacao, taxa, lpp, margem_lucro));
}

void Hotel::PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa, vector <int> funcsnif, vector <int> numprods, float margem_lucro){
    list <Funcionario *> lpf;
    int fnsize = funcsnif.size();
    for(int i = 0; fnsize > i; i++){
        for(auto it = funcionarios.begin(); it != funcionarios.end(); it++){
            if((*it).nif == funcsnif[i]){
                lpf.push_back(&(*it));
                break;
            }
        }
    }
    list <Produto *> lpp;
    int npsize = numprods.size();
    for(int i = 0; npsize > i; i++){
        for(auto it = produtos.begin(); it != produtos.end(); it++){
            if((*it).numero == numprods[i]){
                lpp.push_back(&(*it));
                break;
            }
        }
    }
    return PrestarServico(nif, Servico(nome, idnumero, data_realizacao, taxa, lpf, lpp, margem_lucro));
}


void Hotel::Promocoes(F_Gestor fgestor, vector <int> numquartos){
    int nqsize = numquartos.size();
    list <Quarto *> lq;
    for(int i = 0; nqsize > i; i++){
        for(auto it = quartos.begin(); it != quartos.end(); it++){
            if(numquartos[i] == (*it).numero){
                lq.push_back(&(*it));
                break;
            }
        }
    }
    return fgestor.Promocoes(lq);
}

Produto Hotel::EscolherProduto(F_Gestor fgestor, vector<int> numprodutos) {
    int npsize = numprodutos.size();
    list <Produto *> lp;
    for(int i = 0; npsize > i; i++){
        for(auto it = produtos.begin(); it != produtos.end(); it++){
            if(numprodutos[i] == (*it).numero){
                lp.push_back(&(*it));
                break;
            }
        }
    }
    return fgestor.Escolher_Prod(lp);
}

Produto Hotel::EscolherProduto(F_Gestor fgestor, list<Produto *> lprodutos) {
    return fgestor.Escolher_Prod(lprodutos);
}


void Hotel::ImportarQuartos(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        cout << endl << "O Ficheiro não abre!" << endl;
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Quartos" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    int tquarto, piso, numero, capacidade;
    float preco;
    getline(inficheiro, line);
    while(line != "" && !inficheiro.eof()){
        stringstream ss(line);
        ss >> tquarto >> piso >> numero >> capacidade >> preco;
        AddQuarto(Quarto(static_cast<tipo_quarto>(tquarto), piso, numero, capacidade, preco));
        getline(inficheiro, line);
    }
    inficheiro.close();
}

void Hotel::ImportarClientes(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if (inficheiro.fail()) {
        cout << endl << "O Ficheiro não abre!" << endl;
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while (line != "Clientes" && !inficheiro.eof()) {
        getline(inficheiro, line);
    }
    string nomet= "", nomep = "";
    int nif, usual;
    getline(inficheiro, line);
    while (line != "" && !inficheiro.eof()) {
        nomet= "";
        nomep = "";
        usual = -1;
        stringstream ss(line);
        while(nomep != ","){
            if(nomet != "") nomet += " ";
            nomet += nomep;
            ss >> nomep;
        }
        ss >> nif >> usual;
        if(usual != -1) AddCliente(Cliente(nomet, nif, usual));
        else AddCliente(Cliente(nomet, nif));
        getline(inficheiro, line);
    }
    inficheiro.close();
}

void Hotel::ImportarFuncionarios(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if (inficheiro.fail()) {
        cout << endl << "O Ficheiro não abre!" << endl;
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while (line != "Funcionários" && !inficheiro.eof()) {
        getline(inficheiro, line);
    }
    string nomet= "", nomep = "";
    vector <int> pisos;
    int nif, anos_servico, avaliacao, turno, cargo, piso;
    float salario;
    getline(inficheiro, line);
    while (line != "" && !inficheiro.eof()) {
        nomet= "";
        nomep = "";
        cargo = 0;
        avaliacao = -1;
        pisos.clear();
        stringstream ss(line);
        while(nomep != ","){
            if(nomet != "") nomet += " ";
            nomet += nomep;
            ss >> nomep;
        }
        ss >> nif >> anos_servico >> salario >> cargo;
        cargo = static_cast<tipo_cargo>(cargo);
        switch (cargo){
            case frececao:
                AddFuncionario(F_Rececao(nomet, nif, anos_servico, salario));
                AddFuncionarioRececao(F_Rececao(nomet, nif, anos_servico, salario));
                break;
            case fresponsavel:
                while(ss >> piso){
                    pisos.push_back(piso);
                }
                AddFuncionario(F_Responsavel(nomet, nif, anos_servico, salario, pisos));
                AddFuncionarioResponsavel(F_Responsavel(nomet, nif, anos_servico, salario, pisos));
                break;
            case flimpeza:
                ss >> turno;
                AddFuncionario(F_Limpeza(nomet, nif, anos_servico, salario, static_cast<tipo_turno>(turno)));
                AddFuncionarioLimpeza(F_Limpeza(nomet, nif, anos_servico, salario, static_cast<tipo_turno>(turno)));
                break;
            case fgestor:
                ss >> avaliacao;
                if(avaliacao == -1){
                    AddFuncionario(F_Gestor(nomet, nif, anos_servico, salario));
                    AddFuncionarioGestor(F_Gestor(nomet, nif, anos_servico, salario));
                }
                else{
                    AddFuncionario(F_Gestor(nomet, nif, anos_servico, salario, static_cast<nota_avaliacao>(avaliacao)));
                    AddFuncionarioGestor(F_Gestor(nomet, nif, anos_servico, salario, static_cast<nota_avaliacao>(avaliacao)));
                }
                break;
            default:
                AddFuncionario(Funcionario(nomet, nif, anos_servico, salario));
                break;
        }
        getline(inficheiro, line);
    }
    inficheiro.close();
}

void Hotel::ImportarProdutos(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        cout << endl << "O Ficheiro não abre!" << endl;
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Produtos" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    string nomet= "", nomep = "";
    int tprod, qualidade, numero;
    float preco;
    getline(inficheiro, line);
    while(line != "" && !inficheiro.eof()){
        nomet= "";
        nomep = "";
        stringstream ss(line);
        while(nomep != ","){
            if(nomet != "") nomet += " ";
            nomet += nomep;
            ss >> nomep;
        }
        ss >>numero >> tprod >> qualidade >> preco;
        AddProduto(Produto(nomet, numero, static_cast<tipo_produto>(tprod), static_cast<nota_avaliacao>(qualidade), preco));
        getline(inficheiro, line);
    }
    inficheiro.close();
}

void Hotel::ImportarReservas(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        cout << endl << "O Ficheiro não abre!" << endl;
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Reservas" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    int nifcliente, idnum, lugaresp, qnum, d;
    vector <int> numquartos;
    data datai, dataf;
    getline(inficheiro, line);
    while(line != "" && !inficheiro.eof()){
        numquartos.clear();
        stringstream ss(line);
        ss >> nifcliente >> idnum;
        ss >> d; datai.dia = abs(d);
        ss >> d; datai.mes = abs(d);
        ss >> d; datai.ano = abs(d);
        ss >> d; dataf.dia = abs(d);
        ss >> d; dataf.mes = abs(d);
        ss >> d; dataf.ano = abs(d);
        ss >> lugaresp;
        while(ss >> qnum){
            numquartos.push_back(qnum);
        }
        Reservar(nifcliente, idnum, datai, dataf, lugaresp, numquartos);
        getline(inficheiro, line);
    }
    inficheiro.close();
}

void Hotel::ImportarServicos(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        cout << endl << "O Ficheiro não abre!" << endl;
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Serviços" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    string nomet, nomep, controlo, sf, sp;
    int idnum, nifcliente, d;
    data data_realizacao;
    float taxa, mlucro;
    vector <int> fnifs, pnums;
    getline(inficheiro, line);
    while(line != "" && !inficheiro.eof()){
        fnifs.clear();
        pnums.clear();
        nomet= "";
        nomep = "";
        sf = "";
        sp = "";
        controlo = "";
        stringstream ss(line);
        ss >> nifcliente;
        while(nomep != ","){
            if(nomet != "") nomet += " ";
            nomet += nomep;
            ss >> nomep;
        }
        ss >> idnum;
        ss >> d; data_realizacao.dia = abs(d);
        ss >> d; data_realizacao.mes = abs(d);
        ss >> d; data_realizacao.ano = abs(d);
        ss >> taxa;
        ss >> controlo;
        if (controlo == "") PrestarServico(nifcliente, nomet, idnum, data_realizacao, taxa);
        else{
            if (controlo == "f"){
                while(ss >> sf && sf != ","){
                    if(sf != "" && sf != ",") fnifs.push_back(stoi(sf));
                }
                ss >> controlo;
                if(controlo == "p"){
                    while(ss >> sp && sp != ","){
                        if(sp != "" && sp != ",") pnums.push_back(stoi(sp));
                    }
                    ss >> mlucro;
                    PrestarServico(nifcliente, nomet, idnum, data_realizacao, taxa, fnifs, pnums, mlucro);
                }
                else PrestarServico(nifcliente, nomet, idnum, data_realizacao, taxa, fnifs);
            }
            else{
                while(ss >> sp && sp != ","){
                    if(sp != "" && sp != ",") pnums.push_back(stoi(sp));
                }
                ss >> mlucro;
                PrestarServico(nifcliente, nomet, idnum, data_realizacao, taxa, pnums, mlucro);
            }
        }
        getline(inficheiro, line);
    }
    inficheiro.close();
}

void Hotel::EscreverHotel(string nomedoficheiro) {
    if(nomedoficheiro.substr(nomedoficheiro.size() - 4) != ".txt") nomedoficheiro += ".txt";
    ofstream outficheiro(nomedoficheiro);
    outficheiro << "Hotel" << endl;
    outficheiro << nome << endl << endl;

    outficheiro << "Quartos" << endl;
    for(auto it = quartos.begin(); it != quartos.end(); it++){
        outficheiro << (*it).tquarto << " " << (*it).piso << " " << (*it).numero << " " << (*it).capacidade << " " << (*it).preco << endl;
    }

    outficheiro << endl;
    outficheiro << "Produtos" << endl;
    for(auto it = produtos.begin(); it != produtos.end(); it++){
        outficheiro << (*it).nome << " , " << (*it).numero << " " << (*it).tprod << " " << (*it).qualidade << " " << (*it).preco << endl;
    }

    outficheiro << endl;
    outficheiro << "Clientes" << endl;
    for(auto it = clientes.begin(); it != clientes.end(); it++){
        outficheiro << (*it).nome << " , " << (*it).nif << " " << (*it).cliente_usual << endl;
    }

    outficheiro << endl;
    outficheiro << "Funcionários" << endl;
    for(auto it = funcionarios_rececao.begin(); it != funcionarios_rececao.end(); it++){
        outficheiro << (*it).nome << " , " << (*it).nif << " " << (*it).anos_servico << " " << (*it).salario << " " << (*it).cargo << endl;
    }
    for(auto it = funcionarios_responsaveis.begin(); it != funcionarios_responsaveis.end(); it++){
        string pisos = "";
        for(int a = 0; (*it).pisos_resp.size() > a; a++){
            pisos += to_string((*it).pisos_resp[a]) + " ";
        }
        outficheiro << (*it).nome << " , " << (*it).nif << " " << (*it).anos_servico << " " << (*it).salario << " " << (*it).cargo << " " << pisos << endl;
    }
    for(auto it = funcionarios_limpeza.begin(); it != funcionarios_limpeza.end(); it++){
        outficheiro << (*it).nome << " , " << (*it).nif << " " << (*it).anos_servico << " " << (*it).salario << " " << (*it).cargo << " " << (*it).turno << endl;
    }
    for(auto it = funcionarios_gestores.begin(); it != funcionarios_gestores.end(); it++){
        outficheiro << (*it).nome << " , " << (*it).nif << " " << (*it).anos_servico << " " << (*it).salario << " " << (*it).cargo << " " << (*it).av_prestacao << endl;
    }
    for(auto it = funcionarios.begin(); it != funcionarios.end(); it++){
        if((*it).cargo == naodef) outficheiro << (*it).nome << " , " << (*it).nif << " " << (*it).anos_servico << " " << (*it).salario << " " << (*it).cargo << endl;
    }

    outficheiro << endl;
    outficheiro << "Serviços" << endl;
    for(auto it = servicos.begin(); it != servicos.end(); it++){
        bool cliente_enc = false;
        string cliente_nif = "";
        for(auto itc = clientes.begin(); itc != clientes.end() && !cliente_enc; itc++){
            for(auto itsc = (*itc).servicos_consumidos.begin(); itsc != (*itc).servicos_consumidos.end() && !cliente_enc; itsc++){
                if(*(*itsc) == (*it)){
                    cliente_nif = to_string((*itc).nif);
                    cliente_enc = true;
                    break;
                }
            }
        }
        string focup = "f ";
        string prodcons = "p ";
        for(auto itf = (*it).funcionarios_ocupados.begin(); itf != (*it).funcionarios_ocupados.end(); itf++){
            focup += to_string((*itf)->nif) + " ";
        }
        for(auto itp = (*it).produtos_consumidos.begin(); itp != (*it).produtos_consumidos.end(); itp++){
            prodcons += to_string((*itp)->numero) + " ";
        }
        outficheiro << cliente_nif << " " << (*it).nome << " , " << (*it).idnumero << " " << (*it).data_realizacao << " " << (*it).taxa;
        if(focup == "f " && prodcons == "p ") outficheiro << endl;
        else{
            if(focup != "f "){
                outficheiro << " " << focup;
                if(prodcons != "p ") outficheiro << ", " << prodcons + ", " << (*it).margem_lucro << endl;
                else outficheiro << endl;
            }
            else{
                if(prodcons != "p ") outficheiro << " " << prodcons + ", " << (*it).margem_lucro << endl;
            }
        }
    }

    outficheiro << endl;
    outficheiro << "Reservas" << endl;
    for(auto it = clientes.begin(); it != clientes.end(); it++){
        for(auto itt = (*it).reservas_cliente.begin(); itt != (*it).reservas_cliente.end(); itt++){
            string numquartos = "";
            for(auto ittt = (*itt)->quartos_res.begin(); ittt != (*itt)->quartos_res.end(); ittt++){
                numquartos += to_string((*ittt)->numero) + " ";
            }
            outficheiro << (*it).nif << " " << (*itt)->idnumero << " " << (*itt)->data_inicio << " " << (*itt)->data_fim << " " << (*itt)->lugaresp << " " << numquartos << endl;
        }
    }
    outficheiro.close();
}

//Utils

template <class T>
int Hotel::EncontrarIndex(vector<T> v, T elemento) {
    int vsize = v.size();
    for(int i = 0; vsize > i; i++){
        if (v[i] == elemento) return i;
    }
    return -1;
}


int Hotel::EncontrarIndexReserva(vector<Reserva> vr, Reserva r) {
    int vrsize = vr.size();
    for(int i = 0; vrsize > i; i++){
        if (vr[i].idnumero == r.idnumero) return i;
    }
    return -1;
}

int Hotel::EncontrarIndexReserva(vector<Reserva *> vr, Reserva *r) {
    int vrsize = vr.size();
    for(int i = 0; vrsize > i; i++){
        if (vr[i]->idnumero == r->idnumero) return i;
    }
    return -1;
}

template <class T>
void Hotel::ApagarElementoL(list<T> l, T elemento) {
    for(auto it = l.begin(); it != l.end(); it++){
        if(*it == elemento){
            it = l.erase(it);
            break;
        }
    }
}

void Hotel::ApagarReservaL(list<Reserva> lr, Reserva r) {
    for(auto it = lr.begin(); it != lr.end(); it++){
        if((*it).idnumero == r.idnumero) {
            it = lr.erase(it);
            break;
        }
    }
}

void Hotel::ApagarReservaL(list<Reserva *> lr, Reserva *r) {
    for(auto it = lr.begin(); it != lr.end(); it++){
        if((*it)->idnumero == r->idnumero){
            it = lr.erase(it);
            break;
        }
    }
}

template <class T>
vector<T> Hotel::LtoV(const list<T> &l) {
    vector<T> v;
    for(auto it = l.begin(); it != l.end(); it++){
        v.push_back(*it);
    }
    return v;
}

template <class T>
list<T> Hotel::VtoL(const vector<T> &v) {
    list<T> l;
    for(unsigned i = 0; v.size() > i; i++){
        l.push_back(v[i]);
    }
    return l;
}


list <Reserva *> Hotel::PointerListReserva(list <Reserva> l){
    list <Reserva *> pl;
    for(auto it = l.begin(); it != l.end(); it++){
        Reserva * pr;
        pr = (&(*it));
        pl.push_back(pr);
    }
    return pl;
}

list <Funcionario *> Hotel::PointerListFunc(list<Funcionario> l) {
    list <Funcionario *> pl;
    for(auto it = l.begin(); it != l.end(); it++){
        Funcionario * pr;
        pr = (&(*it));
        pl.push_back(pr);
    }
    return pl;
}

list <Quarto *> Hotel::PointerListQuarto(list<Quarto> l) {
    list <Quarto *> pl;
    for(auto it = l.begin(); it != l.end(); it++){
        Quarto * pr;
        pr = (&(*it));
        pl.push_back(pr);
    }
    return pl;
}

list <Cliente *> Hotel::PointerListCliente(list <Cliente> l){
    list <Cliente *> pl;
    for(auto it = l.begin(); it != l.end(); it++){
        Cliente * pr;
        pr = (&(*it));
        pl.push_back(pr);
    }
    return pl;
}

list <Produto *> Hotel::PointerListProduto(list <Produto> l){
    list <Produto *> pl;
    for(auto it = l.begin(); it != l.end(); it++){
        Produto * pr;
        pr = (&(*it));
        pl.push_back(pr);
    }
    return pl;
}

list <Reserva> Hotel::ListReserva(list<Reserva *> pl) {
    list <Reserva> l;
    for(auto it = pl.begin(); it != pl.end(); it++){
        Reserva elemento = *(*it);
        l.push_back(elemento);
    }
    return l;
}

list <Funcionario> Hotel::ListFunc(list <Funcionario *> pl){
    list <Funcionario> l;
    for(auto it = pl.begin(); it != pl.end(); it++){
        Funcionario elemento = *(*it);
        l.push_back(elemento);
    }
    return l;
}

list <Quarto> Hotel::ListQuarto(list <Quarto *> pl){
    list <Quarto> l;
    for(auto it = pl.begin(); it != pl.end(); it++){
        Quarto elemento = *(*it);
        l.push_back(elemento);
    }
    return l;
}

list <Cliente> Hotel::ListCliente(list <Cliente *> pl){
    list <Cliente> l;
    for(auto it = pl.begin(); it != pl.end(); it++){
        Cliente elemento = *(*it);
        l.push_back(elemento);
    }
    return l;
}

list <Produto> Hotel::ListProduto(list <Produto *> pl){
    list <Produto> l;
    for(auto it = pl.begin(); it != pl.end(); it++){
        Produto elemento = *(*it);
        l.push_back(elemento);
    }
    return l;
}
