#ifndef DFS_HPP 
#define DFS_HPP
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#define MAXTAM 100





typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item_1
{
	string vaux;
};


struct Item{
	int val;
};

struct Block{
	Item data;
	Block *prox;
};

struct Pilha{
	Block *base;
	Block *top;
};


void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
void PImprime(Pilha *p);
void Matriz_arq( Item_1 m);
void Anda_labirinto();


#endif


