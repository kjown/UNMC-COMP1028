#include <stdio.h>

int main() {
    int i, count, value, sum;
    printf("Number of integers: ");
    scanf("%d", &i);

    count = 0;
    while (++count <= i) {
        printf("Integer %d: ", count);
        scanf("%d", &value);
        sum += value;
    }
    double avg = sum / i;
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);
}