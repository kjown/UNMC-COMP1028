#include <stdio.h>

int main() {
    printf("number\tsquare\tcube\n");
    
    int i;

    for (i = 1; i <= 5; i++) {
        int num = i;
        int square = (i * i);
        int cube = (i * i * i);

        printf("%d\t%d\t%d\n", num, square, cube);
    }

    return 0;
}