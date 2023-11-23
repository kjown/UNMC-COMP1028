#include <stdio.h>
#include <string.h>

// struct to store book details
typedef struct book {
    char ISBN[18]; // ISBN has 13 digits and 4 dashes
    char title[200];
    int copiesAvailable;
    int totalCopies;

}Book;

void addBooks();

int main() {
    addBooks();
}

void addBooks() {
    FILE *bPtr = NULL;       // sPtr = Student.txt file pointer

    // fopen opens file; exits program if file cannot be opened
    if ((bPtr = fopen("Books.txt", "a+")) == NULL) {
        puts("File could not be opened.");
    }
    else {
        Book book;

        printf("Enter ISBN, Title, Copies Available and Total Copies: ");
        scanf("%s %3s %d %d", book.ISBN, book.title, &book.copiesAvailable, &book.totalCopies);

        fprintf(bPtr, "%s, %s, %d %d\n", book.ISBN, book.title, book.copiesAvailable, book.totalCopies);

        fclose(bPtr);
    }
}