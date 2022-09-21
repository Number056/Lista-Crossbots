#include "dificeis_p1.h"

char addCaracter(){
    int num = rand()%4;
    if(num == 0){
        return '<';
    } else if(num == 1){
        return '>';
    } else if(num == 2){
        return ',';
    }
    return '.';
}

std::string criaLinha(){
    char letra[N];
    for(int i = 0; i < N; i++){
        letra[i] = addCaracter();
    }
    return letra;
}

std::string remove_areia(std::string linha, int a, int b){
    linha.erase(a, b - a);
    return linha;
}

std::string fecha_diamante(std::string linha, int fim){
    int a = fim - 1;
    while(linha[a] != '<'){
        a--;
    }
    return remove_areia(linha, a, fim + 1);
}

int procura_diamante(std::string linha, int inicio, int i){
    if(inicio >= linha.size() - 2){
        return 0;
    }
    while(linha[inicio] != '<' && linha[inicio] != '>' && inicio < linha.size() - 2){
        inicio++;
    }
    if(linha[inicio] == '<'){
        i++;
        return procura_diamante(linha, inicio + 1, i);
    } else if(linha[inicio] == '>'){
        if(i == 0){
            return procura_diamante(linha, inicio + 1, i);
        }
        i--;
        int tam_ant = linha.size() - 3;
        linha = fecha_diamante(linha, inicio);

        int tam_prox = linha.size() - 3;
        //int novo_inicio = tam_ant - (tam_ant - inicio) - (tam_ant - tam_prox - 1);
        int novo_inicio = inicio + tam_prox - tam_ant + 1;
        return procura_diamante(linha, novo_inicio, i) + 1;
    }
    return 0;
}