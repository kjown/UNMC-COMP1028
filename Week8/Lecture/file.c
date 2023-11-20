#include <stdio.h>

int main(void) {
    FILE *cfPtr = NULL;  // cfPtr = clients.txt file opener

    // fopem opens the file. Exit the program if unable to create the file
    if ((cfPtr = fopen("clients.txt", "w")) == NULL) {
        puts("File could not be opened");
    }
    else {
        puts("Enter account, name and balance.");
        puts("Enter EOF to end input.");
        printf("%s", "? ");

        int account = 0;
        char name[30] = "";
        double balance = 0.0;

        scanf("%d%29s%lf", &account, name, &balance);

        // write account, name and balance into filewith fprintf
        while (!feof(stdin)) {
            fprintf(cfPtr, "%d %s %.2f\n", account, name, balance);
            printf("%s", "? ");
            scanf("%d%29s%lf", &account, name, &balance);
        }
        fclose(cfPtr);
    }
}