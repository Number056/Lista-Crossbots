#include "intermediarios_p2.h"

int main(){
    Lista* lista = preencheLista(QTD);
    printf("Antes: ");
    imprimirLista(lista);

    Lista* aux = lista;
    remove_num_repetido(aux);

    printf("Depois: ");
    imprimirLista(lista);
    return 0;
}