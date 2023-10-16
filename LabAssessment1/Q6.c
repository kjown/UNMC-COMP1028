#include <stdio.h> // Include the standard i/o library 

int main() {
    char name_1 = 'K'; // Declare name1 variable with value char 'K'
    char name_2 = 'a'; // Declare name_2 variable with value char 'a'
    char name_3 = 'i'; // Declare name_3 variable with value char 'i'

    printf("My name is %c%c%c\n\n", name_1, name_2, name_3); // Output "My name is Kai"

    printf("The decimal of %c is %d\n", name_1, name_1); // Output the decimal equivalent of name_1 
    printf("The hexadecimal of %c is %x\n", name_1, name_1); // Output the hexadecimal equivalent of name_1  
    printf("The octal of %c is %o\n\n", name_1, name_2); // Output the octal equivalent of name_1 

    // Repeat the  process for 'name_2'
    printf("The decimal of %c is %d\n", name_2, name_2); // Output the decimal equivalent of name_1
    printf("The hexadecimal of %c is %x\n", name_2, name_2); // Output the hexadecimal equivalent of name_2
    printf("The octal of %c is %o\n\n", name_2, name_2); // Output the octal equivalent of name_3

    return 0; // Program will execute successfully and did what it was intended to do
}