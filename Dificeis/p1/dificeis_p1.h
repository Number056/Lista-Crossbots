#pragma once

#include <iostream>

#include <string.h>
#include <stdlib.h>

#include <time.h>

#define N 1000

char addCaracter();

std::string criaLinha();

std::string remove_areia(std::string linha, int a, int b);

int procura_diamante(std::string linha, int inicio, int i);

std::string fecha_diamante(std::string linha, int fim);