#include "Fila.hpp"

int main(){

    Labirinto lab;

    LeituraConfig(&lab);

    BFS(&lab);

    return 0;
}