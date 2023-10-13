#include <stdio.h> // Include the standard i/o library 

int main() {
    int num; // Declare an integer variable 'num' to store each entered integer value.
    int count; // Declare an integer variable 'count' to store the number of values to compare.
    printf("How many integer values do you want to compare:"); // Prompt the user to input the number of integer values they want to compare.
    scanf("%d", &count); // Read and store the number of values entered by the user.

    int min; // Declare an integer variable 'min' to store the minimum value.
    // Iterate through the loop to compare the entered integer values.
    for (int i = 1; i <= count; i++) {
        printf("Enter the %d value ", i); // Prompt the user to enter an integer
        scanf("%d", &num); // Read and store the integer value inputted by the user.
        
        // Compare the current value 'num' with the current minimum value 'min'.
        // If 'num' is smaller than 'min', update 'min' to be 'num'.
        if (num < min) {
            min = num;
        }
    }
    printf("The smallest value is: %d\n", min); // Display the smallest value
    return 0; // Return 0 to indicate successful program execution.
}