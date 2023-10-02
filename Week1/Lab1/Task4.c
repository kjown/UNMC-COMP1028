#include <stdio.h>

int main() {
    char array[] = {'A', 'B', 'C', 'a', 'b', 'c', '0', '1', '2', '$', '*', '+', '/', ' '};

    for (int i = 0; i < sizeof(array); i++) {
        printf("Characters\tInteger Equivalents\n");
        printf("%c\t\t%d\n", array[i], array[i]);
    }

    return 0;
}