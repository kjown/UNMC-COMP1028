#include <stdio.h>

void convert(char *str) {
    
}

int main() {
    char str[4][20];
    char *strP = str;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 20; j++) {
            printf("Enter string %d representing integers: ");
            scanf("%s", str[i][j]);
        }
    }
    convert(strP);

    return 0;
}