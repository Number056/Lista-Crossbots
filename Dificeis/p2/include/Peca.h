#pragma once 

#include "Coordenada.h"

class Peca {
private:
    const char nome;
    const char reiInimigo;
    Coordenada pos;
    const bool ehBranca;

    Peca* tabuleiro[8][8];
public:
    Peca(const char nome, const Coordenada pos, const bool ehBranca);
    ~Peca();

    const char getNome();
    const Coordenada getPos();

    void setTabuleiro(Peca* tab[8][8]);

    const bool mover();
    const bool cheque(const Coordenada proxPos);
    const bool moveTorre();
    const bool moveCavalo();
    const bool moveBispo();
    const bool moveRainha();
    const bool moveRei();
    const bool movePeao();
};