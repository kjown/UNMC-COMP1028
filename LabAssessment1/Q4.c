#include <stdio.h> // Include the standard input/output library function

int main() {
    float height, weight; // Declare variable height in meters and weight in kilograms

    printf("Enter your weight in kilograms: "); // Prompt user to enter weight (in kiograms)
    scanf("%f", &weight); // Read the input of weight from the user

    printf("Enter your height in meters: "); // Prompt user for height (in meters)
    scanf("%f", &height); // Read the input of height from user
 
    printf("\nThank you for entering your data\nYour BMI is: %.2f\n\n", (weight / (height * height))); // display a thank you sentence and the calculated BMI 

    // Output categories of BMI  
    printf("BMI VALUES\nUnderweight: less than 18.5\nNormal: between 18.5 and 24.9\nOverweight: between 25 and 29.9\nObese: 30 or greater\n");

    return 0; // Program will execute successfully and did what it was intended to do
}