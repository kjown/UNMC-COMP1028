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

// struct to store books details
typedef struct books {
    char ISBN[14]; // ptr has 13 digits and 4 dashes
    char title[200];
    int totalCopies;
    int copiesAvailable;

}Books;

typedef struct borrow {
    char ID[9];
    char ptr[14];
    char borrow_date[10];
    char return_date[10];
} Borrow;

void borrowFunc(char *ptr);

int main() {
    char inputISBN[14] = "12345";       // 
    char *ptr = inputISBN;
    Student std = {1};
    Student *stdPtr = &std;

    borrowFunc(ptr);
}  

void borrowFunc(char *ptr) {
    Borrow borrow;
    Student std;
    Books book;
    FILE *borrowPtr = NULL;
    FILE *bookPtr = NULL;
    FILE *tempPtr = NULL;
    char currentDate[11];
    char returnDate[11];

    // Set date to 25/11/2023
    struct tm tm = {0};
    tm.tm_year = 2023 - 1900;   // years since 1900
    tm.tm_mon = 10;     // month is November
    tm.tm_mday = 25;    // Day

    strftime(currentDate, 11, "%Y-%m-%d", &tm);
    
    // set the return date of books (5 days later)
    tm.tm_mday += 5;
    strftime(returnDate, 11, "%Y-%m-%d", &tm);

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

    while (fscanf(bookPtr, "%s\n%[^\n]\n%d\n%d\n", book.ISBN, book.title, &book.totalCopies, &book.copiesAvailable) == 4) {
        if (strcmp(ptr, book.ISBN) == 0) {
            book.copiesAvailable --;
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

    // update Borrow.txt file
    printf("+====================================+\n");
    printf("\t>>> Borrow Page <<<          \n");
    printf("+====================================+\n");
    printf("> Please enter ID: ");
    scanf("%s", std.ID);

    fprintf(borrowPtr, "\n\n%s\n%s\n%s\n%s\n", std.ID, ptr, currentDate, returnDate);
    fclose(borrowPtr);

    puts("Book borrowed successfully.");
}