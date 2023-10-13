#include <stdio.h> // Include the standard input/output library function

int main() {
    int num1; // Declare variable num1 store values inputted by user

    int num2; // Declare variable num1 store values inputted by user

    printf("Enter the first integer value: "); // Display prompt for user to enter the first integer
    scanf("%d", &num1); // Read the input from user

    printf("Enter the 2nd integer value: "); // Display prompt for user to input the second integer
    scanf("%d", &num2); // Read the input from the user

    // Process to check which number inputted is larger or smaller
    if (num1 > num2) {
        printf("%d is larger than %d\n", num1, num2); // if num1 is larger than num 2, display "num1 is larger than num2"
    }
    if (num1 == num2) {
        printf("These numbers are equal\n"); // If num1 is equal to num2, display "These numbers are equal"
    }
    if (num1 < num2) {
        printf("%d is larger than %d\n", num2, num1); // If num2 is larger than num1, display "num2 is larger than num1"
    }

    return 0; // Program will execute successfully and did what it was intended to do
}