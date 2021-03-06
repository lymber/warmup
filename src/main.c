#include <stdio.h>
#include <stdlib.h>

#include "../include/array.h"
#include "../include/matrix.h"
#include "../include/auxiliary.h"
#include "../include/timing.h"

int main(int argc, char *argv[])
{

	int vecsize, matrixsize;
	int *v;
	float **M, **L, **U;

	long int tStart, tEnd;

	if (argc >= 3) {
		vecsize = atoi(argv[1]);
		matrixsize = atoi(argv[2]);
		if ( (vecsize < 0) || (matrixsize < 0) ) {
		printf("Usage: %s <non-negative array size> <non-negative matrix size>\n", argv[0]);
		exit(EXIT_FAILURE);
		}
		else {
			printf("1) Sorting big array of integers:\n");

			printf("\tGenerating %d random integers...\n", vecsize);
			printf("\tAllocating memory...\n");
			v = mallocX(vecsize * sizeof(int *));
			printf("\tDone!\n");

			printf("\tGenerating %d random integers...\n", vecsize);
			array_gen(vecsize, v);
			printf("\tDone!\n");

			printf("\tSorting array of %d integers using quicksort...\n", vecsize);
			tStart = takethetime();
			quicksort(v, 0, vecsize - 1);
			tEnd = takethetime();
			printf("\tDone!\n");
			printf("\tTotal time spent to sort the array: %f seconds\n", (tEnd-tStart)/1000000.0);

			free(v);

			printf("2) LU factorization of big square matrix:\n");

			printf("\tAllocating memory...\n");
			matrix_alloc(matrixsize, matrixsize, &M);
			matrix_alloc(matrixsize, matrixsize, &L);
			matrix_alloc(matrixsize, matrixsize, &U);
			printf("\tDone!\n");

			printf("\tGenerating %d x %d random diagonally dominant matrix...\n", matrixsize, matrixsize);
			matrix_gen(matrixsize, M);
			printf("\tDone!\n");

			printf("\tFactorizing %d x %d matrix...\n", matrixsize, matrixsize);
			tStart = takethetime();
			lu(matrixsize, M, L, U);
			tEnd = takethetime();
			printf("\tDone!\n");
			printf("\tTotal time spent to factor the matrix: %f seconds\n", (tEnd-tStart)/1000000.0);

			matrix_free(matrixsize, &M);
			matrix_free(matrixsize, &L);
			matrix_free(matrixsize, &U);
		}
	}
	else {
		printf("Usage: %s <non-negative array size> <non-negative matrix size>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
