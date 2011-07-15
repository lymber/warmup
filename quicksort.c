/* Funções abaixo copiadas da página do professor Paulo Feofiloff: */
/* http://www.ime.usp.br/~pf/algoritmos/aulas/quick.html */

/* Recebe vetor de inteiros v[p..r] com p < r. Rearranja os elementos do vetor e */
/* devolve j em p..r tal que v[p..j-1] <= v[j] < v[j+1..r]. */
int separa (int v[], int p, int r){
	int c = v[p], i = p+1, j = r, t;
	while (i <= j) {
		if (v[i] <= c) ++i;
		else if (c < v[j]) --j;
		else {
			t = v[i], v[i] = v[j], v[j] = t;
			++i; --j;
		}
	}
	v[p] = v[j], v[j] = c;
	return j;
}

/* Recebe vetor de inteiros v[p..r] com p <= r. Rearranja os elementos do vetor */
/* em ordem crescente. */
void quicksort (int v[], int p, int r){
	int j;
	while (p < r){
		j = separa (v, p, r);
		quicksort (v, p, j-1);
		p = j + 1;
	}
}
