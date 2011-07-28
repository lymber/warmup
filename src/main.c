#include <stdio.h>
#include <stdlib.h>

#include "../include/quicksort.h"
#include "../include/lu.h"
#include "../include/auxiliary.h"

int main(int argc, char *argv[])
{

	int vecsize, matrixsize;
	int *v;
	float **M, **L, **U;

	vecsize = atoi(argv[1]);
	matrixsize = atoi(argv[2]);

	if ( (argc < 3) || (vecsize < 0) || (matrixsize < 0) ) {
		printf("Usage: %s <non-negative array size> <non-negative matrix size>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else {
		printf("Allocating memory...\n");
		v = mallocX(vecsize * sizeof(int *));
		matrix_alloc(matrixsize, matrixsize, &M);
		matrix_alloc(matrixsize, matrixsize, &L);
		matrix_alloc(matrixsize, matrixsize, &U);
		printf("Done!\n");

		gen_data(vecsize, matrixsize, v, M);

		printf("1) Sorting big array of integers:\n");

		printf("\tSorting array of %d integers using quicksort...\n", vecsize);
		quicksort(v, 0, vecsize - 1);
		printf("\tDone!\n");

		free(v);

		printf("2) LU factorization of big square matrix:\n");

		printf("\tFactorizing %d x %d matrix...\n", matrixsize, matrixsize);
		lu(matrixsize, M, L, U);
		printf("\tDone!\n");

		matrix_free(matrixsize, &M);
		matrix_free(matrixsize, &L);
		matrix_free(matrixsize, &U);
	}
	return 0;
}
