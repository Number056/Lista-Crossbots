#include "../include/Peca.h"

Peca::Peca(const char nome, const Coordenada pos, const bool ehBranca):
    nome(nome), ehBranca(ehBranca), reiInimigo((nome >= 97) ? 75 : 107)
{
    this->pos = pos;
}

Peca::~Peca(){

}

const char Peca::getNome(){
    return nome;
}

const Coordenada Peca::getPos(){
    return pos;
}

void Peca::setTabuleiro(Peca* tab[8][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tabuleiro[i][j] = tab[i][j];
        }
    }
}

//verifica que peça é e depois "movimenta" ela
const bool Peca::mover(){
    if(nome == 'p' || nome == 'P'){
        return movePeao();
    } else if(nome == 'b' || nome == 'B'){
        return moveBispo();
    } else if(nome == 'r' || nome == 'R'){
        return moveTorre();
    } else if(nome == 'n' || nome == 'N'){
        return moveCavalo();
    } else if(nome == 'q' || nome == 'Q'){
        return moveRainha();
    } 
    return moveRei();
}

//verifica se a proxima posição que a peça ocupar está ocupada pelo rei inimigo
const bool Peca::cheque(const Coordenada proxPos){
    if(proxPos.x >= 0 && proxPos.y >= 0 && proxPos.x < 8 && proxPos.y < 8){
        Peca* pecaReiInimigo = nullptr;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(tabuleiro[i][j] != nullptr){
                    if(reiInimigo == tabuleiro[i][j]->getNome()){
                        pecaReiInimigo = tabuleiro[i][j];
                        break;
                    }
                }
            }
        }
        return (tabuleiro[proxPos.x][proxPos.y] == pecaReiInimigo) ? true : false;
    }
    return false;
}

const bool Peca::moveTorre(){
    //move torre na horizontal p/ direita
    Coordenada it = Coordenada(pos.x + 1, pos.y);
    if(it.x < 8){
        while(it.x < 8){
            if(tabuleiro[it.x][it.y] != nullptr){
                break;
            }
            it.x++;
        }
        if(cheque(it)){
            return true;
        }
    }
    //move torre na horizontal p/ esquerda
    it.setPos(pos.x - 1, pos.y);
    if(it.x >= 0){
        while(it.x >= 0){
            if(tabuleiro[it.x][it.y] != nullptr){
                break;
            }
            it.x--;
        }
        if(cheque(it)){
            return true;
        }
    }
    //move torre na vertical p/ cima
    it.setPos(pos.x, pos.y + 1);
    if(it.y < 8){
        while(it.y < 8){
            if(tabuleiro[it.x][it.y] != nullptr){
                break;
            }
            it.y++;
        }
        if(cheque(it)){
            return true;
        }
    }
    //move torre na vertical p/ baixo
    it.setPos(pos.x, pos.y - 1);
    if(it.y >= 0){
        while(it.y >=0){
            if(tabuleiro[it.x][it.y] != nullptr){
                break;
            }
            it.y--;
        }
        return cheque(it);
    }
    return false;
}

const bool Peca::moveCavalo(){
    if(cheque(Coordenada(pos.x + 1, pos.y + 2))){
        return true;
    } else if(cheque(Coordenada(pos.x - 1, pos.y + 2))){
        return true;
    } else if(cheque(Coordenada(pos.x + 2, pos.y + 1))){
        return true;
    } else if(cheque(Coordenada(pos.x + 2, pos.y - 1))){
        return true;
    } else if(cheque(Coordenada(pos.x - 2, pos.y + 1))){
        return true;
    } else if(cheque(Coordenada(pos.x - 2, pos.y - 1))){
        return true;
    } else if(cheque(Coordenada(pos.x + 1, pos.y - 2))){
        return true;
    }
    return cheque(Coordenada(pos.x - 1, pos.y - 2));
}

const bool Peca::moveBispo(){
    //move na direita e para baixo
    Coordenada it = Coordenada(pos.x + 1, pos.y + 1);
    if(it.x < 8 && it.y < 8){
        while(it.x < 8 && it.y < 8){
            if(tabuleiro[it.x][it.y] != nullptr){
                break;
            }
            it.x++;
            it.y++;
        }
        if(cheque(it)){
            return true;
        }
    }
    //move para esquerda e p/ baixo
    it.setPos(pos.x + 1, pos.y - 1);
    if(it.x < 8 && it.y >= 0){
        while(it.x < 8 && it.y >=0){
            if(tabuleiro[it.x][it.y] != nullptr){
                break;
            }
            it.x++;
            it.y--;
        }
        if(cheque(it)){
            return true;
        }
    }
    //move para cima e para direita
    it.setPos(pos.x - 1, pos.y + 1);
    if(it.x >= 0 && it.y < 8){
        while(it.x >= 0 && it.y < 8){
            if(tabuleiro[it.x][it.y] != nullptr){
                break;
            }
            it.x--;
            it.y++;
        }
        if(cheque(it)){
            return true;
        }
    }
    //move na esquerda e para cima
    it.setPos(pos.x - 1, pos.y - 1);
    if(it.x >= 0 && it.y >= 0){
        while(it.x >= 0 && it.y >= 0){
            if(tabuleiro[it.x][it.y] != nullptr){
                break;
            }
            it.x--;
            it.y--;
        }
        return cheque(it);
    }
    return false;
}

const bool Peca::moveRainha(){
    //basicamente, a rainha anda as mesmas casas que a torre e o bispo;
    return (moveTorre()) ? true : moveBispo();
}

const bool Peca::moveRei(){
    if(cheque(Coordenada(pos.x + 1, pos.y))){
        return true;
    } else if(cheque(Coordenada(pos.x - 1, pos.y))){
        return true;
    } else if(cheque(Coordenada(pos.x + 1, pos.y + 1))){
        return true;
    } else if(cheque(Coordenada(pos.x + 1, pos.y - 1))){
        return true;
    } else if(cheque(Coordenada(pos.x - 1, pos.y + 1))){
        return true;
    } else if(cheque(Coordenada(pos.x - 1, pos.y - 1))){
        return true;
    } else if(cheque(Coordenada(pos.x, pos.y + 1))){
        return true;
    }
    return cheque(Coordenada(pos.x, pos.y - 1));
}

const bool Peca::movePeao(){
    int aux = (ehBranca) ? -1 : 1;
    if(cheque(Coordenada(pos.x + aux, pos.y + 1))){
        return true;
    }
    return cheque(Coordenada(pos.x + aux, pos.y - 1));
}