#include <stdio.h>
#include <string.h>

int main(void) {
    char x[] = "HOme Sweet Home";

    printf("Before: %s\n", x);
    printf("After: %s\n", (char *) memmove(x, &x[3], 1));


}