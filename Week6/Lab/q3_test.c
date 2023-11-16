#include <stdio.h>

int main() {
    char str[11];  // Buffer for storing the input (up to 10 characters)
    int ch;
    int i = 0;

    printf("Enter a string with more than 5 and less than 10 characters: ");

    while (1) {
        ch = getchar();

        if (ch == '\n' || ch == EOF) {
            break;  // Stop reading at Enter key or EOF
        }

        if (i >= 10) {
            printf("Input is too long. Please enter between 5 and 10 characters.\n");
            while (getchar() != '\n');  // Clear the input buffer
            i = 0;  // Reset the count
            continue;
        }

        str[i] = ch;
        i++;

        if (i > 5 && i < 10) {
            // If the input meets the length requirements, display it
            if (i == 10) {
                str[i] = '\0';  // Null-terminate the string
                printf("You entered: %s\n", str);
                break;
            }
        } else {
            printf("Input does not meet the length requirements. Please try again.\n");
            while (getchar() != '\n');  // Clear the input buffer
            i = 0;  // Reset the count
        }
    }

    return 0;
}