#include <stdio.h>

int main() {
    float weight;
    float height;
    float BMI;
    
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);
    
    BMI = weight / (height * height);
    puts("");
    printf("Thank you for entering your data. \nYour BMI is: %f", BMI);
    
    printf("BMI VALUES \nUnderweight: less than 18.5 \nNormal: between 18.5 and 24.9 \nOverweight: between 25 and 29.9 \nObese: 30 or greater");

    return 0;
}