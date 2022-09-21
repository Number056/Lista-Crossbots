#ifndef SIMPLES_P3_H_INCLUDED
#define SIMPLES_P3_H_INCLUDED

//biblioteca padrão
#include <stdio.h>
#include <stdlib.h>

// inclusão das funções de lista simples
#include "../../ListaSimples/list.h"

// OBS: Este exercício seria muito mais simples se eu utilizar a biblioteca Vector ou List do C++, pois as
// funções já estão prontas. Entretando, por questões de conhecimento e capacidade, optei por criar uma 
// Estruta de Dados.

Lista* remove_nao_primos(Lista* lista);

int ehPrimo(int valor);

#endif // SIMPLES_P3_H_INCLUDED