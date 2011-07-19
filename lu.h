#ifndef LU_H
#define LU_H
#include<stdlib.h>

/* Recebe inteiros m e n e um ponteiro para **M e armazena em **M  */
/* as entradas de uma matriz de floats com m linhas e n colunas. */
void aloca_matriz(int m, int n, float ***M);

/* Recebe inteiros m e n e **X, representando uma matriz m x n */
/* Copia X em Y */
void copia_matriz(int m, int n, float **X, float **Y);

/* Recebe inteiros m e n e imprime o bloco [0..m]x[0..n] */
/* de **M */
void imprime_matriz(int m, int n, float **M);

/* Recebe inteiros m, n e l, **M e **N representando matrizes m x n e n x l  */
/* respectivamente e um ponteiro para **P. Devolve em **P o produto das matrizes M e N */
void multiplica(int m, int n, int l, float **M, float **N, float **P);

/* Recebe um inteiro m e um ponteiro para **M e libera a memoria */
/* alocada por **M "linha a linha" */
void libera(int m, float ***M);

/* Recebe inteiro n, floats k1 e k2 e vetores u[0..n] e v[0..n]. */
/* Devolve em w a combinacao linear k1*u+k2*v */
void comblin(int n, float k1, float k2, float u[], float v[], float w[]);

/* Recebe inteiro n e **M, representando uma matriz n x n. */
/* Devolve matrizes L e U, respectivamente triangulares inferior (n x n) e */
/* superior (n x n) tais que M=LU. */
void lu(int n, float **M, float **L, float **U);
#endif
