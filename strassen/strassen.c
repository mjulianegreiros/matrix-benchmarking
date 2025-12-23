#include <stdio.h>
#include <stdlib.h>
#include "strassen.h"

void zerar(int** mat , int tam){
    int i , j;

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            mat[i][j] = 0;
        }
    }
}
void adicao(int** a , int** b , int** c, int tam){
    int i , j;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            c[i][j] = a[i][j] + b[j][i];
        }
    }
}
void subtracao(int** a , int** b , int** c, int tam){
    int i , j;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            c[i][j] = a[i][j] - b[j][i];
        }
    }
}
void strassen(int **a , int **b , int **c , int tam){
    zerar(c , tam);
    if(tam==2){
        // só multiplica normal
    } else{
        // divide, soma, multiplica.
    }
}
