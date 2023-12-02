#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAX_BOOKS 100

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

void borrow_return_details() {
    FILE *borrowPtr;
    FILE *studentPtr;
    FILE *bookPtr;
    FILE *returnPtr;
    Borrow borrow;
    Book book;
    Student std;
    Return r;

    if ((borrowPtr = fopen("Borrow.txt", "r")) == NULL) {
        puts("Error opening Borrow.txt file.");
    }

    if ((studentPtr = fopen("Student.txt", "r")) == NULL) {
        puts("Error opening Student.txt file.");
        fclose(borrowPtr);
    }

    if ((bookPtr = fopen("Books.txt", "r")) == NULL) {
        puts("Error opening Books.txt file.");
        fclose(borrowPtr);
        fclose(studentPtr);
    }

    printf("+====================================+\n");
    printf("\t>>> Borrow Details <<<\n");
    printf("+====================================+\n");
    printf("----------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-20s |\n", "ISBN", "Student ID", "Date of Borrow");
    printf("|----------------------|----------------------|----------------------|\n");

    while (fscanf(borrowPtr, "%s\n%s\n%s\n%s\n", borrow.ID, borrow.ISBN, borrow.currentDate, borrow.toBeReturnDate) == 4) {
            printf("| %-20s | %-20s | %-20s |\n", borrow.ISBN, borrow.ID, borrow.currentDate);
    }    

    puts("----------------------------------------------------------------------\n");

    fclose(borrowPtr);
    fclose(studentPtr);
    fclose(bookPtr);


    printf("+====================================+\n");
    printf("\t>>> Return Details <<<\n");
    printf("+====================================+\n");
    printf("----------------------------------------------------------------------\n");
    printf("| %-20s | %-20s | %-20s |\n", "ISBN", "Student ID", "Date of Return");
    printf("|----------------------|----------------------|----------------------|\n");

    if ((returnPtr = fopen("Return.txt", "r")) == NULL) {
        puts("Error opening Return.txt file.");
    }

    while (fscanf(returnPtr, "%s\n%s\n%s\n%s\n%f\n", r.ID, r.ISBN, r.returnDate, r.toBeReturnDate, &r.penalty) == 5) {
            printf("| %-20s | %-20s | %-20s |\n", r.ISBN, r.ID, r.returnDate);
    }    

    puts("----------------------------------------------------------------------\n");
}

int main () {
    borrow_return_details();
}