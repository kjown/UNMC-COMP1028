#include <stdio.h> // Include the standard i/o library 

int main() {
    char name1 = 'O'; // Declare a character variable 'name1' and assign the character 'O' to it.
    char name2 = 'w'; // Declare a character variable 'name2' and assign the character 'w' to it.
    char name3 = 'n'; // Declare a character variable 'name3' and assign the character 'n' to it.

    printf("My name is %c%c%c\n\n", name1, name2, name3); // Display a message .

    printf("The decimal of %c is %d\n", name1, name1); // Display the decimal value of 'name1' 
    printf("The hexadecimal of %c is %x\n", name1, name1); // Display the hexadecimal value of 'name1' 
    printf("The octal of %c is %o\n\n", name1, name2); // Display the octal value of 'name1' 

    // Repeat the  process for 'name2'
    printf("The decimal of %c is %d\n", name2, name2);
    printf("The hexadecimal of %c is %x\n", name2, name2);
    printf("The octal of %c is %o\n\n", name2, name2);

    return 0; // Return 0 to indicate successful program execution.
}