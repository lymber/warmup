#ifndef LU_H
#define LU_H
/* Takes ints m and n and a pointer to **M storing in **M  */
/* the entries of a float matrix with m rows and n columns. */
void aloca_matriz(int m, int n, float ***M);

/* Takes ints m and n, **X **Y, treated as an m x n matrices. */
/* Copies X to Y */
void copia_matriz(int m, int n, float **X, float **Y);

/* Takes ints m and n and prints the block [0..m]x[0..n] of **M. */
void imprime_matriz(int m, int n, float **M);

/* Takes ints m, n and l, matrices **M and **N m x n and n x l  */
/* respectively and a pointer to **P. Stores in **P the product of M and N. */
void multiplica(int m, int n, int l, float **M, float **N, float **P);

/* Takes an int m and a pointer to **M freeing allocated memory to it */
/* "row by row". */
void libera(int m, float ***M);

/* Takes an int n, floats k1 and k2 e arrays u[0..n] and v[0..n]. */
/* Stores in w the linear combination  k1*u+k2*v. */
void comblin(int n, float k1, float k2, float u[], float v[], float w[]);

/* Takes an int n and **M, a matrix n x n. Stores, respectively, in **L and */
/* **U  an inferior and superior square matrices such that M=LU. */
void lu(int n, float **M, float **L, float **U);
#endif
