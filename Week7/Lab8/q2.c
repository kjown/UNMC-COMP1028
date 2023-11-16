#include <stdio.h>
#include <string.h>
#define MAX 30 

int main() {
    char input[MAX];
    char search[MAX];
    char *rep;
    int i = 0; 

    printf("Enter text: ");
    fgets(input, MAX, stdin);

    printf("Enter search string: ");
    fgets(search, MAX, stdin);

    input[strlen(input) - 1] = '\0';
    search[strlen(search) - 1] = '\0';

    rep = strstr(input, search);

    while(rep != NULL) {
        i++;
        rep = strstr(rep + 1, search);
    }

    printf("Total occurences of search string: %d\n", i);

    return 0;
}