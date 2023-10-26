#include <stdio.h>

void f(const int *xPtr);

int main(void) {
    int y = 7;

    f(&y); 
}