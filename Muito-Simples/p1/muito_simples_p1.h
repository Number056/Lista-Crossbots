#ifndef MUITO_SIMPLES_P1_H_INCLUDED
#define MUITO_SIMPLES_P1_H_INCLUDED

// inclusão da biblioteca padrão 
#include <stdio.h>
#include <stdlib.h>

// inclusão da biblioteca math para acessar as funções matemáticas, como a potenciação e a radiciação
#include <math.h>

struct Coordenada
{
    int x;
    int y;
};

float calcDistancia(Coordenada ponto1, Coordenada ponto2);

Coordenada initCoordenada(int p1, int p2);

#endif // MUITO_SIMPLES_P1_H_INCLUDED