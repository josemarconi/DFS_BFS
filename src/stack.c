#include "stack.h"

void FPVazia(Pilha *p){
	p->base = (BlockStack*) malloc (sizeof(BlockStack));
	p->top  = p->base;
	p->base->prox = NULL;
}

bool isVaziaStack(Pilha *p){
	return p->top == p->base;
}

void Push(Pilha *p, CoordenadaStack c){
	BlockStack *aux = (BlockStack*) malloc (sizeof(BlockStack));
	aux->data = c;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, CoordenadaStack *c){
	BlockStack *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*c = aux->data;
	free(aux);
}


void PImprime(Pilha *p){
	BlockStack *aux;

	aux = p->top;
	while(aux != p->base){
		printf("[%d][%d]\n", aux->data.linha, aux->data.coluna);
		aux = aux->prox;
	}

}
