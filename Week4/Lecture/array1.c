#include <stdio.h>

int main() {
    int n[5];

    for (size_t i = 0; i < 5; ++i) {
        n[i] = 0;
    }

    printf("%s%8s\n", "Element", "Value");

    for (size_t i = 0; i < 5; ++i) {
        printf("%7zu%8d\n", i, n[i]);
    }
}