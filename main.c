#include <stdio.h>
#include <stdlib.h>

#include "include/quicksort.h"
#include "include/lu.h"
#include "include/auxiliary.h"

#define vecsize 1000000
#define matrixsize 1000

int main(void){

	FILE *array, *matrix;
	int i=0, j=0, *v;
	float **M, **L, **U;

	v = mallocX(vecsize * sizeof(int *));

	printf("1) Sorting big array of integers test:\n");

	printf("\t Reading data from file...");
	array = fopen ("./testing/data-array", "r");
	if (array == NULL) {
		printf (" File not found!\n");
		exit (EXIT_FAILURE);
	}
	while ((i < vecsize) && (!feof(array))) {fscanf(array, "%d", &v[i]); i++;}
	printf(" Done!\n");
	fclose(array);

	printf("\t Sorting array of %d integers using quicksort...", vecsize);
	quicksort(v, 0, vecsize-1);
	printf(" Done!\n");

	free(v);

	printf("2) LU factorizations of big square matrixt:\n");

	aloca_matriz(matrixsize, matrixsize, &M);
        aloca_matriz(matrixsize, matrixsize, &L);
        aloca_matriz(matrixsize, matrixsize, &U);

	printf("\t Reading data from file...");
	matrix = fopen ("./testing/data-matrix", "r");
	if (matrix == NULL) {
		printf (" File not found!\n");
		exit (EXIT_FAILURE);
	}
	while (!feof(matrix)) {
		for (i = 0; i < matrixsize; i++) {
			for (j = 0; j < matrixsize; j++) {fscanf(matrix, "%f", &M[i][j]);}
		}
	}
	printf("\t Done!\n");
	fclose(matrix);

        /* imprime_matriz(matrixsize, matrixsize, M); */

	printf("\t Factorizing %d x %d matrix...", matrixsize, matrixsize);
        lu(matrixsize, M, L, U);
	/* imprime_matriz(matrixsize, matrixsize, L); */
	/* imprime_matriz(matrixsize, matrixsize, U); */
	printf("\t Done!\n");

        /* printf("M=L*U:\n"); */
        /* multiplica(matrixsize, matrixsize, matrixsize , L, U, M); */
        /* imprime_matriz(matrixsize, matrixsize, M); */
	libera(matrixsize, &M);
        libera(matrixsize, &L);
        libera(matrixsize, &U);

	return 0;
}
