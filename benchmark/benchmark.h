#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "../produto-matriz/multMatriz.h"
#include "../strassen/strassen.h"
#include "../strassenGeral/geral.h"

double calcTempMultMatriz(int **a, int **b, int **c, int tam);

double calcTempStrassen(int **a, int **b, int **c, int tam, int *qtdCham);

double calcTempStrassenGeral(int **a, int **b, int **c, int tam, int *qtdCham);

#endif