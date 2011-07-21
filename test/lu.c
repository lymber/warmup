#include<stdio.h>
#include<stdlib.h>

#include "include/lu.h"
#include "include/auxiliary.h"

int main(void)
{

	int i, j;
	int n;			/* linhas e colunas da matriz */
	float **M, **L, **U;	/* guarda as entradas das matrizes M, L e U */

	printf("\nInforme o número de linhas e colunas da matriz M: ");
	scanf("%10d", &n);
	aloca_matriz(n, n, &M);
	aloca_matriz(n, n, &L);
	aloca_matriz(n, n, &U);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%20.20f", &M[i][j]);
		}
	}

	/* M[0][0]=2;M[0][1]=1;M[0][2]=1; */
	/* M[1][0]=4;M[1][1]=-6;M[1][2]=0; */
	/* M[2][0]=-2;M[2][1]=7;M[2][2]=2; */

	imprime_matriz(n, n, M);

	lu(n, M, L, U);

	printf("M=L*U:\n");
	multiplica(n, n, n, L, U, M);
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
	*M = mallocX(m * sizeof(float *));
	for (i = 0; i < m; i++) {
		(*M)[i] = mallocX(n * sizeof(float));
	}
}

/* ---------------------------------------------------------------------- */

void copia_matriz(int m, int n, float **X, float **Y)
{
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			Y[i][j] = X[i][j];
		}
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
			for (k = 0; k < n; k++) {
				P[i][j] = P[i][j] + M[i][k] * N[k][j];
			}
		}
	}
}

/* ---------------------------------------------------------------------- */

void comblin(int n, float k1, float k2, float u[], float v[], float w[])
{
	int i;
	for (i = 0; i < n; i++) {
		w[i] = k1 * u[i] + k2 * v[i];
	};
}

/* ---------------------------------------------------------------------- */

void lu(int n, float **M, float **L, float **U)
{
	int i, j;		/* indices que percorrem a matriz M */
	copia_matriz(n, n, M, U);
	for (j = 0; j < n; j++) {
		L[j][j] = 1;
	}
	printf("Passos da fatoração:\n");
	for (j = 0; j < n - 1; j++) {
		for (i = j + 1; i < n; i++) {
			L[i][j] = U[i][j] / U[j][j];
			comblin(n, -L[i][j], 1, U[j], U[i], U[i]);
			imprime_matriz(n, n, U);
		}
	}
	printf("Matriz L:\n");
	imprime_matriz(n, n, L);

	printf("Fatoração concluída!\n");
}

/* ---------------------------------------------------------------------- */
