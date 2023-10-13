#include <stdio.h>

int main() {
    int count = 1;

    do {
        printf("%d ", count);
    }
    while (count++ < 10);
    
    return 0;
}

// Executes 10 times