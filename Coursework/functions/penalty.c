#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_BOOKS 100

// functions to mainMenu user and obtain login details
void mainMenu();
void get_userType();
void studentLogin();
void studentMenu();
void librarianLogin();
void librarianMenu();
void addStudent();

// function for users in studentMenu
void searchBook();
void borrowFunc(char *ptr);
void returnFunc();
void penalty();
int compareBooks(const void *a, const void *b);
void displayList();

// functions for users in librarianMenu
void borrow_return_details();
void monthlyReport();
void addBooks();

void end();

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

void penalty() {    
    char current_date[11];
    Borrow borrow;
    Return r;
    FILE *borrowPtr = NULL;
    FILE *penPtr = NULL;
    FILE *returnPtr = NULL;
    float penalty;

    if (((borrowPtr)  = fopen("Borrow.txt", "r")) == NULL) {
        puts("Error opening Borrow.txt file.");
    }
    if (((penPtr) = fopen("Penalty.txt", "r+")) == NULL) {
        puts("Error opening Penalty.txt file.");
    }
    if (((returnPtr) = fopen("Return.txt", "r")) == NULL) {
        puts("Error opening Return.txt file.");
    }


    // Set date to 25/11/2023
    struct tm tm = {0};
    tm.tm_year = 2023 - 1900;   // years since 1900
    tm.tm_mon = 10;     // month is November
    tm.tm_mday = 25;    // Day
    strftime(current_date, 11, "%Y-%m-%d", &tm);

    int rows = 0;

    while (fscanf(borrowPtr, "%s\n%s\n%s\n%s\n", borrow.ID, borrow.ISBN, borrow.currentDate, borrow.toBeReturnDate) == 4 && fscanf(returnPtr, "%s\n%s\n%s\n%s\n%f\n", r.ID, r.ISBN, r.toBeReturnDate, r.toBeReturnDate, &r.penalty) == 5) {
        if (strcmp(borrow.ID, r.ID) == 0 && strcmp(borrow.ISBN, r.ISBN) == 0) {
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

                penalty = 1 * difference_in_days;

                fprintf(penPtr, "%s\n%s\n%.2f\n\n", borrow.ID, borrow.ISBN, penalty);
                rows++;
            }
        }
    }
    fclose(borrowPtr);
    rewind(penPtr);

    printf("+====================================+\n");
    printf("\t>>> Penalty Page <<<          \n");
    printf("+====================================+\n");

    // display the Penalty details
    while (fscanf(penPtr, "%s\n%s\n%f\n", borrow.ID, borrow.ISBN, &penalty) == 3) {
        // Print the header for each block
        printf("----------------------------------------------\n");
        printf("| %-10s | %-13s | %-10s  |\n", "Student ID", "ISBN", "Penalty (RM)");
        printf("|------------|---------------|---------------|\n");

        // Display the contents of each block
        printf("| %-10s | %-13s | %-10.2f    |\n", borrow.ID, borrow.ISBN, penalty);

        // Consume the empty line
        fscanf(penPtr, "\n");
    }
    puts("----------------------------------------------");
    //fclose(borrowPtr);
    fclose(penPtr);
}   

int main() {
    penalty();
}