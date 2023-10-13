#include <stdio.h>

int main() {
    int n, f = 1;
    double e = 0.0;
    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input\n");
    }

    for (int i = 1; i <= n; i++) {
        f *= i;
        e += 1.0 / f;
    }
    
    printf("Sum of e: %lf\n", e);
}