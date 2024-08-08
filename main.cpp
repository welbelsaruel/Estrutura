#include <iostream>
#include <memory>
#include "fila.h"

using namespace std;

int main(){
    Fila list;
    list.Adiciona(0, 1);   // Lista: 1
    list.Adiciona(1, 2);   // Lista: 1 -> 2
    list.Adiciona(2, 4);   // Lista: 1 -> 2 -> 3
    list.Adiciona(3, 8);   // Lista: 1 -> 4 -> 2 -> 3

    cout << "List after inserting 1 at index 0, 2 at index 1, 3 at index 2, and 4 at index 1:" << std::endl;
    list.Exibe();

    cout << "Modifying element at index 2 to 10:" << std::endl;
    list.Modifica(2, 10);  // Modifica o elemento no índice 2 para 10

    cout << "List after modification:" << std::endl;
    list.Exibe();

    return 0;
}
