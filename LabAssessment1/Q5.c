#include <stdio.h> // Include the standard input/output library function

int main() {
    // Initialize a variable 'i' to 2, and the loop continues as long as 'i' is less than or equal to 20000.
    // In each iteration, 'i' is multiplied by 2, effectively doubling its value each time.
    for (int i = 2; i <= 20000; i *= 2) {
        printf("%d\n", i); // Print the current value of 'i' followed by a newline.
    }
    return 0; // Return 0 to indicate successful program execution.
}