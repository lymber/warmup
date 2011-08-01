#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "../include/auxiliary.h"

void matrix_alloc(int m, int n, float ***M)
{

	int i;
	*M = mallocX(m * sizeof(float *));
	for (i = 0; i < m; i++) {		(*M)[i] = mallocX(n * sizeof(float));
	}
}

void matrix_free(int m, float ***M)
{

	int i;
	for (i = 0; i < m; i++) {
		free((*M)[i]);
	}
	free(*M);
}

void matrix_gen(int matrixsize, float **M)
{
	int i,j;
	float sum;

	srand(time(NULL));

        for (i = 0; i < matrixsize; i++) {
                for (j = 0; j < matrixsize; j++) {
                        if (j != i) {
                                M[i][j] =rand()/(RAND_MAX + 1.0);
                        }
			else {
                                M[i][i] = 0;
                        }
                }
        }
        for (i = 0; i < matrixsize; i++) {
                sum = 0;
                for (j = 0; j < matrixsize; j++) {
                        sum = sum + fabs(M[i][j]);
                }
                M[i][i] = sum + 1;
        }
}

void matrix_print(int m, int n, float **M)
{

	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.4f\t", M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void matrix_multiply(int m, int n, int l, float **M, float **N, float **P)
{

	int i, j, k;
	for (i = 0; i < m; i++) {
		for (j = 0; j < l; j++) {
			P[i][j] = 0;
			for (k = 0; k < n; k++) {
				P[i][j] = P[i][j] + M[i][k] * N[k][j];
			}
		}
	}
}

/* Takes ints m and n, **X **Y, treated as an m x n matrices. */
/* Copies X to Y */
static void matrix_copy(int m, int n, float **X, float **Y)
{

	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			Y[i][j] = X[i][j];
		}
	}
}

/* Takes an int n, floats k1 and k2 e arrays u[0..n] and v[0..n]. */
/* Stores in w the linear combination  k1*u+k2*v. */
static void lin_comb(int n, float k1, float k2, float u[], float v[], float w[])
{

	int i;
	for (i = 0; i < n; i++) {
		w[i] = k1 * u[i] + k2 * v[i];
	};
}

void lu(int n, float **M, float **L, float **U)
{

	int i, j;
	matrix_copy(n, n, M, U);
	for (j = 0; j < n; j++) {
		L[j][j] = 1;
	}
	for (j = 0; j < n - 1; j++) {
		for (i = j + 1; i < n; i++) {
			L[i][j] = U[i][j] / U[j][j];
			lin_comb(n, -L[i][j], 1, U[j], U[i], U[i]);
		}
	}
}
