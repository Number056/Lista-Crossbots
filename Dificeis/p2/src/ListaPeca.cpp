#include "../include/ListaPeca.h"

ListaPeca::ListaPeca():
    objListaPeca(new Lista::Lista<Peca>())
{

}

ListaPeca::~ListaPeca(){
    if(objListaPeca){
        delete(objListaPeca);
        objListaPeca = nullptr;
    }
}

//adiciona a peça na lista de peças
void ListaPeca::addPeca(Peca* peca){
    objListaPeca->adicionar(peca);
}

//retorna o tamanho da lista
const int ListaPeca::getTamanho(){
    return objListaPeca->getTamLista();
}

Peca* ListaPeca::getPeca(int posicao){
    return objListaPeca->operator[](posicao);
}

//movimenta as peças
void ListaPeca::moverPecas(Peca* tabuleiro[8][8]){
    int tamLista = objListaPeca->getTamLista();
    for(int i = 2; i < tamLista - 1; i++){
        Peca* peca = objListaPeca->operator[](i);
        peca->setTabuleiro(tabuleiro);
        if(peca->mover()){
            if(peca->getNome() >= 97){
                std::cout << "o rei branco esta em cheque" << std::endl;
            } else {
                std::cout << "o rei preto esta em cheque" << std::endl;
            }
            return;
        }
    }
    std::cout << "nenhum rei esta em cheque" << std::endl;
}

//verifica se os dois reis estão em cheque
bool ListaPeca::chequeReis(Peca* tabuleiro[8][8]){
    int tam = objListaPeca->getTamLista();
    bool chequeReiPreto = false;
    bool chequeReiBranco = false;
    for(int i = 0; i < tam - 1; i++){
        Peca* peca = objListaPeca->operator[](i);
        peca->setTabuleiro(tabuleiro);
        if(peca->mover()){
            if(peca->getNome() >= 97){
                chequeReiBranco = true;
            } else {
                chequeReiPreto = true;
            }
            if(chequeReiBranco == true && chequeReiPreto == true){
                return true;
            }
        }
    }
    return false;
}

//remove todos as peças da lista
void ListaPeca::removerLista(){
    objListaPeca->removerLista();
}