#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./strassen/strassen.h"
#include "./benchmark/benchmark.h"

#define N 1024

int main(){
    srand(time(NULL));

    int **a = alocar(N);
    int **b = alocar(N);
    int **c = alocar(N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a[i][j] = rand()%10 + 1;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            b[i][j] = rand()%10 + 1;
        }
    }

    printf("MATRIZ A: \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d " , a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("MATRIZ B: \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d " , b[i][j]);
        }
        printf("\n");
    }
    int qtdCham=1;
    double tempoStrassenGeral = calcTempStrassenGeral(a , b , c , N , &qtdCham);
    //double tempoStrassen = calcTempStrassen(a , b , c , N, &qtdCham);
    double tempoMultMatriz = calcTempMultMatriz(a , b , c , N);
    printf("\nMATRIZ C: \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d " , c[i][j]);
        }
        printf("\n");
    }
    printf("\nqtd chamdas recursivas: %d\n" , qtdCham);

    printf("Tempo de execucao do Strassen geral: %.5f\n", tempoStrassenGeral);

    //printf("Tempo de execucao do Strassen: %.5f\n", tempoStrassenGeral);

    printf("Tempo de execucao da multiplicacao de matrizes: %.5f\n", tempoMultMatriz);

    return 0;
}