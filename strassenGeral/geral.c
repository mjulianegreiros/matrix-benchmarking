#include <stdio.h>
#include <stdlib.h>
#include "../strassen/strassen.h"
#include "geral.h"


int **alocarMat(int tam){
    int **matriz = malloc(tam*sizeof(int*));
    for(int i=0;i<tam;i++){
        matriz[i] = calloc(tam , sizeof(int)); // zera a matriz automaticamente quando inicia
    }

    return matriz;
}
int proxPot2(int tam){
    int i = 1;
    while(i<tam){
        i = i*2;
    }
    return i;
}
void liberarMat(int **matriz , int tam){
    for(int i=0;i<tam;i++){
        free(matriz[i]);
    }
    free(matriz);
}
void strassenGeral(int **a , int** b , int **c , int tam, int *qtdCham){
    int novoTam = proxPot2(tam);

    // alocando matrizes de potencia de 2 preenchidas com 0
    int **a2 = alocarMat(novoTam);
    int **b2 = alocarMat(novoTam);
    int **c2 = alocarMat(novoTam);

    // copiando os dados das matrizes a e b
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            a2[i][j] = a[i][j];
            b2[i][j] = b[i][j];
        }
    }

    // resolve a multiplicacao de matrizes com o strassen normal
    strassen(a2 , b2 , c2 , novoTam, qtdCham);

    // copia o resultado pra matriz C original
    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            c[i][j] = c2[i][j];
        }
    }

    // libera os ponts
    liberarMat(a2 , novoTam);
    liberarMat(b2 , novoTam);
    liberarMat(c2 , novoTam);
}