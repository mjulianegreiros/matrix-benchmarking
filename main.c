#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./strassen/strassen.h"
#include "./benchmark/benchmark.h"

#define N1 64
#define N2 128
#define N3 256
#define N4 512

int main(){
    srand(time(NULL));
    int op = 0;
    int tam = 0;

    do{
        printf("Para qual tamanho de matriz voce quer realizar os testes?\n");
        printf("[0] Sair\n[1] 64x64\n[2] 128x128\n[3] 256x256\n[4] 512x512\n>> ");
        scanf("%d", &op);
        if(op == 0){
            printf("Saindo...\n");
            return 0;
        }
        switch (op)
        {
        case 1:
            tam = N1;

            break;
        case 2:
            tam = N2;

            break;
        case 3:
            tam = N3;

            break;
        case 4:
            tam = N4;

            break;

        default:
            break;
        }

        int **a = alocar(tam);
        int **b = alocar(tam);
        int **c = alocar(tam);

        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                a[i][j] = rand()%10 + 1;
            }
        }

        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                b[i][j] = rand()%10 + 1;
            }
        }

        printf("MATRIZ A: \n");
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                printf("%d " , a[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        printf("MATRIZ B: \n");
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                printf("%d " , b[i][j]);
            }
            printf("\n");
        }
        int qtdCham=1;
        double tempoStrassenGeral = calcTempStrassenGeral(a , b , c , tam , &qtdCham);
        //double tempoStrassen = calcTempStrassen(a , b , c , N, &qtdCham);
        double tempoMultMatriz = calcTempMultMatriz(a , b , c , tam);
        printf("\nMATRIZ C: \n");
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                printf("%d " , c[i][j]);
            }
            printf("\n");
        }
        printf("\nqtd chamdas recursivas: %d\n" , qtdCham);

        printf("Tempo de execucao do Strassen geral: %.5f\n", tempoStrassenGeral);

        //printf("Tempo de execucao do Strassen: %.5f\n", tempoStrassenGeral);

        printf("Tempo de execucao da multiplicacao de matrizes: %.5f\n\n", tempoMultMatriz);

    }while(op != 0);
        
    return 0;
}