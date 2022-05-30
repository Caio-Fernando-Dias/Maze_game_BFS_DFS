#include "Fila.hpp"

void FFVazia(Fila *f){
	f->prim = (BlockB*) malloc (sizeof(BlockB));
	f->ult  = f->prim;
	f->prim->prox = NULL;
}

void Enfileira(Fila *f, ItemB d){
	f->ult->prox = (BlockB*) malloc (sizeof(BlockB));
	f->ult = f->ult->prox;
	f->ult->data = d;
	f->ult->prox = NULL;
}

void Desenfileira(Fila *f, ItemB *d){
	BlockB *aux;
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
	BlockB *aux;
	aux = f->prim->prox;
	while(aux != NULL){
		cout << aux->data.val << " ";
		aux = aux->prox;
	}
}

void FFVaziaA(FilaA *f){
	f->prim = (BlockA*) malloc (sizeof(BlockA));
	f->ult  = f->prim;
	f->prim->prox = NULL;
}

void EnfileiraA(FilaA *f, ItemA d){
	f->ult->prox = (BlockA*) malloc (sizeof(BlockA));
	f->ult = f->ult->prox;
	f->ult->dataA = d;
	f->ult->prox = NULL;
}

void DesenfileiraA(FilaA *f, ItemA *d){
	BlockA *aux;
	if(f->prim == f->ult || f == NULL || f->prim->prox == NULL){
		//printf("Erro: Lista vazia!\n");
		return;
	}
	aux = f->prim->prox;
	f->prim->prox = aux->prox;
	if (f->prim->prox == NULL){
		f->ult = f->prim;
	}
		d->dist = aux->dataA.dist;
		free(aux);
}

void FImprimeA(FilaA *f){
	BlockA *aux;
	aux = f->prim->prox;
	while(aux != NULL){
		cout << aux->dataA.dist << " ";
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

bool Verifica_fila_vaziaA(FilaA *f){
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
	config.open("Matriz_DFS.txt");
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
	cout << "TAMANHO DA MATRIZ NXN: " << tamanho << endl;
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			matriz[i][j] = vet_aux2[k];
			k++;
		}
	}

	//Passo 5: Testando matriz antes de entrar no BFS

	cout << "MATRIZ INICIAL DO LABIRINTO: " << endl;
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			cout << matriz[i][j] << '\t';
		}
		cout << endl;
	}

	//Passo 6: Começa BFS

	Fila coluna, linha;
	ItemB l, c;

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

	cout << "O NUMERO DE INTERACOES: " << cont << endl;
	cout << "MATRIZ APOS SER PERCORRIDA: " << endl;
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			cout << matriz[i][j] << "\t";
		}
		cout << endl;
	}
}

void A(Labirinto *lab){

	int opcA = 0;

	MenuA();
	cout << "DIGITE A OPCAO DESEJADA -> ";
	cin >> opcA;

	int tamanho = lab->tam;
	int i = 0;
	int j = 0;
	int matriz[tamanho][tamanho];
	int vet_aux2[tamanho * tamanho];
	int k = 0;

	for(k = 0; k < tamanho * tamanho; k++){
		vet_aux2[k] = lab->vet_aux[k];
	}

	k = 0;
	
	for(i = 0; i < tamanho; i++){
		for(j = 0; j < tamanho; j++){
			matriz[i][j] = vet_aux2[k];
			k++;
		}
	}

	FilaA calculo;
	ItemA aux;
	aux.dist = 0;
	aux.i = 0;
	aux.j = 0;

	FFVaziaA(&calculo);

	int cont = 0;

	float D_E;
	float D_M;
	
	D_E = sqrt((pow(((tamanho - 1) - i),2)) + (pow(((tamanho - 1) - j),2)));
	D_M = (abs((tamanho - 1) - i) + abs((tamanho - 1) - j));

	cout << opcA;
	if(opcA == 1){
		aux.dist = D_E;
	}else if(opcA == 2){
		aux.dist = D_M;
	}

	EnfileiraA(&calculo, aux);

	while(i != tamanho - 1 || j != tamanho - 1){
		if(((i <= (tamanho - 1) && matriz[i + 1][j] == 0))){

			i++;
			aux.i = i;
			aux.j = j;
			matriz[i][j] = -1;

			D_E = sqrt((pow(((tamanho - 1) - i),2)) + (pow(((tamanho - 1) - j),2)));
			D_M = (abs((tamanho - 1) - i) + abs((tamanho - 1) - j));

			if(opcA == 1){
				aux.dist = D_E;
			}else if(opcA == 2){
				aux.dist = D_M;
			}

			EnfileiraA(&calculo, aux);
		}

		if(((j <= (tamanho - 1) && matriz[i][j + 1] == 0))){

			j++;
			aux.i = i;
			aux.j = j;
			matriz[i][j] = -1;

			D_E = sqrt((pow(((tamanho - 1) - i),2)) + (pow(((tamanho - 1) - j),2)));
			D_M = (abs((tamanho - 1) - i) + abs((tamanho - 1) - j));

			if(opcA == 1){
				aux.dist = D_E;
			}else if(opcA == 2){
				aux.dist = D_M;
			}

			EnfileiraA(&calculo, aux);
		}

		if((Verifica_fila_vaziaA(&calculo)) && (i > 0) && (matriz[i - 1][j] == 0)){

			i--;
			aux.i = i;
			aux.j = j;
			matriz[i][j] = -1;

			D_E = sqrt((pow(((tamanho - 1) - i),2)) + (pow(((tamanho - 1) - j),2)));
			D_M = (abs((tamanho - 1) - i) + abs((tamanho - 1) - j));

			if(opcA == 1){
				aux.dist = D_E;
			}else if(opcA == 2){
				aux.dist = D_M;
			}
			
			EnfileiraA(&calculo, aux);
		}
		DesenfileiraA(&calculo, &aux);

		if((i != tamanho - 1) || (j != tamanho - 1)){
			cont++;
		}

			i = aux.i;
			j = aux.j;

	}
	
		matriz[0][0] = -1;
		matriz[tamanho - 1][tamanho - 1] = -1;
		cout << endl;

		cout << "O NUMERO DE INTERACOES: " << cont << endl;

		cout << "MATRIZ APOS SER PERCORRIDA: " << endl;
		for(i = 0; i < tamanho; i++){
			for(j = 0; j < tamanho; j++){
				cout << matriz[i][j] << "\t";
				}
			cout << endl;
		}

}

void Menu(){
	cout << endl;
	cout << "|----------------|" << endl;
	cout << "|------MENU------|" << endl;
	cout << "|[1] - DFS       |" << endl;
	cout << "|[2] - BFS       |" << endl;
	cout << "|[3] - A*        |" << endl;
	cout << "|[4] - Finalizar |" << endl;
	cout << "|----------------|" << endl;
	cout << endl;
}

void MenuA(){
	cout << endl;
	cout << "|-----------------|" << endl;
	cout << "|------MENU-------|" << endl;
	cout << "|[1] - Euclidiana |" << endl;
	cout << "|[2] - Manhatttan |" << endl;
	cout << "|[3] - Voltar     |" << endl;
	cout << "|-----------------|" << endl;
	cout << endl;
}