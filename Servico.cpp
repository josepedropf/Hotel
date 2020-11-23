#include "Servico.h"

/**
 * Construtor da classe Servico
 * @param nome nome do Serviço
 * @param idnumero identificador do Serviço
 * @param data_realizacao data em que o Serviço foi realizado
 * @param taxa taxa aplicável ao Serviço
 */
Servico::Servico(string nome, int idnumero, data data_realizacao, float taxa) {
    this->nome = nome;
    this->idnumero = abs(idnumero);
    this->data_realizacao = data_realizacao;
    this->taxa = taxa;
    funcionarios_ocupados = {};
    produtos_consumidos = {};
    custo = 0;
    margem_lucro = 0;
    preco_consumidor = taxa;
    lucro = taxa;
}

/**
 * Construtor da classe Servico
 * @param nome nome do Serviço
 * @param idnumero identificador do Serviço
 * @param data_realizacao data em que o Serviço foi realizado
 * @param taxa taxa aplicável ao Serviço
 * @param funcionarios_ocupados lista de apontadores para Funcionários ocupados com o Serviço
 */
Servico::Servico(string nome, int idnumero, data data_realizacao, float taxa, list<Funcionario *> funcionarios_ocupados) {
    this->nome = nome;
    this->idnumero = abs(idnumero);
    this->data_realizacao = data_realizacao;
    this->taxa = taxa;
    this->funcionarios_ocupados = funcionarios_ocupados;
    produtos_consumidos = {};
    custo = 0;
    margem_lucro = 0;
    preco_consumidor = taxa;
    lucro = taxa;
}

/**
 * Construtor da classe Servico
 * @param nome nome do Serviço
 * @param idnumero identificador do Serviço
 * @param data_realizacao data em que o Serviço foi realizado
 * @param taxa taxa aplicável ao Serviço
 * @param produtos_consumidos lista de apontadores para Produtos consumidos no Serviço
 * @param margem_lucro percentagem de lucro do Hotel por Produto vendido
 */
Servico::Servico(string nome, int idnumero, data data_realizacao, float taxa, list<Produto *> produtos_consumidos, float margem_lucro) {
    this->nome = nome;
    this->idnumero = abs(idnumero);
    this->data_realizacao = data_realizacao;
    this->taxa = taxa;
    this->produtos_consumidos = produtos_consumidos;
    this->margem_lucro = fabs(margem_lucro);
    funcionarios_ocupados = {};
    custo = 0;
    for(auto it = produtos_consumidos.begin(); it != produtos_consumidos.end(); it++){
        custo += (*it)->preco;
    }
    preco_consumidor = taxa + (custo + (margem_lucro / 100.0) * custo);
    lucro = preco_consumidor - custo;
}

/**
 * Construtor da classe Servico
 * @param nome nome do Serviço
 * @param idnumero identificador do Serviço
 * @param data_realizacao data em que o Serviço foi realizado
 * @param taxa taxa aplicável ao Serviço
 * @param funcionarios_ocupados lista de apontadores para Funcionários ocupados com o Serviço
 * @param produtos_consumidos lista de apontadores para Produtos consumidos no Serviço
 * @param margem_lucro percentagem de lucro do Hotel por Produto vendido
 */
Servico::Servico(string nome, int idnumero, data data_realizacao, float taxa, list<Funcionario *> funcionarios_ocupados, list<Produto *> produtos_consumidos, float margem_lucro) {
    this->nome = nome;
    this->idnumero = abs(idnumero);
    this->data_realizacao = data_realizacao;
    this->taxa = taxa;
    this->produtos_consumidos = produtos_consumidos;
    this->margem_lucro = fabs(margem_lucro);
    this->funcionarios_ocupados = funcionarios_ocupados;
    custo = 0;
    for(auto it = produtos_consumidos.begin(); it != produtos_consumidos.end(); it++){
        custo += (*it)->preco;
    }
    preco_consumidor = taxa + (custo + (margem_lucro / 100.0) * custo);
    lucro = preco_consumidor - custo;
}

/**
 * Imprime as Informações do Serviço
 */
void Servico::Info() const {
    cout << "<SERVICO>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Numero ID: " << idnumero << " | ";
    cout << "Data de Realização: " << data_realizacao << " | ";
    cout << "Custo ao Hotel: " << custo << " | ";
    cout << "Taxa: " << taxa << " | ";
    cout << "Preco de Consumo: " << preco_consumidor << " | ";
    cout << "Margem de Lucro do Hotel: " << margem_lucro << "% | ";
    cout << "Lucro do Hotel: " << lucro << " | ";
    if(!produtos_consumidos.empty()) {
        cout << "Produtos Consumidos: ";
        for (auto it = produtos_consumidos.begin(); it != produtos_consumidos.end(); it++) {
            cout << (*it)->nome;
            if(*it != produtos_consumidos.back()) cout << ", ";
        }
        if(!funcionarios_ocupados.empty()) cout << " | ";
    }
    if(!funcionarios_ocupados.empty()){
        cout << "Funcionarios Ocupados: ";
        for(auto it = funcionarios_ocupados.begin(); it != funcionarios_ocupados.end(); it++){
            cout << (*it)->nome;
            if(*it != funcionarios_ocupados.back()) cout << ", ";
    }
    }
    cout << endl;
}