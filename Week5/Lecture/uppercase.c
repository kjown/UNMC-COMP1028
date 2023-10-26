#include <stdio.h>
#include <ctype.h>

void convert(char *sPtr);   // prototype (pass by reference)

int main(void) {
    char string[] = "cHaRaCteRs and $32.98";

    convert(string);
    printf("The string after conversion: %s\n", string);
}

void convert(char *sPtr) {
    while (*sPtr != 0)
    {
        *sPtr = toupper(*sPtr);
        ++sPtr;
    }
}