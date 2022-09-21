#include "simples_p3.h"

int main(){
    Lista* lista = criaLista();
    lista = preencheLista(10);
    printf("Antes: ");
    imprimirLista(lista);

    lista = remove_nao_primos(lista);
    printf("Depois: ");
    imprimirLista(lista);

    deletaLista(lista);
    return 0;
    
}