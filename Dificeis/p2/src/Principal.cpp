#include "../include/Principal.h"

Principal::Principal():
    tabuleiros()
{
    Executar();
}

Principal::~Principal(){

}

void Principal::Executar(){
    int qtdJogos = (rand()%LIMITE_DE_JOGOS) + 1;
    for(int i = 0; i < qtdJogos; i++){
        Tabuleiro* tab = new Tabuleiro();
        tabuleiros.push_back(tab);
        std::cout << std::endl;
    }
    for(int i = 0; i < qtdJogos; i++){
        std::cout << "#" << i + 1 << ": ";
        tabuleiros[i]->resultado();
    }
    tabuleiros.clear();
}