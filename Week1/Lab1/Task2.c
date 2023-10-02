#include <stdio.h>

int main() {
    float a, b;
    
    printf("Float a: ");
    scanf("%f", &a);

    printf("Float b: ");
    scanf("%f", &b);

    float x;
    x = (-b / a);

    printf("Solution of a*x + b = 0 is %.1f\n", x);

    return 0; 
}