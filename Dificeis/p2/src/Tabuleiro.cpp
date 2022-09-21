#include "../include/Tabuleiro.h"

Tabuleiro::Tabuleiro():
    listaPeca()
{
    Executar();
}

Tabuleiro::~Tabuleiro(){
    listaPeca.removerLista();
}

//inicia todos os pontos do tabuleiro
void Tabuleiro::iniciaTabuleiro(){
    for(int i = 0; i < NUM_CASA; i++){
        for(int j = 0; j < NUM_CASA; j++){
            tabuleiro[i][j] = nullptr;
        }
    }
}

//posiciona as peças no tabuleiro
void Tabuleiro::iniciaPecas(){
    //cria reis:
    criaReis();
    //contador das peças do tabuleiro
    for(int i = 0; i < CONT_PECA; i++){
        cont_pecas[i] = 0;
    }

    //cria as peças brancas:
    int qtdPeca = (rand()%13) + 1;
    for(int i = 0; i < qtdPeca; i++){
        Peca* peca = criaPeca(true);
        listaPeca.addPeca(peca);
    }

    //zera o contador para as peças pretas
    for(int i = 0; i < CONT_PECA; i++){
        cont_pecas[i] = 0;
    }

    //cria as peças pretas:
    qtdPeca = (rand()%13) + 1;
    for(int i = 0; i < qtdPeca; i++){
        Peca* peca = criaPeca(false);
        listaPeca.addPeca(peca);
    }
}

//cria reis
void Tabuleiro::criaReis(){
    Coordenada pos = Coordenada(rand()%NUM_CASA, rand()%NUM_CASA);
    //cria rei branco
    Peca* reiBranco = new Peca('K', pos, true);
    listaPeca.addPeca(reiBranco);
    tabuleiro[pos.x][pos.y] = reiBranco;

    //cria rei preto
    pos.setPos(rand()%NUM_CASA, rand()%NUM_CASA);
    while(tabuleiro[pos.x][pos.y] != nullptr){
        pos.setPos(rand()%NUM_CASA, rand()%NUM_CASA);
    }
    Peca* reiPreto = new Peca('k', pos, false);
    listaPeca.addPeca(reiPreto);
    tabuleiro[pos.x][pos.y] = reiPreto;
}

//gera uma letra P, N, R, Q aleatoriamente
char Tabuleiro::criaLetra(int tipo){
    int i = 0;
    int aux = tipo;
    while(1){
        tipo = (aux + (C1*i) + (C2*i*i))%CONT_PECA;
        if(tipo == 0){
            if(cont_pecas[tipo] < 8){
                cont_pecas[tipo]++;
                return 'P';
            }
        } else if(tipo == 1){
            if(cont_pecas[tipo] < 2){
                cont_pecas[tipo]++;
                return 'R';
            }
        } else if(tipo == 2){
            if(cont_pecas[tipo] < 2){
                cont_pecas[tipo]++;
                return 'N';
            }
        } else if(tipo == 3){
            if(cont_pecas[tipo] < 2){
                cont_pecas[tipo]++;
                return 'B';
            }
        } else {
            if(cont_pecas[4] < 1){
                cont_pecas[4]++;
                return 'Q';
            }
        }
        i++;
    }
}

//cria a Peça e coloca na lista de peças
Peca* Tabuleiro::criaPeca(const bool ehBranca){
    Coordenada pos = Coordenada(rand()%NUM_CASA, rand()%NUM_CASA);
    while(!estaVazio(pos)){
        pos.setPos(rand()%NUM_CASA, rand()%NUM_CASA);
    }
    char nome = criaLetra(rand()%CONT_PECA);
    Peca* peca = nullptr;
    if(ehBranca){
        peca = new Peca(nome, pos, true);
        tabuleiro[pos.x][pos.y] = peca;
    } else {
        peca = new Peca(nome + VARIACAO_ASCII, pos, false); 
        tabuleiro[pos.x][pos.y] = peca;
    }
    return peca;
}

//verifica se a posição está vazia
bool Tabuleiro::estaVazio(const Coordenada pos){
    return (tabuleiro[pos.x][pos.y] == nullptr) ? true : false;
}

//imprime o tabuleiro
void Tabuleiro::imprime(){
    for(int i = 0; i < NUM_CASA; i++){
        for(int j = 0; j < NUM_CASA; j++){
            if(tabuleiro[i][j] != nullptr){
                std::cout << tabuleiro[i][j]->getNome() << " ";
            } else {
                std::cout << '.' << " ";
            }
        }
        std::cout << "\n";
    }
}

//"move" as peças, dando o resultado final
void Tabuleiro::resultado(){
    listaPeca.moverPecas(tabuleiro);
}

void Tabuleiro::Executar(){
    inicio:
    iniciaTabuleiro();
    iniciaPecas();
    if(listaPeca.chequeReis(tabuleiro)){
        listaPeca.removerLista();
        goto inicio;
    }
    imprime();
}