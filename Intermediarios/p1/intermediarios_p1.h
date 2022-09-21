#ifndef INTERMEDIARIOS_P1_H_INCLUDED
#define INTERMEDIARIOS_P1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#define PI 3.14159265

typedef struct
{
    int x;
    int y;
    float angulo;
}Coordenada;

typedef struct
{
    Coordenada Ponto[3];
    float lado[3];
}Triangulo;

Coordenada iniciaCoordenada(int v1, int v2);

Triangulo inicializaTriangulo();

float calculadaLado(Coordenada a, Coordenada b);

Triangulo calculaAngulo(Triangulo triangulo);

#endif // INTERMEDIARIOS_P1_H_INCLUDED