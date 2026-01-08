#include <stdio.h>
#include <time.h>
#include "benchmark.h"

double calcTempMultMatriz(int **a, int **b, int **c, int tam){
    clock_t inicio = clock();
    multMatrizes(a, b, c, tam);
    clock_t fim = clock();
    double tempo = ((double) (fim - inicio)) /CLOCKS_PER_SEC;
    return tempo;
}

double calcTempStrassen(int **a, int **b, int **c, int tam, int *qtdCham){
    clock_t inicio = clock();
    strassen(a, b, c, tam, qtdCham);
    clock_t fim = clock();
    double tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    return tempo;
}

double calcTempStrassenGeral(int **a, int **b, int **c, int tam, int *qtdCham){
    clock_t inicio = clock();
    strassenGeral(a, b, c, tam, qtdCham);
    clock_t fim = clock();
    double tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    return tempo;
}