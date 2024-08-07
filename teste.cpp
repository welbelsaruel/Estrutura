//Falta rodar
#include <memory>
#include <iostream>

class Lista{
    private:
    //atributos
        struct No{
            int dado;
            std::unique_ptr<No> proximo;
            
            //Construtor
            //No(int valor) : dado(valor), proximo(nullptr){}
            //Talvez não precise
        };
        
        std::unique_ptr<No> Inicio;

    public:
    //metodos
        //Construtor
        //Lista():Inicio(nullptr){} 

        bool Verifica_Vazia(){
            if(Inicio==nullptr)
                return true;
        };

        void getLista(int pos){
            if (!Inicio || pos < 0) 
                std::cerr<<"Index invalido"<<std::endl;

            No* aux = Inicio.get();
            for (int i = 0; aux && i < pos; ++i) {
                aux = aux->proximo.get();
            }

            if (!aux) 
                std::cerr<<"Index inexistente"<<std::endl;
            std::cout<<aux->dado<<std::endl;
        };

        void Modifica(int pos, int valor){
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
        };

        void Adiciona(int pos, int dado){
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
        };

        void Remove(int pos){
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
        };

        void Exibe(){
            No* aux = Inicio.get();
            while (aux) {
                std::cout << aux->dado << " -> ";
                aux = aux->proximo.get();
            }
            std::cout << "nullptr" << std::endl;
        };
        

    //Construtor
    //Lista::Lista();
};

using namespace std;

int main(){
    Lista list;
    list.Adiciona(1, 0);   // Lista: 1
    list.Adiciona(2, 1);   // Lista: 1 -> 2
    list.Adiciona(3, 2);   // Lista: 1 -> 2 -> 3
    list.Adiciona(4, 1);   // Lista: 1 -> 4 -> 2 -> 3

    cout << "List after inserting 1 at index 0, 2 at index 1, 3 at index 2, and 4 at index 1:" << std::endl;
    list.Exibe();

    cout << "Modifying element at index 2 to 10:" << std::endl;
    list.Modifica(2, 10);  // Modifica o elemento no índice 2 para 10

    cout << "List after modification:" << std::endl;
    list.Exibe();

    return 0;
}
