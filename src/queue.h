#ifndef QUEUE_H 
#define QUEUE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct CoordenadasQueue CoordenadasQueue;
typedef struct BlockQueue BlockQueue;
typedef struct Fila Fila;

struct CoordenadasQueue{
	int linha;
	int coluna;
};

struct BlockQueue{
	CoordenadasQueue data;
	BlockQueue *prox;
};

struct Fila{
	BlockQueue *first;
	BlockQueue *last;
};

void FFVazia(Fila *f);
bool isVaziaQueue(Fila *f);
void Enfileira(Fila *f, CoordenadasQueue q);
void Desenfileira(Fila *f, CoordenadasQueue *q);
void FImprime(Fila *f);
CoordenadasQueue Busca(Fila *f);
#endif