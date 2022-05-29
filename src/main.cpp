#include "Fila.hpp"
#include "DFS.hpp"

int main(){

    int opc;
    Labirinto lab;
    Item_1 d;

    while(opc !=  4){

        Menu();
        cout << "DIGITE A OPCAO DESEJADA -> ";
        cin >> opc;

        if(opc == 1){
            Matriz_arq(d);
            Anda_labirinto();
        }

        if(opc == 2){
            LeituraConfig(&lab);
            BFS(&lab);
        }

        if(opc == 3){
            LeituraConfig(&lab);
            A(&lab);       
        }

    }
  
    return 0;
}