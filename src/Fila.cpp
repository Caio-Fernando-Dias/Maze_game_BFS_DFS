#include "Fila.hpp"

void FFVazia(Fila *f){

	f->prim = (Block*) malloc (sizeof(Block));
	f->ult  = f->prim;
	f->prim->prox = NULL;

}

void Enfileira(Fila *f, Item d){

	f->ult->prox = (Block*) malloc (sizeof(Block));
	f->ult = f->ult->prox;
	f->ult->data = d;
	f->ult->prox = NULL;

}

void Desenfileira(Fila *f, Item *d){
	Block *aux;

	if(f->prim == f->ult || f == NULL || f->prim->prox == NULL){
		//printf("Erro: Lista vazia!\n");
		return;
	}
	
	aux = f->prim->prox;
	f->prim->prox = aux->prox;
	if (f->prim->prox == NULL){
		f->ult = f->prim;
	}
		d->val = aux->data.val;
		free(aux);
}


void FImprime(Fila *f){
	Block *aux;

	aux = f->prim->prox;
	while(aux != NULL){
		cout << aux->data.val << " ";
		aux = aux->prox;
	}

}

bool Verifica_fila_vazia(Fila *f){
	if(f-> prim == f-> ult || f->prim->prox == NULL || f == NULL){
		return true;
	}else{
		return false;
	}
}

void LeituraConfig(Labirinto *lab){

   //Passo 1: Leitura do tamanho da matriz no arquivo configuracao

	int tam;
	char n;
	ifstream config;
	config.open("configuracao.txt");
	config >> tam;
	lab->tam = tam;

	//Passo 2: Leitura da matriz no arquivo configuracao

	int vetor[tam * tam];
	int j = 0;

	if(config.is_open()){
		while(!config.eof()){
			config.get(n);
			if(n == '1' || n == '0'){
				n = n - '0';
				vetor[j] = n;
				lab->vet_aux[j] = vetor[j];
				j++;
			}
		}
	}
	config.close();
}

void BFS(Labirinto *lab){

	int tamanho = lab->tam;
	int i = 0;
	int j = 0;
	int matriz[tamanho][tamanho];
	int vet_aux2[tamanho * tamanho];
	int k = 0;

	//Passo 3: Transferir os valores do vetor da struct para um vetor auxiliar na função

	for(k = 0; k < tamanho * tamanho; k++){
		vet_aux2[k] = lab->vet_aux[k];
	}

	//Passo 4: Transferindo os valores do vetor auxiliar na função para uma matriz

	k = 0;
	cout << endl;
	cout << "Tamanho da matriz: " << tamanho << endl;
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			matriz[i][j] = vet_aux2[k];
			k++;
		}
	}

	//Passo 5: Testando matriz antes de entrar no BFS

	cout << "Matriz inicial labirinto: " << endl;
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			cout << matriz[i][j] << '\t';
		}
		cout << endl;
	}

	//Passo 6: Começa BFS

	Fila coluna, linha;
	Item l, c;

	int cont = 0;

	FFVazia(&linha);
	FFVazia(&coluna);
	l.val = 0;
	c.val = 0;
	Enfileira(&linha, l);
	Enfileira(&coluna, c);
 
	while(i != tamanho - 1 || j != tamanho - 1){
		

		if(((i < (tamanho - 1) && matriz[i + 1][j] == 0))){
			l.val = i + 1;
			c.val = j;
			matriz[i + 1][j] = -1;
			Enfileira(&linha, l);
			Enfileira(&coluna, c);
		}

		if(((j < (tamanho - 1) && matriz[i][j + 1] == 0))){
			l.val = i;
			c.val = j + 1;
			matriz[i][j + 1] = -1;
			Enfileira(&linha, l);
			Enfileira(&coluna, c);
		}

		if((Verifica_fila_vazia(&linha)) && (i > 0) && (matriz[i - 1][j] == 0)){
				l.val = i - 1;
				c.val = j;
				matriz[i - 1][j] = -1;
				Enfileira(&linha, l);
				Enfileira(&coluna, c);
		}
		Desenfileira(&linha, &l);
		Desenfileira(&coluna, &c);

		if((i != tamanho - 1) || (j != tamanho - 1)){
			cont++;
		}

		i = l.val;
		j = c.val;


	}
	
matriz[0][0] = -1;
matriz[tamanho - 1][tamanho - 1] = -1;

cout << endl;
cout << "O número de interações foram: " << cont << endl;

cout << "Matriz final labirinto: " << endl;
for(i = 0; i < tamanho; i++){
	for(j = 0; j < tamanho; j++){
		cout << matriz[i][j] << "\t";
	}
	cout << endl;
}

}