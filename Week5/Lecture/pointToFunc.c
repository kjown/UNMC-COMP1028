#include <stdio.h>

void addOne(int* ptr) {
    (*ptr)++;    // add 1 to *ptr
}

int main() {
    int* p, i = 10;
    p = &i;
    addOne(p);

    printf("%d\n", *p);

    return 0;
}