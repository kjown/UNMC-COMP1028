#include <stdio.h>
#define SIZE 10

int main(void) {
    // initialize a
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    int pass; // passes counter
    size_t i; // comparision counter
    int hold; // temporary location used to swap array elemeent

    puts("Data items in ori order: \n");

    // output orginal array
    for (i = 0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }
    // bubble sort
    // loop to control num of passes
    for (pass = 1; pass < SIZE; ++pass) {
        for (i = 0; i < SIZE - 1; ++i) {
            if (a[i] > a[i + 1]) {
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;
            }
        }
    }
            
    puts("\nData item in ascending order: ");
    for (i=0; i < SIZE; ++i) {
        printf("%4d", a[i]);
    }
    puts("");
}