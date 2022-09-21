#include "intermediarios_p2.h"

// deixei uma imagem representando a lógica que foi utilizado nesta função para melhorar o entendimento.
void remove_num_repetido(Lista* lista){
    if(lista != NULL){
        Lista* temp = lista;
        Lista* tempAux = lista;
        Lista* tempProx = lista->prox;

        while(tempProx != NULL){
            if(temp->valor == tempProx->valor){
                tempProx = removerElemento(tempProx, tempProx->valor);
                tempAux->prox = tempProx;
            } else {
                tempAux = tempProx;
                tempProx = tempProx->prox;
            }
        }
        remove_num_repetido(temp->prox);
    }
}