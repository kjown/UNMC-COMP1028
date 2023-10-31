#include <stdio.h>

int find_gcd(int result_num, int result_denum) {
    if (result_denum == 0) {
        return result_num;
    }
    else {
        return find_gcd(result_denum, result_num%result_denum);
    }
}

void add(int numerator1, int denominator1, int numerator2, int denominator2) {
    int result_num;
    int result_denum;
    int temp_num1, temp_num2;
    int temp_denum;

    if (denominator1 == denominator2) {
        result_num = numerator1 + numerator2;
        result_denum = denominator1;
    }
    else {
        temp_num1 = numerator1 * denominator2;
        temp_num2 = numerator2 * denominator1;
        result_num = temp_num1 + temp_num2;
        result_denum = denominator1 * denominator2;
    }

    int gcd = find_gcd(result_num, result_denum);

    result_num /= gcd;
    result_denum /= gcd;

    printf("%d/%d + %d/%d = %d/%d\n", numerator1, denominator1, numerator2, denominator2, result_num, result_denum);
}

void subtract(int numerator1, int denominator1, int numerator2, int denominator2) {
    int result_num;
    int result_denum;
    int temp_num1, temp_num2;
    int temp_denum;

    if (denominator1 == denominator2) {
        result_num = numerator1 - numerator2;
        result_denum = denominator1;
    }
    else {
        temp_num1 = numerator1 * denominator2;
        temp_num2 = numerator2 * denominator1;
        result_num = temp_num1 - temp_num2;
        result_denum = denominator1 * denominator2;
    }

    int gcd = find_gcd(result_num, result_denum);

    result_num /= gcd;
    result_denum /= gcd;

    printf("%d/%d - %d/%d = %d/%d\n", numerator1, denominator1, numerator2, denominator2, result_num, result_denum);
}

void multiply(int numerator1, int denominator1, int numerator2, int denominator2) {
    int result_num;
    int result_denum;

    result_num = numerator1 * numerator2;
    result_denum = denominator1 * denominator2;

    int gcd = find_gcd(result_num, result_denum);

    result_num /= gcd;
    result_denum /= gcd;

    printf("%d/%d * %d/%d = %d/%d\n", numerator1, denominator1, numerator2, denominator2, result_num, result_denum);
}

void divide(int numerator1, int denominator1, int numerator2, int denominator2) {
    int result_num;
    int result_denum;

    result_num = numerator1 * denominator2;
    result_denum = denominator1 * numerator2;

    int gcd = find_gcd(result_num, result_denum);

    result_num /= gcd;
    result_denum /= gcd;

    printf("%d/%d / %d/%d = %d/%d\n", numerator1, denominator1, numerator2, denominator2, result_num, result_denum);  
}

int main() {
    int numerator1;
    int denominator1;
    int numerator2;
    int denominator2;

    printf("Enter the numerator and the denominator of fraction 1: ");
    scanf("%d %d", &numerator1, &denominator1);

    printf("Enter the numerator and the denominator of fraction 2: ");
    scanf("%d %d", &numerator2, &denominator2);

    add(numerator1, denominator1, numerator2, denominator2);
    subtract(numerator1, denominator1, numerator2, denominator2);
    multiply(numerator1, denominator1, numerator2, denominator2);
    divide(numerator1, denominator1, numerator2, denominator2);

    return 0;
}