#pragma once

#include <iostream>

class Coordenada {
public:
    int x;
    int y;

    Coordenada();
    Coordenada(const int x, const int y);
    ~Coordenada();

    void setPos(const int x, const int y);
    void setPos(const Coordenada pos);
    Coordenada getPos();
};