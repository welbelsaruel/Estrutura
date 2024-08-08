#include "fila.h"
#include <iostream>

bool Fila::Verifica_Vazia() {
    if(Inicio==nullptr)
        return true;
}

void Fila::getLista(int pos) {
    if (!Inicio || pos < 0) 
        std::cerr<<"Index invalido"<<std::endl;

    No* aux = Inicio.get();
    for (int i = 0; aux && i < pos; ++i) {
        aux = aux->proximo.get();
    }

    if (!aux) 
        std::cerr<<"Index inexistente"<<std::endl;
    std::cout<<aux->dado<<std::endl;
    
}

void Fila::Modifica(int pos, int valor) {
    if (pos < 0) 
        std::cerr << "Error: Index cannot be negative" << std::endl;   

    No* aux = Inicio.get();
    for (int i = 0; aux && i < pos; ++i) {
        aux = aux->proximo.get();
    }

    if (!aux) 
        std::cerr << "Error: Index out of range" << std::endl;

    aux->dado = valor;
    std::cout << "Element at index " << pos << " modified to " << valor << std::endl;

}

void Fila::Adiciona(int pos, int dado) {
    if (pos < 0) 
        std::cerr<<"Index invalido"<<std::endl;

    std::unique_ptr<No> newNo = std::make_unique<No>(dado);

    if (pos == 0) {
        newNo->proximo = std::move(Inicio);
        Inicio = std::move(newNo);
    } 
    else {
        No* aux = Inicio.get();
        for (int i = 0; aux && i < pos - 1; ++i) {
            aux = aux->proximo.get();
    }

        if (aux) {
            newNo->proximo = std::move(aux->proximo);
            aux->proximo = std::move(newNo);
        }
    }
}

void Fila::Remove(int pos) {
    if (!Inicio || pos < 0) 
        std::cerr<<"Não foi possivel fazer a remocao"<<std::endl;

    if (pos == 0) {
        Inicio = std::move(Inicio->proximo);
        std::cerr<<"Não foi possivel fazer a remocao"<<std::endl;
    }

    No* aux = Inicio.get();
    for (int i = 0; aux->proximo && i < pos - 1; ++i) {
        aux = aux->proximo.get();
    }

    if (!aux->proximo) 
        std::cerr<<"Index invalido"<<std::endl;

    aux->proximo = std::move(aux->proximo->proximo);

}

void Fila::Exibe() {
    No* aux = Inicio.get();
    while (aux) {
        std::cout << aux->dado << " -> ";
        aux = aux->proximo.get();
    }
    std::cout << "nullptr" << std::endl;
}
