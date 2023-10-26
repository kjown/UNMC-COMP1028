#include <stdio.h>
#define SIZE 5

void modArray(int b[], size_t size);
void modElement(int e);

int main() {
    int a[SIZE] = {0, 1, 2, 3, 4};

    puts("Effects of passing entire array by reference: \n\nThe values of hte original array are: ");

    for (size_t i = 0; i < SIZE; ++i) {
        printf("%3d", a[i]);
    }    

    puts("");

    modArray(a, SIZE);
    puts("The values of the modified array are: ");

    for (size_t i = 0; i < SIZE; ++i) {
        printf("%3d", a[i]);
    }

    printf("\n\nEffects of passing array element by value:\n\nThe value of a a[3] is %d\n", a[3]);

    modElement(a[3]);

    printf("The value of a[3] is %d\n", a[3]);
}

void modArray(int b[], size_t size) {
    for (size_t j = 0; j < size; ++j) {
        b[j] *= 2;
    }
}

void modElement(int e) {
    e *= 2;
    printf("Value in modElement is %d\n", e);
}