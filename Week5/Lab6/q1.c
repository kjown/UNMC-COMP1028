#include <stdio.h>

int len(const char *str) {
    int length = 0;  // counter
    while (str[length] != '\0') {
        length++;
    }
    if (length < 100) {
        printf("Length of string is %d\n", length);
    }
}

int main() {
    char string[101]; // 100 char and \0
    printf("Enter a string (up to 100 characters): ");
    scanf("%[^\n]s", string);
    len(string);
    return 0;
}