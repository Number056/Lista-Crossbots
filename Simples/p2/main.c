#include "simples_p2.h"

int main(){
    int v;
    printf("Digito: ");
    scanf("%d", &v);

    if(verificaPerfeito(v)){
        printf("Eh perfeito!");
    } else {
        printf("N eh perfeito!");
    }
    return 0;
}