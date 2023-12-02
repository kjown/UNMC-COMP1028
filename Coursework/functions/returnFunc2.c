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
    char author[50];
    char year[5];
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

int isBookReturned(const char *inputID, const char *inputISBN) {
    FILE *returnPtr = fopen("Return.txt", "r");
    Return r;

    while (fscanf(returnPtr, "%s\n%s\n%s\n%s\n%f\n", r.ID, r.ISBN, r.toBeReturnDate, r.returnDate, &r.penalty) == 5) {
        if (strcmp(inputID, r.ID) == 0 && strcmp(inputISBN, r.ISBN) == 0) {
            fclose(returnPtr);
            return 1; // Book already returned
        }
    }

    fclose(returnPtr);
    return 0; // Book not yet returned
}

void returnFunc() {
    FILE *borrowPtr = NULL;
    FILE *bookPtr = NULL;
    FILE *returnPtr = NULL;
    FILE *tempBookPtr = NULL;
    Return r;
    Student std;
    Borrow borrow;
    Book book;
    char inputISBN[14];
    char inputID[9];
    
    // Set current Date to 25/11/2023
    struct tm tm = {0};
    tm.tm_year = 2023 - 1900;   // years since 1900
    tm.tm_mon = 10;     // month is November
    tm.tm_mday = 25;    // Day

    strftime(r.returnDate, 11, "%Y-%m-%d", &tm);

    // User interface
    printf("+====================================+\n");
    printf("\t>>> Return Page <<<          \n");
    printf("+====================================+\n");
    // prompt user for input ID and ISBN
    printf("> Student ID: ");
    scanf("%s", inputID);
    printf("> ISBN of Book: ");
    scanf("%s", inputISBN);

    
    // open Borrow.txt file
    if ((borrowPtr = fopen("Borrow.txt", "r+")) == NULL) {
        puts("Error opening Borrow.txt.");
    }
    if ((bookPtr = fopen("Books.txt", "r+")) == NULL) {
        puts("Error opening Books.txt.");
    }

    // open tempBook.txt file
    if ((tempBookPtr = fopen("tempBook.txt", "w")) == NULL) {
        puts("Error opening tempBook.txt file.");
    }
    
    // open Return.txt
    if ((returnPtr = fopen("Return.txt", "a")) == NULL) {
        puts("Error opening Return.txt file.");
    }

    // Check if the book has already been returned
    if (isBookReturned(inputID, inputISBN)) {
        printf("Book already returned.\n");
        return;
    }

    // compare input ID & ISBN with borrow.ID & borrow.ISBN, if match book.copiesAvailable++ and update Books.txt file
    while (fscanf(borrowPtr, "%s\n%[^\n]\n%s\n%s\n", borrow.ID, borrow.ISBN, borrow.currentDate, borrow.toBeReturnDate) == 4) {
        if (strcmp(inputID, borrow.ID) == 0 && strcmp(inputISBN, borrow.ISBN) == 0) {
            // Read all book details before updating
            while (fscanf(bookPtr, "%s\n%[^\n]\n%[^\n]\n%s\n%d\n%d\n", book.ISBN, book.title, book.author, book.year, &book.totalCopies, &book.copiesAvailable) == 6) {
                if (strcmp(inputISBN, book.ISBN) == 0) {
                    // Update copiesAvailable
                    book.copiesAvailable++;
                }
                // Write all book details to tempBook.txt
                fprintf(tempBookPtr, "%s\n%s\n%s\n%s\n%d\n%d\n\n", book.ISBN, book.title, book.author, book.year, book.totalCopies, book.copiesAvailable);
            }
        }

    }

    fclose(tempBookPtr);

    // update details in Books.txt file

    // replace Books.txt with tempBook.txt
    if (remove("Books.txt") != 0) {
        printf("Error deleting original Books.txt file.\n");
    }
    if (rename("tempBook.txt", "Books.txt") != 0) {
        printf("Error renaming tempBook.txt file.\n");
    }
    fclose(bookPtr);

    // add details in Return.txt

    // calculate penalty
    //convert struct tm to time_t (seconds since epoch)
    time_t time1 = mktime(&tm);
    struct tm tm_borrow = {0};
    sscanf(borrow.toBeReturnDate, "%d-%d-%d", &tm_borrow.tm_year, &tm_borrow.tm_mon, &tm_borrow.tm_mday);
    tm_borrow.tm_year -= 1900;
    tm_borrow.tm_mon--;
    time_t time2 = mktime(&tm_borrow);

    // if current_date > borrow.toBeReturnDate
    if (time1 > time2) {
        // calculate difference in seconds
        double difference = difftime(time1, time2);

        // convert seconds to days
        double difference_in_days = difference / (24 * 60 * 60);

        r.penalty = 1 * difference_in_days;
    }
    fprintf(returnPtr, "\n\n%s\n%s\n%s\n%s\n%.2f", inputID, inputISBN, borrow.toBeReturnDate, r.returnDate, r.penalty);

    fclose(returnPtr);
    fclose(borrowPtr);

    printf("Book successfully returned!\n");

}



int main() {
    returnFunc();
    return 0;
}