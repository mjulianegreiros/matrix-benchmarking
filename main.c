#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#include "strassen/strassen.h"
#include "produto-matriz/multMatriz.h"
#include "strassenGeral/geral.h"

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

    strassenGeral(a , b , c , N);
    //multMatrizes(a , b , c , N);
    printf("\nMATRIZ C: \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d " , c[i][j]);
        }
        printf("\n");
    }

    return 0;
}