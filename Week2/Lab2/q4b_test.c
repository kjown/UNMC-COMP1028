#include <stdio.h>

int main() {
    int n;
    double e = 0;  // Initialize e to 1.0 (the first term in the sum)

    printf("Enter a nonnegative integer (n): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. Please enter a nonnegative integer.\n");
    } else {
        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
            e += 1.0 / factorial;
        }

        printf("Approximation of e: %lf\n", e);
    }

    return 0;
}