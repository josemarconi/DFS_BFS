#include "lab.h"
#include "queue.h"
#include "stack.h"

void LerMatriz(CoordenadaStack c, CoordenadasQueue q){

	struct stat sb;
    stat("dataset/input.data", &sb);

    FILE *f;
	int i=0, j=0, tam=0, cont=0;
    char *linha = malloc(sb.st_size);
    char *tok;
    char **mat;

    if ((f = fopen("dataset/input.data", "r")) == NULL){
        printf("file could not be opened");
        exit(-1);
    }

    while (fscanf(f, "%[^\n] ", linha) != EOF) {
		if(cont==0){
			tok = strtok(linha, "\n");
			while (tok != NULL){
				tam=atoi(tok);
				tok = strtok (NULL," ");
    		}
		
			mat = malloc(tam*sizeof(char*));

			for(int k=0;k<tam;k++)
				mat[k]=malloc(sizeof(char)*tam);
			cont++;

		}
		else{
			tok = strtok(linha, " ");

			while (tok != NULL)
   			{
				mat[i][j]=*tok;
				j++;
				tok = strtok (NULL," ");
    		}
			
			j=0;
			i++;
		}
    }

	fclose(f);

	printf("\n\nINICIANDO METODOS DE BUSCA\n");

	printf("\n===========RANDOMICO===========");
	Caminho(mat,tam);

	printf("\n================================================================================\n");

	printf("\n==============DFS==============");
	DFS(mat,tam,c);

	printf("\n================================================================================\n");
	
	printf("\n==============BFS==============");
	BFS(mat,tam,q);

	printf("\n================================================================================\n");
}

void Caminho(char **mat, int tam)
{
	double time_spent = 0.0;
 	clock_t begin = clock();

    int posicao_linha=0, posicao_coluna=0, contador0=0, contador1=0;
	int path_linha, path_coluna;
	int passos=0;
	bool vitoria = false;

	srand(time(NULL));

	printf("\n\nPOSICAO INICIAL  %d x %d = [%c] \n" , posicao_linha, posicao_coluna, mat[posicao_linha][posicao_coluna]);

	printf("\nMAPA DO LABIRINTO  \n\n");
		for(int i=0; i<tam; i++){
			for(int j=0; j<tam; j++){
				printf("%c ", mat[i][j]);
			}
			printf("\n");
		}
	printf("\n");
    
	do
	{
		do{
			// casos especiais
			// se a posicao for alguma da primeira linha 
			if(posicao_linha==0){
				// se a posicao for a posicao 0x0 da matriz
				if(posicao_linha==0 && posicao_coluna==0){
					path_linha=rand()% 2;
					path_coluna=rand()% 2;
				}
				// se a posicao for na primeira linha/ultima coluna
				else if(posicao_linha==0 && posicao_coluna==tam-1){
					path_linha=rand()% 2;
					path_coluna=(rand()% 2) -1;
				}
				// se a posicao for alguma da ultima linha fora as posicoes acima
				else{
					path_linha=rand()% 2;
					path_coluna=(rand()% 3)-1;
				}
			}

			// se a posicao for alguma da ultima linha
			else if(posicao_linha==tam-1){
				// se a posicao for na ultima linha/primeira coluna
				if(posicao_linha==tam-1 && posicao_coluna==0){
					path_linha=(rand()% 2) -1;
					path_coluna=(rand()% 2);
				}
				
				// se a posicao for a NxN matriz 
				else if(posicao_linha==tam-1 && posicao_coluna==tam-1){
					path_linha=(rand()% 2) -1;
					path_coluna=(rand()% 2) -1;
				}

				// se a posicao for alguma da ultima linha fora as posicoes acima
				else{
					path_linha=(rand()% 2) -1;
					path_coluna=(rand()% 3) -1;
				}

			}

			// se a posicao for alguma da primeira coluna
			else if(posicao_coluna==0){
				// se a posicao for a 0x0 da matriz
				if(posicao_linha==0 && posicao_coluna==0){
					path_linha=rand()% 2;
					path_coluna=rand()% 2;
				}
				
				// se a posicao for na ultima linha/primeira coluna
				if(posicao_linha==tam-1 && posicao_coluna==0){
					path_linha=(rand()% 2) -1;
					path_coluna=(rand()% 2);
				}
				// se a posicao for alguma da primeira coluna fora as posicoes acima
				else{
					path_linha=(rand()% 3) -1;
					path_coluna=rand()% 2;
				}
			}

			// se a posicao for alguma da ultima coluna
			else if(posicao_coluna==tam-1){
				// se a posicao for na primeira linha/ultima coluna
				if(posicao_linha==0 && posicao_coluna==tam-1){
					path_linha=rand()% 2;
					path_coluna=(rand()% 2) -1;
				}

				// se a posicao for a NxN matriz 
				else if(posicao_linha==tam-1 && posicao_coluna==tam-1){
					path_linha=(rand()% 2) -1;
					path_coluna=(rand()% 2) -1;
				}

				// se for alguma posicao na ultima coluna fora as posicoes acima
				else{
					path_linha=(rand()% 3) -1;
					path_coluna=(rand()% 2) -1;
				}

			}

			// se a posicao for qualquer uma que nao seja na borda da matriz
			else{
				path_linha=(rand()% 3) -1;
				path_coluna=(rand()% 3) -1;
			}
		}while((mat[posicao_linha+path_linha][posicao_coluna+path_coluna] == '#') || (path_linha==0 && path_coluna==0) );
		
		posicao_linha=posicao_linha+path_linha;
		posicao_coluna=posicao_coluna+path_coluna;
		passos++;
		
		if (mat[posicao_linha][posicao_coluna] == '1')
		{
			contador1++;
			contador0 = 0;
		}
        
        // vendo se essa posicao eh armadilha
		if(mat[posicao_linha][posicao_coluna]=='*'){
			mat[posicao_linha][posicao_coluna] = '1';
			posicao_linha = 0;
			posicao_coluna = 0;
			contador0=0;
		}

		if(mat[posicao_linha][posicao_coluna]=='?'){
			printf("\nO PONTO DE PARADA (?) FOI ACHADO NA POSICAO [%d][%d]\n", posicao_linha, posicao_coluna);
			break;
		}

		if (mat[posicao_linha][posicao_coluna] == '0'){
			contador0++;
		}

		if (contador0 == contador1*contador1){
			vitoria = true;
			break;
		}

		mat[posicao_linha][posicao_coluna]='0';

	}while(1);

	if (vitoria == true){
		printf("\nIMPOSSIVEL ENCONTRAR O PONTO DE PARADA NESTA MATRIZ\n");
	}

	printf("\nRESULTADO DO MAPA RANDOMICO: \n\n");
	for(int i=0; i<tam; i++){
			for(int j=0; j<tam; j++){
				printf("%c ", mat[i][j]);
			}
			printf("\n");
		}
	printf("\nSENDO 0 O CAMINHO FEITO\n");


	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\nO TEMPO DE EXECUCAO FOI %f SEGUNDOS\n", time_spent);
	printf("\nQUANTIDADE TOTAL DE PASSOS : %d\n", passos);
}

void DFS(char **mat, int tam, CoordenadaStack c)
{
	double time_spent = 0.0;
 	clock_t begin = clock();
	int posicao_linha=0, posicao_coluna=0;
	int passos=0;
	bool vitoria=false;
	Pilha p;
	FPVazia(&p);

	SetMatrix(mat);

	printf("\n\nPOSICAO INICIAL  %d x %d = [%c] \n" , posicao_linha, posicao_coluna, mat[posicao_linha][posicao_coluna]);
	c.linha=posicao_linha;
	c.coluna=posicao_coluna;
	Push(&p,c);

	printf("\nMAPA DO LABIRINTO  \n\n");
		for(int i=0; i<tam; i++){
			for(int j=0; j<tam; j++){
				printf("%c ", mat[i][j]);
			}
			printf("\n");
		}
	printf("\n");


	do{
		
		posicao_linha = p.top->data.linha;
		posicao_coluna = p.top->data.coluna;

		if(mat[posicao_linha][posicao_coluna]=='?'){
			printf("\nO PONTO DE PARADA (?) FOI ACHADO NA POSICAO [%d][%d]\n", posicao_linha, posicao_coluna);
			vitoria = true;
			break;
		}

		Pop(&p,&c);

		if (mat[posicao_linha][posicao_coluna] == '*'){
			mat[posicao_linha][posicao_coluna] = '1';
			posicao_linha = 0;
			posicao_coluna = 0;

			while(isVaziaStack(&p) == false){
				Pop(&p,&c);
			}
			
			ResetMatrix(mat,tam);

			c.linha=posicao_linha;
			c.coluna=posicao_coluna;
			Push(&p,c);
		}
		else{
			mat[posicao_linha][posicao_coluna] = '0';
			Empilhar(mat,posicao_linha-1,posicao_coluna-1,c,&p,tam);
			Empilhar(mat,posicao_linha-1,posicao_coluna,c,&p,tam);
			Empilhar(mat,posicao_linha,posicao_coluna-1,c,&p,tam);
			Empilhar(mat,posicao_linha-1,posicao_coluna+1,c,&p,tam);
			Empilhar(mat,posicao_linha+1,posicao_coluna-1,c,&p,tam);
			Empilhar(mat,posicao_linha,posicao_coluna+1,c,&p,tam);
			Empilhar(mat,posicao_linha+1,posicao_coluna,c,&p,tam);
			Empilhar(mat,posicao_linha+1,posicao_coluna+1,c,&p,tam);
		}		

		passos++;

	}while(isVaziaStack(&p) == false);

	if(vitoria == false){
		printf("\nIMPOSSIVEL ENCONTRAR O PONTO DE PARADA NESTA MATRIZ\n");
	}

	printf("\nRESULTADO DO MAPA DFS: \n\n");
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam; j++){
				printf("%c ", mat[i][j]);
		}
		printf("\n");
	}

	printf("\nSENDO 0 O CAMINHO FEITO E X AS POSICOES EMPILHADAS NAO VISITADAS\n");

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
   	printf("\nO TEMPO DE EXECUCAO FOI %f SEGUNDOS\n", time_spent);
	printf("\nQUANTIDADE TOTAL DE PASSOS : %d\n", passos);
}	

void Empilhar(char **mat, int posicao_linha, int posicao_coluna, CoordenadaStack c, Pilha *p, int tam)
{	
	if(posicao_linha>=0 && posicao_linha<tam && posicao_coluna>=0 && posicao_coluna<tam && (mat[posicao_linha][posicao_coluna]=='1' || mat[posicao_linha][posicao_coluna]=='*' || mat[posicao_linha][posicao_coluna]=='?')){
		c.linha=posicao_linha;
		c.coluna=posicao_coluna;
		Push(p,c);
		if(mat[posicao_linha][posicao_coluna] == '1')
			mat[posicao_linha][posicao_coluna]='x';
	}	
}

void ResetMatrix(char **mat, int tam)
{
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam; j++){
			if(mat[i][j]=='0' || mat[i][j]=='x')
				mat[i][j]='1';  
		}
	}
}

void BFS(char **mat, int tam, CoordenadasQueue q)
{
	double time_spent = 0.0;
 	clock_t begin = clock();

	Fila f;
	FFVazia(&f);

	SetMatrix(mat);

	bool vitoria = false;

	CoordenadasQueue aux;

	int posicao_linha = 0, posicao_coluna = 0;
	int passos=0;

	q.linha = posicao_linha;
	q.coluna = posicao_coluna;

	Enfileira(&f, q);

	mat[posicao_linha][posicao_coluna] = '1';

	printf("\n\nPOSICAO INICIAL  %d x %d = [%c] \n\n" , posicao_linha, posicao_coluna, mat[posicao_linha][posicao_coluna]);

	printf("\nMAPA DO LABIRINTO  \n\n");
		for(int i=0; i<tam; i++){	
			for(int j=0; j<tam; j++){
				printf("%c ", mat[i][j]);
			}
			printf("\n");
		}
	printf("\n");

	while (isVaziaQueue(&f) == false)
	{
		if (posicao_linha == 0 && posicao_coluna == 0)
		{	
			//Direita//
			if (mat[posicao_linha][posicao_coluna + 1] != '#' && mat[posicao_linha][posicao_coluna + 1] != 'x' && mat[posicao_linha][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//DDR//
			if (mat[posicao_linha + 1][posicao_coluna + 1] != '#' && mat[posicao_linha + 1][posicao_coluna + 1] != 'x' && mat[posicao_linha + 1][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha + 1][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//Down//
			if (mat[posicao_linha + 1][posicao_coluna] != '#' && mat[posicao_linha + 1][posicao_coluna] != 'x' && mat[posicao_linha + 1][posicao_coluna] != '0')
			{ 	
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna;

				if (mat[posicao_linha + 1][posicao_coluna] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna] = 'x';
					Enfileira(&f, q);
				}
			}
		}
		else if (posicao_linha != 0 && posicao_linha < (tam - 1) && posicao_coluna != 0 && posicao_coluna < (tam - 1))
		{
			//DUR//
			if (mat[posicao_linha - 1][posicao_coluna + 1] != '#' && mat[posicao_linha - 1][posicao_coluna + 1] != 'x' && mat[posicao_linha - 1][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha - 1][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//Direita//
			if (mat[posicao_linha][posicao_coluna + 1] != '#' && mat[posicao_linha][posicao_coluna + 1] != 'x' && mat[posicao_linha][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha;
				q.coluna = posicao_coluna + 1;
				
				if (mat[posicao_linha][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//DDR//
			if (mat[posicao_linha + 1][posicao_coluna + 1] != '#' && mat[posicao_linha + 1][posicao_coluna + 1] != 'x' && mat[posicao_linha + 1][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha + 1][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//Down//
			if (mat[posicao_linha + 1][posicao_coluna] != '#' && mat[posicao_linha + 1][posicao_coluna] != 'x' && mat[posicao_linha + 1][posicao_coluna] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna;

				if (mat[posicao_linha + 1][posicao_coluna] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna] = 'x';
					Enfileira(&f, q);
				}
			}
			//DDL//
			if (mat[posicao_linha + 1][posicao_coluna - 1] != '#' && mat[posicao_linha + 1][posicao_coluna - 1] != 'x' && mat[posicao_linha + 1][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha + 1][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//L//
			if (mat[posicao_linha][posicao_coluna - 1] != '#' && mat[posicao_linha][posicao_coluna - 1] != 'x' && mat[posicao_linha][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//DUL//
			if (mat[posicao_linha - 1][posicao_coluna - 1] != '#' && mat[posicao_linha - 1][posicao_coluna - 1] != 'x' && mat[posicao_linha - 1][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha - 1][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//UP//
			if (mat[posicao_linha - 1][posicao_coluna] != '#' && mat[posicao_linha - 1][posicao_coluna] != 'x' && mat[posicao_linha - 1][posicao_coluna] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna;

				if (mat[posicao_linha - 1][posicao_coluna] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna] = 'x';
					Enfileira(&f, q);
				}
			}

		}
		else if (posicao_linha == 0 && posicao_coluna != 0 && posicao_coluna < (tam - 1))
		{	
			//Direita//
			if (mat[posicao_linha][posicao_coluna + 1] != '#' && mat[posicao_linha][posicao_coluna + 1] != 'x' && mat[posicao_linha][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//DDR//
			if (mat[posicao_linha + 1][posicao_coluna + 1] != '#' && mat[posicao_linha + 1][posicao_coluna + 1] != 'x' && mat[posicao_linha + 1][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha + 1][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//Down//
			if (mat[posicao_linha + 1][posicao_coluna] != '#' && mat[posicao_linha + 1][posicao_coluna] != 'x' && mat[posicao_linha + 1][posicao_coluna] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna;

				if (mat[posicao_linha + 1][posicao_coluna] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna] = 'x';
					Enfileira(&f, q);
				}
			}
			//DDL//
			if (mat[posicao_linha + 1][posicao_coluna - 1] != '#' && mat[posicao_linha + 1][posicao_coluna - 1] != 'x' && mat[posicao_linha + 1][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha + 1][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//L//
			if (mat[posicao_linha][posicao_coluna - 1] != '#' && mat[posicao_linha][posicao_coluna - 1] != 'x' && mat[posicao_linha][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}
		}
		else if (posicao_coluna == 0 && posicao_linha != 0 && posicao_linha < (tam - 1))
		{	
			//Direita//
			if (mat[posicao_linha][posicao_coluna + 1] != '#' && mat[posicao_linha][posicao_coluna + 1] != 'x' && mat[posicao_linha][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//DDR//
			if (mat[posicao_linha + 1][posicao_coluna + 1] != '#' && mat[posicao_linha + 1][posicao_coluna + 1] != 'x' && mat[posicao_linha + 1][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha + 1][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//Down//
			if (mat[posicao_linha + 1][posicao_coluna] != '#' && mat[posicao_linha + 1][posicao_coluna] != 'x' && mat[posicao_linha + 1][posicao_coluna] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna;

				if (mat[posicao_linha + 1][posicao_coluna] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna] = 'x';
					Enfileira(&f, q);
				}
			}
			//DUR//
			if (mat[posicao_linha - 1][posicao_coluna + 1] != '#' && mat[posicao_linha - 1][posicao_coluna + 1] != 'x' && mat[posicao_linha - 1][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha - 1][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			if (mat[posicao_linha - 1][posicao_coluna] != '#' && mat[posicao_linha - 1][posicao_coluna] != 'x' && mat[posicao_linha - 1][posicao_coluna] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna;

				if (mat[posicao_linha - 1][posicao_coluna] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna] = 'x';
					Enfileira(&f, q);
				}
			}
		}
		else if (posicao_coluna == (tam - 1) && posicao_linha != 0  && posicao_linha < tam)
		{
			//Down//
			if (mat[posicao_linha + 1][posicao_coluna] != '#' && mat[posicao_linha + 1][posicao_coluna] != 'x' && mat[posicao_linha + 1][posicao_coluna] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna;

				if (mat[posicao_linha + 1][posicao_coluna] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna] = 'x';
					Enfileira(&f, q);
				}
			}
			//DDL//
			if (mat[posicao_linha + 1][posicao_coluna - 1] != '#' && mat[posicao_linha + 1][posicao_coluna - 1] != 'x' && mat[posicao_linha + 1][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha + 1;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha + 1][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha + 1][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha + 1][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//L//
			if (mat[posicao_linha][posicao_coluna - 1] != '#' && mat[posicao_linha][posicao_coluna - 1] != 'x' && mat[posicao_linha][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//DUL//
			if (mat[posicao_linha - 1][posicao_coluna - 1] != '#' && mat[posicao_linha - 1][posicao_coluna - 1] != 'x' && mat[posicao_linha - 1][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha - 1][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//UP//
			if (mat[posicao_linha - 1][posicao_coluna] != '#' && mat[posicao_linha - 1][posicao_coluna] != 'x' && mat[posicao_linha - 1][posicao_coluna] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna;

				if (mat[posicao_linha - 1][posicao_coluna] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna] = 'x';
					Enfileira(&f, q);
				}
			}

		}
		else if (posicao_linha == (tam - 1) && posicao_coluna != 0  && posicao_coluna < tam)
		{
			//Direita//
			if (mat[posicao_linha][posicao_coluna + 1] != '#' && mat[posicao_linha][posicao_coluna + 1] != 'x' && mat[posicao_linha][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//DUR//
			if (mat[posicao_linha - 1][posicao_coluna + 1] != '#' && mat[posicao_linha - 1][posicao_coluna + 1] != 'x' && mat[posicao_linha - 1][posicao_coluna + 1] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna + 1;

				if (mat[posicao_linha - 1][posicao_coluna + 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna + 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna + 1] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna + 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//UP//
			if (mat[posicao_linha - 1][posicao_coluna] != '#' && mat[posicao_linha - 1][posicao_coluna] != 'x' && mat[posicao_linha - 1][posicao_coluna] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna;

				if (mat[posicao_linha - 1][posicao_coluna] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna] = 'x';
					Enfileira(&f, q);
				}
			}
			//DUL//
			if (mat[posicao_linha - 1][posicao_coluna - 1] != '#' && mat[posicao_linha - 1][posicao_coluna - 1] != 'x' && mat[posicao_linha - 1][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha - 1;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha - 1][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha - 1][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha - 1][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}
			//L//
			if (mat[posicao_linha][posicao_coluna - 1] != '#' && mat[posicao_linha][posicao_coluna - 1] != 'x' && mat[posicao_linha][posicao_coluna - 1] != '0')
			{
				q.linha = posicao_linha;
				q.coluna = posicao_coluna - 1;

				if (mat[posicao_linha][posicao_coluna - 1] == '?')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna - 1] == '*')
				{
					Enfileira(&f, q);
				}
				else if (mat[posicao_linha][posicao_coluna - 1] == '1')
				{
					mat[posicao_linha][posicao_coluna - 1] = 'x';
					Enfileira(&f, q);
				}
			}	
		}

		aux = Busca(&f);

		posicao_linha = aux.linha;
		posicao_coluna = aux.coluna;

		passos++;
		
		Desenfileira(&f, &q);

		if (mat[posicao_linha][posicao_coluna] == '?')
		{
			printf("\nO PONTO DE PARADA (?) FOI ACHADO NA POSICAO [%d][%d]\n", posicao_linha, posicao_coluna);
			vitoria = true;
			break;
		}
		else if (mat[posicao_linha][posicao_coluna] == '*')
		{
			mat[posicao_linha][posicao_coluna] = '1';

			posicao_coluna = 0;
			posicao_linha = 0;
			
			while (isVaziaQueue(&f) == false)
			{
				Desenfileira(&f,&q);
			}

			for (int i = 0; i < tam; i++)
			{
				for (int j = 0; j < tam; j++)
				{
					if (mat[i][j] == 'x' || mat[i][j] == '0')
					{
						mat[i][j] = '1';
					}
				}
			}

			q.linha = posicao_linha;
			q.coluna = posicao_coluna;

			Enfileira(&f, q);
		}

		mat[posicao_linha][posicao_coluna] = '0';
	}

	printf("\nRESULTADO MAPA BFS:\n\n");

	if (vitoria == false)
	{
		printf("\nIMPOSSIVEL ENCONTRAR O PONTO DE PARADA NESSA MATRIZ\n\n");
	}

	for(int i=0; i<tam; i++)
	{	
		for(int j=0; j<tam; j++)
		{
			printf("%c ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("\nSENDO 0 O CAMINHO FEITO E X AS POSICOES ENFILEIRADAS NAO VISITADAS\n");

	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
  	printf("\nO TEMPO DE EXECUCAO FOI %f SEGUNDOS\n", time_spent);
	printf("\nQUANTIDADE TOTAL DE PASSOS : %d\n", passos);

}

void SetMatrix(char **mat)
{
	struct stat sb;
	stat("dataset/input.data", &sb);
	FILE *f;
	int i=0, j=0, cont=0;
    char *linha = malloc(sb.st_size);
    char *tok;

    if ((f = fopen("dataset/input.data", "r")) == NULL){
        printf("file could not be opened");
        exit(-1);
    }

  	while (fscanf(f, "%[^\n] ", linha) != EOF) {
		if(cont==0){
			tok = strtok(linha, "\n");
			while (tok != NULL){
				tok = strtok (NULL," ");
			}
			cont++;

		}
		else{
			tok = strtok(linha, " ");

			while (tok != NULL)
			{
				mat[i][j]=*tok;
				j++;
				tok = strtok (NULL," ");
			}
			
			j=0;
			i++;	
		}
	}

	fclose(f);
}	
