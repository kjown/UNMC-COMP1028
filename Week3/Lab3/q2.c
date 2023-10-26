#include <stdio.h>

int integerPower(int base, int exponent) {
    int ans = 1;
    for (int i = 1; i <= exponent; i++) {
        ans = ans * base;
    }
    return ans;
}

int main() {
    int base;
    int exponent;
    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    printf("Answer: %d\n", integerPower(base, exponent));

    return 0;
}