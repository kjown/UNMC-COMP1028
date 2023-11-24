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

void exit();

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

int main() {
    mainMenu();

    return 0;
}

void mainMenu() {
    printf("\n\n");
    printf("+====================================+\n");
    printf("                                      \n");
    printf("--------------------------------------\n");
    printf("\tWELCOME TO THE LIBRARY        \n");
    printf("--------------------------------------\n");
    printf("                                      \n");
    printf("+====================================+\n\n");
    get_userType();
}

void get_userType(void) {
    int userType;
    printf("> 1. STUDENT\n");
    printf("> 2. LIBRARIAN\n");
    printf("> 3. NEW USER\n");
    printf("> 4. EXIT\n");
    printf("> Enter number and press ENTER: ");
    scanf("%d", &userType);

    switch (userType)
    {
    case 1:
        studentLogin();
        break;
    case 2:
        librarianLogin();
        break;
    case 3:
        addStudent();
        break;
    case 4:
        exit();
        break;
    default:
        printf("Invalid input");
        get_userType();
        break;
    }
}

void studentLogin() { // require FILE knowledge
    Student std;
    FILE *sPtr = NULL;

    if ((sPtr = fopen("Student.txt", "r")) == NULL) {
        printf("File could not be opened.\n");
    }
    else {
        // User interface
        printf("+====================================+\n");
        printf("\t>>> Student Login Page <<<          \n");
        printf("+====================================+\n");
        Student std;
        char inputID[9];
        char inputPassword[11];

        printf("Student ID: ");
        scanf("%s", inputID);

        printf("Password: ");
        scanf("%s", inputPassword);

        // Read through each line of the Student.txt file and compare with the user input
        while (fscanf(sPtr, "%8s\n%29[^\n]\n%10s\n", std.ID, std.name, std.password) == 3) {
            if (strcmp(inputID, std.ID) == 0 && strcmp(inputPassword, std.password) == 0) {
                printf("Login Successful!\n");
                fclose(sPtr);
                studentMenu();
            }
            else {
                printf("Invalid input. Please enter again.\n");
                studentLogin();
            }
        }
    }
}

void librarianLogin() { // require FILE knowledge
    Librarian lib;
    FILE *lPtr = fopen("Librarian.txt", "r");

    if ((lPtr = fopen("Librarian.txt", "r")) == NULL) {
        puts("File could not be opened");
    }
    else {
        Librarian lib;
        char inputID[9];
        char inputPassword[11];
        
        // User interface
        printf("+====================================+\n");
        printf("\t>>> Staff Login Page <<<            \n");
        printf("+====================================+\n");
        
        printf("Staff ID: ");
        scanf("%s", inputID);

        printf("Password: ");
        scanf("%s", inputPassword);

        // Read through each line of the Student.txt file and compare with the user input
        while (fscanf(lPtr, "%8s\n%29[^\n]\n%10s\n", lib.ID, lib.name, lib.password) == 3) {
            if (strcmp(inputID, lib.ID) == 0 && strcmp(inputPassword, lib.password) == 0) {
                printf("Login successful.\n");
                fclose(lPtr);
                librarianMenu();
            }
            else {
                printf("Invalid input. Please enter again.\n");
                librarianLogin();
            }
        }
    }
}

void addStudent() { // require FILE knowledge
    FILE *sPtr = NULL;       // sPtr = Student.txt file pointer

    // fopen opens file; exits program if file cannot be opened
    if ((sPtr = fopen("Student.txt", "a+")) == NULL) {
        puts("File could not be opened.");
    }
    else {
        Student std;

        printf("Enter Student ID: ");
        scanf("%s", std.ID);

        printf("Enter Name: ");
        scanf("%s", std.name);

        printf("Enter Password: ");
        scanf("%s", std.password);

        fprintf(sPtr, "\n\n%s\n%s\n%s", std.ID, std.name, std.password);

        fclose(sPtr);
    }
    get_userType();
}   

void studentMenu() {
    int num;

    printf("+====================================+\n");
    printf("\t>>> Student Menu <<<");
    printf("+====================================+\n");
    printf("> 1. Book Query and Borrow\n");
    printf("> 2. Return Book\n");
    printf("> 3. Display list of books\n");
    printf("> 4. Calculate penalty for late return\n");
    printf("> 5. Previous Page\n");
    printf("> 6. Exit\n");
    printf("> Enter the number and press ENTER: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        searchBook();
        break;
    case 2:
        returnFunc();
        break;
    case 3: 
        displayList();
        break;
    case 4:
        penalty();
        break;
    case 5:
        mainMenu();
        break;
    case 6:
        exit();
        break;
    default:
        printf("Invalid input.");
        studentMenu();
        break;
    }
}

// query on book using ISBN
void searchBook() { // require FILE knowledge
    char inputISBN[14];
    char ans;
    int found = 0;

    FILE *bPtr = NULL;

    if ((bPtr = fopen("Books.txt", "r")) == NULL) {
        printf("File could not be opened.\n");
    }
    else {
        Book book;
        
        printf("+====================================+\n");
        printf("\t>>> Book Search <<<\n");
        printf("+====================================+\n");
        
        printf("ISBN of Book: ");
        scanf("%s", inputISBN);
        
        while (fscanf(bPtr, "%s\n%[^\n]\n%d\n%d\n", book.ISBN, book.title, &book.totalCopies, &book.copiesAvailable) == 4) {
            if (strcmp(inputISBN, book.ISBN) == 0) {
                // Print the found book details
                found = 1;
                printf("ISBN: %s\n", book.ISBN);
                printf("Title: %s\n", book.title);
                printf("Total Copies: %d\n", book.totalCopies);
                printf("Copies Available: %d\n", book.copiesAvailable);
                if (book.copiesAvailable > 0) {
                    printf("\n> Would you like to borrow this book?\n> 1. Yes\n> 2. No\n");
                    scanf("%c", &ans);
                    switch (ans)
                    {
                    case 1:
                        char *ptr = inputISBN;
                        borrowFunc(ptr);
                        break;
                    case 2:
                        printf("Search done.\n");
                        studentMenu();
                        break;
                    default:
                        searchBook();
                    }
                }
                else {
                    puts("Book is not available.");
                    studentMenu();
                }
                fclose(bPtr);
            }
        }
        if (found != 0) {
            printf("Book not found.\n");
            searchBook();
        }
    }
}

void borrowFunc(char *ptr) {
    Student std;
    Book book;
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

void returnFunc() {
    // copiesAvailable ++

    // update borrow_return_detals
    
}

// function to compare the values of str of books to sort displayList in a alphabetical order
int compareBooks(const void *a, const void *b) {
    return strcmp(((Book *)a)->title, ((Book *)b)->title);
}

// display title of books in library, in ascending alphabetical order
void displayList() { // require FILE knowledge
    FILE *bPtr = NULL;

    // open Books.txt file for reading
    if ((bPtr = fopen("Books.txt", "r")) == NULL) {
        printf("File could not be opened.\n");
    }

    Book books[MAX_BOOKS];
    int bookCount = 0;

    printf("+====================================+\n");
    printf("\t>>> Book List <<<\n");
    printf("+====================================+\n");
    
    // read each line from file into entry
    int blockCount = 0;
    
    // sort the data in Book.txt using alphabetical order
    while (fscanf(bPtr, "%s\n%[^\n]\n%d\n%d\n", books[bookCount].ISBN, books[bookCount].title, &books[bookCount].totalCopies, &books[bookCount].copiesAvailable) == 4) {
        bookCount++;
    }
    
    // close the file
    fclose(bPtr);

    // Sort the books based on their titles
    qsort(books, bookCount, sizeof(Book), compareBooks);

    // Print out the sorted data
    for (int i = 0; i < bookCount; ++i) {
        printf("ISBN: %s\nTitle: %s\nTotal Copies: %d\nCopies Available: %d\n\n",
               books[i].ISBN,
               books[i].title,
               books[i].totalCopies,
               books[i].copiesAvailable);
    }
}

void penalty() { 

}

void librarianMenu() {
    int num;
    
    printf("+====================================+\n");
    printf("\t>>> Librarian Menu <<<                \n");
    printf("+====================================+\n");
    printf("> 1. Book Query and Borrow");
    printf("> 2. Return Book");
    printf("> 3. Display list of books\n");
    printf("> 4. Add Books\n");
    printf("> 5. Calculate penalty for late return\n");
    printf("> 6. Borrow and Return Details\n");
    printf("> 7. Generate monthly report\n");
    printf("> 8. Previous Page\n");
    printf("> 9. Exit\n");
    printf("> Enter the number and press ENTER: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        searchBook();
        break;
    case 2:
        returnFunc();
        break;
    case 3: 
        displayList();
        break;
    case 4:
        addBooks();
        break;
    case 5:
        penalty();
        break;
    case 6:
        borrow_return_details();
        break;
    case 7: 
        monthlyReport();
        break;
    case 8: 
        mainMenu();
        break;
    case 9:
        exit();
        break;
    default:
        printf("Invalid input.");
        librarianMenu();
        break;
    }
}

void addBooks() { // require FILE knowledge
    FILE *bPtr = NULL;       // sPtr = Student.txt file pointer

    // fopen opens file; exits program if file cannot be opened
    if ((bPtr = fopen("Books.txt", "a+")) == NULL) {
        puts("File could not be opened.");
    }
    else {
        Book book;

        printf("Enter ISBN: ");
        scanf("%s", book.ISBN);

        printf("Title: ");
        scanf("%s", book.title);

        printf("Total Copies: ");
        scanf("%d", book.totalCopies);

        printf("Copies Available: ");
        scanf("%d", book.totalCopies);

        fprintf(bPtr, "\n\n%s\n%s\n%d\n%d", book.ISBN, book.title, book.totalCopies, book.copiesAvailable);

        fclose(bPtr);
    }
    librarianMenu();
}

void borrow_return_details() {
    /* info of books and students who borrow and return the book
       and date of borrow and date of return */

}

void monthlyReport() {
    // display no. of books borrowed

    // display no. of books returned

    // display no. of books TO BE returned

    // display total fines collected

}

void exit() {
    printf("+====================================+\n");
    printf("\t>>> Session Ended <<<                \n");
    printf("\tThank you                 \n");
    printf("+====================================+\n");
}