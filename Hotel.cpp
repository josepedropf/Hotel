#include "Hotel.h"

/**
 * Construtor da classe Hotel
 * @param nome nome do Hotel
 */
Hotel::Hotel(string nome): frota(Veiculo()) {
    this->nome = nome;
}

/**
 * Constroi uma lista com apontadores para Clientes que se encontram no Hotel
 * @return lista com apontadores para Clientes que se encontram no Hotel
 */
const list <Cliente *> Hotel::GetClientesnoHotel() {
    list <Cliente *> resultado;
    for(auto it = clientes.begin(); it != clientes.end(); it++){
        if((*it).nohotel) resultado.push_back(&(*it));
    }
    return resultado;
}

// Hotel Database Add
/**
 * Adicionar Produto à lista de Produtos
 * @param produto Produto a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddProduto(Produto produto) {
    for(auto it = produtos.begin(); it != produtos.end(); it++){
        if(*it == produto) return false ;
    }
    produtos.push_back(produto);
    return true;
}

/**
 * Adicionar Reserva à lista de reservas
 * @param reserva Reserva a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
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
        throw MembroRepetido("Reserva", reserva.idnumero);
        return false;
    }
    for (auto it = reserva.quartos_res.begin(); it != reserva.quartos_res.end(); it++){
        capacidadetotal += (*it)->capacidade;
    }
    if(reserva.lugaresp <= capacidadetotal && (reserva.data_fim - reserva.data_inicio > 0)) reservas.push_back(reserva);
    else{
        throw CapacidadeExcesso(reserva.lugaresp);
        return false;
    }
    return true;
}

/**
 * Retirar a Reserva com o idnumero especificado da lista de reservas
 * @param idnumero di da Reserva a retirar
 */
void Hotel::PopReserva(int idnumero) {
    for (auto it = reservas.begin(); it != reservas.end(); it++){
        if((*it).idnumero == idnumero){
            it = reservas.erase(it);
            break;
        }
    }
}

/**
 ** Adicionar Reserva à lista de reservas_atuais
 * @param reserva Reserva a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddReservasAtuais(Reserva reserva) {
    for(auto it = reservas_atuais.begin(); it != reservas_atuais.end(); it++){
        if((*it) == reserva) return false ;
    }
    reservas_atuais.push_back(reserva);
    return true;
}

/**
 * Adicionar Reserva à lista de estadias
 * @param reserva Reserva a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddEstadia(Reserva reserva) {
    for(auto it = estadias.begin(); it != estadias.end(); it++){
        if((*it) == reserva) return false ;
    }
    estadias.push_back(reserva);
    return true;
}

/**
 * Adicionar Cliente à lista de clientes
 * @param cliente Cliente a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddCliente(Cliente cliente) {
    for(auto it = clientes.begin(); it != clientes.end(); it++){
        if((*it) == cliente) return false ;
    }
    clientes.push_back(cliente);
    if(cliente.cliente_usual) clientes_usuais.insert(cliente);
    return true;
}

/**
 * Adicionar Quarto à lista de quartos
 * @param quarto Quarto a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddQuarto(Quarto quarto) {
    for(auto it = quartos.begin(); it != quartos.end(); it++){
        if((*it) == quarto) return false ;
    }
    quartos.push_back(quarto);
    return true;
}

/**
 * Adicionar Funcionário à lista de funcionarios
 * @param funcionario Funcionário a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddFuncionario(Funcionario funcionario) {
    for(auto it = funcionarios.begin(); it != funcionarios.end(); it++){
        if((*it) == funcionario) return false ;
    }
    funcionarios.push_back(funcionario);
    return true;
}

/**
 * Adicionar Funcionário à lista de funcionarios_rececao
 * @param funcionario_rec Funcionário da Receção a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddFuncionarioRececao(F_Rececao funcionario_rec) {
    for(auto it = funcionarios_rececao.begin(); it != funcionarios_rececao.end(); it++){
        if((*it) == funcionario_rec) return false ;
    }
    funcionarios_rececao.push_back(funcionario_rec);
    return true;
}

/**
 * Adicionar Funcionário à lista de funcionarios_responsaveis
 * @param funcionario_resp Funcionário Responsável a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddFuncionarioResponsavel(F_Responsavel funcionario_resp) {
    for(auto it = funcionarios_responsaveis.begin(); it != funcionarios_responsaveis.end(); it++){
        if((*it) == funcionario_resp) return false ;
    }
    funcionarios_responsaveis.push_back(funcionario_resp);
    return true;
}

/**
 * Adicionar Funcionário à lista de funcionarios_limpeza
 * @param funcionario_limpeza Funcionário de Limpeza a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddFuncionarioLimpeza(F_Limpeza funcionario_limpeza) {
    for(auto it = funcionarios_limpeza.begin(); it != funcionarios_limpeza.end(); it++){
        if((*it) == funcionario_limpeza) return false ;
    }
    funcionarios_limpeza.push_back(funcionario_limpeza);
    return true;
}

/**
 * Adicionar Funcionário à lista de funcionarios_gestores
 * @param funcionario_gestor Funcionário Gestor a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddFuncionarioGestor(F_Gestor funcionario_gestor) {
    for(auto it = funcionarios_gestores.begin(); it != funcionarios_gestores.end(); it++){
        if((*it) == funcionario_gestor) return false ;
    }
    funcionarios_gestores.push_back(funcionario_gestor);
    return true;
}

/**
 * Adicionar Serviço à lista de servicos
 * @param servico Serviço a adicionar
 * @return verdadeiro se foi possível adicionar o novo elemento, falso caso contrário
 */
bool Hotel::AddServico(Servico servico) {
    for(auto it = servicos.begin(); it != servicos.end(); it++){
        if((*it) == servico) return false ;
    }
    servicos.push_back(servico);
    return true;
}

bool Hotel::AddViagem(Viagem viagem) {
    for(auto it = viagens_realizadas.begin(); it != viagens_realizadas.end(); it++){
        if((*it) == viagem) return false;
    }
    viagens_realizadas.push_back(viagem);
    return true;
}

bool Hotel::AddCompra(Compra compra) {
    vector <Compra> temp;
    while(!compras.empty()){
        Compra c = compras.top();
        if(c.ID() == compra.ID()) return false;
        temp.push_back(c);
        compras.pop();
    }
    for(int i = 0; temp.size() > i; i++) compras.push(temp[i]);
    compras.push(compra);
    return true;
}

bool Hotel::DeleteCompra(int id) {
    vector <Compra> temp;
    while(!compras.empty()){
        Compra c = compras.top();
        if(c.ID() == id){
            compras.pop();
            for(int i = 0; temp.size() > i; i++) compras.push(temp[i]);
            return true;
        }
        temp.push_back(c);
        compras.pop();
    }
    for(int i = 0; temp.size() > i; i++) compras.push(temp[i]);
    return false;
}

/**
 * Criar a Reserva e adicioná-la à lista de reservas e de reservas do Cliente
 * @param cliente Cliente que efetua a Reserva
 * @param idnumero número identificador da Reserva
 * @param data_inicial data de inicio da Reserva
 * @param data_final data do final da Reserva
 * @param lugaresperados capacidade esperada na Reserva
 * @param numquartos vecotr<int> com os números dos quartos a reservar
 * @return verdadeiro se foi possível criar a Reserva e adicioná-la às listas
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
     if (data_inicial >= data_final) return false;
     Reserva reserva(idnumero, data_inicial, data_final, lugaresperados, vq);
     try {
         if (AddReserva(reserva)) {
             for (auto it = reservas.begin(); it != reservas.end(); it++) {
                 if ((*it).idnumero == idnumero) {
                     cliente.reservas_cliente.push_back(&(*it));
                     break;
                 }
             }
             cliente.reservas_cliente.sort(Reserva::P_DataIcomp_Cr);
             if (!cliente.cliente_usual) {
                 reserva.primeiravez = true;
             } else reserva.primeiravez = false;
             return true;
         }
     }
    catch(MembroRepetido mr){
        cout << endl << "Membro Repetido da Classe " << mr.tipo << " com o ID: " << mr.id << endl;
    }
    catch(CapacidadeExcesso ce){
        cout << endl << "Reserva pede capacidade superior à dos quartos: " << ce.capacidade << endl;
    }
    return false;
    }

/**
 * Criar a Reserva e adicioná-la à lista de reservas e de reservas do Cliente com o nif indicado
 * @param nif nif do Cliente que efetua a Reserva
 * @param idnumero número identificador da Reserva
 * @param data_inicial data de inicio da Reserva
 * @param data_final data do final da Reserva
 * @param lugaresperados capacidade esperada na Reserva
 * @param numquartos vecotr<int> com os números dos quartos a reservar
 * @return verdadeiro se foi possível criar a Reserva e adicioná-la às listas
 */
bool Hotel::Reservar(int nif, int idnumero, data data_inicial, data data_final, int lugaresperados, vector<int> numquartos) {
    auto it = clientes.begin();
    bool found = false;
    for (it; it != clientes.end(); it++){
        if((*it).nif == nif) {
            found = true;
            break;
        }
    }
    if (data_inicial >= data_final) return false;
    if(found) return Reservar((*it), idnumero, data_inicial, data_final, lugaresperados, numquartos);
    else return false;
}

/**
 * Elimina a Reserva da lista reservas e da lista de reservas do Cliente que a efetuou
 * @param cliente Cliente que efetuou a Reserva
 * @param idreserva id da Reserva a cancelar
 */
void Hotel::CancelarReserva(Cliente &cliente, int idreserva) {
    bool encontrado = false;
    for(auto it = cliente.reservas_cliente.begin(); it != cliente.reservas_cliente.end(); it++){
        if((*it)->idnumero == idreserva) {
            it = cliente.reservas_cliente.erase(it);
            encontrado = true;
            break;
        }
    }
    if(encontrado) PopReserva(idreserva);
}

/**
 * Elimina a Reserva da lista reservas e da lista de reservas do Cliente que a efetuou
 * @param nif nif do Cliente que efetuou a Reserva
 * @param idreserva id da Reserva a cancelar
 */
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
 * Efetua o Check-In, a estadia atual do Cliente passa a apontar para a sua Reserva mais recente, que sai da lista das reservas e passa para a das reservas_atuais
 * @param cliente Cliente que está a entrar no Hotel
 */
void Hotel::CheckIn(Cliente &cliente) {
    Reserva reserva = *cliente.reservas_cliente.front();
    ApagarReservaL(cliente.reservas_cliente, reserva);
    AddReservasAtuais(reserva);
    for(auto it = reservas_atuais.begin(); it != reservas_atuais.end(); it++){
        if((*it).idnumero == reserva.idnumero){
            cliente.estadia_atual = &(*it);
            break;
        }
    }
    cliente.nohotel = true;
    ApagarReservaL(reservas, reserva);
}

/**
 * Efetua o Check-In, a estadia atual do Cliente passa a apontar para a sua Reserva mais recente, que sai da lista das reservas e passa para a das reservas_atuais
 * @param nif nif do Cliente que está a entrar no Hotel
 */
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
 * Efetua o Check-Out, a estadia atual do Cliente deixade existir e a que ele acaba de gozar passa para a lista estadias
 * @param cliente Cliente a sair do Hotel
 */
void Hotel::CheckOut(Cliente &cliente) {
    Reserva reserva = *cliente.estadia_atual;
    AddEstadia(reserva);
    for(auto it = estadias.begin(); it != estadias.end(); it++){
        if((*it).idnumero == reserva.idnumero){
            cliente.estadias_anteriores.push_back(&(*it));
            break;
        }
    }
    cliente.estadia_atual = NULL;
    ApagarReservaL(reservas_atuais, reserva);
    cliente.nohotel = false;
    if(!cliente.cliente_usual){
        cliente.cliente_usual = true;
        clientes_usuais.insert(cliente);
    }
}

/**
 * Efetua o Check-Out, a estadia atual do Cliente deixade existir e a que ele acaba de gozar passa para a lista estadias
 * @param nif nif do Cliente a sair do Hotel
 */
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

const list<Reserva *> Hotel::P_RestringirClientesNovos(bool clientes_novos, list<Reserva *> creservas) {
    list<Reserva *> resultado;
    if(clientes_novos) {
        for (auto it = creservas.begin(); it != creservas.end(); it++){
            if ((*it)->primeiravez) resultado.push_back(*it);
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

const list<Reserva *> Hotel::P_Pesquisa_Reservas_DataI(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, list<Reserva *> creservas) {
    list <Reserva *> pesquisa_duracao = P_RestringirClientesNovos(clientes_novos, creservas);
    if(inverso) pesquisa_duracao.sort(Reserva::P_DataIcomp_Decr);
    else pesquisa_duracao.sort(Reserva::P_DataIcomp_Cr);
    if(clientes_novos_primeiro) pesquisa_duracao.sort(Reserva::P_PrimeiraReserva);
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

const list<Reserva *> Hotel::P_Pesquisa_Reservas_DataF(bool inverso, bool clientes_novos, bool clientes_novos_primeiro, list<Reserva *> creservas) {
    list <Reserva *> pesquisa_duracao = P_RestringirClientesNovos(clientes_novos, creservas);
    if(inverso) pesquisa_duracao.sort(Reserva::P_DataFcomp_Decr);
    else pesquisa_duracao.sort(Reserva::P_DataFcomp_Cr);
    if(clientes_novos_primeiro) pesquisa_duracao.sort(Reserva::P_PrimeiraReserva);
    return pesquisa_duracao;
}

const list<Reserva> Hotel::Pesquisa_Reservas_Preco(bool inverso, bool clientes_novos, bool clientes_novos_primeiro) {
    list <Reserva> pesquisa_preco = RestringirClientesNovos(clientes_novos);
    if(inverso) pesquisa_preco.sort(Reserva::Precocomp_Decr);
    else pesquisa_preco.sort(Reserva::Precocomp_Cr);
    if(clientes_novos_primeiro) pesquisa_preco.sort(Reserva::PrimeiraReserva);
    return pesquisa_preco;
}

/**
 * Retorna uma lista de apontadores para Reservas que tenham pelo menos um dia no intervalo dado nos argumentos
 * @param datai data inicial do intervalo
 * @param dataf data final do intervalo
 * @return lista de apontadores para Reservas que tenham pelo menos um dia no intervalo dado nos argumentos
 */
list<Reserva *> Hotel::ReservasSobrepostas(data datai, data dataf) {
    UpdateReservasTotais();
    bool done = false;
    list <Reserva *> lri = P_Pesquisa_Reservas_DataI(0, 0, 0, reservas_totais);
    vector <Reserva *> ri = LtoV(lri);
    int risize = ri.size();
    int vmin = 0, vmax = ri.size();
    int vmedio = vmax/2;
    int vmedioant = 0;
    while(vmedio != vmax || vmedio != vmin){
        if(ri[vmedio]->data_inicio <= dataf) vmin = vmedio;
        if(ri[vmedio]->data_inicio > dataf) vmax = vmedio;
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
    list <Reserva *> lrf = P_Pesquisa_Reservas_DataF(0, 0, 0, lri);
    vector<Reserva *> rf = LtoV(lrf);
    int rfsize = rf.size();
    vmin = 0, vmax = rf.size();
    vmedio = vmax/2;
    vmedioant = 0;
    done = false;
    while(vmedio != vmax || vmedio != vmin){
        if(ri[vmedio]->data_fim < datai) vmin = vmedio;
        if(ri[vmedio]->data_fim >= datai) vmax = vmedio;
        vmedioant = vmedio;
        vmedio = vmin + (vmax - vmin)/2;
        if(done) break;
        if (vmedio == vmedioant){
            vmedio = vmin + (vmax - vmin)/2 + (vmax - vmin);
            done = true;
        }
    }
    rf.erase(rf.begin(), rf.begin() + min(vmin, rfsize));
    list <Reserva *> resultado = VtoL(rf);
    return resultado;
}

/**
 * Chama a ReservasSobrepostas com argumentos correspondentes ao m~es que recebe nos seus parâmetros
 * @param mesp mês
 * @param anop ano
 * @return lista de apontadores para Reservas que tenham pelo menos um dia no mês definido nos parâmetros
 */
list <Reserva *> Hotel::Reservas_Fin(int mesp, int anop){
    data dataf = DiaFinal(mesp, anop);
    data datai = {.dia = 1, .mes = mesp, .ano = anop};
    return ReservasSobrepostas(datai, dataf);
}

/**
 * Retorna uma lista de apontadores para Serviços que tenham sido efetuados no mês definido nos parâmetros
 * @param mesp mês
 * @param anop ano
 * @return lista de apontadores para Serviços que tenham sido efetuados no mês definido nos parâmetros
 */
list <Servico *> Hotel::Servicos_Fin(int mesp, int anop){
    data data_inicial = {.dia = 1, .mes = mesp, .ano = anop};
    data data_final = DiaFinal(mesp, anop);
    list <Servico *> resultado;
    for (auto it = servicos.begin(); it != servicos.end(); it++){
        if((*it).data_realizacao >= data_inicial && (*it).data_realizacao <= data_final) resultado.push_back(&(*it));
    }
    return resultado;
}

/**
 * Retorna uma lista de apontadores para Quartos disponíveis em todos os dias do intervalo recebido
 * @param data_inicial data inicial do intervalo
 * @param data_final data final do intervalo
 * @return lista de apontadores para Quartos disponíveis em todos os dias do intervalo recebido
 */
list<Quarto *> Hotel::Quartos_Disponiveis(data data_inicial, data data_final) {
    list <Quarto > quartos_disponiveis = quartos;
    list <Reserva *> reservas_sobrepostas = ReservasSobrepostas(data_inicial, data_final);
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
/**
 * Calcula os Custos mensais de operação do Hotel
 * @param impostos valor gasto em impostos no mês
 * @param despesasfixas valor gasto em despesas fixas (água, eletricidade...) no mês
 * @return o valor dos Custos mensais
 */
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

/**
 * Compõe a data final do mês
 * @param mesp mês
 * @param anop ano
 * @return data final do mês
 */
data Hotel::DiaFinal(int mesp, int anop) {
    if (mesp == 2) return {.dia = 28, .mes = mesp, .ano= anop};
    else if (mesp == 4 || mesp == 6 || mesp == 9 || mesp == 11) return {.dia = 30, .mes = mesp, .ano= anop};
    else return {.dia = 31, .mes = mesp, .ano= anop};
}

/**
 * Calcula o Rendimento Total do mês para o Hotel
 * @param mes mês
 * @param ano ano
 * @return o valor do Rendimento Mensal
 */
float Hotel::RendimentosTotais(int mes, int ano) {
    data data_inicial = {.dia = 1, .mes = mes, .ano = ano};
    data data_final = DiaFinal(mes, ano);
    list <Reserva *> reservas_fin = Reservas_Fin(mes, ano);
    int realdur;
    float preco_res;
    float count_rquartos = 0, rendimento = 0;
    for (auto it = reservas_fin.begin(); it != reservas_fin.end(); it++){
        preco_res = (*it)->preco;

        if((*it)->data_inicio >= data_inicial && (*it)->data_fim <= data_final) realdur = (*it)->duracao;
        if((*it)->data_inicio >= data_inicial && (*it)->data_fim > data_final) realdur = data_final - (*it)->data_inicio + 1;
        if((*it)->data_inicio < data_inicial && (*it)->data_fim <= data_final) realdur = (*it)->data_fim - data_inicial + 1;
        if((*it)->data_inicio < data_inicial && (*it)->data_fim > data_final) realdur = data_final - data_inicial + 1;

        count_rquartos += preco_res * realdur;

        }
    rendimento += count_rquartos;
    for (auto it = servicos.begin(); it != servicos.end(); it++){
        if((*it).data_realizacao >= data_inicial && (*it).data_realizacao <= data_final) rendimento += (*it).lucro;
    }
    return rendimento;
    }

/**
 * Calcula o Balanço Financeiro (lucro ou prejuízo) de um determinado mês do Hotel
 * @param mes mês
 * @param ano ano
 * @param impostos valor gasto em impostos no mês
 * @param despesasfixas valor gasto em despesas fixas (água, eletricidade...) no mês
 * @return o valor do Balanço Financeiro (positivo ou negativo, caso seja lucro ou prejuízo)
 */
float Hotel::BalancoFin(int mes, int ano, float impostos, float despesasfixas) {
    return RendimentosTotais(mes, ano) - CustosTotais(impostos, despesasfixas);
}

/**
 * Escolhe o cargo com menos trabalhadores no momento
 * @return cargo com menos trabalhadores no momento
 */
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

/**
 * Escolhe o turno com menos Funcionários de Limpeza
 * @return turno com menos Funcionários de Limpeza
 */
tipo_turno Hotel::EscolherTurno() {
    int countdia = 0, countnoite = 0;
    for (auto it = funcionarios_limpeza.begin(); it != funcionarios_limpeza.end(); it++){
        if((*it).turno == dia) countdia++;
        else countnoite++;
    }
    if(countdia > countnoite) return noite;
    else return dia;
}

/**
 * Escolhe o piso com menos Funcionários Responsáveis ou o primeiro sem nenhum
 * @return o número do piso com menos Funcionários Responsáveis ou o primeiro sem nenhum
 */
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

/**
 * Contrata um Funcionário com os dados recebidos e do cargo especificado, adicionando-o à lista funcionarios e à especifica do seu cargo
 * @param nome nome do Funcionário a contratar
 * @param nif nif do Funcionário a contratar
 * @param cargo cargo do Funcionário a contratar
 */
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

/**
 Contrata um Funcionário com os dados recebidos e com o cargo com menos Funcionários, adicionando-o à lista funcionarios e à especifica do seu cargo
 * @param nome nome do Funcionário a contratar
 * @param nif nif do Funcionário a contratar
 */
void Hotel::Contratar(string nome, int nif){
    tipo_cargo cargo = EscolherCargo();
    return Contratar(nome, nif, cargo);
}

/**
 * Despede o Funcionário com o nif indicado, apagando-o da lista funcionarios e da especifica ao seu cargo
 * @param nif
 */
void Hotel::Despedir(int nif){
    tipo_cargo cargo;
    for(auto it = funcionarios.begin(); it != funcionarios.end(); it++){
        if((*it).nif == nif){
            cargo = (*it).cargo;
            break;
        }
    }
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

/**
 * Adiciona um ano de serviço ao Funcionário com o nif especificado
 * @param idf nif do Funcionário
 */
void Hotel::AddAnoServico(int idf) {
    for (auto it = funcionarios.begin(); it != funcionarios.end(); it++){
        if((*it).ID() == idf){
            (*it).anos_servico++;
            (*it).salario += (*it).salario * 0.05;
            return;
        }
    }
}

/**
 * Artibui um novo salário ao Funcionário com o nif indicado
 * @param idf nif do Funcionário
 * @param novosalario salário mensal a atribuir ao Funcionário
 */
void Hotel::SetSalario(int idf, float novosalario) {
    for (auto it = funcionarios.begin(); it != funcionarios.end(); it++){
        if((*it).ID() == idf){
            {(*it).salario = novosalario;}
            return;
        }
    }
}

/**
 * Cria um Serviço e adiciona-o à lista servicos e à do Cliente que requesitou o Serviço
 * @param cliente Cliente que requesitou o Serviço
 * @param servico Serviço a ser prestado
 * @return verdadeiro se o Serviço foi prestado, falso caso contrário
 */
bool Hotel::PrestarServico(Cliente &cliente, Servico servico) {
    if (!AddServico(servico)) return false;
    for(auto it = servicos.begin(); it != servicos.end(); it++){
        if((*it) == servico){
            cliente.servicos_consumidos.push_back(&(*it));
            break;
        }
    }
    return true;
}

bool Hotel::PrestarServico(int nif, Servico servico) {
    auto it = clientes.begin();
    bool found = false;
    for (it; it != clientes.end(); it++){
        if((*it).nif == nif) {
            found = true;
            break;
        }
    }
    if(found) return PrestarServico((*it), servico);
    else return false;
}

bool Hotel::PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa){
    return PrestarServico(nif, Servico(nome, idnumero, data_realizacao, taxa));
}

bool Hotel::PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa, vector <int> funcsnif){
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

bool Hotel::PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa, vector <int> numprods, float margem_lucro){
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

bool Hotel::PrestarServico(int nif, string nome, int idnumero, data data_realizacao, float taxa, vector <int> funcsnif, vector <int> numprods, float margem_lucro){
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
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Quartos" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    if(inficheiro.eof()) throw FicheiroIncompativel(localizacao);
    int tquarto, piso, numero, capacidade;
    float preco;
    try {
    getline(inficheiro, line);
        while (line != "" && !inficheiro.eof()) {
            bool add = false;
            stringstream ss(line);
            ss >> tquarto >> piso >> numero >> capacidade >> preco;
            add = AddQuarto(Quarto(static_cast<tipo_quarto>(tquarto), piso, numero, capacidade, preco));
            if(!add) throw FicheiroIncompativel(localizacao);
            getline(inficheiro, line);
        }
    }
    catch (FicheiroIncompativel fi){
        inficheiro.close();
        cout << endl << "O Ficheiro em " << fi.nomeficheiro << "não é compatível" << endl;
    }
    inficheiro.close();
}

void Hotel::ImportarClientes(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if (inficheiro.fail()) {
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while (line != "Clientes" && !inficheiro.eof()) {
        getline(inficheiro, line);
    }
    if(inficheiro.eof()) throw FicheiroIncompativel(localizacao);
    string nomet= "", nomep = "";
    int nif, usual;
    try {
        getline(inficheiro, line);
        while (line != "" && !inficheiro.eof()) {
            bool add = false;
            nomet = "";
            nomep = "";
            usual = -1;
            stringstream ss(line);
            while (nomep != ",") {
                if (nomet != "") nomet += " ";
                nomet += nomep;
                ss >> nomep;
            }
            ss >> nif >> usual;
            if (usual != -1) add = AddCliente(Cliente(nomet, nif, usual));
            else add = AddCliente(Cliente(nomet, nif));
            if(!add) throw FicheiroIncompativel(localizacao);
            getline(inficheiro, line);
        }
    }
    catch (FicheiroIncompativel fi){
        inficheiro.close();
        cout << endl << "O Ficheiro em " << fi.nomeficheiro << "não é compatível" << endl;
    }
    inficheiro.close();
}

void Hotel::ImportarFuncionarios(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if (inficheiro.fail()) {
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while (line != "Funcionarios" && !inficheiro.eof()) {
        getline(inficheiro, line);
    }
    if(inficheiro.eof()) throw FicheiroIncompativel(localizacao);
    string nomet= "", nomep = "";
    vector <int> pisos;
    int nif, anos_servico, avaliacao, turno, cargo, piso;
    float salario;
    try {
        getline(inficheiro, line);
        while (line != "" && !inficheiro.eof()) {
            bool add = false;
            nomet = "";
            nomep = "";
            cargo = 0;
            avaliacao = -1;
            pisos.clear();
            stringstream ss(line);
            while (nomep != ",") {
                if (nomet != "") nomet += " ";
                nomet += nomep;
                ss >> nomep;
            }
            ss >> nif >> anos_servico >> salario >> cargo;
            cargo = static_cast<tipo_cargo>(cargo);
            switch (cargo) {
                case frececao:
                    add = AddFuncionario(F_Rececao(nomet, nif, anos_servico, salario));
                    add = AddFuncionarioRececao(F_Rececao(nomet, nif, anos_servico, salario));
                    break;
                case fresponsavel:
                    while (ss >> piso) {
                        pisos.push_back(piso);
                    }
                    add = AddFuncionario(F_Responsavel(nomet, nif, anos_servico, salario, pisos));
                    add = AddFuncionarioResponsavel(F_Responsavel(nomet, nif, anos_servico, salario, pisos));
                    break;
                case flimpeza:
                    ss >> turno;
                    add = AddFuncionario(F_Limpeza(nomet, nif, anos_servico, salario, static_cast<tipo_turno>(turno)));
                    add = AddFuncionarioLimpeza(F_Limpeza(nomet, nif, anos_servico, salario, static_cast<tipo_turno>(turno)));
                    break;
                case fgestor:
                    ss >> avaliacao;
                    if (avaliacao == -1) {
                        add = AddFuncionario(F_Gestor(nomet, nif, anos_servico, salario));
                        add = AddFuncionarioGestor(F_Gestor(nomet, nif, anos_servico, salario));
                    } else {
                        add = AddFuncionario(
                                F_Gestor(nomet, nif, anos_servico, salario, static_cast<nota_avaliacao>(avaliacao)));
                        add = AddFuncionarioGestor(
                                F_Gestor(nomet, nif, anos_servico, salario, static_cast<nota_avaliacao>(avaliacao)));
                    }
                    break;
                default:
                    add = AddFuncionario(Funcionario(nomet, nif, anos_servico, salario));
                    break;
            }
            if(!add) throw FicheiroIncompativel(localizacao);
            getline(inficheiro, line);
        }
    }
    catch (FicheiroIncompativel fi){
        inficheiro.close();
        cout << endl << "O Ficheiro em " << fi.nomeficheiro << "não é compatível" << endl;
    }
    inficheiro.close();
}

void Hotel::ImportarProdutos(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Produtos" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    if(inficheiro.eof()) throw FicheiroIncompativel(localizacao);
    string nomet= "", nomep = "";
    int tprod, qualidade, numero, stock;
    float preco;
    try {
        getline(inficheiro, line);
        while (line != "" && !inficheiro.eof()) {
            bool add = false;
            nomet = "";
            nomep = "";
            stringstream ss(line);
            while (nomep != ",") {
                if (nomet != "") nomet += " ";
                nomet += nomep;
                ss >> nomep;
            }
            ss >> numero >> tprod >> qualidade >> preco >> stock;
            if(stock > 1) add = AddProduto(Produto(nomet, numero, static_cast<tipo_produto>(tprod), static_cast<nota_avaliacao>(qualidade),
                                                  preco, stock));
            else add = AddProduto(Produto(nomet, numero, static_cast<tipo_produto>(tprod), static_cast<nota_avaliacao>(qualidade),
                            preco));
            if (!add) throw FicheiroIncompativel(localizacao);
            getline(inficheiro, line);
        }
    }
    catch (FicheiroIncompativel fi){
        inficheiro.close();
        cout << endl << "O Ficheiro em " << fi.nomeficheiro << "não é compatível" << endl;
    }
    inficheiro.close();
}

void Hotel::ImportarReservas(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Reservas" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    if(inficheiro.eof()) throw FicheiroIncompativel(localizacao);
    int nifcliente, idnum, lugaresp, qnum, d;
    vector <int> numquartos;
    data datai, dataf;
    try {
        getline(inficheiro, line);
        while (line != "" && !inficheiro.eof()) {
            bool add = false;
            numquartos.clear();
            stringstream ss(line);
            ss >> nifcliente >> idnum;
            ss >> d;
            datai.dia = abs(d);
            ss >> d;
            datai.mes = abs(d);
            ss >> d;
            datai.ano = abs(d);
            ss >> d;
            dataf.dia = abs(d);
            ss >> d;
            dataf.mes = abs(d);
            ss >> d;
            dataf.ano = abs(d);
            ss >> lugaresp;
            while (ss >> qnum) {
                numquartos.push_back(qnum);
            }
            add = Reservar(nifcliente, idnum, datai, dataf, lugaresp, numquartos);
            if (!add) throw FicheiroIncompativel(localizacao);
            getline(inficheiro, line);
        }
    }
    catch (FicheiroIncompativel fi){
        inficheiro.close();
        cout << endl << "O Ficheiro em " << fi.nomeficheiro << "não é compatível" << endl;
    }
    inficheiro.close();
}

void Hotel::ImportarServicos(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Servicos" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    if(inficheiro.eof()) throw FicheiroIncompativel(localizacao);
    string nomet, nomep, controlo, sf, sp;
    int idnum, nifcliente, d;
    data data_realizacao;
    float taxa, mlucro;
    vector <int> fnifs, pnums;
    getline(inficheiro, line);
    try {
        while (line != "" && !inficheiro.eof()) {
            bool add = false;
            fnifs.clear();
            pnums.clear();
            nomet = "";
            nomep = "";
            sf = "";
            sp = "";
            controlo = "";
            stringstream ss(line);
            ss >> nifcliente;
            while (nomep != ",") {
                if (nomet != "") nomet += " ";
                nomet += nomep;
                ss >> nomep;
            }
            ss >> idnum;
            ss >> d;
            data_realizacao.dia = abs(d);
            ss >> d;
            data_realizacao.mes = abs(d);
            ss >> d;
            data_realizacao.ano = abs(d);
            ss >> taxa;
            ss >> controlo;
            if (controlo == "") add = PrestarServico(nifcliente, nomet, idnum, data_realizacao, taxa);
            else {
                if (controlo == "f") {
                    while (ss >> sf && sf != ",") {
                        if (sf != "" && sf != ",") fnifs.push_back(stoi(sf));
                    }
                    ss >> controlo;
                    if (controlo == "p") {
                        while (ss >> sp && sp != ",") {
                            if (sp != "" && sp != ",") pnums.push_back(stoi(sp));
                        }
                        ss >> mlucro;
                        add = PrestarServico(nifcliente, nomet, idnum, data_realizacao, taxa, fnifs, pnums, mlucro);
                    } else add = PrestarServico(nifcliente, nomet, idnum, data_realizacao, taxa, fnifs);
                } else {
                    while (ss >> sp && sp != ",") {
                        if (sp != "" && sp != ",") pnums.push_back(stoi(sp));
                    }
                    ss >> mlucro;
                    add = PrestarServico(nifcliente, nomet, idnum, data_realizacao, taxa, pnums, mlucro);
                }
            }
            if (!add) throw FicheiroIncompativel(localizacao);
            getline(inficheiro, line);
        }
    }
    catch (FicheiroIncompativel fi){
        inficheiro.close();
        cout << endl << "O Ficheiro em " << fi.nomeficheiro << "não é compatível" << endl;
    }
    inficheiro.close();
}

void Hotel::ImportarVeiculos(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Veiculos" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    if(inficheiro.eof()) throw FicheiroIncompativel(localizacao);
    int lugares;
    string smatricula;
    double kms;
    try {
        getline(inficheiro, line);
        while (line != "" && !inficheiro.eof()) {
            bool add = false;
            stringstream ss(line);
            ss >> smatricula;
            ss >> kms;
            ss >> lugares;
            add = addVeiculo(smatricula, kms, lugares);
            if (!add) throw FicheiroIncompativel(localizacao);
            getline(inficheiro, line);
        }
    }
    catch (FicheiroIncompativel fi){
        inficheiro.close();
        cout << endl << "O Ficheiro em " << fi.nomeficheiro << "não é compatível" << endl;
    }
    inficheiro.close();
}

void Hotel::ImportarCompras(string localizacao) {
    ifstream inficheiro;
    inficheiro.open(localizacao);
    if(inficheiro.fail()){
        throw FicheiroIncompativel(localizacao);
    }
    string line;
    while(line != "Compras" && !inficheiro.eof()){
        getline(inficheiro, line);
    }
    if(inficheiro.eof()) throw FicheiroIncompativel(localizacao);
    string nomet= "", nomep = "", fornecedorp = "", fornecedort = "";
    int tprod, qualidade, numero_prod, stock, id, quantidade;
    float preco;
    try {
        getline(inficheiro, line);
        while (line != "" && !inficheiro.eof()) {
            stock = -1;
            bool add = false, prod_found = false;
            nomet = "";
            nomep = "";
            stringstream ss(line);
            ss >> id >> numero_prod;
            while (fornecedorp != ",") {
                if (fornecedort != "") fornecedort += " ";
                fornecedort += fornecedorp;
                ss >> fornecedorp;
            }
            ss >> quantidade;
            for(auto it = produtos.begin(); it != produtos.end() && !prod_found; it++){
                if((*it).ID() == numero_prod){
                    Produto p = (*it);
                    prod_found = true;
                }
            }
            if(prod_found){
                add = FazerCompra(id, numero_prod, fornecedort, quantidade);
            }
            else{
                while (nomep != ",") {
                    if (nomet != "") nomet += " ";
                    nomet += nomep;
                    ss >> nomep;
                }
                ss >> tprod >> qualidade >> preco >> stock;
                add = FazerCompra_NovoProduto(id, nomep, numero_prod, static_cast<tipo_produto>(tprod), static_cast<nota_avaliacao>(qualidade), preco, stock, fornecedort, quantidade);
            }
            if (!add) throw FicheiroIncompativel(localizacao);
            getline(inficheiro, line);
        }
    }
    catch (FicheiroIncompativel fi){
        inficheiro.close();
        cout << endl << "O Ficheiro em " << fi.nomeficheiro << "não é compatível" << endl;
    }
    inficheiro.close();
}



void Hotel::EscreverHotel(string nomedoficheiro) {
    if(nomedoficheiro.length() < 4 || nomedoficheiro.substr(nomedoficheiro.size() - 4) != ".txt") nomedoficheiro += ".txt";
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
        outficheiro << (*it).nome << " , " << (*it).numero << " " << (*it).tprod << " " << (*it).qualidade << " " << (*it).preco << " " << (*it).stock << endl;
    }

    outficheiro << endl;
    outficheiro << "Clientes" << endl;
    for(auto it = clientes.begin(); it != clientes.end(); it++){
        outficheiro << (*it).nome << " , " << (*it).nif << " " << (*it).cliente_usual << endl;
    }

    outficheiro << endl;
    outficheiro << "Funcionarios" << endl;
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
    outficheiro << "Servicos" << endl;
    for(auto it = servicos.begin(); it != servicos.end(); it++){
        int cliente_nif;
        for(auto itc = clientes.begin(); itc != clientes.end(); itc++){
            for(auto its = (*itc).servicos_consumidos.begin(); its != (*itc).servicos_consumidos.end(); its++){
                if((*its)->idnumero == (*it).idnumero){
                    cliente_nif = (*itc).nif;
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

    outficheiro << endl;
    outficheiro << "Veiculos" << endl;
    BSTItrIn<Veiculo> it(frota);
    for (; !it.isAtEnd();it.advance()) {
        outficheiro << (it.retrieve()).getMatricula() << " " << (it.retrieve()).getKms() << " " << (it.retrieve()).getLugares() << endl;
    }

    outficheiro << endl;
    outficheiro << "Compras" << endl;
    vector <Compra> temp;
    while(!compras.empty()){
        Compra c = compras.top();
        outficheiro << c.ID() << " " << c.getProdNumber() << " " << c.getFornecedor() << " , " << c.getQuantidade() << endl;
        temp.push_back(c);
        compras.pop();
    }
    for(int i = 0; temp.size() > i; i++) compras.push(temp[i]);

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

void Hotel::ApagarReservaL(list<Reserva> &lr, Reserva r) {
    for(auto it = lr.begin(); it != lr.end(); it++){
        if((*it).idnumero == r.idnumero) {
            it = lr.erase(it);
            break;
        }
    }
}

void Hotel::ApagarReservaL(list<Reserva *> &lr, Reserva r) {
    for(auto it = lr.begin(); it != lr.end(); it++){
        if((*it)->idnumero == r.idnumero){
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

void Hotel::UpdateReservasTotais() {
    reservas_totais.clear();
    for (auto it = reservas.begin(); it != reservas.end(); it++){
        reservas_totais.push_back(&(*it));
    }
    for (auto it = reservas_atuais.begin(); it != reservas_atuais.end(); it++){
        reservas_totais.push_back(&(*it));
    }
    for (auto it = estadias.begin(); it != estadias.end(); it++){
        reservas_totais.push_back(&(*it));
    }
}

list <Cliente *> Hotel::GetClientesInicial(char inicial){
    list <Cliente *> res;
    for(auto it = clientes.begin(); it != clientes.end(); it++){
        if((*it).getName()[0] == inicial){
            if(clientes_usuais.find(*it) != clientes_usuais.end()) res.push_back(&(*it));
        }
    }
    return res;
}

void Hotel::PromoIniciais(char p_inicial, char s_inicial){
    list <Cliente *> escolhidos;
    escolhidos = GetClientesInicial(p_inicial);
    for(auto it = GetClientesInicial(s_inicial).begin(); it != GetClientesInicial(s_inicial).end(); it++){
        escolhidos.push_back(*it);
    }

    for(auto it = escolhidos.begin(); it != escolhidos.end(); it++){
        bool found = false;
        for(auto cit = clientes.begin(); cit != clientes.end() && !found; cit++){
            if((*cit).getNif() == (*it)->getNif()){
                (*cit).setPromo(2);
                found = true;
            }
        }
    }

}

/**
 * Retorna a bst que contém os veículos alugados
 * @return a bst frota
 */
BST<Veiculo> Hotel::GetFrota() const {
    return frota;
}
/**
 *
 * @return número de veículos presentes na bst frota
 */
int Hotel::numVeiculos() const {
    int result = 0;
    BSTItrIn<Veiculo> it(frota);
    for (; !it.isAtEnd();it.advance()) {
        result++;
    }
    return result;
}

bool Hotel::addVeiculo(Veiculo veiculo) {
    BSTItrIn<Veiculo> it(frota);
    for (; !it.isAtEnd();it.advance()) {
        if (veiculo.getMatricula() == it.retrieve().getMatricula()) return false;
    }
    veiculo.setkms(0);
    frota.insert(veiculo);
    return true;
}

bool Hotel::addVeiculo(matricula matricula, double kms, int lugares) {
    if(kms <= 0) kms = 0;
    Veiculo v(matricula, kms, lugares);
    return addVeiculo(v);
}

bool Hotel::addVeiculo(string smatricula, double kms, int lugares) {
    if(kms <= 0) kms = 0;
    Veiculo v(smatricula, kms, lugares);
    return addVeiculo(v);
}
/**
 * Esvazia a frota e adiciona os veículos cujos apontadores estão no parametro rfrota
 * @param rFrota contém os veículos a adicionar à frota
 */
void Hotel::alugarFrota(const vector <Veiculo>& rFrota) {
    frota.makeEmpty();
    for (auto & i : rFrota) {
        addVeiculo(i);
    }
}
/**
 * Pesquisa por um veículo na bst
 * Caso não encontre, lança uma exceção VeículoInexistente
 * @param matricula do veículo
 * @return apontador para veículo cuja matricula é igual a matricula(param)
 */
Veiculo* Hotel::pesquisaVeiculo(matricula matricula) {
    BSTItrIn<Veiculo> it(frota);
    for (; !it.isAtEnd();it.advance()) {
        if (matricula == it.retrieve().getMatricula()) return const_cast<Veiculo *>(&(it.retrieve()));
    }
    throw VeiculoInexistente(); //not implemented yet
}
/**
 *
 * @return um apontador para o veículo com menos kms percorridos
 */
Veiculo* Hotel::menorKm() {
    return const_cast<Veiculo *>(&(frota.findMin())); 
}
/**
 * Remove o veícuclo cuja matrícula é matricula(param) da bst
 * @param matricula do veícula a devolver
 */
void Hotel::devolveVeiculo(matricula matricula) {
    Veiculo* toreturn;
    BSTItrIn<Veiculo> it(frota);
    for (; !it.isAtEnd();it.advance()) {
        if (matricula == it.retrieve().getMatricula()) {
            frota.remove(it.retrieve());
            break;
        }
    }

    /*toreturn = pesquisaVeiculo(p);
    veiculos.remove(toreturn);*/
}


void Hotel::Viajar(Cliente * cliente, double distancia, string ponto_partida, string destino, int id){
    Viagem v = {v.destino = destino, v.ponto_partida = ponto_partida, v.distancia = distancia, v.matricula = menorKm()->getMatricula(), v.id = id};
    menorKm()->updateKms(distancia);
    if(menorKm()->getKms() >= 5000) devolveVeiculo(menorKm()->getMatricula());
    if(AddViagem(v)){
        for(auto it = clientes.begin(); it != clientes.end(); it++){
            if((*it).nif == cliente->getNif()){
                for(auto itv = viagens_realizadas.begin(); itv != viagens_realizadas.end(); itv++){
                    if((*itv) == v) {
                        (*it).addViagem(&(*itv));
                        break;
                    }
                }
            }
        }
    }

}

void Hotel::Viajar(Cliente * cliente, double distancia, int id){
    Viagem v = {v.destino = "Hotel", v.ponto_partida = "Aeroporto", v.distancia = distancia, v.matricula = menorKm()->getMatricula(), v.id = id};
    menorKm()->updateKms(distancia);
    if(menorKm()->getKms() >= 5000) devolveVeiculo(menorKm()->getMatricula());
    if(AddViagem(v)){
        for(auto it = clientes.begin(); it != clientes.end(); it++){
            if((*it).nif == cliente->getNif()){
                for(auto itv = viagens_realizadas.begin(); itv != viagens_realizadas.end(); itv++){
                    if((*itv) == v) {
                        (*it).addViagem(&(*itv));
                        break;
                    }
                }
            }
        }
    }
}
/**
 *
 * @param stock_min stock mínimo da compra
 * @param stock_max stock máximo da compra
 * @return Compras cujo stock se encontra dentro do intervalo definido pelos valores dos parametros
 *
 */
priority_queue<Compra> Hotel::GetComprasStocks(int stock_min, int stock_max){
    if(stock_min > stock_max) throw InputInvalido();
    priority_queue<Compra> res;
    vector <Compra> temp;
    while(!compras.empty()){
        Compra c = compras.top();
        if(c.getStock() >= stock_min && c.getStock() <= stock_max){
            res.push(c);
        }
        temp.push_back(c);
        compras.pop();
    }
    for(int i = 0; temp.size() > i; i++) compras.push(temp[i]);
    if(res.size() == 0) throw InputInvalido();
    return res;
}

Compra Hotel::EscolherCompra(int id_func, int stock_min, int stock_max){
    priority_queue<Compra> compras_select;
    try{
        compras_select = GetComprasStocks(stock_min, stock_max);
        for(auto it = funcionarios_gestores.begin(); it != funcionarios_gestores.end(); it++){
            if((*it).ID() == id_func) return (*it).Escolher_Compra(compras_select);
        }
    }
    catch (InputInvalido ii) {
        cout << endl << "Input Inválido" << endl;
    }
    return Compra();
}

Compra Hotel::EscolherCompra(F_Gestor fgestor, int stock_min, int stock_max){
    return EscolherCompra(fgestor.ID(), stock_min, stock_max);
}


bool Hotel::FazerCompra_NovoProduto(int id, Produto produto, string fornecedor, int quantidade){
    if(!AddProduto(produto)) return false;
    if(quantidade <= 1) quantidade = 1;
    return FazerCompra(id, produto.ID(), fornecedor, quantidade);
}

bool Hotel::FazerCompra_NovoProduto(int id, string nome_prod, int numero_prod, tipo_produto tprod,
                                    nota_avaliacao qualidade, float preco, int stock, string fornecedor,
                                    int quantidade) {
    if(stock <= 1) stock = 1;
    Produto p(nome_prod, numero_prod, tprod, qualidade, preco, stock);
    if(!AddProduto(p)) return false;
    return FazerCompra_NovoProduto(id, p, fornecedor, quantidade);
}

bool Hotel::FazerCompra(int id, list <Produto> lprodutos, int numero_prod, string fornecedor, int quantidade) {
    if(quantidade <= 1) quantidade = 1;
    for(auto it = lprodutos.begin(); it != lprodutos.end(); it++){
        if((*it).ID() == numero_prod){
            Compra c(id, &(*it), fornecedor, quantidade);
            return AddCompra(c);
        }
    }
    return false;
}

bool Hotel::FazerCompra(int id, int numero_prod, string fornecedor, int quantidade) {
    return FazerCompra(id, produtos, numero_prod, fornecedor, quantidade);
}




