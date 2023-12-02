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

void monthlyReport() {
    char line[100];
    int num_borrow = 0;
    int in_borrow_block = 0;
    int num_return = 0;
    int in_return_block = 0;
    float total_fine = 0;
    int num_books_to_be_returned;
    Return r;

    FILE *borrowPtr;
    FILE *returnPtr;
    FILE *penPtr;

    if ((borrowPtr = fopen("Borrow.txt", "r")) == NULL) {
        puts("Error opening Borrow.txt.");
    }
    if ((returnPtr = fopen("Return.txt", "r")) == NULL) {
        puts("Error opening Return.txt.");
    }
    if ((penPtr = fopen("Penalty.txt", "r")) == NULL) {
        puts("Error opening Penalty.txt.");
    }

    // count number of books borrowed
    while (fgets(line, sizeof(line), borrowPtr) != NULL) {
        // check if line is empty
        if (line[0] == '\n') {
            in_borrow_block = 0;    // mark end of current block
        }
        else if(!in_borrow_block) {
            // start of new block
            in_borrow_block = 1;
            num_borrow++;
        }
    }
    fclose(borrowPtr);

    // Count the number of books returned and calculate total fines
    while (fscanf(returnPtr, "%s\n%s\n%s\n%s\n%f\n", r.ID, r.ISBN, r.toBeReturnDate, r.returnDate, &r.penalty) == 5) {
        num_return++;
        total_fine += r.penalty;
    }
    fclose(returnPtr);

    num_books_to_be_returned = num_borrow - num_return;

    // num of books borrowed, num of books returned, number of books to be returned, total fines collected in a particular month
    printf("+====================================+\n");
    printf(" >>> Monthly Report November 2023 <<<          \n");
    printf("+====================================+\n");

    // Print the Monthly Report table
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-13s | %-13s | %-10s |\n", "Number of Books Borrowed", "Number of Books Returned", "Number of Books to Be Returned", "Total Fines (RM)");
    printf("|--------------------------|--------------------------|--------------------------------|------------------|\n");
    printf("| %-24d | %-24d | %-30d | %-16.2f |\n", num_borrow, num_return, num_books_to_be_returned, total_fine);
    puts("-----------------------------------------------------------------------------------------------------------\n");

}

int main() {
    monthlyReport();
}