#include "Funcionario.h"

/**
 * Construtor da Classe Funcionario
 * @param nome nome do Funcionário
 * @param nif nif do Funcionário
 * @param anos_servico número de anos que o Funcionário trabalhou no Hotel
 * @param salario salário mensal do Funcionário
 */
Funcionario::Funcionario(string nome, int nif, int anos_servico, float salario) {
    this->nome = nome;
    this->nif = abs(nif);
    this->anos_servico = anos_servico;
    this->salario = salario;
    cargo = naodef;
}

/**
 * Construtor da Classe Funcionario
 * @param nome nome do Funcionário
 * @param nif nif do Funcionário
 * @param anos_servico número de anos que o Funcionário trabalhou no Hotel
 * @param salario salário mensal do Funcionário
 * @param cargo cargo do Funcionário
 */
Funcionario::Funcionario(string nome, int nif, int anos_servico, float salario, tipo_cargo cargo) {
    this->nome = nome;
    this->nif = abs(nif);
    this->anos_servico = anos_servico;
    this->salario = salario;
    this->cargo = cargo;
}

/**
 * Construtor da Classe F_Rececao
 * @param nome nome do Funcionário
 * @param nif nif do Funcionário
 * @param anos_servico número de anos que o Funcionário trabalhou no Hotel
 * @param salario salário mensal do Funcionário
 */
F_Rececao::F_Rececao(string nome, int nif, int anos_servico, float salario): Funcionario(nome, nif, anos_servico, salario, frececao) {}
/**
* Construtor da Classe F_Rececao
 * @param nome nome do Funcionário
 * @param nif nif do Funcionário
 * @param anos_servico número de anos que o Funcionário trabalhou no Hotel
 * @param salario salário mensal do Funcionário
 * @param cargo cargo do Funcionário
 */
F_Rececao::F_Rececao(string nome, int nif, int anos_servico, float salario, tipo_cargo c): Funcionario(nome, nif, anos_servico, salario, c) {}


/**
 * Construtor da Classe F_Responsavel
 * @param nome nome do Funcionário
 * @param nif nif do Funcionário
 * @param anos_servico número de anos que o Funcionário trabalhou no Hotel
 * @param salario salário mensal do Funcionário
 */
F_Responsavel::F_Responsavel(string nome, int nif, int anos_servico, float salario): F_Rececao(nome, nif, anos_servico, salario, fresponsavel) {}
/**
 * Construtor da Classe F_Responsavel
 * @param nome nome do Funcionário
 * @param nif nif do Funcionário
 * @param anos_servico número de anos que o Funcionário trabalhou no Hotel
 * @param salario salário mensal do Funcionário
 * @param pisos_resp vetor<int> com os números dos pisos pelos quais o Funcionário é responsável
 */
F_Responsavel::F_Responsavel(string nome, int nif, int anos_servico, float salario, vector<int> pisos_resp): F_Rececao(nome, nif, anos_servico, salario, fresponsavel) {
    this->pisos_resp = pisos_resp;
}

/**
 * Construtor da Classe F_Limpeza
 * @param nome nome do Funcionário
 * @param nif nif do Funcionário
 * @param anos_servico número de anos que o Funcionário trabalhou no Hotel
 * @param salario salário mensal do Funcionário
 * @param turno turno do Funcionário, pode ser dia ou noite
 */
F_Limpeza::F_Limpeza(string nome, int nif, int anos_servico, float salario, tipo_turno turno): Funcionario(nome, nif, anos_servico, salario, flimpeza) {
    this->turno = turno;
}

/**
 * Construtor da Classe F_Gestor
 * @param nome nome do Funcionário
 * @param nif nif do Funcionário
 * @param anos_servico número de anos que o Funcionário trabalhou no Hotel
 * @param salario salário mensal do Funcionário
 */
F_Gestor::F_Gestor(string nome, int nif, int anos_servico, float salario): Funcionario(nome, nif, anos_servico, salario, fgestor) {}
/**
 * Construtor da Classe F_Gestor
 * @param nome nome do Funcionário
 * @param nif nif do Funcionário
 * @param anos_servico número de anos que o Funcionário trabalhou no Hotel
 * @param salario salário mensal do Funcionário
 * @param av_prestacao avaliação qualitativa de má a excelente, atribuida ao Funcionário
 */
F_Gestor::F_Gestor(string nome, int nif, int anos_servico, float salario, nota_avaliacao av_prestacao): Funcionario(nome, nif, anos_servico, salario, fgestor) {
    this->av_prestacao = av_prestacao;
}

/**
 * Imprime as Informações do Funcionário
 */
void Funcionario::Info() const{
    string scargo = "";
    switch(cargo){
        case naodef:
            break;
        case frececao:
            scargo = " RECECAO";
            break;
        case fresponsavel:
            scargo = " RESPONSAVEL";
            break;
        case flimpeza:
            scargo = " LIMPEZA";
            break;
        case fgestor:
            scargo = " GESTOR";
            break;
        default:
            break;
    }
    cout << "<FUNCIONARIO" << scargo << ">" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Nif: " << nif << " | ";
    cout << "Anos de Servico: " << anos_servico << " | ";
    cout << "Salario: " << salario << endl;
}

/**
 * Imprime as Informações do Funcionário
 */
void F_Rececao::Info() const {Funcionario::Info(); cout << endl;}

/**
 * Imprime as Informações do Funcionário
 */
void F_Responsavel::Info() const {
    Funcionario::Info();
    string pisos = "";
    if(!pisos_resp.empty()){
        int prsize = pisos_resp.size();
        for(int i = 0; prsize > i; i++){
            pisos += " " + to_string(pisos_resp[i]);
        }
    }
    cout << " | Pisos da sua Responsabilidade: " << pisos;
    cout << endl;
}

/**
 * Imprime as Informações do Funcionário
 */
void F_Limpeza::Info() const{
    Funcionario::Info();
    if(turno == dia) cout << " | Turno: dia";
    else cout << " | Turno: noite";
    cout << endl;
}

/**
 * Imprime as Informações do Funcionário
 */
void F_Gestor::Info() const{
    Funcionario::Info();
    cout << " | Avaliacao: " << av_prestacao;
    cout << endl;
}

// Gestor Funcs
/**
 * Aplica Promoções aos quartos indicados
 * @param quartos_promo lista de apontadores para quartos a receber promoção
 */
void F_Gestor::Promocoes(list <Quarto *> &quartos_promo) {
    for(auto it = quartos_promo.begin(); it != quartos_promo.end(); it++){
        (*it)->preco *= float(float(100 - (*it)->promo) / 100.0);
    }
}

/**
 * O Funcionário escolhe um Produto entre os que lhe são dados a escolher, com base primeiro no preço e depois na qualidade
 * @param prods lista de apontadores para Produtos entre os quais o Funcionário tem de realizar a escolha
 * @return Produto escolhido pelo Funcionário
 */
Produto F_Gestor::Escolher_Prod(list <Produto *> prods) {
    auto it = prods.begin();
    Produto escolhido = *(*it);
    for (it; it != prods.end(); it++){
        if((*it)->preco < escolhido.preco) escolhido = *(*it);
        else if((*it)->preco == escolhido.preco){
            if((*it)->qualidade > escolhido.qualidade) escolhido = *(*it);
        }
    }
    return escolhido;
}
