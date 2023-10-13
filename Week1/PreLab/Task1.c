#include <stdio.h>

int main() {
    int a = 5;
    printf("Hello, World\n");
    printf("%s %d\n", "This is my first lab.", a);

    int b;
    printf("Enter the value you want to display: ");
    scanf("%d", &b);
    printf("Value of b is %d\n", b);

    return 0;
}