#include <stdio.h>
#include <math.h>

double hypotenuse(double side1, double side2) {
    double hypotenuse_squared = (side1 * side1) + (side2 * side2);
    double hypo = sqrt(hypotenuse_squared);
    return hypo;
}

int main() {
    double side1;
    double side2;

    printf("Enter length of side 1: ");
    scanf("%lf", &side1);

    printf("Enter length of side 2: ");
    scanf("%lf", &side2);

    printf("Hypotenuse of triangle inputted is: %.1lf\n", hypotenuse(side1, side2));

    return 0;
}