#include "simples_p4.h"

//cria uma string com um conteúdo qualquer
std::string criaString(){
    //std::string nome("uma frase generica de questões de programação");
    return std::string("uma frase generica de questões de programação");
}

//conta a quantidade de "letra" na "palavra"
unsigned int encontra_letra(char letra, std::string palavra){
    int i = 0;
    unsigned int qtdLetra = 0;
    while(palavra[i] != '\0'){
        if(palavra[i] == letra){
            qtdLetra++;
        }
        i++;
    }
    return qtdLetra;
}