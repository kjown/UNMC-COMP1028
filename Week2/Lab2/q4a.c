#include <stdio.h>

int main() {
    int i, factorial = 1;
    printf("Enter an integer: ");
    scanf("%d", &i);

    while (i > 0) {
        factorial *= i;
        i = i - 1;
    }
    printf("Factorial: %d\n", factorial);
}