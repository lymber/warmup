#ifndef QUICKSORT_H
#define QUICKSORT_H
/* Recebe vetor de inteiros v[p..r] com p < r. Rearranja os elementos do vetor e */
/* devolve j em p..r tal que v[p..j-1] <= v[j] < v[j+1..r]. */
int separa (int v[], int p, int r);

/* Recebe vetor de inteiros v[p..r] com p <= r. Rearranja os elementos do vetor */
/* em ordem crescente. */
void quicksort (int v[], int p, int r);
#endif
