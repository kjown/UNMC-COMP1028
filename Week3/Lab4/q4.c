#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    double random = 1, random1 = 1;
    srand(time(NULL));
    while (random1 <= 4) {
        random = (double)rand() / RAND_MAX * 3 + 1;
        random1++;
        //printf("Random number: %.2lf\n", random);
    }
    printf("Random number: %.2lf\n", random);
}