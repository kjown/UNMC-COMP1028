#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

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

void returnFunc() {
    Student std;
    Book book;
    Borrow borrow;
    Return r;
    FILE *returnPtr = NULL;
    FILE *bookPtr = NULL;
    FILE *borrowPtr = NULL;
    FILE *tempPtr = NULL;
    FILE *tempBorrowPtr = NULL;
    char currentDate[11];
    char returnDate[11];

    // Set date to 25/11/2023
    struct tm tm = {0};
    tm.tm_year = 2023 - 1900;   // years since 1900
    tm.tm_mon = 10;     // month is November
    tm.tm_mday = 25;    // Day

    strftime(r.returnDate, 11, "%Y-%m-%d", &tm);

    // open Books.txt
    if ((bookPtr = fopen("Books.txt", "r")) == NULL) {
        puts("Error opening Books.txt.");
    }

    // open Borrow.txt file
    if ((borrowPtr = fopen("Borrow.txt", "r+")) == NULL) {
        puts("Error opening Borrow.txt.");
    }
    // open Return.txt file
    if ((returnPtr = fopen("Return.txt", "a+")) == NULL) {
        puts("Error opening Return.txt.");
    }
    if ((tempPtr = fopen("Temp.txt", "w")) == NULL ) {
        puts("Error opening Temp.txt");
    }
    printf("+====================================+\n");
    printf("\t>>> Return Page <<<          \n");
    printf("+====================================+\n");
    printf("> Student ID: ");
    scanf("%s", std.ID);
    printf("> ISBN of Book: ");
    scanf("%s", r.ISBN);

    // compare currentDate with returnDate
    while (fscanf(borrowPtr, "%s\n%s\n%s\n%s\n", borrow.ID, book.ISBN, borrow.currentDate, borrow.toBeReturnDate == 4) {
        // if StudentID in Borrow.txt, continue; else, print message
        int penalise = 0;
        if (strcmp(std.ID, borrow.ID) == 0  ) {
            if (strcmp(r.returnDate, borrow.toBeReturnDate) < 0) {
                penalise = 1;
            }
            book.copiesAvailable++;
            // in Books.txt, update copiesAvailable++
            // place result into temporary file Temp.txt
            fprintf(tempPtr, "%s\n%s\n%d\n%d\n\n", book.ISBN, book.title, book.totalCopies, book.copiesAvailable);
        }


        // Replace Books.txt with Temp.txt
        if (remove("Books.txt") != 0) {
            printf("Error deleting original file.\n");
        }
        if (rename("Temp.txt", "Books.txt") != 0) {
            printf("Error renaming Temp.txt file.\n");
        }
        // update Return.txt 
        fprintf(returnPtr, "\n\n%s\n%s\n%s\n%s\n%.2f", r.ID, r.ISBN, r.toBeReturnDate, r.returnDate, r.penalty);
        fclose(returnPtr);

        printf("You have returned:\n%s\n", book.title);
        if (penalise == 1) {
            printf("Late Return\n");
            printf("Please pay the penalty of RM%.2f", r.penalty);
        }
    }

    // close Return.txt
    fclose(returnPtr);

    if (((tempBorrowPtr) = fopen("tempBorrow.txt", "w")) == NULL) {
        puts("Error creating temporary Borrow.txt file.");
    }

    // remove borrow details in Borrow.txt 
    while (fscanf(borrowPtr, "%s\n%s\n%s\n%s\n", borrow.ID, borrow.ISBN, borrow.currentDate, borrow.toBeReturnDate) == 4) {
        if (strcmp(std.ID, borrow.ID) != 0) {
            // if block does not match, put into temp Borrow.txt file
            fprintf(tempBorrowPtr, "%s\n%s\n%s\n%s\n\n", borrow.ID, borrow.ISBN, borrow.currentDate, borrow.toBeReturnDate);
        }
    }
    fclose(bookPtr);
    fclose(tempPtr);

    // close Borrow.txt file
    fclose(borrowPtr);
    fclose(tempBorrowPtr);

    // Replace the original Borrow.txt file with the temporary file
    if (remove("Books.txt") != 0) {
        printf("Error deleting original file.\n");
    }
    if (rename("tempBorrow.txt", "Books.txt") != 0) {
        printf("Error renaming temporaryBorrow.txt file.\n");
    }
}

int main() {
    returnFunc();
    return 0;
}