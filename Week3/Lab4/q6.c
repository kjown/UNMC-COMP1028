#include <stdio.h>

// function to calculate cube of a number
int cube(int num) {
    int cube = num * num * num;
    return cube;
}

// function to calculate the square of a number
int square(int num) {
    int square = num * num;
    return square;
}


int main() {
    int num; // declare a num int 
    printf("Enter an integer: "); 
    scanf("%d", &num);

    int sum = square(num) + cube(num); // sum of square and cube of a number
    printf("Sum of cube and square of %d: %d\n", num, sum); // display sum

    return 0;
}