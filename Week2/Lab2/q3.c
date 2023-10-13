#include <stdio.h>

int convert_binary(int decimal) {
    int binary_num = 0, i = 1, remainder;
    while (decimal != 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary_num += remainder * i;
        i *= 10;
    }
    return binary_num;
}

int convert_octal(int decimal) {
    int octal_num = 0, i = 1, remainder;
    while (decimal != 0) {
        remainder = decimal % 8;
        decimal /= 8;
        octal_num += remainder * i;
        i *= 10;
    }
    return octal_num;
}

int main() {
    printf("Decimal\t\tBinary\t\tOctal\t\tHexadecimal\n");
    int decimal, binary, octal, hexadecimal;
    for (decimal = 1; decimal <= 256; decimal++) {
        binary = convert_binary(decimal);
        octal = decimal;
        hexadecimal = decimal;
        printf("%-8d\t%-8d\t%#-8o\t%#-8X\n", decimal, binary, octal, hexadecimal);
    }
}