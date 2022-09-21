#include "intermediarios_p1.h"

int main(){
    Triangulo triangulo = inicializaTriangulo();
    for(int i = 0; i < 3; i++){
        printf("Ponto %d angulo: %.2f graus\n", i, triangulo.Ponto[i].angulo);
    }
    return 0;
}