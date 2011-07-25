#include <stdio.h>
#include <stdlib.h>

#include "../include/quicksort.h"
#include "../include/lu.h"
#include "../include/auxiliary.h"

#define vecsize 1000000
#define matrixsize 1000

int main(void)
{

	FILE *array, *matrix;
	int i = 0, j = 0, *v;
	float **M, **L, **U;

	v = mallocX(vecsize * sizeof(int *));

	printf("1) Sorting big array of integers test:\n");

	printf("\t Reading data from file...");
	array = fopen("./test/data-array", "r");
	if (array == NULL) {
		printf(" File not found!\n");
		exit(EXIT_FAILURE);
	}
	while ((i < vecsize) && (!feof(array))) {
		fscanf(array, "%10d", &v[i]);
		i++;
	}
	printf(" Done!\n");
	fclose(array);

	printf("\t Sorting array of %d integers using quicksort...", vecsize);
	quicksort(v, 0, vecsize - 1);
	printf(" Done!\n");

	free(v);

	printf("2) LU factorizations of big square matrixt:\n");

	matrix_alloc(matrixsize, matrixsize, &M);
	matrix_alloc(matrixsize, matrixsize, &L);
	matrix_alloc(matrixsize, matrixsize, &U);

	printf("\t Reading data from file...");
	matrix = fopen("./test/data-matrix", "r");
	if (matrix == NULL) {
		printf(" File not found!\n");
		exit(EXIT_FAILURE);
	}
	while (!feof(matrix)) {
		for (i = 0; i < matrixsize; i++) {
			for (j = 0; j < matrixsize; j++) {
				fscanf(matrix, "%20.20f", &M[i][j]);
			}
		}
	}
	printf("\t Done!\n");
	fclose(matrix);

	printf("\t Factorizing %d x %d matrix...", matrixsize, matrixsize);
	lu(matrixsize, M, L, U);
	printf("\t Done!\n");

	matrix_free(matrixsize, &M);
	matrix_free(matrixsize, &L);
	matrix_free(matrixsize, &U);

	return 0;
}
