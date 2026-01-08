#ifndef GERAL_H
#define GERAL_H

int **alocarMat(int tam);
int proxPot2(int tam);
void liberarMat(int **matriz , int tam);
void strassenGeral(int **a , int** b , int **c , int tam, int *qtdCham);

#endif