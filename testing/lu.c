#include<stdio.h>
#include<stdlib.h>

/* Recebe inteiros m e n e um ponteiro para **M e armazena em **M  */
/* as entradas de uma matriz de floats com m linhas e n colunas. */
void aloca_matriz(int m, int n, float ***M);

/* Recebe inteiros m e n e **X, representando uma matriz m x n */
/* Copia X em Y */
void copia_matriz(int m, int n, float **X, float **Y);

/* Recebe inteiros m e n e imprime o bloco [0..m]x[0..n] */
/* de **M */
void imprime_matriz(int m, int n, float **M);

/* Recebe um inteiro m e um ponteiro para **M e libera a memoria */
/* alocada por **M "linha a linha" */
void libera(int m, float ***M);

/* Recebe inteiros m, n e l, **M e **N representando matrizes m x n e n x l  */
/* respectivamente e um ponteiro para **P. Devolve em **P o produto das matrizes M e N */
void multiplica(int m, int n, int l, float **M, float **N, float **P);

/* Recebe inteiro n, floats k1 e k2 e vetores u[0..n] e v[0..n]. */
/* Devolve em w a combinacao linear k1*u+k2*v */
void comblin(int n, float k1, float k2, float u[], float v[], float w[]);

/* Recebe inteiro n e **M, representando uma matriz n x n. */
/* Devolve matrizes L e U, respectivamente triangulares inferior (n x n) e */
/* superior (n x n) tais que M=LU. */
void lu(int n, float **M, float **L, float **U);

int main(void)
{

	int i, j;
	int n;		/* linhas e colunas da matriz */
	float **M, **L, **U;	/* guarda as entradas das matrizes M, L e U */

	printf("\nInforme o número de linhas e colunas da matriz M: ");
	scanf("%d", &n);
	aloca_matriz(n, n, &M);
	aloca_matriz(n, n, &L);
	aloca_matriz(n, n, &U);

	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){scanf("%f",&M[i][j]);}
	}

	/* M[0][0]=2;M[0][1]=1;M[0][2]=1; */
	/* M[1][0]=4;M[1][1]=-6;M[1][2]=0; */
	/* M[2][0]=-2;M[2][1]=7;M[2][2]=2; */

	imprime_matriz(n, n, M);

	lu(n, M, L, U);

	printf("M=L*U:\n");
	multiplica(n, n, n , L, U, M);
	imprime_matriz(n, n, M);

	printf("Desalocando as matrizes envolvidas...");
	libera(n, &M);
	libera(n, &L);
	libera(n, &U);
	printf("Pronto!\n");
	return 0;
}

/* ---------------------------------------------------------------------- */

void aloca_matriz(int m, int n, float ***M)
{

	int i;			/* indexador para cada vetor em M */
	*M = malloc(m * sizeof(float *));
	if (*M == NULL) {
		fprintf(stderr,
			"Não há memória disponível para alocar a matriz\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < m; i++) {
		(*M)[i] = malloc(n * sizeof(float));
		if ((*M)[i] == NULL) {
			fprintf(stderr,
				"Não há memória disponível para alocar a linha %i da matriz\n",
				i);
			exit(EXIT_FAILURE);
		}
	}
}

/* ---------------------------------------------------------------------- */


void copia_matriz(int m, int n, float **X, float **Y)
{
	int i, j;
	for(i = 0; i < m; i++) {
		for (j = 0; j < n; j++){Y[i][j]=X[i][j];}
	}
}

/* ---------------------------------------------------------------------- */

void libera(int m, float ***M)
{

	int i;
	for (i = 0; i < m; i++) {
		free((*M)[i]);
	}
	free(*M);
}

/* ---------------------------------------------------------------------- */

void imprime_matriz(int m, int n, float **M)
{

	int i, j /* indices para percorrer a matriz */ ;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%.4f\t", M[i][j]);
		printf("\n");
	}
	printf("\n");
}

/* ---------------------------------------------------------------------- */

void multiplica(int m, int n, int l, float **M, float **N, float **P)
{

	int i, j;		/* indices para percorrer a matriz P */
	int k;			/* indice para percorrer as colunas de M e linhas de N */
	for (i = 0; i < m; i++) {
		for (j = 0; j < l; j++) {
			P[i][j] = 0;
			for (k = 0; k < n; k++) {P[i][j] = P[i][j] + M[i][k] * N[k][j];}
		}
	}
}

/* ---------------------------------------------------------------------- */

void comblin(int n, float k1, float k2, float u[], float v[], float w[])
{
	int i;
	for (i = 0; i < n; i++) {w[i] = k1 * u[i] + k2 * v[i];};
}

/* ---------------------------------------------------------------------- */

void lu(int n, float **M, float **L, float **U)
{
	int i, j;		/* indices que percorrem a matriz M */
	copia_matriz(n, n, M, U);
	for (j = 0; j < n; j++){L[j][j]=1;}
	printf("Passos da fatoração:\n");
	for (j = 0; j < n-1; j++) {
		for (i = j+1; i < n; i++) {
			L[i][j]=U[i][j]/U[j][j];
			comblin(n, -L[i][j], 1, U[j], U[i], U[i]);
			imprime_matriz(n, n, U);
		}
	}
	printf("Matriz L:\n");
	imprime_matriz(n, n, L);

	printf("Fatoração concluída!\n");
}

/* ---------------------------------------------------------------------- */
