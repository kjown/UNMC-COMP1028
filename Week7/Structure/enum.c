#include <stdio.h>

enum months {
    JAN = 1, FEB, MAR, APR, MAY
};

int main() {
    const char *monthName[] = {"", "January", "February", "March", "April", "May"};

    for (enum months month = JAN; month <= MAY; ++month) {
        printf("%2d%11s\n", month, monthName[month]);
    }  
}