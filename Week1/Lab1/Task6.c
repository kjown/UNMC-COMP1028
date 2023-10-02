#include <stdio.h>

int main() {
    int x, y;

    printf("Enter first integer: ");
    scanf("%d", &x);

    printf("Enter second integer: ");
    scanf("%d", &y);

    if (x > y) {
        printf("%d\n", y);
        printf("%d\n", x);
    }
    else {
        printf("%d\n", x);
        printf("%d\n", y);
    }
    return 0;
}