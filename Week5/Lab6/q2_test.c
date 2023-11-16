#include <stdio.h>

void swap(char *str1, char *str2);

int main() {
    char str1[101];
    char str2[101];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    char *ptr1 = str1;
    char *ptr2 = str2;

    printf("Before swap\nString1: %s\nString2:%s\n", str1, str2);

    swap(ptr1, ptr2);

    printf("After swapping:\nString1: %s\nString2: %s\n", str1, str2);

    return 0;
}

void swap(char * str1, char * str2) {
    char temp;
    while (*str1 != '\0' || *str2 != '\0') {
        temp = *str1;
        *str1 = *str2;
        *str2 = temp;
        str1++;
        str2++;
    }
}