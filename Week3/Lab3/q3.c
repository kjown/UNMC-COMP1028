#include <stdio.h>

float maximum(float num1, float num2, float num3) {
    if (num1 > num2 && num1 > num3) {
        return num1;
    }
    if (num2 > num1 && num2 > num3) {
        return num2;
    }
    return num3;
}

int main() {
    float num1, num2, num3;
    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("Enter third number: ");
    scanf("%f", &num3);

    printf("Maximum among the three numbers: %.4f\n", maximum(num1, num2, num3));

    return 0;
}