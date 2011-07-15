#include<stdio.h>
#include<stdlib.h>

/* Recebe inteiros m e n e um ponteiro para **M e armazena em **M  */
/* as entradas de uma matriz de floats com m linhas e n colunas. */
void aloca_matriz(int m, int n, float ***M);

/* Recebe inteiros m e n e imprime o bloco [0..m]x[0..n] */
/* de **M */
void imprime_matriz(int m, int n, float **M);

/* Recebe um inteiro m e um ponteiro para **M e libera a memória */
/* alocada por **M "linha a linha" */
void libera(int m, float ***M);

/* Recebe inteiros m, n e l, **M e **N representando matrizes m por n e n por l  */
/* respectivamente e um ponteiro para **P. Devolve em **P o produto das matrizes M e N */
void multiplica(int m, int n, int l, float **M, float **N, float **P);

/* Recebe inteiros m e n e **M, representando uma matriz m por n. */
/* Devolve matrizes L e U, respectivamente triangulares inferior e */
/* superior tais que M=LU. */
void lu(int m, int n, float **M, float **L, float **U);

int main(void)
{

	int m, n, k, l;		/* linhas e colunas da matriz */
	int i, j;		/* indices para linhas e colunas */
	float **M, **L, **U;	/* guarda as entradas das matrizes M, N e P */

	printf("\nInforme o número de linhas da matriz M: ");
	scanf("%d", &m);
	printf("Informe o número de colunas da matriz M: ");
	scanf("%d", &n);
	aloca_matriz(m, n, &M);

	printf("\nInforme o número de linhas da matriz L: ");
	scanf("%d", &k);
	printf("Informe o número de colunas da matriz L: ");
	scanf("%d", &l);
	aloca_matriz(k, l, &L);


	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			M[i][j] = i + j;
		}
	}

	for (i = 0; i < k; i++) {
		for (j = 0; j < l; j++) {
			L[i][j] = 2*i+j;
		}
	}

	for (i = 0; i < m; i++) {
		M[i][2] = 0;
	}

	imprime_matriz(m, n, M);
	imprime_matriz(k, l, L);

	if (n == k) {
		aloca_matriz(m, l, &U);
		multiplica(m, n, l, M, L, U);
		printf("O produto de M e L é:\n");
		imprime_matriz(m, l, U);
	} else {
		printf
		    ("Número de colunas de M e linhas de L de tamanho diferentes, não é possível fazer o produto.\n");
		printf("Desalocando a matriz M:\n");
		libera(m, &M);
		printf("Desalocando a matriz L:\n");
		libera(k, &L);
		printf("Saindo do programa...\n");
		return 0;
	}

	printf("Desalocando a matriz M:\n");
	libera(m, &M);
	printf("Desalocando a matriz L:\n");
	libera(k, &L);
	printf("Desalocando a matriz U:\n");
	libera(m, &U);
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

void libera(int m, float ***M)
{

	int i;
	for (i = 0; i < m; i++) {
		free((*M)[i]);
		printf("Linha %d desalocada\n", i);
	}
	free(*M);
}

/* ---------------------------------------------------------------------- */

void imprime_matriz(int m, int n, float **M)
{

	int i, j /* indices para percorrer a matriz */ ;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf("%.0f ", M[i][j]);
		printf("\n");
	}
	printf("\n");
}

/* ---------------------------------------------------------------------- */

void multiplica(int m, int n, int l, float **M, float **N, float **P)
{

	int i, j;		/* indices para percorrer a matriz P */
	int k;			/* indice para percorrer as colunas de M e linhas de N */
	for (i = 0; i < m; i++)
		for (j = 0; j < l; j++) {
			P[i][j] = 0;
			for (k = 0; k < n; k++)
				P[i][j] = P[i][j] + M[i][k] * N[k][j];
		}
}

/* ---------------------------------------------------------------------- */

void lu(int m, int n, float **M, float **L, float **U)
{
	int i, j;		/* indices que percorrem a matriz M */

}

/* ---------------------------------------------------------------------- */
