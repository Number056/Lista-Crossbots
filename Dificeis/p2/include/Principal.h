#pragma once

#include <iostream>
#include "Tabuleiro.h"

#include <vector>

#define LIMITE_DE_JOGOS 150

class Principal {
private:
    std::vector<Tabuleiro*> tabuleiros;
public:
    Principal();
    ~Principal();
    void Executar();
};