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
void soma(int** a , int** b , int** c, int tam){ //faz uma das etapas do algoritmo.(soma matrizes e armazena na matriz C)
    int i , j;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void subtrai(int** a , int** b , int** c, int tam){  //faz uma das etapas do algoritmo.(subtrai matrizes e armazena na matriz C)
    int i , j;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

/*
    Explicação sobre a função separa:
    linha e coluna é o marco de ínicio onde a separação começa e é colada na matriz c
    tam é o tamanho de C(ou até que parte de C vai ser colado a matriz a)
*/
void separa(int** a , int** c , int linha , int coluna , int tam){ //separa uma matriz em 4
    int i , j;

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            c[i][j] = a[linha+i][coluna+j];
        }
    }
}
/*
    Explicação sobre a função junta:
    linha e coluna é o marco de ínicio onde a separação começa e é colada na matriz a
    tam é o tamanho de C(ou até que parte de C vai ser colado a matriz a)
*/

void junta(int** a , int **c , int linha , int coluna , int tam){ // tendi nada
    int i , j;

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            a[linha+i][coluna+j] = c[i][j];
        }
    }
}
void strassen(int **a , int **b , int **c , int tam){
    zerar(c , tam);
    if(tam==1){
        c[0][0] = a[0][0] * b[0][0];
    } else{
        // matrizes auxiliares que dividem as matrizes maiores em 4 matrizes menores com 1/4 do tamanho original
        int **a1 , **a2 , **a3 , **a4;
        int **b1 , **b2 , **b3 , **b4;

        // separando a matriz a
        separa(a , a1 , 0 , 0 , tam/2);
        separa(a , a2 , 0 , tam/2 , tam/2);
        separa(a , a3 , tam/2 , 0 , tam/2);
        separa(a , a4 , tam/2 , tam/2 , tam/2);

        // separando a matriz b
        separa(b , b1 , 0 , 0 , tam/2);
        separa(b , b2 , 0 , tam/2 , tam/2);
        separa(b , b3 , tam/2 , 0 , tam/2);
        separa(b , b4 , tam/2 , tam/2 , tam/2   );

        // usando as fórmulas do algoritmo
        int **s1 , **s2 , **s3 , **s4 , **s5;
        int **s6 , **s7 , **s8 , **s9 , **s10;

        subtrai(b2 , b4 , s1 , tam/2);
        soma(a1 , a2 , s2 , tam/2);
        soma(a3 , a4 , s3 , tam/2);
        subtrai(b3 , b1 , s4 , tam/2);
        soma(a1 , a4 , s5 , tam/2);
        soma(b1 , b4 , s6 , tam/2);
        subtrai(a2, a4 , s7 , tam/2);
        soma(b3 , b4 , s8 , tam/2);
        subtrai(a1 , a3 , s9 , tam/2);
        soma(b1 , b2 , s10 , tam/2);

        // multiplicando as somas
        int **p1 , **p2 , **p3 , **p4 , **p5 , **p6 , **p7;
        strassen(a1 , s1 , p1 , tam/2);
        strassen(s2 , b4 , p2 , tam/2);
        strassen(s3 , b1 , p3 , tam/2);
        strassen(a4 , s4 , p4 , tam/2);
        strassen(s5 , s6 , p5 , tam/2);
        strassen(s7 , s8 , p6 , tam/2);
        strassen(s9 , s10 , p7 , tam/2);
        
        // remontando a matriz C
        int **t1 , **t2; // matrizes auxiliares para o processo de remontagem
        int **c1 , **c2 , **c3 , **c4; // matrizes a serem remontadas
        // remontando C1
        soma(p5 , p4 , t1 , tam/2);
        subtrai(t1 , p2 , t2 , tam/2);
        soma(t2 , p6 , c1 , tam/2);

        // remontando C2
        soma(p3 , p5 , c2 , tam/2);

        // remontando C3
        soma(p3 , p4 , c3 , tam/2);

        // remontando C4
        soma(p5 , p1 , t1 , tam/2);
        subtrai(t1 , p3 , t2 , tam/2);
        soma(t2 , p7 , c4 , tam/2);

        // juntando tudo 
        junta(c1 , c , 0 , 0 , tam/2);
        junta(c2 , c , 0 , tam/2 , tam/2);
        junta(c3 , c , tam/2 , 0 , tam/2);
        junta(c4 , c , tam/2 , tam/2 , tam/2);
        
    }
}
