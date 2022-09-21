#include "../include/Coordenada.h"

Coordenada::Coordenada():
    x(-1), y(-1)
{ }

Coordenada::Coordenada(const int x, const int y){ 
    this->x = x;
    this->y = y;
}

Coordenada::~Coordenada(){

}

void Coordenada::setPos(const int x, const int y){
    this->x = x;
    this->y = y;
}

void Coordenada::setPos(const Coordenada pos){
    x = pos.x;
    y = pos.y;
}

Coordenada Coordenada::getPos(){
    return Coordenada(x, y);
}