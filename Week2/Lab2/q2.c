#include <stdio.h>

int main() {
    int i = 1, sum = 0;
    while (i <= 100) {
        if (i % 7 == 0) {
            sum += i;
        }
        i++;
    }
    printf("Sum: %d\n", i);

}