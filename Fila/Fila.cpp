#include "Fila.h"
#include <iostream>

bool Fila::Vazia(){
    return inicio==nullptr;
}

void Fila::Adiciona_Fila(int valor){
    auto novoNo = std::make_shared<No>(valor);
    if(Vazia()){
        inicio = novoNo;
        fim = novoNo;
    }
    else{
        fim->prox=novoNo;
        fim=novoNo;
    }
}

void Fila::Remove_Fila(){
    if (!Vazia()) {
        inicio = inicio->prox;
        if (!inicio) {
            fim = nullptr;  // Fila ficou vazia
        }
    }
}

void Fila::Exibe_Fila(){
    auto atual=inicio;
    while(atual!=nullptr){
        std::cout<<atual->info<<" ";
        atual=atual->prox;
    }
    std::cout<<std::endl;
}
