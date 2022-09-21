#include "list.h"

Lista* criaLista(){
    return NULL;
}

Lista* inserirElemento(Lista* lista, int valor){
    Lista* aux = (Lista*)malloc(sizeof(Lista));
    if(aux == NULL){
        printf("Error -1: nao eh possivel alocar memoria");
        exit(1);
    }
    aux->valor = valor;
    aux->prox = lista;
    return aux;
}

Lista* removerElemento(Lista* lista, int valor){
    Lista *temp1 = lista, *temp2 = NULL;
    while (temp1 != NULL && temp1->valor != valor) {
        temp2 = temp1;
        temp1 = temp1->prox;
    }
    //não encontro o valor:
    if(temp1 == NULL){
        return lista;
    }
    //encontro o valor:
    if(temp2 == NULL){
        lista = temp1->prox;
    } else {
        temp2->prox = temp1->prox;
    }
    free(temp1);
    return lista;
}

void imprimirLista(Lista* lista){
    Lista* temp = lista;
    while(temp != NULL){
        printf("%d ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

// função que preenche a lista com "qtdValor" de elementos
Lista* preencheLista(int qtdValor){
    Lista* lista = criaLista();
    srand(time(NULL));
    int aleatorio;
    for(int i = 0; i < qtdValor; i++){
        aleatorio = rand() % qtdValor;
        lista = inserirElemento(lista, aleatorio);
    }
    return lista;
}

void deletaLista(Lista* lista){
    while(lista != NULL){
        Lista* temp  = lista->prox;
        free(lista);
        lista = temp;
    }
}