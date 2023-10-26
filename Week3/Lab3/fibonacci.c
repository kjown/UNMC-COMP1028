#include <stdio.h>

// 0 1 1 2 3 5 8
// 0 1 2 3 4 5 6

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        return fib(n-1) + fib(n-2);
    }
}

int main() {
    int i;
    printf("Enter an integer: ");
    scanf("%d", &i);

    printf("Fibonacci(%d): %d\n", i, fib(i));
}