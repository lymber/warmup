#ifndef LU_H
#define LU_H

/* Takes an int n and **M, a matrix n x n. Stores, respectively, in **L and */
/* **U  an inferior and superior square matrices such that M=LU. */
void lu(int n, float **M, float **L, float **U);
#endif
