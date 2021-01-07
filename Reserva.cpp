#include "Reserva.h"

/**
 * Construtor da classe Reserva
 * @param idnumero identificador da Reserva
 * @param data_inicio data de incio da Reserva
 * @param data_fim data do final ad Reserva
 * @param lugaresp capacidade pretendida na Reserva
 * @param quartos_res lista de apontadores para os Quartos a reservar
 */
Reserva::Reserva(int idnumero, data data_inicio, data data_fim, int lugaresp, list <Quarto *> quartos_res, int promo){
    this->idnumero = abs(idnumero);
    this->data_inicio = data_inicio;
    this->data_fim = data_fim;
    duracao = data_fim - data_inicio + 1;
    this->lugaresp = lugaresp;
    this->quartos_res = quartos_res;
    int qsize = quartos_res.size();
    if(promo > 100) promo = 100;
    preco = 0;
    for (auto it = quartos_res.begin(); it != quartos_res.end(); it++){
        preco += (*it)->preco;
    }
    preco = preco * ((100 - promo) / 100.0);
}

/**
 * Construtor da classe Reserva
 * @param idnumero identificador da Reserva
 * @param data_inicio data de incio da Reserva
 * @param data_fim data do final ad Reserva
 * @param lugaresp capacidade pretendida na Reserva
 * @param quartos_res lista de apontadores para os Quartos a reservar
 * @param primeiravez verdadeiro se a Reserva for efetuada por um Cliente que nunca veio antes ao Hotel, falso caso contrário
 */
Reserva::Reserva(int idnumero, data data_inicio, data data_fim, int lugaresp, list <Quarto *> quartos_res, bool primeiravez, int promo) {
    this->idnumero = abs(idnumero);
    this->primeiravez = primeiravez;
    this->data_inicio = data_inicio;
    this->data_fim = data_fim;
    duracao = data_fim - data_inicio + 1;
    this->lugaresp = lugaresp;
    this->quartos_res = quartos_res;
    int qsize = quartos_res.size();
    if(promo > 100) promo = 100;
    preco = 0;
    for (auto it = quartos_res.begin(); it != quartos_res.end(); it++){
        preco += (*it)->preco;
    }
    preco = preco * ((100 - promo) / 100.0);
}

/**
 * Imprime as Informações da Reserva
 */
void Reserva::Info() const{
    cout << "<RESERVA>" << endl;
    cout << "Numero ID: " << idnumero << " | ";
    cout << "Data de Inicio: " << data_inicio << " | ";
    cout << "Data de Fim: " << data_fim << " | ";
    cout << "Duracao: " << duracao << " | ";
    cout << "Lugares Esperados: " << lugaresp << " | ";
    cout << "Quartos Reservados: ";
    for(auto it = quartos_res.begin(); it != quartos_res.end(); it++){
        cout << (*it)->numero << " ";
    }
    cout << endl;
}

/**
 * Indica se duas Reservas se sobrepõem
 * @param r2 Segunda Reserva
 * @return verdadeiro se ocorrer sobreposição de Reservas, falso caso contrário
 */
bool Reserva::operator==(const Reserva &r2) const {
    if(idnumero == r2.idnumero) return true;
    bool quartoscom = false;
    for(auto it = quartos_res.begin(); it != quartos_res.end(); it++){
        for(auto itt = r2.quartos_res.begin(); itt != r2.quartos_res.end(); itt++){
            if((*it) == (*itt)){
                quartoscom = true;
                break;
            }
        }
    }
    if(!quartoscom) return false;
    return (data_inicio >= r2.data_inicio && data_inicio <= r2.data_fim) || (data_fim >= r2.data_inicio && data_fim <= r2.data_fim) || (data_inicio < r2.data_inicio && data_fim > r2.data_fim);
}