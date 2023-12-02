#include <stdio.h>
#include <string.h>

typedef struct book {
    char ISBN[14]; // ISBN has 13 digits and 4 dashes
    char title[200];
    int totalCopies;
    int copiesAvailable;

}Book;

void searchBook();

void main() {
    searchBook();
}

void searchBook() {
    char inputISBN[14];
    char ans;
    int found = 0;

    FILE *bPtr = NULL;

    if ((bPtr = fopen("Books.txt", "r")) == NULL) {
        printf("File could not be opened.\n");
    }
    else {
        Book book;
        
        printf("+====================================+\n");
        printf("\t>>> Book Search <<<\n");
        printf("+====================================+\n");
        
        printf("ISBN of Book: ");
        scanf("%s", inputISBN);
        
        while (fscanf(bPtr, "%s\n%[^\n]\n%d\n%d\n", book.ISBN, book.title, &book.totalCopies, &book.copiesAvailable) == 4) {
            if (strcmp(inputISBN, book.ISBN) == 0) {
                found = 1;
                // Print the found book details
                printf("ISBN: %s\n", book.ISBN);
                printf("Title: %s\n", book.title);
                printf("Total Copies: %d\n", book.totalCopies);
                printf("Copies Available: %d\n", book.copiesAvailable);
                if (book.copiesAvailable > 0) {
                    printf("\nWould you like to borrow this book?\n> 1. Yes\n> 2. No\n");
                    scanf("%c", &ans);
                    switch (ans)
                    {
                    case 1:
                        printf("borrow\n");
                        break;
                    case 2:
                        printf("no\n");
                        break;
                    default:
                        break;
                    }
                }
                fclose(bPtr);
            }
        }
        if (found != 1) {
            printf("Book not found.\n");
            searchBook();
        }
    }
}