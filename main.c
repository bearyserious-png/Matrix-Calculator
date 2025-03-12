/*
Matrix Operations Calculator: 
- A + B
- A - B
- A * scalar 
- transpose of A
- rank of A 
*/
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
void transposeMatrix(int m, int n, int A[m][n], int C[n][m]);
//int rankMatrix(int m, int n, int A[m][n], C[m][n]);
void printMatrix(int m, int n, int A[m][n]);
void choices(int c, int m, int n, int A[m][n], int B[m][n], int C[m][n]);

int main() {
    int m, n; 
    randomizeSeed();

    printf("************************************************\n");
    printf("\t\tMatrix Calculator\n");
    printf("************************************************\n");

    askUserDimensions(&m, &n);

    int A[m][n];
    initMatrix(m, n, A);
    int B[m][n];
    initMatrix(m, n, B);
    int C[m][n];

    int choice;
    do {
        choice = askUserChoice(m, n, A, B, C);
        choices(choice, m, n, A, B, C);
        printf("\n\n");
    } while (choice != 0); 

    return 0;
}

void loading(int opt) {
    if(opt == 0) printf("\n\nLoading...\n");
    else if(opt == 1) printf("\n\nOkay! Exiting the program...\n"); 

    sleep(1); 
    printf("...\n");
    sleep(1);
    printf("...\n");
    sleep(1);
    printf("...\n");
    printf("Done!\n\n");
    sleep(1);
}

void askUserDimensions(int *m, int *n) {
    int ret1, ret2;
    do {
        printf("\nEnter number of rows: ");
        ret1 = scanf("%d", m); 
        if(ret1 != 1) {
            printf("\n+++\nYou entered the wrong value.\nRetry.\n+++\n\n");
            while(getchar() != '\n');   
            continue;     
        }

        printf("Enter number of columns: ");
        ret2 = scanf("%d", n);
        if(ret2 != 1) {
            printf("\n+++\nYou entered the wrong value.\nRetry.\n+++\n\n");
            while(getchar() != '\n');   
            continue;
        }
    } while(ret1 != 1 || ret2 != 1);

    loading(0);
}

void randomizeSeed() {
    srand((unsigned int) time(NULL) ^ getpid());
}

void initMatrix(int m, int n, int A[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            A[i][j] = rand() % 10 + 1;
        }
    }
}

int askUserChoice(int m, int n, int A[m][n], int B[m][n], int C[m][n]) {
    int ret, choice = -1; 
    do {
        printf("\nChoose an operation.\n");
        printf("1. Sum of two matrices\n2. Sub of two matrices\n3. Multiplication of two matrices\n4. Multiplication of a matrix by a number\n5. Transpose of a matrix\n6. Rank of a matrix\n0. Exit\n\n");
        
        printf("\nEnter your choice (0-6): ");  
        ret = scanf("%d", &choice); 

        if(ret != 1 || (choice < 0 || choice > 6)) {
            printf("\n+++\nYou entered the wrong value.\nRetry.\n+++\n");
            while(getchar() !=  '\n');
        }
    } while(ret != 1 || (choice < 0 || choice > 6));

    return choice;
}

void sumMatrix(int m, int n, int A[m][n], int B[m][n], int C[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    } 
}

void subMatrix(int m, int n, int A[m][n], int B[m][n], int C[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    } 
}

void multiplyMatrix(int m, int n, int A[m][n], int B[m][n], int C[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
            C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
}

void multiplyByNum(int m, int n, int num, int A[m][n], int C[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[i][j] = A[i][j] * num;
        }
    }
}

void transposeMatrix(int m, int n, int A[m][n], int C[n][m]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            C[j][i] = A[i][j];
        }
    }
}

//int rankMatrix(int m, int n, int A[m][n], C[m][n]) {}

void printMatrix(int m, int n, int A[m][n]) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");  
    }
}


void choices(int c, int m, int n, int A[m][n], int B[m][n], int C[m][n]) {
    int num; 
    switch(c) {
        case 1: 
            sumMatrix(m, n, A, B, C);
            printf("\n[Matrice A]\n");
            printMatrix(m, n, A);
            printf("\n[Matrice B]\n");
            printMatrix(m, n, B);
            printf("\n[A+B]\n");
            printMatrix(m, n, C);
            loading(0);
            break; 
        
        case 2: 
            subMatrix(m, n, A, B, C);
            printf("\n[Matrice A]\n");
            printMatrix(m, n, A);
            printf("\n[Matrice B]\n");
            printMatrix(m, n, B);
            printf("\n[A-B]\n");
            printMatrix(m, n, C);
            loading(0);
            break;

        case 3:
            multiplyMatrix(m, n, A, B, C);
            printf("\n[Matrice A]\n");
            printMatrix(m, n, A);
            printf("\n[Matrice B]\n");
            printMatrix(m, n, B);
            printf("\n[A*B]\n");
            printMatrix(m, n, C);
            loading(0);
            break;

        case 4:
            printf("\nEnter a number to multiply by: ");
            scanf("%d", &num);
            multiplyByNum(m, n, num, A, C);
            printf("\n[Matrice A]\n");
            printMatrix(m, n, A);
            printf("\n[A*num]\n");
            printMatrix(m, n, C);
            loading(0);
            break;

        case 5: 
            transposeMatrix(m, n, A, C);
            printf("\n[Matrice A]\n");
            printMatrix(m, n, A);
            printf("\n[Transpose of A]\n");
            printMatrix(n, m, C);
            loading(0);
            break;

        case 6: 
            /*int rank = rankMatrix(m, n, A, C);
            printf("\n[Matrice A]\n");
            printMatrix(m, n, A);
            printf("[Simplified A]\n"); 
            printMatrix(m, n, C);
            printf("Rank: %d\n", rank);*/
            printf("\nWIP. Sorry. :(\n");
            loading(0);
            break;

        default:
            loading(1);
            printf("Bye!\n");
            exit(-1);        
    }
}