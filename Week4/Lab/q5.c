#include <stdio.h>

int main() {
    int array[10] = {0};
    int input;
    printf("Enter 10 integers (excluding 0 and -1):\n");

    for (int i = 0; i < 10; i++) { // Corrected loop index, starting from 0
        scanf("%d", &input);
        if ((input != 0) && (input != -1)) {
            if ((input % 2 == 0) && (i % 2 == 0)){
                array[i] = input;
            }
            else if ((input % 2 == 1) && (i % 2 == 1)){
                array[i] = input;
            }
            else {
                printf("Invalid input.\n");
                i--;
            }
        }
        else {
            printf("Invalid input.\n");
            i--;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (array[i] == 0 || array[i] == -1) {
            array[i] = -1;
        }
    }

    printf("Array after input:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}