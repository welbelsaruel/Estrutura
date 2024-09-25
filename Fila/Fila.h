#pragma once
#include <memory>

class Fila{
    private:
        
        struct No{
            int info;
            std::shared_ptr<No> prox;            
            No(int dado):info(dado), prox(nullptr){}//construtor do no
            //info recebe dado e prox sempre vai receber um nullptr
        };

        std::shared_ptr<No> inicio;
        std::shared_ptr<No> fim;

    public:
        Fila() : inicio(nullptr), fim(nullptr){}//construtor da fila
        //ela comeca vazia, então o inicio e o fim apontam para nullptr
        bool Vazia();
        void Adiciona_Fila(int valor);
        void Remove_Fila();
        void Exibe_Fila();
};
