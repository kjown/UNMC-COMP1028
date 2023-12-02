#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct book {
    char ISBN[14]; // ISBN has 13 digits and 4 dashes
    char title[200];
    int totalCopies;
    int copiesAvailable;
}Book;

int compareBooks(const void *a, const void *b) {
    return strcmp(((Book *)a)->title, ((Book *)b)->title);
}

int main() { // require FILE knowledge
    FILE *bPtr = NULL;

    // open Books.txt file for reading
    if ((bPtr = fopen("Books.txt", "r")) == NULL) {
        printf("File could not be opened.\n");
    }

    Book books[MAX_BOOKS];
    int bookCount = 0;

    printf("+====================================+\n");
    printf("\t>>> Book List <<<\n");
    printf("+====================================+\n");
    
    // read each line from file into entry
    int blockCount = 0;
    
    // sort the data in Book.txt using alphabetical order
    while (fscanf(bPtr, "%s\n%[^\n]\n%d\n%d\n", books[bookCount].ISBN, books[bookCount].title, &books[bookCount].totalCopies, &books[bookCount].copiesAvailable) == 4) {
        bookCount++;
    }
    
    // close the file
    fclose(bPtr);

    // Sort the books based on their titles
    qsort(books, bookCount, sizeof(Book), compareBooks);

    // Print out the sorted data
    for (int i = 0; i < bookCount; ++i) {
        printf("ISBN: %s\nTitle: %s\nTotal Copies: %d\nCopies Available: %d\n\n",
               books[i].ISBN,
               books[i].title,
               books[i].totalCopies,
               books[i].copiesAvailable);
    }

    return 0;
}