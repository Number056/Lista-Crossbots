#pragma once

#include <iostream>

namespace Lista {
    template<class TE>
    class Elemento {
        private:
            Elemento<TE>* prox;
            TE* tipo;
        public:
            Elemento();
            ~Elemento();
            void setProx(Elemento<TE>* prox);
            Elemento<TE>* getProx();
            void setTipo(TE* tipo);
            TE* getTipo();
    };

    template<class TE>
    Elemento<TE>::Elemento():
        prox(nullptr), tipo(nullptr)
    { }

    template<class TE>
    Elemento<TE>::~Elemento(){
        if(tipo){
            delete(tipo);
            tipo = nullptr;
        }
    }

    template<class TE>
    void Elemento<TE>::setProx(Elemento<TE>* prox){
        this->prox = prox;
    }

    template<class TE>
    Elemento<TE>* Elemento<TE>::getProx(){
        return prox;
    }

    template<class TE>
    void Elemento<TE>::setTipo(TE* tipo){
        this->tipo = tipo;
    }

    template<class TE>
    TE* Elemento<TE>::getTipo(){
        return tipo;
    }
}