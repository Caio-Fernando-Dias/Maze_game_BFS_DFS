#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include <fstream>
#include <math.h>

#define MAXTAM 100

using namespace std;

struct ItemB{
	float val;
};

struct BlockB{
	ItemB data;
	BlockB *prox;
};

struct Fila{
	BlockB *prim;
	BlockB *ult;
};

struct Labirinto{
	int tam;
	int vet_aux[MAXTAM];
};

struct ItemA{
	int i;
	int j;
	float dist;
};

struct BlockA{
	ItemA dataA;
	BlockA *prox;
};

struct FilaA{
	BlockA *prim;
	BlockA *ult;
};

void FFVazia(Fila *f);
void Enfileira(Fila *f, ItemB d);
void Desenfileira(Fila *f, ItemB *d);
void FImprime(Fila *f);

void FFVaziaA(FilaA *f);
void EnfileiraA(FilaA *f, ItemA d);
void DesenfileiraA(FilaA *f, ItemA *d);
void FImprimeA(FilaA *f);
bool Verifica_fila_vaziaA(FilaA *f);

void LeituraConfig(Labirinto *lab);
bool Verifica_fila_vazia(Fila *f);
void BFS(Labirinto *lab);
void A(Labirinto *lab);
void Menu();
void MenuA();

#endif