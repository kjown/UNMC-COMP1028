#include <stdio.h>

void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10, b = 20;
    printf("Values before swapping: %d, %d\n", a, b);
    swap(&a, &b);
    printf("Values after swap are: %d, %d\n", a, b);
    return 0;
}