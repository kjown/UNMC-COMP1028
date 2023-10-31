#include <stdio.h>

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }
    else {
        return gcd(y, x%y);
    }
}

int main() {
    int x;
    int y;
    
    printf("Please enter x: ");
    scanf("%d", &x);

    printf("Please enter y: ");
    scanf("%d", &y);
    
    printf("The greatest common divisor is: %d\n", gcd(x,y));

    return 0;
}