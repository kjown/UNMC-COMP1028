#include <stdio.h>
#include <string.h>

void upper(char *str) {
    char low[] = {'a', 'b', 'c', '\0'};
    char up[] = {'A', 'B', 'C', '\0'};
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; low[j] != '\0'; j++) {
            if (str[i] == low[j]) {
                str[i] = up[j];
            }
            else {
                continue;
            } 
        }
    }
    printf("Upper case: %s\n", str);
}

void lower(char *str) {
    char low[] = {'a', 'b', 'c', '\0'};
    char up[] = {'A', 'B', 'C', '\0'};
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; up[j] != '\0'; j++) {
            if (str[i] == up[j]) {
                str[i] = low[j];
            }
            else {
                continue;
            } 
        }
    }
    printf("Lower case: %s\n", str);
}


int main() {
    char str[100];
    char *strP = str;
    printf("Enter a string: ");
    //fgets(str, 3, stdin);
    scanf("%s", str);

    upper(strP);
    lower(strP);

    return 0;
}