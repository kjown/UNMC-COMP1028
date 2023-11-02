#include <stdio.h> // standard input output library

// function to find greatest common divisor
int gcd(int x, int y) {
    if (y == 0) {
        return x; // if y = 0, return x
    }
    else {
        return gcd(y, x%y); // replace x with y, and y becomes remainder of x/y. Repeat until y = 0 and then x is the gcd
    }
}

int main() {
    int x; // initialise variable x
    int y; // initialise variable y
    
    printf("Please enter x: "); // prompt user for input x
    scanf("%d", &x); // read input x from user

    printf("Please enter y: "); // prompt user for input y 
    scanf("%d", &y); // read input y from user
    
    // display the gcd 
    printf("The greatest common divisor is: %d\n", gcd(x,y));

    return 0;
}