#include <stdio.h> // standard input output library

// function to find the greatest common divisor between 2 number
int find_gcd(int result_num, int result_denum) {
    if (result_denum == 0) {
        // return result_num if it is 0
        return result_num;
    }
    else {
        return find_gcd(result_denum, result_num%result_denum); // replace result_num with result_denum, and result_denum becomes remainder. Repeat until result_denum = 0 and then result_num is the gcd
    }
}

// function to add two fractions
void add(int numerator1, int denominator1, int numerator2, int denominator2) {
    int result_num; // initialise variable for the final numerator answer
    int result_denum; // initialise variable for the final denominator answer
    int temp_num1, temp_num2; // initialise temporary numerator variables
    int temp_denum; // initialise temporary denominator variable

    if (denominator1 == denominator2) {
        result_num = numerator1 + numerator2; // if both denominator are equal, add both numerator
        result_denum = denominator1; 
    }
    else {
        // instructions to add fractions both have different denominator
        temp_num1 = numerator1 * denominator2;
        temp_num2 = numerator2 * denominator1;
        result_num = temp_num1 + temp_num2;
        result_denum = denominator1 * denominator2;
    }
    
    int gcd = find_gcd(result_num, result_denum); // call function the find the gcd of both numerator and denominator
    //get most simplied fraction
    result_num /= gcd; 
    result_denum /= gcd;
    // display the final answer of the add operation
    printf("%d/%d + %d/%d = %d/%d\n", numerator1, denominator1, numerator2, denominator2, result_num, result_denum);
}

void subtract(int numerator1, int denominator1, int numerator2, int denominator2) {
    int result_num; // initialise variable for the final numerator answer
    int result_denum; // initialise variable for the final denominator answer
    int temp_num1, temp_num2; // initialise temporary numerator variables
    int temp_denum; // initialise temporary denominator variable

    if (denominator1 == denominator2) {
        result_num = numerator1 - numerator2; // if denominator of both fractions are equal, perform substraction
        result_denum = denominator1; 
    }
    else {
        // instructions to substract fractions that have different denominator
        temp_num1 = numerator1 * denominator2;
        temp_num2 = numerator2 * denominator1;
        result_num = temp_num1 - temp_num2;
        result_denum = denominator1 * denominator2;
    }

    int gcd = find_gcd(result_num, result_denum); // call function to find gcd of both final numerator and denominator
    // get most simplified fraction
    result_num /= gcd;
    result_denum /= gcd;
    // display the result
    printf("%d/%d - %d/%d = %d/%d\n", numerator1, denominator1, numerator2, denominator2, result_num, result_denum);
}
// function to mulitply fractions
void multiply(int numerator1, int denominator1, int numerator2, int denominator2) {
    int result_num; // initialise variable result_num
    int result_denum; // initialise variable result_denum

    // instructions to perform multiplication of two fractions
    result_num = numerator1 * numerator2; 
    result_denum = denominator1 * denominator2;

    int gcd = find_gcd(result_num, result_denum); // call gcd function
    // get most simplified fraction
    result_num /= gcd; 
    result_denum /= gcd;
    // display the result
    printf("%d/%d * %d/%d = %d/%d\n", numerator1, denominator1, numerator2, denominator2, result_num, result_denum);
}

//function to perform division of two fractions
void divide(int numerator1, int denominator1, int numerator2, int denominator2) {
    int result_num; // initialise variable result_num
    int result_denum; // initialise variable result_denum

    //instruction to perform division of two fractions
    result_num = numerator1 * denominator2;
    result_denum = denominator1 * numerator2;

    int gcd = find_gcd(result_num, result_denum); // call gcd function
    // get most simplified fraction
    result_num /= gcd;
    result_denum /= gcd;
    // display the result
    printf("%d/%d / %d/%d = %d/%d\n", numerator1, denominator1, numerator2, denominator2, result_num, result_denum);  
}

int main() {
    int numerator1; // initialise numerator1 variable to store the first numerator inputted by user
    int denominator1; // initialise denominator1 variable to store the first denominato inputted by user
    int numerator2; // initialise numerator2 variable to store the second numerator inputted by user
    int denominator2; // initialise denominator2 variable to store the second denominator inputted by user

    printf("Enter the numerator and the denominator of fraction 1: "); // prompt user to input first fraction
    scanf("%d %d", &numerator1, &denominator1); // read and store input from user

    printf("Enter the numerator and the denominator of fraction 2: "); // prompt user to input second fraction
    scanf("%d %d", &numerator2, &denominator2); // read and store the input from user

    add(numerator1, denominator1, numerator2, denominator2); // call add function
    subtract(numerator1, denominator1, numerator2, denominator2); // call substract function
    multiply(numerator1, denominator1, numerator2, denominator2); // call multiply function
    divide(numerator1, denominator1, numerator2, denominator2); // call divide function

    return 0;
}