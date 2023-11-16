#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    unsigned int i; // counter
    unsigned int seed; // number used to send seed the random number generaetor

    printf("%s", "Enter seed: ");
    scanf("%u", &seed); // read unsigned int

    srand(seed);
    for (i = 1; i <= 10; ++i) {
        //pick random number from 1 to 6 and output it
        printf("%10d", 1 + (rand() % 16));
    
        // if counter divisible by 5, begin new line of output
        if (i % 5 == 0) {
            puts("");
        }
    }

}