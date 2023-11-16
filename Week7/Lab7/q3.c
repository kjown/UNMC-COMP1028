#include <stdio.h>

union Data
{
    char c;
    int i;
    long b;
};


int main() {
    union Data data;

    printf("Enter a char: ");
    scanf("%c", &data.c);

    printf("Enter an int: ");
    scanf("%d", &data.i);

    printf("Enter a long: ");
    scanf("%ld", &data.b);

    printf("Char: %c\nInt: %d\nLong: %ld\n", data.c, data.i, data.b);

    return 0;
}