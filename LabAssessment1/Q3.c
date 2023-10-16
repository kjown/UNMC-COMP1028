#include <stdio.h> // Include the standard i/o library

int main() {
    int multiple; // Declare variable multiple to store the value of inputted by user
    int factor; // Declare the variable factor to store the value of inputted by user
    printf("Enter two integer numbers separated by a space: "); // Display prompt for user to input two integers separated by a space
    scanf("%d %d", &multiple, &factor); // Read two integer inputted by user seperated by a space

    if (multiple % factor == 0) {
        printf("%d is multiple of %d\n", multiple, factor); // If variable multiple divided by factor has no remainder, then it is a multiple of variable factor
    }
    else {
        printf("%d is not multiple of %d\n", multiple, factor); // If variable multiple divided by factor has remainder, then is not a multiple of variable factor
    }
    return 0; // Program will execute successfully and did what it was intended to do
}