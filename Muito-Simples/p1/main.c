#include "muito_simples_p1.h"

int main(){
    Coordenada ponto1 = initCoordenada(1, 2);
    Coordenada ponto2 = initCoordenada(5, 6);

    printf("%f", calcDistancia(ponto1, ponto2));
    return 0;
}