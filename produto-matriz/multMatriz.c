#include <stdio.h>
#include <stdlib.h>
#include "multMatriz.h"

void zerar(int **mat , int tam){
    int i , j;

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            mat[i][j] = 0;
        }
    }
}
void multMatrizes(int **a , int **b , int **c , int tam){
    int i , j , k;
    zerar(c , tam);

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            for(k=0;k<tam;k++){
                c[i][j] += (a[i][k]*b[k][j]);  
            }
        }
    }
}
