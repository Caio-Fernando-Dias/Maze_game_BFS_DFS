 # Busca em profundidade(DFS)

 ## Oque é o DFS ?
  - O DFS é um mecanismos de busca que visa ir o mais profundo em um vertice escolhido da matriz com o objetivo de chegar ao seu final.
  - Prioritaiamente foi escolhido para este algoritmo avançar para baixo indo o mais fundo no vertice lateral esquerdo.

# Proposta apresentada:
 1. Foi pedido:
   - 1.1 A criação de um arquivo contendo:
      - O tamanho de uma matriz quadrada. 
      - posiçoes das paredes.
      - Tipo de busca, neste caso o DFS.
   - 1.1 O jogo deveria terminar apos o alvo ser atingido.
   - 1.3 Tambem foi necessario imprimir o caminho feito pelo algoritmo na matriz, mostrando:
      - Barreiras.
      - Lugares onde foi relizado`ṔOP`.
      - Posiçoes onde foram relizados`PUSH`.

 # Logica utilizada :

 ## Leitura e criação do vetor auxliar.
   4. Primeiramente utilizamos a função `void Matriz_arq( Item_1 m)` onde:
      - na primeira parte do codigo abrimos o arquivo de configuração **Matriz_DSS.txt**.
      - Lemos o primeira linha do arquivo onde esta definido o tamanho da matriz e salvamos na variavel *m* do tipo `string` e logo transformamos ela no tipo `int`.
```c++
  FILE *arq_m;
	ifstream arq;
	string m;
	arq.open("Matriz_DFS.txt");
	if(arq.is_open()){
		getline(arq, m);
		n = stoi(m);
	}
```

- Em seguida começamos a ler caracter por carcter do arquivo, salvando apenas aqueles caracters que eram iguais a *0* ou *1* e adicionandos em um vetor auxiliar:

```c++
  int Total;
	Total=n*n;
	arq.close();
	arq_m = fopen("Matriz_DFS.txt","r");
	for ( int l = 0; l < Total ; ){
		d.vaux = fgetc(arq_m);
		m=d.vaux;
		if(m == "1"|| m == "0"){
			 vetaux[l] = m;
								l++;
		}
	}

```

## Andando na matriz utilizando o DFS.


 5. Para relização desta parte do algoritmo utilizamos a função `void Anda_labirinto();` onde:
  - Primeiramente declaramos algumas variaveis importante como:
```c++
  Pilha column,lines;
  Item co,li;	
  string Matriz[n][n];
  bool Limite=false;
  int aux=0,l,c,Coluna=0,Linha=0;
```
  - Apos isso passamos os valores do vetor auxiliar para nossa matriz e exibimos ela na tela para o usuario.

```c++
  cout<<"Matriz escolhida para ser percorrida:"<<endl;

  for ( l = 0; l < n; l++){
      for ( c = 0; c < n; c++){ 
        Matriz[l][c]=vetaux[aux];
          aux++;
        cout<<Matriz[l][c]<<" ";
      } 
        cout<<endl;
  }
    cout<<"-------------"<<endl;
    cout<<endl;
    cout<<endl;
```
  -  Em seguida utilizamos de um **while** para percorrer a matriz de forma a chegar no final dela.
  - Dentro deste *while* foi utilizado 4 chaves de **if's** principais.
    - Dois destes com a intenção de andar para baixo e para direita dando um **PUSH** nas posiçoes da matriz:
```c++
     if(l<(n-1)&&Matriz[l+1][c]=="0"){
				 while (l!=(n-1)&&Matriz[l+1][c]=="0"){
						cout<<"PUSH"<<" "<<"nas posições :"<<endl;
						cout<<"Linha: "<<l<<endl;
						cout<<"Coluna: "<<c<<endl;
					    l++; 
						li.val=l;
						Push(&lines, li);
						Matriz[l][c]="v"; 	
						Linha++;				
				}		
			}
				else if(c<(n-1)&&Matriz[l][c+1]=="0"){
					while (c!=(n-1)&&Matriz[l][c+1]=="0"){
					cout<<"PUSH"<<" "<<"nas posições :"<<endl;
					cout<<"Linha: "<<l<<endl;
					cout<<"Coluna: "<<c<<endl;
					c++;
					co.val = c;
					Push(&column,co);
					Matriz[l][c]=">";
					Coluna++;	
			}	
		}
```
  - Repare que por onde a acontece o **PUSH** atribuimos os valore de `V` para baixo e `>` para direita.
  - Os outros dois **if's** foram feitos para andar para cima e para esquerda dando um **POP** na posiçao atual da matriz:
```c++
				else if(Coluna!=0&&c>0){
						cout<<"POP"<<" "<<"nas posições :"<<endl;
						cout<<"Linha: "<<l<<endl;
						cout<<"Coluna: "<<c<<endl;
						Matriz[l][c]="<";
						Pop(&column,&co);
						Coluna--;
						c=co.val; 				
				}
			else if(Linha!=0&&l>0){
					cout<<"POP"<<" "<<"nas posições :"<<endl;
					cout<<"Linha: "<<l<<endl;
					cout<<"Coluna: "<<c<<endl;
					Matriz[l][c]="A";
					Pop(&lines,&li);
					l=li.val;
					Linha--;	
			}
```
  - repare que apos o **POP** as posiçoes da matriz sao atualizadas
  - repare tambem que ao andar para esquerda é atribuida a posição o simbolo `<` e para cima a letra `A`.
    
  - Por fim utilizamos um **else** para fechar o programa caso nao haja soloçao para chegar no final da matriz. Fjnalizamos o **while** e imprimimos o resultado da matriz na tela do usuario.
```C++
  else{
				cout<<"Impossivel chegar no final da matriz"<<endl;
				Limite=true;
			}
			 if((n-1)*(n-1)==l*c){
						Limite=true;
			}

cout<<"Matriz percorrida:"<<endl; 
cout<<endl;
for ( l = 0; l < n; l++){
  	for ( c = 0; c < n; c++){ 
		 cout<<Matriz[l][c]<<" ";
  	}
	  cout<<endl;
}
```

# Funcionamento 
   
 ## Funcionamento Makefile:
                                                                   
 |      Comandos       |        Função       |
 | ------------------- | ------------------- |
 |         make        |  Compila o Programa |
 |       make run      | Executa o algoritmo |
 |       make clean    | Limpa todos os dados da ultima compilação|
 ### Funcionamento Aquivo **"Matriz_DFS.txt"**:
 
 - O arquivo deve ser um aquivo txt.
 - Conter ate no maximo uma matriz 10 por 10.
 - O arquivo deve apresentar na primeira linha o tamamho desejado da matriz 
 - Logo abaixo a matriz desejada.
 **EX**:
```
 7
0   0   0   0   1   0   0
0   0   0   0   1   0   0
0   0   1   0   0   1   0
0   0   0   0   0   0   0
0   1   0   0   1   0   0
0   0   0   0   0   0   1
0   1   0   1   1   0   0 
``` 