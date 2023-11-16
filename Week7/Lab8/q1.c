#include <stdio.h>
#include <string.h>
#define TOKEN_SIZE  30

int main() {
    char txt[30];
    char s[2] = " ";
    char *tokenArray[TOKEN_SIZE];
    int i;

    printf("Enter text: ");
    fgets(txt, 30, stdin);

    char *tokenPtr = strtok(txt, s);

    while (tokenPtr != NULL) {
        if (i < TOKEN_SIZE) {
            tokenArray[i++]=tokenPtr;
        }
        else{
            break;
        }
        tokenPtr = strtok(NULL, s);
    }
    while (i >= 0 && tokenArray[--i] != NULL) {
        printf("%s", tokenArray[i]);
    }
    
    puts("");
    return 0;
}