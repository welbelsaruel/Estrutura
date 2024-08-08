#ifndef FILA_H
#define FILA_H
#include <memory>
#include <iostream>

class Fila{
    private:
    //atributos
        struct No{
            int dado;
            std::unique_ptr<No> proximo;
            
            //Construtor
            No(int valor) : dado(valor), proximo(nullptr){}
            //Talvez não precise
        };
        
        std::unique_ptr<No> Inicio;

    public:
    //metodos
        //Construtor
        Fila():Inicio(nullptr){} 

        bool Verifica_Vazia();

        void getLista(int pos);

        void Modifica(int pos, int valor);

        void Adiciona(int pos, int dado);

        void Remove(int pos);

        void Exibe();
        

    //Construtor
    //Lista::Lista();
};

#endif
