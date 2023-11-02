#include <stdio.h>

int main() {
    int i;
    int array[100] = { [0 ... 99] = 1 };
    for (i = 2; i <= 100; i++) {
        if (array[i] == 1) {
            for (int j = i + 1 ; j <= 100; j++) {
                if (j % i == 0) {
                    array[j] = 0;
                }
            }
        }
    }
    array[0] = 0; // 0 is not a prime number
    array[1] = 0; // 1 is not a prime number

    for (i = 0; i < 100; i++) {
        printf("Array[%d] = %d\n", i, array[i]);
    }
    
    return 0;
}