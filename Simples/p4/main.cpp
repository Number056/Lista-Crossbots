#include "simples_p4.h"

int main(){
    std::string nome = criaString();
    char letra = 'a';
    std::cout << "'" << nome << "'" << " tem " << encontra_letra(letra, nome) << " letra(s) " << "'" << letra << "'" << std::endl; 
    return 0;
}