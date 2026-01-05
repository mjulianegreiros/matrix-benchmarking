#ifndef STRASSEN_H
#define STRASSEN_H

// passa-se 3 matrizes como parametro na função pois, multiplicaremos a matriz A pela matriz B e o resultado armazenaremos na matriz C.
// passa-se apenas um tam(tamanho da matriz), pois iremos multiplicar matrizes quadradas(linhas=colunas).
// a função zerar foi criada para, como o proprio nome diz, zerar a matriz
// isso serve para os dados inseridos permanecerem integros e não se misturarem com lixo de memoria.
// void zerar(int** mat , int tam); nao precisa mais por causa do calloc na funcao alocar
int** alocar(int tam);
void liberar(int **matriz , int tam);
void soma(int** a , int** b , int** c, int tam);
void subtrai(int** a , int** b , int** c, int tam);
void separa(int** a , int** c , int linha , int coluna , int tam);
void junta(int** a , int **c , int linha , int coluna , int tam);
void strassen(int **a , int **b , int **c , int tam , int* qtdChamada);

#endif