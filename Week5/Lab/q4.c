#include <stdio.h>

float compare(float *num1, float *num2) {
    int greater;
    if (*num1 > *num2) {
        return *num1;
    }
    if (*num2 > *num1) {
        return *num2;
    }
    if (*num1 == *num2) {
        return 1;
    }
}

int main() {
    float num1;
    float num2;

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    float *num1_ptr = &num1;
    float *num2_ptr = &num2;

    float result = compare(num1_ptr, num2_ptr);

    if (result != 1) {
        printf("The greater value is: %.2f\n", result);
    }
    else {
        printf("Both numbers are equal\n");
    }
    return 0;
}