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

int main() {
    int m, o; //rows of A and B
    int n, p; //cols of A and B

    printf("************************************************\n");
    printf("\t\tMatrix Calculator\n");
    printf("************************************************\n");
    
    int choice = -1; 
    int ret;
    do {
        printf("\nChoose an operation.\n");
        printf("1. Sum of two matrices\n2. Sub of two matrices\n3. Transpose of a matrix\n4. Rank of a matrix\n0. Exit\n\n");
        
        printf("\nEnter a number (0-4): ");  
        ret = scanf("%d", &choice); 

        if(ret != 1 || (choice < 0 || choice > 4)) {
            printf("\n+++\nYou entered the wrong value.\nRetry.\n+++\n");
            while(getchar() !=  '\n');
        }
    } while(ret != 1 || choice != 0);
    //askDirections(m, n);
    //askDirections(o, p);

    //int A[]
    return 0;
}
