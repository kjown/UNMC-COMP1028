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

void returnFunc() {
    
}

int main() {

}

