#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// struct to store student details
typedef struct student_details {
    char ID[9];
    char name[30];
    char password[11];
}Student;

typedef struct librarian_details {
    char ID[9];
    char name[30];
    char password[11];
}Librarian;


// struct to store book details
typedef struct book {
    char ISBN[14]; // ISBN has 13 digits and 4 dashes
    char title[200];
    int totalCopies;
    int copiesAvailable;

}Book;

typedef struct borrow_details {
    char ID[9]; // studentID
    char ISBN[14]; // ISBN has 13 digits and 4 dashes
    char currentDate[11]; // currentDate of program
    char toBeReturnDate[11]; // returnDate 
} Borrow;

typedef struct return_details {
    char ID[9];
    char ISBN[14];
    char toBeReturnDate[11];
    char returnDate[11];
    float penalty;
} Return;
 

void borrowFunc() {
    Borrow borrow;
    Student std;
    Book book;
    FILE *borrowPtr = NULL;
    FILE *bookPtr = NULL;
    FILE *tempPtr = NULL;

    // Set date to 25/11/2023
    struct tm tm = {0};
    tm.tm_year = 2023 - 1900;   // years since 1900
    tm.tm_mon = 10;     // month is November
    tm.tm_mday = 25;    // Day

    strftime(borrow.currentDate, 11, "%Y-%m-%d", &tm);
    
    // set the return date of books (5 days later)
    tm.tm_mday += 5;
    strftime(borrow.toBeReturnDate, 11, "%Y-%m-%d", &tm);

    // update the Books.txt file
    if (((bookPtr) = fopen("Books.txt", "r+")) == NULL) {
        puts("File could not be opened.");
    }
    if (((tempPtr) = fopen("Temp.txt", "w")) == NULL) {
        puts("Error creating temporary file.");
        fclose(bookPtr);
    }
    if (((borrowPtr) = fopen("Borrow.txt", "a+")) == NULL) {
        puts("Error opening Borrow.txt file.");
        fclose(bookPtr);
    }    

    // update Borrow.txt file
    printf("\n+====================================+\n");
    printf("\t>>> Borrow Page <<<          \n");
    printf("+====================================+\n");
    printf("> Please enter Student ID: ");
    scanf("%s", std.ID);
    printf("> Please enter ISBN: ");
    scanf("%s", borrow.ISBN);


    while (fscanf(bookPtr, "%s\n%[^\n]\n%d\n%d\n", book.ISBN, book.title, &book.totalCopies, &book.copiesAvailable) == 4) {
        if (strcmp(borrow.ISBN, book.ISBN) == 0) {
            book.copiesAvailable --;
            fprintf(borrowPtr, "\n\n%s\n%s\n%s\n%s\n", std.ID, borrow.ISBN, borrow.currentDate, borrow.toBeReturnDate);
            printf("You have borrowed:\n%s\n", book.title);
            printf("\nPlease return book by %s.\nFailing to do so will result in a penalty of RM1.00 per late day.\n\n", borrow.toBeReturnDate);
        }
        // place result into file
        fprintf(tempPtr, "%s\n%s\n%d\n%d\n\n", book.ISBN, book.title, book.totalCopies, book.copiesAvailable);
    }
    fclose(bookPtr);
    fclose(tempPtr);

    // Replace the original file with the temporary file
    if (remove("Books.txt") != 0) {
        printf("Error deleting original file.\n");
    }
    if (rename("Temp.txt", "Books.txt") != 0) {
        printf("Error renaming temporary file.\n");
    }

    fclose(borrowPtr);
}

int main() {
    borrowFunc();
}