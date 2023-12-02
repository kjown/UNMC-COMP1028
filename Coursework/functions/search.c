#include <stdio.h>
#include <string.h>

typedef struct book_details {
    char ISBN[14];
    char title[100];
    int totalCopies;
    int copiesAvailable;
} Book;

int searchISBN(const char *inputISBN);

int main() {
    // For demonstration, let's assume you have a user attempting to search by ISBN.
    char userInputISBN[14];

    printf("Enter ISBN to search: ");
    scanf("%s", userInputISBN);

    // Call the searchISBN function to check for the entered ISBN
    int searchResult = searchISBN(userInputISBN);

    if (searchResult == 1) {
        printf("Book found!\n");
    } else {
        printf("Book not found.\n");
    }

    return 0;
}

int searchISBN(const char *inputISBN) {
    FILE *filePtr = fopen("Books.txt", "r");

    if (filePtr == NULL) {
        puts("File could not be opened.");
        return 0;  // Unable to open the file
    }

    Book book;
    int found = 0;  // Flag to indicate whether the ISBN is found

    // Read each block of data from the file
    while (fscanf(filePtr, "%13s\n%99[^\n]\n%d\n%d\n",
                  book.ISBN, book.title, &book.totalCopies, &book.copiesAvailable) == 4) {
        if (strcmp(inputISBN, book.ISBN) == 0) {
            found = 1;  // Set the flag to indicate the ISBN is found

            // Print the found book data
            printf("ISBN: %s\n", book.ISBN);
            printf("Title: %s\n", book.title);
            printf("Total Copies: %d\n", book.totalCopies);
            printf("Copies Available: %d\n", book.copiesAvailable);

            break;  // Exit the loop when a match is found
        }
    }

    // Reset file pointer to read the second block of data
    fseek(filePtr, 0, SEEK_SET);

    // Continue reading for the second block of data
    while (fscanf(filePtr, "%13s\n%99[^\n]\n%d\n%d\n",
                  book.ISBN, book.title, &book.totalCopies, &book.copiesAvailable) == 4) {
        if (strcmp(inputISBN, book.ISBN) == 0) {
            found = 1;  // Set the flag to indicate the ISBN is found

            // Print the found book data
            printf("ISBN: %s\n", book.ISBN);
            printf("Title: %s\n", book.title);
            printf("Total Copies: %d\n", book.totalCopies);
            printf("Copies Available: %d\n", book.copiesAvailable);

            break;  // Exit the loop when a match is found
        }
    }

    fclose(filePtr);

    if (!found) {
        printf("Book not found.\n");
    }

    return found;  // Return the flag value
}
