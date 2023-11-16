#include <stdio.h>

union floatingPoint
{
    float f;
    double d;
    long double x;
}input;


int main() {
    //union floatingPoint input;
    printf("Enter a float: ");
    scanf("%f", &input.f);

    printf("Enter a double: ");
    scanf("%lf", &input.d);

    printf("Enter a long double: ");
    scanf("%Lf", &input.x);

    printf("Float: %f\nDouble: %lf\nLong Double: %Lf\n", input.f, input.d, input.x);
    return 0;
}