#include <stdio.h>

void swap(char **str1Ptr, char **str2Ptr) {
    char *temp;
    temp = *str1Ptr;
    *str1Ptr = *str2Ptr;
    *str2Ptr = temp;
}

int main() {
    char str1[101];
    char str2[101];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    char *str1Ptr = str1;
    char *str2Ptr = str2;

    printf("Pre swap:\nString1: %s\nString2: %s\n", str1Ptr, str2Ptr);
    
    swap(&str1Ptr, &str2Ptr);

    printf("Post swap: \nString1: %s\nString2: %s\n", str1Ptr, str2Ptr);
    
    return 0;
}