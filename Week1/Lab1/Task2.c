#include <stdio.h>

int main() {
    float a, b;
    
    printf("First float: ");
    scanf("%f", &a);

    printf("Second float: ");
    scanf("%f", &b);

    float x;
    x = (-b / a);

    printf("Solution of a*x + b = 0 is %.1f\n", x);

    return 0; 
}