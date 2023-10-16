#include <stdio.h> // Include the standard input/output library function

int main() {
    // initialize i to be 2, and if i < 20000, print i, then i * 2
    for (int i = 2; i <= 20000; i *= 2) {
        printf("%d\n", i); // Print i value 
    }
    return 0; // Program will execute successfully and did what it was intended to do
}