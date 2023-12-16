#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s1[50] = "jack";
    char s2[50] = "jill";
    char s3[50] = "";
    
    printf("%c%s\n", toupper(s1[0]), &s1[1]);
    printf("%s\n", strcpy(s3, s2));
    printf("%s\n", strcat(strcat(strcpy(s3, s1), " and "), s2));
    printf("%zu\n", strlen(s1) + strlen(s2));
    printf("%zu\n", strlen(s3));
}