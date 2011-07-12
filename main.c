#include <stdio.h>
#include "quicksort.h"

#define vecsize 1000000

int main(void){
	int i, *v;

	printf("Tamanho do vetor: %d\n",vecsize);
/*	scanf("%d",&n); */
	v = malloc(vecsize * sizeof(int *));
        if (v == NULL) {
                fprintf(stderr, "Não há memória disponível para alocar vetor desse tamanho.\n");
                exit(EXIT_FAILURE);
	}
	for (i=0;i<vecsize; i++){scanf("%d",&v[i]);};
	printf("Vetor original:\n");
	for (i=0;i<vecsize; i++){printf("%d ",v[i]);}; printf("\n");
	quicksort(v,0,vecsize-1);
	printf("Vetor ordenado:\n");
	for (i=0;i<vecsize; i++){printf("%d ",v[i]);}; printf("\n");
	free(v);
	return 0;
}
