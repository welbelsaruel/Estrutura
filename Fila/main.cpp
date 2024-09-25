#include "Fila.h"
#include <iostream>

int main(){
    Fila f;

    f.Adiciona_Fila(2);
    f.Adiciona_Fila(22);
    f.Adiciona_Fila(1);
    f.Adiciona_Fila(5);
    f.Adiciona_Fila(4);
    
    f.Exibe_Fila();

    f.Remove_Fila();

    f.Exibe_Fila();
}
