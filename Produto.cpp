#include "Produto.h"

Produto::Produto(tipo_produto tp, avaliacao q, float p){
    tprod = tp;
    qualidade = q;
    preco = p;
}

void Produto::Info() {
    cout << "<PRODUTO>" << endl;
    cout << "Tipo de Produto: " << tprod << " | ";
    cout << "Preço: " << preco << " | ";
    cout << "Qualidade: " << qualidade;
    cout << endl;
}
