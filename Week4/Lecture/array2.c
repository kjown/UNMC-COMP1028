#include <stdio.h>
#define SIZE 5

int main() {
    int a[SIZE] = {1, 2, 3, 4, 5};
    int total = 0;

    for (size_t i = 0; i < SIZE; ++i) {
        total += a[i];
    }
    printf("Total is %d\n", total);
}