#include "muito_simples_p1.h"


// função que retorna a distância entre dois pontos em plano cartesiano:
float calcDistancia(Coordenada ponto1, Coordenada ponto2){
    float x = fabs(ponto1.x - ponto2.x);
    float y = fabs(ponto1.y - ponto2.y);
    return sqrt(pow(x, 2) + pow(y, 2));
}

Coordenada initCoordenada(int p1, int p2){
    Coordenada ponto;
    ponto.x = p1;
    ponto.y = p2;
    return ponto;
}