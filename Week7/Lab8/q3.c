#include <stdio.h>
#include <string.h>
#define MAX 20

int main() {
    char txt[MAX];
    char search;
    char *rep;
    int i;

    printf("Enter text: ");
    fgets(txt, MAX, stdin);

    printf("Enter search char: ");
    scanf("%c", &search);

    txt[strlen(txt) - 1] = '\0';

    rep = strchr(txt, search);

    while(rep != NULL) {
        i++;
        rep = strchr(rep + 1, search);
    }

    printf("%d\n", i);

    return 0;
}