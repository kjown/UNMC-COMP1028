#include <stdio.h>

int  main(void) {
    int sum = 0;
    int i = 0;


    for (int num = 2; num <= 100; num += 2) {
        sum += num;
        printf("Iteration count: %d\n", ++i); 
    }

    printf("Sum is %d\n", sum);
    
} 