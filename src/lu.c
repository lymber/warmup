#include <stdlib.h>
#include <stdio.h>

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
