#include <stdio.h>

int main() {
    int i;
    
    printf("Enter an integer: ");
    scanf("%d", &i);

    if (i < 0) {
        i = i * -1;
        printf("Absolute = %d\n", i);
    }
    else {
        printf("Absolute = %d\n", i);
    }
    return 0;
}