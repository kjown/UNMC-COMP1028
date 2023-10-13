#include <stdio.h>

// ii) Multiply both int
int multiply(int num1, int num2) {
    return (num1 * num2);
}

// iii) Divide both int
float divide(int num1, int num2) {
    return (num1 / num2);
}

int main() {
    int num1, num2;
    // i) Read 2 int

    printf("Enter first integer: ");
    scanf("%d", &num1);

    printf("Enter second integer: ");
    scanf("%d", &num2);
    
    // Dusplay
    printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));

    printf("%d / %d = %.1f\n", num1, num2, divide(num1, num2));

    return 0;
}