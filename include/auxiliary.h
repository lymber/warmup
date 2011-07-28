#ifndef AUXILIARY_H
#define AUXILIARY_H
/*
  The mallocX() function allocates size bytes and returns a pointer to the
  allocated memory.  The memory is not cleared.  If size is 0, then it
  returns whatever the standard library malloc() returns, unless it is NULL.

  In the circumstances where the return value would be NULL, it terminates
  the execution of the program.
*/

void *mallocX(size_t size);

/* Takes ints m and n and a pointer to **M storing in **M  */
/* the entries of a float matrix with m rows and n columns. */
void matrix_alloc(int m, int n, float ***M);

/* Takes an int m and a pointer to **M freeing allocated memory to it */
/* "row by row". */
void matrix_free(int m, float ***M);

/* Takes ints m and n and prints the block [0..m]x[0..n] of **M. */
void matrix_print(int m, int n, float **M);

/* Takes ints m, n and l, matrices **M and **N m x n and n x l  */
/* respectively and a pointer to **P. Stores in **P the product of M and N. */
void matrix_multiply(int m, int n, int l, float **M, float **N, float **P);

/* Takes ints vecsize and matrix size and stores  a random array of vecsize */
/* ints in *v and a random float matrixsize x matrixsize matrix in **M. */
void gen_data(int vecsize, int matrixsize, int *v, float **M);
#endif
