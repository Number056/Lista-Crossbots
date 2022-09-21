#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Essa é uma lista simples que é utiliza em algumas questões da lista de exercícios.

#include <time.h>

typedef struct lista{
    int valor;
    struct lista* prox;
} Lista;

Lista* criaLista();

Lista* inserirElemento(Lista* lista, int valor);

Lista* removerElemento(Lista* lista, int valor);

void imprimirLista(Lista* lista);

Lista* preencheLista(int qtdValor);

void deletaLista(Lista* lista);

#endif // LIST_H_INCLUDED