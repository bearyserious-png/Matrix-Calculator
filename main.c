/*
Matrix Operations Calculator: 
- A + B
- A - B
- A * scalar 
- transpose of A
- rank of A 
*/
#include <stdio.h>

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
