#include "simples_p2.h"

int verificaPerfeito(int v){
    int soma = 0;
    printf("Divisores: ");
    for(int i = 1; i < v; i++){
        if(v % i == 0){
            soma += i;
            printf("%d ", i);
        }
    }
    printf("\nSoma = %d\n", soma);
    return (v == soma)? 1 : 0;
}