#ifndef SIMPLES_P1_H_INCLUDED
#define SIMPLES_P1_H_INCLUDED

//biblioteca padrão
#include <stdio.h>
#include <stdlib.h>

//biblioteca para gerar números aleatórios para o vetor em questão
#include <time.h>

struct Vector
{
    int *v;
    int tam;
};


Vector criaVector(int tam);

void deletaVector(Vector vet);

void preencheVector(Vector vet);

void imprimeVector(Vector vet);

#endif // SIMPLES_P1_H_INCLUDED