#include <stdio.h>

double avg(float num1, float num2, float num3) {
    double sum = num1 + num2 + num3;
    double average = sum /  3;
    if (average >= 1.2 && average <= 5.6) {
        return average; 
    }
    else {
        return -1.0;
    }
}

int main() {
    double num1, num2, num3;
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    printf("Enter third number: ");
    scanf("%lf", &num3);

    double result = avg(num1, num2, num3);
    if (result != -1.0) {
        printf("Average: %.1lf\n", result);
    }
    else {
        printf("Average value out of range\n");
    }
    return 0;
}