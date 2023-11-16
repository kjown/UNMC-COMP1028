#include <stdio.h>

void read(char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count += 1;
    }
    printf("Length of string is %d\n", count);
}

int main() {
    char str[101];
    char *strP = str;
    printf("Enter a string: ");
    scanf("%s", str);

    read(strP);
}