#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    printf("Enter a char from keyboard: ");
    scanf("%c", &c);

    if (c == '\n') {
        printf("isblank: %d\n", 1);
    }
    else {
        printf("isblank: %d\n", isblank(c));
    }

    

}