#include <stdio.h>

/* Funções abaixo copiadas da página do professor Paulo Feofiloff: */
/* http://www.ime.usp.br/~pf/algoritmos/aulas/quick.html */

/* Recebe vetor de inteiros v[p..r] com p < r. Rearranja os elementos do vetor e */
/* devolve j em p..r tal que v[p..j-1] <= v[j] < v[j+1..r]. */
int separa (int v[], int p, int r);

/* Recebe vetor de inteiros v[p..r] com p <= r. Rearranja os elementos do vetor */
/* em ordem crescente. */
void quicksort (int v[], int p, int r);

int main(void){
	int i, n=0, v[1000];
	printf("Tamanho do vetor(<=1000): ");
	scanf("%d",&n);
	for (i=0;i<n; i++){scanf("%d",&v[i]);};
	printf("Vetor original:\n");
	for (i=0;i<n; i++){printf("%d ",v[i]);}; printf("\n");
	quicksort(v,0,n-1);
	printf("Vetor ordenado:\n");
	for (i=0;i<n; i++){printf("%d ",v[i]);}; printf("\n");
	return 0;
}

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

void quicksort (int v[], int p, int r){
	int j;
	while (p < r){
		j = separa (v, p, r);
		quicksort (v, p, j-1);
		p = j + 1;
	}
}
