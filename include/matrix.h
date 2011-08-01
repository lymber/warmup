#ifndef MATRIX_H
#define MATRIX_H

/* Takes ints m and n and a pointer to **M storing in **M  */
/* the entries of a float matrix with m rows and n columns. */
void matrix_alloc(int m, int n, float ***M);

/* Takes an int m and a pointer to **M freeing allocated memory to it */
/* "row by row". */
void matrix_free(int m, float ***M);

void matrix_gen(int matrixsize, float **M);

/* Takes ints m and n and prints the block [0..m]x[0..n] of **M. */
void matrix_print(int m, int n, float **M);

/* Takes ints m, n and l, matrices **M and **N m x n and n x l  */
/* respectively and a pointer to **P. Stores in **P the product of M and N. */
void matrix_multiply(int m, int n, int l, float **M, float **N, float **P);

/* Takes an int n and **M, a matrix n x n. Stores, respectively, in **L and */
/* **U  an inferior and superior square matrices such that M=LU. */
void lu(int n, float **M, float **L, float **U);
#endif
