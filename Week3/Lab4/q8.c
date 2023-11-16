#include <stdio.h>

int fact(int n) {
    if (n > 1) {
        return (n * fact(n-1));
    }
    else{
        return 1;
    }
}

int main() {
    int i;
    printf("Int: ");
    scanf("%d", &i);

    printf("Factorial: %d\n", fact(i));
}