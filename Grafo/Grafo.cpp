#include "Grafo.h"
using namespace std;

void Grafo::Cria_Matriz(string arquivo){
    ifstream arq(arquivo);
    
    if(!arq.is_open()){
        cerr<<"Erro ao abrir o arquivo"<<endl;
        return;
    }

    //Armazena o valor da primeira linha do arquivo em "tam"
    arq >> tam;

    //grafo->Cria_Lista(tam);
    matriz=make_unique<unique_ptr<int[]>[]>(tam);/*cria uma matriz "size x size", a ideia é que
    depois isso seja feito usando unique_ptr o que me garante acesso 
    exclusivo a minha matriz,ou seja, impede o vazamento de memória
    e assegura a destruição dela ao final do programa*/
    for(int i=0;i<tam;++i){
        matriz[i]=make_unique<int[]>(tam);
        for(int j=0;j<tam;++j){
            arq >> matriz[i][j];
        }
    }

    arq.close();

    cout<<"Matriz"<<endl;
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++)
            cout<<matriz[i][j]<<" ";
        cout<<endl;
    }

    Cria_Lista();
}

void Grafo::Cria_Lista(){
        for (int i = 0; i < tam; ++i) {
        std::shared_ptr<Lista_adj> novaLista = std::make_shared<Lista_adj>(i);

        // Percorre a linha da matriz
        for (int j = 0; j < tam; ++j) {
            if (matriz[i][j] != 0) {  // Se houver uma aresta, adiciona à lista
                auto novoNo = std::make_shared<No>(j);

                // Insere o nó na lista encadeada
                if (!novaLista->cabeca) {
                    novaLista->cabeca = novoNo;  // A primeira inserção
                } else {
                    auto temp = novaLista->cabeca;
                    while (temp->proximo) {
                        temp = temp->proximo;
                    }
                    temp->proximo = novoNo;  // Insere no final da lista
                }
            }
        }

        // Insere a lista de adjacência no grafo
        if (!Lista) {
            Lista = novaLista;  // Se for a primeira lista
        } else {
            auto temp = Lista;
            while (temp->prox_lista) {
                temp = temp->prox_lista;
            }
            temp->prox_lista = novaLista;  // Insere no final da lista de adjacências
        }
    }

    // Exibe a lista de adjacência
    exibirListaAdjacencia();
}

void Grafo::exibirListaAdjacencia() const{
    auto listaAtual = Lista;
    while (listaAtual) {
        cout << "Vértice " << listaAtual->vertice << ": ";
        auto noAtual = listaAtual->cabeca;
        while (noAtual) {
            cout << noAtual->dado << " ";
            noAtual = noAtual->proximo;
        }
        cout << endl;
        listaAtual = listaAtual->prox_lista;
    }
}

void BFS(int origem, int dest){
    Fila<int> fila;  // Usa a fila com smart pointers

    // Usamos std::unique_ptr para gerenciar o array de visitados
    auto visitado = std::make_unique<bool[]>(tam);

    // Inicializa todos os vértices como não visitados (false)
    for (int i = 0; i < tam; ++i) {
        visitado[i] = false;
    }

    // Marca o vértice inicial como visitado e o insere na fila
    fila.Adiciona_Fila(inicio);
    visitado[inicio] = true;

    std::cout << "BFS a partir do vértice " << inicio << ": ";

    // Inicia a BFS
    while (!fila.vazia()) {
        int v = fila.frenteFila();  // Pega o vértice da frente da fila
        fila.desenfileira();        // Remove o vértice da fila
        std::cout << v << " ";      // Exibe o vértice visitado

        // Percorre a lista de adjacência do vértice atual
        auto listaAtual = Lista;
        while (listaAtual && listaAtual->vertice != v) {
            listaAtual = listaAtual->prox_lista;
        }

        // Se encontrou a lista de adjacência do vértice atual
        if (listaAtual) {
            auto noAtual = listaAtual->cabeca;
            while (noAtual) {
                int adj = noAtual->dado;  // Vértice adjacente
                if (!visitado[adj]) {     // Se ainda não foi visitado
                    fila.enfileira(adj);  // Enfileira o vértice adjacente
                    visitado[adj] = true; // Marca o vértice como visitado
                }
                noAtual = noAtual->proximo;
            }
        }
    }

    std::cout << std::endl;
}
