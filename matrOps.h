#ifndef MATROPS_H
#define MATROPS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void loading(int opt);
void askUserDimensions(int *m, int *n);
void randomizeSeed();
void initMatrix(int m, int n, int A[m][n]);
int askUserChoice(int m, int n, int A[m][n], int B[m][n], int C[m][n]);
void sumMatrix(int m, int n, int A[m][n], int B[m][n], int C[m][n]);
void subMatrix(int m, int n, int A[m][n], int B[m][n], int C[m][n]);
void multiplyMatrix(int m, int n, int A[m][n], int B[m][n], int C[m][n]);
void multiplyByNum(int m, int n, int num, int A[m][n], int C[m][n]);
void transposeMatrix(int m, int n, int A[m][n], int C[m][n]);
//int rankMatrix(int m, int n, int A[m][n], int C[m][n]);
void printMatrix(int m, int n, int A[m][n]);
void choices(int c, int m, int n, int A[m][n], int B[m][n], int C[m][n]);

#endif
