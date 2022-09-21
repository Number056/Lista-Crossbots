#pragma once

#include "Elemento.h"

namespace Lista{
    template<class TL>
    class Lista {
        private:
            Elemento<TL>* inicio;
            Elemento<TL>* ultimo;
            unsigned int tamLista;
        public:
            Lista();
            ~Lista();
            Elemento<TL>* getInicio();
            Elemento<TL>* getUltimo();
            int getTamLista();

            void adicionar(TL* tipo);
            TL* operator[](int posicao);
            void removerLista();

    };

    template<class TL>
    Lista<TL>::Lista():
        inicio(nullptr), ultimo(nullptr), tamLista(0)
    { }

    template<class TL>
    Lista<TL>::~Lista(){
        if(inicio){
            Elemento<TL>* aux = inicio;
            while(aux != nullptr){
                delete(aux->getTipo());
                aux->getTipo() == nullptr;
                aux = aux->getProx();
            }
            inicio = nullptr;
            ultimo = nullptr;
            tamLista = 0;
        }
    }

    template<class TL>
    Elemento<TL>* Lista<TL>::getInicio(){
        return inicio;
    }

    template<class TL>
    Elemento<TL>* Lista<TL>::getUltimo(){
        return ultimo;
    }

    template<class TL>
    int Lista<TL>::getTamLista(){
        return (int)tamLista;
    }

    template<class TL>
    void Lista<TL>::adicionar(TL* tipo){
        if(tipo == nullptr){
            std::cout << "ponteiro eh nulo" << std::endl;
            exit(1);
        }
        Elemento<TL>* aux = new Elemento<TL>();
        if(aux == nullptr){
            std::cout << "Nao eh possivel alocar memoria" << std::endl;
            exit(1);
        }
        aux->setTipo(tipo);
        if(inicio == nullptr){
            inicio = aux;
            ultimo = aux;
        } else {
            ultimo->setProx(aux);
            ultimo = aux;
        }
        tamLista++;
    }

    template<class TL>
    TL* Lista<TL>::operator[](int posicao){
        if(posicao < 0 && posicao >= tamLista){
            std::cout << "Nao eh possivel acessar essa posicao da lista" << std::endl;
            exit(1);
        }
        Elemento<TL>* aux = inicio;
        for(int i = 0; i <= posicao; i++){
            aux = aux->getProx();
        }
        return aux->getTipo();
    }

    template<class TL>
    void Lista<TL>::removerLista(){
        if(inicio){
            Elemento<TL>* aux = inicio;
            Elemento<TL>* aux2 = nullptr;
            while(aux != nullptr){
                aux2 = aux->getProx();
                delete(aux);
                aux = nullptr;
                aux = aux2;
            }
            inicio = nullptr;
            ultimo = nullptr;
            tamLista = 0;
        }
    }
}