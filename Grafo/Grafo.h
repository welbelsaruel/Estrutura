#pragma once
//#include ""
#include <memory>
#include <fstream>
#include <iostream>

using namespace std;

//template<typename T>
class Grafo{
    private:
        
        /*
        O NO serve para criar a LISTA_DE_ADJACÊNCIA de LISTAS_DE_ADJACÊNCIAS
        a ideia é que não alocando um vetor estatico na memória eu possa fazer
        um uso mais eficiente dela, e como eu uso shared_ptr, a chance de ocorrer
        vazamento de memória acaba sendo bem menor do que usando ponteiros normais
        */
        
        struct No{
            int dado;
            std::shared_ptr<No> proximo;

            No(int dado){
                this->dado=dado;
                proximo=nullptr;
            }
        };

        /*
        Aqui é implementada a LISTA_DE_ADJACÊNCIA, a CABEÇA é o começo
        de cada lista e a PROX_LISTA é a proxima lista em si
        CABEÇA é equivalente as colunas e a PROX_LISTA é equivalente as linhas        
        o vertice é o valor do NO em si, o nome do vertice NÃO É SEU PESO
        */

        struct Lista_adj{
            int vertice;
            std::shared_ptr<No> cabeca;
            std::shared_ptr<Lista_adj> prox_lista;

            Lista_adj(int vertice){
                this->vertice=vertice;
                cabeca=nullptr;
                prox_lista=nullptr;
            }
        };

        std::shared_ptr<Lista_adj> Lista=nullptr;

        std::unique_ptr<std::unique_ptr<int[]>[]> matriz;
        int tam;
        //void Cria_Aresta(int Origem, int Destino);

    public:

        void BFS(int origem, int dest);
        void DFS(int origem);
        void Cria_Lista();
        void Cria_Matriz(string arquivo);
        void exibirListaAdjacencia() const;

};

