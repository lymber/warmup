#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../include/auxiliary.h"

/*
  The mallocX() function allocates size bytes and returns a pointer to the
  allocated memory.  The memory is not cleared.  If size is 0, then it
  returns whatever the standard library malloc() returns, unless it is NULL.

  In the circumstances where the return value would be NULL, it terminates
  the execution of the program.
*/

void *mallocX(size_t size)
{
	void *res;
	res = malloc(size);
	if (res == NULL) {
		perror("Could not allocate memory!");
		exit(EXIT_FAILURE);
	}
	return res;
}

void matrix_alloc(int m, int n, float ***M)
{

	int i;
	*M = mallocX(m * sizeof(float *));
	for (i = 0; i < m; i++) {
		(*M)[i] = mallocX(n * sizeof(float));
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

void gen_data(int vecsize, int matrixsize, int *v, float **M)
{
	int i,j;
	float sum;

	srand(time(NULL));

	printf("Generating %d random integers...\n", vecsize);
	for (i = 0; i <= vecsize; i++) {
		v[i]=rand();
	}
	printf("Done!\n");
	printf("Generating %d x %d random diagonally dominant matrix...\n", matrixsize, matrixsize);
        for (i = 0; i < matrixsize; i++) {
                for (j = 0; j < matrixsize; j++) {
                        if (j != i) {
                                M[i][j] =rand()/((float)RAND_MAX + 1);
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
	printf("Done!\n");
}
