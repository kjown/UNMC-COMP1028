#include <stdio.h> // Include the standard i/o library 

int main() {
    int number; // Declare variable number to store int inputted by user
    int count; // Variable count to store the number of input required by user
    printf("How many integer values do you want to compare:"); // Prompt the user to input the number of integer values they want to compare.
    scanf("%d", &count); // Read the count value inputted by user

    int minimum; // Declare an integer variable 'min' to store the minimum value.
    // Iterate through the loop while i <= count
    for (int i = 1; i <= count; i++) {
        printf("Enter the %d value ", i); // Prompt user for an integer
        scanf("%d", &number); // Read integer value inputted by the user.
        
        // Compare the current value 'num' with the current minimum value 'min'.
        // If 'num' is smaller than 'min', update 'min' to be 'num'.
        if (number < minimum) {
            minimum = number;
        }
    }
    printf("The smallest value is: %d\n", minimum); // Output the minimum value
    return 0; // Program will execute successfully and did what it was intended to do
}