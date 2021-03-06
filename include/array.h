#ifndef QUICKSORT_H
#define QUICKSORT_H

void array_gen(int matrixsize, int *v);

/* Takes an array v[p..r] of ints with p <= r. */
/* Returns in *v a sorted permutation of its elements. */
void quicksort(int v[], int p, int r);
#endif
