#include <stdio.h>

int cubeByValue(int n); //prototype

int main(void) {
    int num = 5;

    printf("The original value of num is %d\n", num);
    num = cubeByValue(num);
    printf("The new value of number is %d\n", num);
}

int cubeByValue(int n) {
    return n*n*n;
}