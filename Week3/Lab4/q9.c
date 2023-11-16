#include <stdio.h>

unsigned long long int fibonacci(unsigned int n); // fucntion prototype

int main() {
    unsigned long long int result; // fibonacci value
    unsigned int number;

    // obtain integer from user
    printf("%s", "Enter an integer: ");
    scanf("%u", &number);

    // calculate fibonacci value for number input by user
    result = fibonacci(number);

    // display result
    printf("Fibonacci(%u) = %11llu\n", number, result);
}

unsigned long long int fibonacci(unsigned int n) {
    // base case
    if (0 == n || 1 == n) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}