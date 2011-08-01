#include <stdlib.h>
#include <time.h>

void array_gen(int vecsize, int *v)
{
	int i;

	srand(time(NULL));

	for (i = 0; i <= vecsize; i++) {
		v[i]=rand();
	}
}

/* The functions below were shamelessly copied from professor Paulo Feofiloff's webpage: */
/* http://www.ime.usp.br/~pf/algoritmos/aulas/quick.html */

/* Takes an array of ints v[p..r] with p < r.  Returns int j and shuffles the */
/* elements of this array such that v[p..j-1] <= v[j] < v[j+1..r]. */
static int separa(int v[], int p, int r)
{
	int c = v[p], i = p + 1, j = r, t;
	while (i <= j) {
		if (v[i] <= c)
			++i;
		else if (c < v[j])
			--j;
		else {
			t = v[i], v[i] = v[j], v[j] = t;
			++i;
			--j;
		}
	}
	v[p] = v[j], v[j] = c;
	return j;
}

/* Take an array of ints v[p..r] with p <= r. */
/*  Returns in *v a sorted permutation of its elements. */
void quicksort(int v[], int p, int r)
{
	int j;
	while (p < r) {
		j = separa(v, p, r);
		quicksort(v, p, j - 1);
		p = j + 1;
	}
}
