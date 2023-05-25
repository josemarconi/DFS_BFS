#include "queue.h"

void FFVazia(Fila *f)
{
	f->first = (BlockQueue*) malloc (sizeof(BlockQueue));
	f->last  = f->first;
	f->first->prox = NULL;
}

bool isVaziaQueue(Fila *f)
{
	return f->first == f->last;
}

void Enfileira(Fila *f, CoordenadasQueue q){
	f->last->prox = (BlockQueue*) malloc (sizeof(BlockQueue));
	f->last = f->last->prox;
	f->last->data = q;
	f->last->prox = NULL;
}

void FImprime(Fila *f){
	BlockQueue *aux;
	int i = 0;

	aux = f->first->prox;
	while(aux != NULL){
		printf("%d = [%d][%d]\n", i, aux->data.linha, aux->data.coluna);
		aux = aux->prox;
		i++;
	}
}

CoordenadasQueue Busca(Fila *f)
{
	BlockQueue *aux;
	CoordenadasQueue c;
	aux = f -> first -> prox;

	if (aux != NULL)
	{
		//printf("\n AuxBusca: Linha: %d ; Coluna: %d. \n", aux -> data.linha, aux -> data.coluna);
		c.linha = aux -> data.linha;
		c.coluna = aux -> data.coluna;

	}
	
	return c;
}

void Desenfileira(Fila *f, CoordenadasQueue *q)
{
	BlockQueue *aux;

		if(f->first == f->last)
		{
			printf("FILA VAZIA!\n");
			return;
		}
		
		aux = f->first->prox;
		f->first->prox = aux->prox;
		
		if (f->first->prox == NULL)
			f->last = f->first;
		
		*q = aux->data;
		free(aux);
}