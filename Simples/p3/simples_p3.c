#include "simples_p3.h"

Lista* remove_nao_primos(Lista* lista){
     Lista* temp = lista;
     while(temp != NULL){
        if(!ehPrimo(temp->valor)){
            while(!ehPrimo(temp->valor)){
                lista = removerElemento(lista, temp->valor);
                temp = lista;
            }
        }
        temp = temp->prox;
     }
     return lista;
}

// função que verifica se o valor é primo
int ehPrimo(int valor){
    if(valor == 0 || valor == 1){
        return 0;
    }
    for(int i = 2; i < valor; i++){
        if(valor%i == 0){
            return 0;
        }
    }
    return 1;
}