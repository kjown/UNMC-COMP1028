#include <stdio.h>

int main() {
    int array[2][3];
    printf("Enter 6 integers:\n");

    int row, column; // counter variables
    for (row = 0 ; row < 2; row++) {
        for (column = 0; column < 3; column++) {
            scanf("%d", &array[row][column]);
        }
    }
    printf("Array in reverse order:\n");

   for (row = 1; row >= 0; row--) {
    for (column = 2; column >= 0; column--){
        printf("%d ", array[row][column]);
    }
   } 

    return 0;
}