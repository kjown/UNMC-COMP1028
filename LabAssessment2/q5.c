#include <stdio.h> // standard input output library

int main() {
    int i; // initialise variable i for subscript of array
    int array[100] = { [0 ... 99] = 1 }; // initialise 100 element arrays to 1
    // start loop from subscript 2
    for (i = 2; i <= 100; i++) {
        // loop through elements of the array to find prime numbers
        if (array[i] == 1) {
            for (int j = i + 1 ; j <= 100; j++) {
                // if element is !prime, then set that element to 0
                if (j % i == 0) {
                    array[j] = 0;
                }
            }
        }
    }
    array[0] = 0; // 0 is not a prime number
    array[1] = 0; // 1 is not a prime number

    // print the final arrays
    for (i = 0; i < 100; i++) {
        printf("Array[%d] = %d\n", i, array[i]);
    }
    
    return 0; // program execute successfully
}