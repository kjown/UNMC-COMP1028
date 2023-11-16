#include <stdio.h>
#include <string.h>
#define MAX 30

int main() {
    char txt[30];
    char search[2] = {' ', '\n'};
    int count = 0;
    
    printf("Enter text: ");
    fgets(txt, 30, stdin);

    char *tokenPtr = strtok(txt, " ");
    
    while (tokenPtr != NULL) {
        count++;
        tokenPtr = strtok(NULL, " ");
    }

    printf("%d\n", count);
    
    return 0;
}