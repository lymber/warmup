#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>

#define vecsize 1000000
#define matrixsize 1000

#define BACKSPACE 8  /* ^H */
#define SPACE     ' '
#define NEWLINE   '\n'

int main()
{
	int i, j;
	double soma, m[matrixsize][matrixsize];
	FILE *array, *matrix;

	srand(time(NULL));

	printf("Generating random array of integers with %d positions...", vecsize);
	array = fopen ("./data-array", "w");
	for (i = 0; i < vecsize-1; i++){fprintf(array, "%d", rand()); putc(SPACE, array);}
	fprintf(array, "%d", rand());
	fclose(array);
	printf(" Done!\n");

	printf("Generating %d x %d random diagonally dominant matrix...", matrixsize, matrixsize);
	for (i = 0; i < matrixsize; i++){
		for (j = 0; j < matrixsize; j++){
			if (j != i) {m[i][j] = (double) rand () / ((double) RAND_MAX + 1);}
			else{m[i][i] = 0;}
		}
	}
	for (i = 0; i < matrixsize; i++){
		soma=0;
		for (j = 0; j < matrixsize; j++){soma = soma + abs(m[i][j]);}
		m[i][i] = soma+1;
	}
	matrix = fopen ("./data-matrix", "w");
	for (i = 0; i < matrixsize; i++){
		for (j = 0; j<matrixsize-1; j++){
			fprintf(matrix, "%f", m[i][j]); putc(SPACE, matrix);}
		fprintf(matrix, "%f", m[i][j]); putc(NEWLINE, matrix);
	}
	fclose(matrix);
	printf(" Done!\n");

	return 0;
}
