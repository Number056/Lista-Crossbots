#include "dificeis_p1.h"

int main(){
    int num;
    std::cout << "Quantidade de minas: ";
    std::cin >> num;
    system("cls");
    srand((time(NULL)));
    for(int i = 0; i < num; i++){
        std::string linha = criaLinha();
        std::cout << "Quantidade de diamante(s) na mina " << i + 1 << ": " << procura_diamante(linha, 0, 0) << std::endl;
    }
    return 0;
}