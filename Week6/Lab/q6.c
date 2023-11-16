#include <stdio.h>
#define SIZE 80

void mystery1(char *s1, const char *s2);

int main(void) {
    char string1[SIZE];
    char string2[SIZE];

    puts("Enter two string: ");
    scanf("%39s%39s", string1, string2);
    mystery1(string1, string2);
    printf("%s", string1);
}

void mystery1(char *s1, const char *s2) {
    while (*s1 != ) {
        ++s1;
    }
    for(; *s1 = *s2; ++s1, ++s2) {
        ;
    }
}