#include <stdio.h>
#include <string.h>

int main() {
    char str[11];
    int ch;
    int count = 0;

    printf("Enter a string with more than 5 characters and less than 10 characters: ");
    
    while (1) {
        ch = getchar();

        if (count < 10) {
            str[count] = ch;
            count++;
        }
        else {
            printf("Input is too long. Please enter again.\n");
        }

        str[count] = ch;
        count++;

       if (ch == '\n' || ch == EOF) {
            break;
        }
    }

    printf("String entered: %s", str);

    return 0;
}