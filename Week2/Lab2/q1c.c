#include <stdio.h>
#include <stdlib.h>


int check_multiple(int value) {
    if (value % 3 != 0 || value ==12) {
        printf("Please enter again: ");
        scanf("%d", &value);
    }
    if (value == 3) {
        printf("Value is 3. No more entries accepted.\n");
    }
    return value;
}

int main() {
    int count, value, sum = 0;
    double size, avg;
    printf("Number of integers: ");
    char input[10];
    
    fgets(input, 10, stdin);

    if (input[0] == '\n') {
        printf("You have not entered any value and end the entries\n");
    }
    else {
        size = atof(input);
            count = 0;
            while (++count <= size) {
                printf("Integer %d: ", count);
                scanf("%d", &value);
                check_multiple(value);
                if (value == 3) {
                    break;
                }
                sum += value;
            }
            avg = (double)sum / size;
            printf("Sum: %d\n", sum);
            printf("Average: %.2f\n", avg);
        }
}
