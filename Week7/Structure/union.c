#include <stdio.h>

union number
{
    int x;
    double y;
};

int main(void) {
    union number value; //define a union variable

    value.x = 100;
    puts("Put 100 in the int number and print both numbers: ");
    printf("int: %d\ndouble: %.2f\n\n", value.x, value.y);

    value.y = 100.0;
    puts("Put 100.0 in the double number and print both numbers: ");
    printf("int: %d\ndouble: %.2f\n\n", value.x, value.y);
}