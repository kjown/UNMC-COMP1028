#include <stdio.h>
#define SIZE 80

size_t mystery2(const char *s);

int main(void) {
    char string[SIZE];

    puts("Enter a string: ");
    scanf("%79s", string);
    printf("%ld\n", mystery2(string));
}

size_t mystery2(const char *s) {
    size_t x;

    for (x = 0; *s != 0; ++s) {
        ++x;
    }
    return x;
}