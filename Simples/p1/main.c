#include "simples_p1.h"

int main(){
    Vector vet = criaVector(10);
    preencheVector(vet);
    imprimeVector(vet);

    int x, y;
    int flag = 1;

    while(flag){
        printf("Digite x: ");
        scanf("%d", &x);

        printf("Digite y: ");
        scanf("%d", &y);

        if(x < vet.tam && y < vet.tam && x >= 0 && y >= 0){
            flag = 0;
        } else {
            printf("Entrada invalida! digite valores entre [0,%d)\n\n", vet.tam);
        }
    }

    printf("Soma = %d", vet.v[x] + vet.v[y]);
    deletaVector(vet);
    return 0;
}