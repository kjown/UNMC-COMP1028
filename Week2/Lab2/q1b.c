#include <stdio.h>
#include <stdlib.h>

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
                sum += value;
            }
            avg = (double)sum / size;
            printf("Sum: %d\n", sum);
            printf("Average: %.2f\n", avg);
        }
}
