#include<stdio.h>
#include<stdlib.h>

// function to add two 3x3 matrix
void add(int (*m)[3], int (*n)[3], int (*result)[3]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            result[i][j] = m[i][j] + n[i][j];
        }
    }
    // display the result of addition of 2 matrices
    printf("\nSum of both matrices\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d\t",result[i][j]);
        }
    printf("\n"); // new line
    }
}

// function to multiply two 3x3 matrix
void multiply(int (*m)[3], int (*n)[3], int (*result)[3]) {
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
        result[i][j] = 0; // assign 0
        // find product
            for (int k = 0; k < 3; k++) {
                result[i][j] += m[i][k] * n[k][j];
            }
        }
    }
    // display the result of multiplication of 2 matrices
    printf("\nMultiplication of both matrices\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d\t",result[i][j]);
        }
        printf("\n"); // new line
    }
}

// main function
int main() {
    int i;
    int j;
    // matrix
    int matrix1[3][3];
    int matrix2[3][3];
    int result[3][3];
    // prompt user for values of matrix 1
    printf("Input matrix 1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    // prompt user for values of matrix 2
    printf("Input matrix 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    add(matrix1, matrix2, result);  // call add function to add 2 matrices

    multiply(matrix1, matrix2, result); // call multiply function to multiply 2 matrices
    
    return 0;
}