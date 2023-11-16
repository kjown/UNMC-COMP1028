#include <stdio.h>

void read(char *string);

int main() {
    char string[21];
    printf("Enter a string up to 20 characters: ");
    fgets(string, sizeof(string), stdin);

    read(string);

    return 0;
}

void read(char *string) {
    int i = 0;
    int char_count = 0;
    int c_count = 0;
    while (string[i] != '\0') {
        char_count++;

        if (string[i] == 'c') {
            c_count++;
        }
        if (string[i] == ' ') {
            string[i] = '\n';
        }
        if (string[i] == 'b') {
            string[i] = 'z';
        }

        i++;
    }
    printf("The number of characters: %d\nFrequency of 'c': %d\nInput string after modification: \n%s\n", char_count, c_count, string);
}