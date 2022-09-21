#include "intermediarios_p1.h"

Coordenada iniciaCoordenada(int v1, int v2){
    Coordenada ponto;
    ponto.x = v1;
    ponto.y = v2;
    return ponto;
}

Triangulo inicializaTriangulo(){
    Triangulo triangulo;
    //inicializa pontos do triangulo
    triangulo.Ponto[0] = iniciaCoordenada(0, 0);
    triangulo.Ponto[1] = iniciaCoordenada(2, 0);
    triangulo.Ponto[2] = iniciaCoordenada(1, 2);

    //inicializa o lado do triangulo
    triangulo.lado[0] = calculadaLado(triangulo.Ponto[0], triangulo.Ponto[1]);
    triangulo.lado[1] = calculadaLado(triangulo.Ponto[0], triangulo.Ponto[2]);
    triangulo.lado[2] = calculadaLado(triangulo.Ponto[1], triangulo.Ponto[2]);

    return calculaAngulo(triangulo);
}

float calculadaLado(Coordenada a, Coordenada b){
    int x = fabs(a.x - b.x);
    int y = fabs(a.y - b.y);
    return sqrt(pow(x, 2) + pow(y, 2));
}

Triangulo calculaAngulo(Triangulo triangulo){
    float angulo = (-1*(pow(triangulo.lado[1], 2) - pow(triangulo.lado[0], 2) - pow(triangulo.lado[2], 2)))/(2*triangulo.lado[0]*triangulo.lado[2]);
    triangulo.Ponto[0].angulo = (acos(angulo) * 180) / PI;

    angulo = (-1*(pow(triangulo.lado[2], 2) - pow(triangulo.lado[1], 2) - pow(triangulo.lado[0], 2)))/(2*triangulo.lado[1]*triangulo.lado[0]);
    triangulo.Ponto[1].angulo = (acos(angulo) * 180) / PI;

    angulo = (-1*(pow(triangulo.lado[0], 2) - pow(triangulo.lado[2], 2) - pow(triangulo.lado[1], 2)))/(2*triangulo.lado[2]*triangulo.lado[1]);
    triangulo.Ponto[2].angulo = (acos(angulo) * 180) / PI;

    return triangulo;
}