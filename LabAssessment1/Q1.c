#include <stdio.h> // Include the standard input/output library function

int main() {
    int count = 1; // Declare variable count to act as a counter
    int quotient; // Declare variable quotient to store value of quotient
    float num; // declare variable num to store numbers inputted by user
    float sum = 0; // declare variable sum, and set sum to 0. To store the sum of inputted numbers by the  user
    float product = 1; // declare variable product and set to 1. To store the total product of numbers inputted by the user
    float avg; // Declare variable to store the value of the average
    float remainder; // Declare variable remainder to store value of remainder

    // Execute while user inputs less than or equal to 5 number
    while (count <= 5) {
        printf("Enter number %d: ", count); // Print statement to prompt user for input
        scanf("%f", &num); // Read input from user

        sum += num; // Add the inputted number to sum
        product *= num; // Multiply the inputted number to the variable product
        count += 1; // Increase variable count by 1

    }
    int divisor = count; // Set divisor to be equal to count
    if (divisor = 5) { // if divisor is 5, execute
        avg = sum / divisor; // the average (avg) is equal to sum / divisor
        quotient = sum / divisor; // quotient is the result of dividing one quantity by antother (sum / divisor) 
        remainder = sum - (quotient * divisor); // if there is remainder, it is the remaining part or leftover value after performing the division

        printf("Sum: %f\n", sum); // Display the result of sum
        printf("Product: %f\n", product); // Display the result of product
        printf("Average: %f\n", avg); // Display the value of average
        printf("Quotient: %d\n", quotient); // Display the result of the quotient 
        printf("Remainder: %f\n", remainder); // Display the value of remainder
    }
    return 0; // Program will execute successfully and did what it was intended to do
}