#include <stdio.h>

void trytoModArray(const int b[]);

int main(void) {
    int a[] = { 10, 20, 30 };

    trytoModArray( a );

    printf("%d %d %d\n", a[0], a[1], a[2]);
}

void trytoModArray(const int b[]) {
    b[0] /= 2;
    b[1] /= 2;
    b[3] /= 2;
}