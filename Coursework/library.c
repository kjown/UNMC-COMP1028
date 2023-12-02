#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>   

#define MAX_BOOKS 100

// functions to mainMenu user and obtain login details
void mainMenu();
void get_userType();
int getCH();
void studentLogin();
void studentMenu();
void librarianLogin();
void librarianMenu();
void addStudent();

// function for users in studentMenu
void searchBook();
void borrowFunc();
int isBookReturned(const char *inputID, const char *inputISBN);
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
        end();
        break;
    default:
        printf("Invalid input");
        get_userType();
        break;
    }
    getchar();
}

int getCH() {
    int ch;
    // struct to hold the terminal settings
    struct termios old_settings, new_settings;
    // take default setting in old_settings
    tcgetattr(STDIN_FILENO, &old_settings);
    // make of copy of it (Read my previous blog to know 
    // more about how to copy struct)
    new_settings = old_settings;
    // change the settings for by disabling ECHO mode
    // read man page of termios.h for more settings info
    new_settings.c_lflag &= ~(ICANON | ECHO);
    // apply these new settings
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    // now take the input in this mode
    ch = getchar();
    // reset back to default settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    return ch;
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
        char ch;

        printf("Student ID: ");
        scanf("%s", inputID);
        // clear input buffer
        getchar();

        printf("Password: ");
        scanf("%s", inputPassword);
        
        // int i;
        // while ((ch = getCH()) != '\n') {
        //     if (ch == 127 || ch == 8) { // handle backspace
        //         if (i != 0) {
        //             i--;
        //             printf("\b \b");
        //         }
        //     }
        //     else {
        //         inputPassword[i++] = ch;
        //         // echo the '*' to get feel of taking password 
        //         printf("*");
        //     }
        // }
        
        // puts("");

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
    printf("\n+====================================+\n");
    printf("> 1. Book Query\n");
    printf("> 2. Display list of books\n");
    printf("> 3. Calculate penalty for late return\n");
    printf("> 4. Previous Page\n");
    printf("> 5. Exit\n");
    printf("> Enter the number and press ENTER: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        searchBook();
        break;
    case 2: 
        displayList();
        break;
    case 3:
        penalty();
        break;
    case 4:
        mainMenu();
        break;
    case 5:
        end();
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
    int ans;
    int found = 0;

    FILE *bookPtr = NULL;

    if ((bookPtr = fopen("Books.txt", "r")) == NULL) {
        printf("File could not be opened.\n");
    }
    else {
        Book book;
        
        printf("\n+====================================+\n");
        printf("\t>>> Book Search <<<\n");
        printf("+====================================+\n");
        
        printf("ISBN of Book: ");
        scanf("%s", inputISBN);
        getchar();
        
        while (fscanf(bookPtr, "%s\n%[^\n]\n%[^\n]\n%s\n%d\n%d\n", book.ISBN, book.title, book.author, book.year, &book.totalCopies, &book.copiesAvailable) == 6) {
            if (strcmp(inputISBN, book.ISBN) == 0) {
                // Print the found book details
                found = 1;
                printf("ISBN: %s\n", book.ISBN);
                printf("Title: %s\n", book.title);
                printf("Author: %s\n", book.author);
                printf("Year of Publication: %s\n", book.year);
                printf("Total Copies: %d\n", book.totalCopies);
                printf("Copies Available: %d\n", book.copiesAvailable);
                printf("> Enter any character to continue:\n");
                char key = getchar();
                studentMenu();

                // if (book.copiesAvailable > 0) {
                //     printf("\n> Would you like to borrow this book?\n> 1. Yes\n> 2. No\n");
                //     printf("Enter the number and press Enter: ");
                //     scanf("%d", &ans);
                //     switch (ans)
                //     {
                //     case 1:
                //         char *ptr = inputISBN;
                //         borrowFunc(ptr);
                //         break;
                //     case 2:
                //         printf("Search done.\n");
                //         studentMenu();
                //         break;
                //     default:
                //         searchBook();
                //     }
                // }
                // else {
                //     puts("Book is not available.");
                //     searchBook();
                // }
                fclose(bookPtr);
            }
        }
        if (found == 0) {
            printf("Book not found.\n");
            searchBook();
        }
        studentMenu();
    }
}

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


    while (fscanf(bookPtr, "%s\n%[^\n]\n%[^\n]\n%s\n%d\n%d\n", book.ISBN, book.title, book.author, book.year, &book.totalCopies, &book.copiesAvailable) == 6) {
        if (strcmp(borrow.ISBN, book.ISBN) == 0) {
            book.copiesAvailable --;
            fprintf(borrowPtr, "\n\n%s\n%s\n%s\n%s\n", std.ID, borrow.ISBN, borrow.currentDate, borrow.toBeReturnDate);
            printf("You have borrowed:\n%s\n", book.title);
            printf("\nPlease return book by %s.\nFailing to do so will result in a penalty of RM1.00 per late day.\n\n", borrow.toBeReturnDate);
        }
        // place result into file
        fprintf(tempPtr, "%s\n%s\n%s\n%s\n%d\n%d\n\n", book.ISBN, book.title, book.author, book.year, book.totalCopies, book.copiesAvailable);
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

// function to compare the values of str of books to sort displayList in a alphabetical order
int compareBooks(const void *a, const void *b) {
    return strcmp(((Book *)a)->title, ((Book *)b)->title);
}

// display title of books in library, in ascending alphabetical order
void displayList() { // require FILE knowledge
    FILE *bookPtr = NULL;

    // open Books.txt file for reading
    if ((bookPtr = fopen("Books.txt", "r")) == NULL) {
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
    while (fscanf(bookPtr, "%s\n%[^\n]\n%[^\n]\n%s\n%d\n%d\n", books[bookCount].ISBN, books[bookCount].title, books[bookCount].author, books[bookCount].year, &books[bookCount].totalCopies, &books[bookCount].copiesAvailable) == 6) {
        bookCount++;
    }
    
    // close the file
    fclose(bookPtr);

    // Sort the books based on their titles
    qsort(books, bookCount, sizeof(Book), compareBooks);

    printf("| %-20s | %-60s | %-30s | %-20s | %-20s | %-20s |\n", "ISBN", "Title", "Author", "Year of Publication", "Total Copies", "Copies Available");
    // Print out the sorted data
    for (int i = 0; i < bookCount; ++i) {
        printf("| %-20s | %-60s | %-30s | %-20s | %-20d | %-20d |\n", books[i].ISBN, books[i].title, books[i].author, books[i].year, books[i].totalCopies, books[i].copiesAvailable);
    }
    getchar();
    printf("> Enter any key to continue.\n");
    char key = getchar();
    studentMenu();
}

void penalty() { 
    char current_date[11];
    Borrow borrow;
    FILE *borrowPtr = NULL;
    FILE *penPtr = NULL;
    float penalty;

    if (((borrowPtr)  = fopen("Borrow.txt", "r")) == NULL) {
        puts("Error opening Borrow.txt file.");
    }
    if (((penPtr) = fopen("Penalty.txt", "r+")) == NULL) {
        puts("Error opening Penalty.txt file.");
    }


    // Set date to 25/11/2023
    struct tm tm = {0};
    tm.tm_year = 2023 - 1900;   // years since 1900
    tm.tm_mon = 10;     // month is November
    tm.tm_mday = 25;    // Day
    strftime(current_date, 11, "%Y-%m-%d", &tm);

    int rows = 0;
    while (fscanf(borrowPtr, "%s\n%s\n%s\n%s\n", borrow.ID, borrow.ISBN, borrow.currentDate, borrow.toBeReturnDate) == 4) {
        //convert struct tm to time_t (seconds since epoch)
        time_t time1 = mktime(&tm);
        struct tm tm_borrow = {0};
        sscanf(borrow.toBeReturnDate, "%d-%d-%d", &tm_borrow.tm_year, &tm_borrow.tm_mon, &tm_borrow.tm_mday);
        tm_borrow.tm_year -= 1900;
        tm_borrow.tm_mon--;
        time_t time2 = mktime(&tm_borrow);

        // if current_date > borrow.toBeReturnDate
        if (time2 > time1) {
            // calculate difference in seconds
            double difference = difftime(time2, time1);

            // convert seconds to days
            double difference_in_days = difference / (24 * 60 * 60);

            penalty = 1 * difference_in_days;

            fprintf(penPtr, "%s\n%s\n%.2f\n\n", borrow.ID, borrow.ISBN, penalty);
            rows++;
        }
    }

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
    fclose(borrowPtr);
    fclose(penPtr);

    getchar();
    printf("Enter any key to continue.\n");
    char key = getchar();
    studentMenu();
    
}

void librarianMenu() {
    int num;
    
    printf("+====================================+\n");
    printf("\t>>> Librarian Menu <<<                \n");
    printf("+====================================+\n");
    printf("> 1. Book Query\n");
    printf("> 2. Borrow Book\n");
    printf("> 3. Return Book\n");
    printf("> 4. Display list of books\n");
    printf("> 5. Add Books\n");
    printf("> 6. Calculate penalty for late return\n");
    printf("> 7. Borrow and Return Details\n");
    printf("> 8. Generate monthly report\n");
    printf("> 9. Previous Page\n");
    printf("> 10. Exit\n");
    printf("> Enter the number and press ENTER: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        searchBook();
        librarianMenu();
        break;
    case 2:
        borrowFunc();
        librarianMenu();
    case 3:
        returnFunc();
        librarianMenu();
        break;
    case 4: 
        displayList();
        librarianMenu();
        break;
    case 5:
        addBooks();
        librarianMenu();
        break;
    case 6:
        penalty();
        librarianMenu();
        break;
    case 7:
        borrow_return_details();
        librarianMenu();
        break;
    case 8: 
        monthlyReport();
        librarianMenu();
        break;
    case 9: 
        mainMenu();
        break;
    case 10:
        end();
        break;
    default:
        printf("Invalid input.");
        librarianMenu();
        break;
    }
}

void addBooks() { // require FILE knowledge
    FILE *bookPtr = NULL;       // sPtr = Student.txt file pointer

    // fopen opens file; exits program if file cannot be opened
    if ((bookPtr = fopen("Books.txt", "a+")) == NULL) {
        puts("File could not be opened.");
    }
    else {
        Book book;

        printf("Enter ISBN: ");
        scanf("%s", book.ISBN);

        printf("Title: ");
        scanf("%s", book.title);

        printf("Author: ");
        scanf("%s", book.author);

        printf("Year of Publication: ");
        scanf("%s", book.year);

        printf("Total Copies: ");
        scanf("%d", &book.totalCopies);

        printf("Copies Available: ");
        scanf("%d", &book.totalCopies);

        fprintf(bookPtr, "\n\n%s\n%s%s\n%s\n\n%d\n%d", book.ISBN, book.title, book.author, book.year, book.totalCopies, book.copiesAvailable);

        fclose(bookPtr);
    }
    librarianMenu();
}

void borrow_return_details() {
    /* info of books and students who borrow and return the book
       and date of borrow and date of return */
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

    getchar();
    printf("Enter any key to continue.\n");
    char key = getchar();
}

void end() {
    printf("+====================================+\n");
    printf("\t>>> Session Ended <<<                \n");
    printf("\t\tThank you                 \n");
    printf("+====================================+\n");
}

