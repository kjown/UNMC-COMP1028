#include <stdio.h>

int convert_binary(int decimal) {
    int binary_num = 0, remainder, i;
    while (decimal != 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary_num += remainder * i;
        i*= 10;
    }
    printf("%d", binary_num);
}

int main() {
    convert_binary(5);
}