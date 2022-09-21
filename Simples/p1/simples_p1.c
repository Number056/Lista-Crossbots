#include "simples_p1.h"


//cria um vetor com "tam" posições
Vector criaVector(int tam){
    //aloca memória para o vetor de acordo com a quantidade "tam"
    Vector vet;
    int *p = (int*)malloc(sizeof(int) * tam); 
    if (p == NULL){
        printf("ERROR -1: vetor is NULL");
        exit(1);
    }
    vet.v = p;
    vet.tam = tam;
    return vet;
}

void deletaVector(Vector vet){
    free(vet.v);
    vet.v = NULL;
}

//preenche o vector de "tam" posições com valors no intervalor de [0,100)
void preencheVector(Vector vet){
    srand(time(NULL));
    for(int i = 0; i < vet.tam; i++){
        vet.v[i] = rand()%100;
    }
}

void imprimeVector(Vector vet){
    for(int i = 0; i < vet.tam; i++){
        printf("%d ", vet.v[i]);
    }
    printf("\n\n");
}