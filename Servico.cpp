#include "Servico.h"

Servico::Servico(string nome, int idnumero, data data_realizacao, float taxa) {
    this->nome = nome;
    this->idnumero = abs(idnumero);
    this->data_realizacao = data_realizacao;
    this->taxa = taxa;
    custo = 0;
    margem_lucro = 0;
    preco_consumidor = taxa;
    lucro = taxa;
}

Servico::Servico(string nome, int idnumero, data data_realizacao, float taxa, list<Funcionario *> funcionarios_ocupados) {
    this->nome = nome;
    this->idnumero = abs(idnumero);
    this->data_realizacao = data_realizacao;
    this->taxa = taxa;
    this->funcionarios_ocupados = funcionarios_ocupados;
    custo = 0;
    margem_lucro = 0;
    preco_consumidor = taxa;
    lucro = taxa;
}

Servico::Servico(string nome, int idnumero, data data_realizacao, float taxa, list<Produto *> produtos_consumidos, float margem_lucro) {
    this->nome = nome;
    this->idnumero = abs(idnumero);
    this->data_realizacao = data_realizacao;
    this->taxa = taxa;
    this->produtos_consumidos = produtos_consumidos;
    this->margem_lucro = fabs(margem_lucro);
    custo = 0;
    for(auto it = produtos_consumidos.begin(); it != produtos_consumidos.end(); it++){
        custo += (*it)->preco;
    }
    preco_consumidor = taxa + (custo + (margem_lucro / 100.0) * custo);
    lucro = preco_consumidor - custo;
}

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

void Servico::Info() const {
    cout << "<SERVIÇO>" << endl;
    cout << "Nome: " << nome << " | ";
    cout << "Número ID: " << idnumero << " | ";
    cout << "Data de Realização: " << data_realizacao << " | ";
    cout << "Custo ao Hotel: " << custo << " | ";
    cout << "Preço de Consumo: " << preco_consumidor << " | ";
    cout << "Lucro do Hotel: " << lucro << " | ";
    cout << "Produtos Consumidos: ";
    for(auto it = produtos_consumidos.begin(); it != produtos_consumidos.end(); it++){
        cout << (*it)->nome << " ";
    }
    cout << " | ";
    cout << "Funcionários Ocupados: ";
    for(auto it = funcionarios_ocupados.begin(); it != funcionarios_ocupados.end(); it++){
        cout << (*it)->nome << " ";
    }
    cout << endl;
}