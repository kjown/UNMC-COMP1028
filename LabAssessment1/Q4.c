#include <stdio.h> // Include the standard input/output library function

int main() {
    float weight; // Declare variable to store the weight (in kilograms)
    float height; // Declare the variable to store the height (in meters)

    printf("Enter your weight in kilograms: "); // Display prompt for user to enter weight in kiograms
    scanf("%f", &weight); // Read and store the weight input from the user 

    printf("Enter your height in meters: "); // Display prompt for user to enter height in meters
    scanf("%f", &height); // Read and store the height input from the user
 
    float BMI = (weight / (height * height)); // Calculate the BMI using input of weight and height
    printf("\nThank you for entering your data\nYour BMI is: %.2f\n\n", BMI); // display a thank you sentence and the calculated BMI 

    // Display BMI categories for reference of the user
    printf("BMI VALUES\nUnderweight: less than 18.5\nNormal: between 18.5 and 24.9\nOverweight: between 25 and 29.9\nObese: 30 or greater\n");

    return 0; // Return 0 to indicate successful program execution
}