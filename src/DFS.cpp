#include "DFS.hpp"
int n;
string vetaux[MAXTAM];
// string Matriz[n][n];

void FPVazia(Pilha *p){
	p->base = (Block*) malloc (sizeof(Block));
	p->top  = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Item d){
	Block *aux = (Block*) malloc (sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, Item *d){
	Block *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}


void PImprime(Pilha *p){
	Block *aux;

	aux = p->top;
	while(aux != p->base){
		cout<<aux->data.val<<" ";
		aux = aux->prox;
	}
cout<<endl;
}
void Matriz_arq( Item_1 d){
	FILE *arq_m;
	ifstream arq;
	string m;
	arq.open("Matriz_DFS.txt");
	if(arq.is_open()){
		getline(arq, m);
		n = stoi(m);
	}
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
}


void Anda_labirinto(){
Pilha column,lines;
Item co,li;	
string Matriz[n][n];
bool Limite=false;
int aux=0,l,c,Coluna=0,Linha=0,Interactions=0;
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
FPVazia(&column);
FPVazia(&lines);
l=0;c=0;	 
li.val= l;
co.val= c;
Push(&lines,li );
Push(&column, co );
cout<<"PUSH"<<" "<<"nas posições :"<<endl;
cout<<"Linha: "<<l<<endl;
cout<<"Coluna: "<<c<<endl;
Matriz[l][c]="I";
while (Limite==false){
			if(l<(n-1)&&Matriz[l+1][c]=="0"){
				 while (l!=(n-1)&&Matriz[l+1][c]=="0"){
						cout<<"PUSH"<<" "<<"nas posições :"<<endl;
					    l++; 
						li.val=l;
						Push(&lines, li);
						Matriz[l][c]="v"; 	
						Linha++;	
						Interactions++;	
						cout<<"Linha: "<<l<<endl;
						cout<<"Coluna: "<<c<<endl;			
				}		
			}
				else if(c<(n-1)&&Matriz[l][c+1]=="0"){
					while (c!=(n-1)&&Matriz[l][c+1]=="0"){
					cout<<"PUSH"<<" "<<"nas posições :"<<endl;
					c++;
					co.val = c;
					Push(&column,co);
					Matriz[l][c]=">";
					Coluna++;
					Interactions++;
					cout<<"Linha: "<<l<<endl;
					cout<<"Coluna: "<<c<<endl;
			}	
		}
				else if(Coluna!=0&&c>0){
						cout<<"POP"<<" "<<"nas posições :"<<endl;
						Matriz[l][c]="<";
						Pop(&column,&co);
						Coluna--;
						c=co.val; 	
						Interactions++;
						cout<<"Linha: "<<l<<endl;
						cout<<"Coluna: "<<c<<endl;
				}
			else if(Linha!=0&&l>0){
					cout<<"POP"<<" "<<"nas posições :"<<endl;
					Matriz[l][c]="A";
					Pop(&lines,&li);
					l=li.val;
					Linha--;	
					Interactions++;
					cout<<"Linha: "<<l<<endl;
					cout<<"Coluna: "<<c<<endl;
			} else{
				cout<<"Impossivel chegar no final da matriz"<<endl;
				Limite=true;
			}
			 if((n-1)*(n-1)==l*c){
						Limite=true;
			}
}
cout<<"PUSH"<<" "<<"nas posições :"<<endl;
cout<<"Linha: "<<l<<endl;
cout<<"Coluna: "<<c<<endl;
cout<<endl;
cout<<"Matriz percorrida:"<<endl; 
cout<<endl;
 for ( l = 0; l < n; l++){
  	for ( c = 0; c < n; c++){ 
		 cout<<Matriz[l][c]<<" ";
  	}
	  cout<<endl;
}
cout<<"O numero de interaçoes foi de: "<<Interactions<<endl;
cout<<endl;
cout<<"PUSH(para baixo)"<<" = "<<"V"<<endl;
cout<<endl;
cout<<"PUSH(para direita)"<<" = "<<">"<<endl;
cout<<endl;
cout<<"POP(Para cima)"<<" = "<<"A"<<endl;
cout<<endl;
cout<<"POP(Para esquerda)"<<" = "<<"<"<<endl;
cout<<endl;
}


