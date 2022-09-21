#pragma once

#define NUM_CASA 8
#define CONT_PECA 5
#define C1 1
#define C2 2
#define VARIACAO_ASCII 32

#include <time.h>

#include "ListaPeca.h"
#include "Peca.h"

class Tabuleiro {
private:
    Peca* tabuleiro[NUM_CASA][NUM_CASA];
    ListaPeca listaPeca;
    int cont_pecas[CONT_PECA];

public:
    Tabuleiro();
    ~Tabuleiro();

    void iniciaTabuleiro();
    void iniciaPecas();
    void criaReis();
    Peca* criaPeca(const bool ehBranca);
    char criaLetra(int tipo);
    bool estaVazio(const Coordenada pos);
    void resultado();
    void imprime();
    void Executar();
};