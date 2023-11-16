#include <stdio.h>

int main() {
    int numbers[20] = {0};
    int input;

    printf("Enter 20 numbers between 10 and 100 inclusive:\n");

    for (int i = 0; i < 20; i++) {
        scanf("%d", &input);

        if (input >= 10 && input <= 100) {
            int isDuplicate = 0; // Flag to check for duplicates

            for (int j = 0; j < i; j++) {
                if (input == numbers[j]) {
                    isDuplicate = 1;
                    printf("Entered duplicate.\n");
                    break; // No need to continue checking
                }
            }

            if (!isDuplicate) {
                numbers[i] = input;
                printf("%d\n", numbers[i]);
            }
        } else {
            printf("Invalid input.\n");
            i--; // Decrement the loop counter to re-enter the number
        }
    }

    return 0;
}