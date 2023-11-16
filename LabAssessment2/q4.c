#include <stdio.h> // standard input output library

void add(int array[2][2]); // function prototype to add two fractions
void subtract(int array[2][2]); // function prototype to perform subtraction of two functions 
void multiply(int array[2][2]); // function protottype to perform multiplication of two fractions
void divide(int array[2][2]); // function prototype to perform division of two fractions
int gcd(int x,int y); // function prototype to find the gcd tof the numerator and denominator

int main() {
    // numerator 1 is [0][0], denominator1 is [0][1], numerator2 is [1][0], denominator is [1][1]
    int array[2][2]; // initialise array to store the numerator and denominator of fractions

    printf("Enter the numerator and the denominator of fraction 1: "); // prompt user to enter first fraction
    scanf("%d %d", &array[0][0], &array[0][1]); // read and store  input from user

    printf("Enter the numerator and the denominator of fraction 2: "); // prompt user to enter second fraction
    scanf("%d %d", &array[1][0], &array[1][1]); // read and store input from user

    add(array); // call add function
    subtract(array); // call subtract function
    multiply(array); // call multiply function
    divide(array); // call divide function

    return 0; // program execute successfully
}
// function to find gcd of numerator and denominator of a fraction
int find_gcd(int result_num, int result_denum) {
    // return 0 if result_denum is 0
    if (result_denum == 0) {
        return result_num;
    }
    else {
        // return the gcd 
        return find_gcd(result_denum, result_num%result_denum);
    }
}

// function to add two fractions
void add(int array[2][2]) {
    int result_num; // initialise variable result_num
    int result_denum; // initialise variable result_denum 
    int temp_num1, temp_num2; // initialise temp variables fro numerator
    int temp_denum; // initialise temp variable for denominator

    if (array[0][1] == array[1][1]) {
        // instructions to add two fractions if both denominator are the same
        result_num = array[0][0] + array[1][0];
        result_denum = array[0][1];
    }
    else {
        // instructions to add two fractions if both denominator are not equal
        temp_num1 = array[0][0] * array[1][1];
        temp_num2 = array[1][0] * array[0][1];
        result_num = temp_num1 + temp_num2;
        result_denum = array[0][1] * array[1][1];
    }

    int gcd = find_gcd(result_num, result_denum); // call function to find the gcd between final numerator and denominator

    // get the most simplified fraction for the final answer
    result_num /= gcd; 
    result_denum /= gcd;
    // display the result
    printf("%d/%d + %d/%d = %d/%d\n", array[0][0], array[0][1], array[1][0], array[1][1], result_num, result_denum);
}

// function to perform substraction of two fractions
void subtract(int array[2][2]) {
    int result_num; // initialise variable result_num
    int result_denum; // initialise variable result_denum
    int temp_num1, temp_num2; // initialise temp variable for numerators 
    int temp_denum; // initialise temp variable for denominator

    if (array[0][1] == array[1][1]) {
        // instruction to subtract two fractions if both fraction have the same denominator
        result_num = array[0][0] - array[1][0];
        result_denum = array[0][1];
    }
    else {
        // instruction to subtract two fractions if both fractions have different denominator
        temp_num1 = array[0][0] * array[1][1];
        temp_num2 = array[1][0] * array[0][1];
        result_num = temp_num1 - temp_num2;
        result_denum = array[0][1] * array[1][1];
    }

    int gcd = find_gcd(result_num, result_denum); // find the gcd between the final numerator and denominator
    // find most simplified fraction
    result_num /= gcd;
    result_denum /= gcd;
    // display the result
    printf("%d/%d - %d/%d = %d/%d\n", array[0][0], array[0][1], array[1][0], array[1][1], result_num, result_denum);
}
// function to perform multiplication of two fractions
void multiply(int array[2][2]) {
    int result_num; // initialise variable result_num
    int result_denum; // initialise variable result_denum

    // perform multiplication of two fractions
    result_num = array[0][0] * array[1][0];
    result_denum = array[0][1] * array[1][1];

    int gcd = find_gcd(result_num, result_denum); // find the gcd of the numerator and denominator
    // get the most simplified fraction
    result_num /= gcd;
    result_denum /= gcd;
    // display the result
    printf("%d/%d * %d/%d = %d/%d\n", array[0][0], array[0][1], array[1][0], array[1][1], result_num, result_denum);
}
// function to perform division of two fractions
void divide(int array[2][2]) {
    int result_num; // initialise variable result_num
    int result_denum; // initlalise variable result_denum
    // perform division of two fractions
    result_num = array[0][0] * array[1][1];
    result_denum = array[0][1] * array[1][0];

    int gcd = find_gcd(result_num, result_denum); // find the gcd between numerator and denominator
    // find the most simplified fraction
    result_num /= gcd;
    result_denum /= gcd;    
    // display the result
    printf("%d/%d / %d/%d = %d/%d\n", array[0][0], array[0][1], array[1][0], array[1][1], result_num, result_denum);  
}