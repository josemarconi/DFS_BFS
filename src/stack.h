#ifndef STACK_H 
#define STACK_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct CoordenadaStack CoordenadaStack;
typedef struct BlockStack BlockStack;
typedef struct Pilha Pilha;

struct CoordenadaStack{
	int linha;
	int coluna;
};

struct BlockStack{
	CoordenadaStack data;
	BlockStack *prox;
};

struct Pilha{
	BlockStack *base;
	BlockStack *top;
};


void FPVazia(Pilha *p);
void Push(Pilha *p, CoordenadaStack c);
void Pop(Pilha *p, CoordenadaStack *c);
void PImprime(Pilha *p);
bool isVaziaStack(Pilha *p);

#endif