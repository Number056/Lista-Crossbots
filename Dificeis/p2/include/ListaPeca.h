#pragma once

#include "Lista.h"
#include "Peca.h"

class ListaPeca {
private:
    Lista::Lista<Peca>* objListaPeca;
public:
    ListaPeca();
    ~ListaPeca();
    void addPeca(Peca* peca);
    const int getTamanho();
    Peca* getPeca(int posicao);
    void moverPecas(Peca* tabuleiro[8][8]);
    bool chequeReis(Peca* tabuleiro[8][8]);
    void removerLista();
};