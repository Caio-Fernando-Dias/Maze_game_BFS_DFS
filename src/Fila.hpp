#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include <fstream>

#define MAXTAM 100

using namespace std;

struct Item{

	int val;
};

struct Block{

	Item data;
	Block *prox;

};

struct Fila{

	Block *prim;
	Block *ult;

};

struct Labirinto{
	int tam;
	int vet_aux[MAXTAM];
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, Item d);
void Desenfileira(Fila *f, Item *d);
void FImprime(Fila *f);

void LeituraConfig(Labirinto *lab);
bool Verifica_fila_vazia(Fila *f);
void BFS(Labirinto *lab);



#endif