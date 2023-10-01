#include <stdio.h>

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number); // & is a memory address of a variable

    printf("You entered: %d\n", number);

    return 0;
}