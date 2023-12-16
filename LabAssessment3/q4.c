#include <stdio.h>
#define MAX_COUNT 100

// function to count the number of vowels and number of consonants in a string input
void count(char *str) {
    int vowelCount = 0; // initialise variable vowelCount to 0
    int consCount = 0;  // initialise variable consCount to 0
    
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'}; // array of vowels
    // array of consonants
    char consonants[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};   

    // for loop to find the number of vowels present in a string input
    for (int i = 0; i < sizeof(str); i++) {
        for (int j = 0; j < 5; j++) {
            if (str[i] == vowels[j]) {
                vowelCount++;   // if str[i] matches a vowel, vowelCount increments by 1
        }

        }
    }
    // for loop to find the number of consonants present in a string input
    for (int i; i < sizeof(str); i++) {
        for (int j = 0; j < 21; j++) {
            if (str[i] == consonants[j]) {
                consCount++;    // if str[i] matches a consonant, consCount increments by 1
            }
        }
    }
    printf("Number of vowels: %d\n", vowelCount);   // display number of vowels in a string input
    printf("Number of consonants: %d\n", consCount);    // display number of consonants in a string input
}
 
int main() {
    char str[MAX_COUNT];
    printf("Input a string: "); // prompt user for string input
    scanf("%s", str);   // read and store input into variable str

    count(str); // call function to find number of vowels and number of consonants in string input

    return 0;
}