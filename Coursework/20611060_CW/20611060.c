#include <stdio.h>  // library for standard input output
#include <string.h> // contains function for manipulating string
#include <time.h>   // contains definitions of functions to get and manipulate date and time information
#include <stdlib.h> // standard library of C that declares various utility functions for type conversions, memory allocations, algorithms and other similiar use cases
#include <unistd.h>  // defines miscellaneous symbolic constants and types and declares miscellaneous functions

// function prototypes to mainMenu user and obtain login details
void mainMenu(); // function to display the main menu of the Library Management System
void get_userType(); // function to get the user type (Student or Librarian) from user
void studentLogin(); // function to facilitate the student login
void studentMenu(); // function to display the Student Menu
void librarianLogin(); // function to facilitate Librarian login
void librarianMenu(); // function to display librarian menu
void addStudent(); // function to add new student details

// function prototypes for users in studentMenu
void searchBook();  // function for user to search for a book using ISBN
void borrowFunc(); // function for user to borrow books
int isBookReturned(const char *inputID, const char *inputISBN); // function used in returnFunc to check whether book have been returned
void returnFunc(); // function to allow user to return a borrowed book
void penalty(); // to calculate and display the penalty of student with late return
int compareBooks(const void *a, const void *b); // function used in displaylist() to compare the value of books (to compare and sort in alphabetical order)
void displayList(); // function to display all books in alphabetical order

// functions for users in librarianMenu
void borrow_return_details(); //function to show borrow return details
void monthlyReport(); // function to generate monthly report
void addBooks(); // function to add books into the system

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

// struct to store borrow details
typedef struct borrow_details {
    char ID[9]; // studentID
    char ISBN[14]; // ISBN has 13 digits and 4 dashes
    char currentDate[11]; // currentDate of program
    char toBeReturnDate[11]; // returnDate 
} Borrow;

// struct to store return details
typedef struct return_details {
    char ID[9];
    char ISBN[14];
    char toBeReturnDate[11];
    char returnDate[11];
    float penalty;
} Return;

// main function
int main() {
    mainMenu(); // call mainMenu() function

    return 0;
}

// main menu function
void mainMenu() {
    printf("\n\n");
    printf("+====================================+\n");
    printf("                                      \n");
    printf("--------------------------------------\n");
    printf("\tWELCOME TO THE LIBRARY        \n");
    printf("--------------------------------------\n");
    printf("                                      \n");
    printf("+====================================+\n");
    printf("Date: 2023-11-25\n\n");
    
    get_userType();
}
// function to get the type of user (Student/Librarian/New User)
void get_userType(void) {
    int userType;
        printf("+====================================+\n");
        printf("\t>>>  Main Menu <<<          \n");
        printf("+====================================+\n");

    printf("> 1. STUDENT\n");
    printf("> 2. LIBRARIAN\n");
    printf("> 3. NEW USER\n");
    printf("> 4. EXIT\n");
    printf("> Enter number and press ENTER: ");
    scanf("%d", &userType);

    switch (userType)
    {
    case 1:
        studentLogin(); // login as student
        break;
    case 2:
        librarianLogin(); // login as librarian
        break;
    case 3:
        addStudent(); // register new student
        break;
    case 4:
        end();  // exit the program
        break;
    default:
        printf("Invalid input.\n "); // if invalid input, then display error message
        get_userType(); // ask user for user type again
        break;
    }
    getchar(); // clear input buffer
}

void studentLogin() {
    Student std; // struct std
    FILE *sPtr = NULL; // initialise pointer for Student.txt file
    // open Student.txt file
    if ((sPtr = fopen("Student.txt", "r")) == NULL) {
        // if file does not exist, display error message
        printf("File could not be opened.\n");
    }
    else {
        // User interface
        printf("+====================================+\n");
        printf("     >>> Student Login Page <<<          \n");
        printf("+====================================+\n");
        char inputID[9]; // variable to store ID inputted by user
        char inputPassword[11]; // variable to store password inputted by user
        char ch; 

        printf("Student ID: "); // prompt user for student ID
        scanf("%s", inputID); // read and store input student ID
        // clear input buffer
        getchar();

        printf("Password: "); // prompt user to input password
        scanf("%s", inputPassword);

        // Read through each line of the Student.txt file and compare with the user input
        while (fscanf(sPtr, "%8s\n%29[^\n]\n%10s\n", std.ID, std.name, std.password) == 3) {
            if (strcmp(inputID, std.ID) == 0 && strcmp(inputPassword, std.password) == 0) {
                printf("Login Successful!\n");
                fclose(sPtr);
                studentMenu();
            }
            else {
                // if inputID and inputPassword does not match the data in Student.txt, display error message
                printf("Invalid input. Please enter again.\n");
                studentLogin(); // go back to student login page to repeat the process until valid input
            }
        }
    }
}

// function for librarian to login
void librarianLogin() { 
    Librarian lib; // librarian struct
    FILE *lPtr; // Librarian.txt file pointer
    // if file does not exist, display error message
    if ((lPtr = fopen("Librarian.txt", "r")) == NULL) {
        puts("File could not be opened");
    }
    else {
        char inputID[9];
        char inputPassword[11];
        
        // User interface
        printf("+====================================+\n");
        printf("       >>> Staff Login Page <<<            \n");
        printf("+====================================+\n");
        // prompt user for Staff ID
        printf("Staff ID: ");   
        scanf("%s", inputID);
        // prompt user for password
        printf("Password: ");
        scanf("%s", inputPassword);

        // Read through each line of the Student.txt file and compare with the user input
        while (fscanf(lPtr, "%8s\n%29[^\n]\n%10s\n", lib.ID, lib.name, lib.password) == 3) {
            // if input ID and password match, then login is successful
            if (strcmp(inputID, lib.ID) == 0 && strcmp(inputPassword, lib.password) == 0) {
                printf("Login successful.\n");
                fclose(lPtr); // close Librarian.txt 
                librarianMenu(); // proceed to librarian menu
            }
            else {
                // if input is wrong, display error messsage and prompt for input again
                printf("Invalid input. Please enter again.\n");
                librarianLogin();
            }
        }
    }
}
// function to add student
void addStudent() { 
    FILE *sPtr = NULL;       // sPtr = Student.txt file pointer

    // fopen opens file; exits program if file cannot be opened
    if ((sPtr = fopen("Student.txt", "a+")) == NULL) {
        puts("File could not be opened.");
    }
    else {
        Student std;
        // user interface
        printf("\n+====================================+\n");
        printf("       >>> Adding New User <<<            \n");
        printf("+====================================+\n");


        printf("Enter Student ID: ");
        scanf("%s", std.ID);
        getchar(); // clear input buffer

        fflush(stdin); // clear output buffer
        printf("Enter Name: ");
        fgets(std.name, 30, stdin);
        size_t len = strlen(std.name);
        if (len > 0 && std.name[len - 1] == '\n') {
            std.name[len - 1] = '\0'; // Replace newline with null terminator
        }
        printf("Enter Password: ");
        fgets(std.password, 11, stdin);
        // print the inputs into Student.txt
        fprintf(sPtr, "\n\n%s\n%s\n%s", std.ID, std.name, std.password);

        fclose(sPtr); // close Student.txt
    }
    printf("User added successfully.\n");
    get_userType(); // go back to get type of user
}   

// function to display student menu
void studentMenu() {
    int num;
    // user interface
    printf("\n+====================================+\n");
    printf("\t>>> Student Menu <<<");
    printf("\n+====================================+\n");
    printf("> 1. Book Query\n");
    printf("> 2. Display list of books\n");
    printf("> 3. Calculate penalty for late return\n");
    printf("> 4. Logout\n");
    printf("> 5. Exit\n");
    printf("> Enter the number and press ENTER: ");
    scanf("%d", &num);

    switch (num)
    {
    case 1:
        searchBook();
        studentMenu();
        break;
    case 2: 
        displayList();
        studentMenu();
        break;
    case 3:
        penalty();
        studentMenu();
        break;
    case 4:
        mainMenu();
        break;
    case 5:
        end();
        break;
    default:
        printf("Invalid input."); // display error message if input is invalid
        studentMenu(); // go back to student menu
        break;
    }
}

// query on book using ISBN
void searchBook() { 
    char inputISBN[14]; // variable to store ISBN inputted by user
    int ans; 
    int found = 0; // variable to indicate whether book is found or not

    FILE *bookPtr = NULL; // file pointer for Book.txt
    // open Book.txt
    if ((bookPtr = fopen("Books.txt", "r")) == NULL) {
        printf("File could not be opened.\n");
    }
    else {
        Book book;
        // user interface
        printf("\n+====================================+\n");
        printf("\t>>> Book Search <<<\n");
        printf("+====================================+\n");
        
        printf("ISBN of Book: ");
        scanf("%s", inputISBN);
        getchar();
        
        while (fscanf(bookPtr, "%s\n%[^\n]\n%[^\n]\n%s\n%d\n%d\n", book.ISBN, book.title, book.author, book.year, &book.totalCopies, &book.copiesAvailable) == 6) {
            if (strcmp(inputISBN, book.ISBN) == 0) {
                // Print the found book details
                found = 1; // book is found
                // display the details in table form
                printf("| %-20s | %-60s | %-30s | %-20s | %-20s | %-20s |\n", "ISBN", "Title", "Author", "Year of Publication", "Total Copies", "Copies Available");
                printf("| %-20s | %-60s | %-30s | %-20s | %-20d | %-20d |\n", book.ISBN, book.title, book.author, book.year, book.totalCopies, book.copiesAvailable);

                puts("");
                printf("> Enter any character to continue:\n");
                char key = getchar();

                fclose(bookPtr);
            }
        }
        if (found == 0) {
            // display error mesage if book is not found
            printf("Book not found.\n");
            searchBook(); // execute searchBook() again
        }
    }
}

// function for user to borrow book
void borrowFunc() {
    Borrow borrow;
    Student std;
    Book book;
    FILE *borrowPtr = NULL; // file pointer for Borrow.txt
    FILE *bookPtr = NULL; // file pointer for Books.txt
    FILE *tempPtr = NULL; // file pointer for Temporart file

    // Set date to 25/11/2023
    struct tm tm = {0};
    tm.tm_year = 2023 - 1900;   // years since 1900
    tm.tm_mon = 10;     // month is November
    tm.tm_mday = 25;    // Day

    strftime(borrow.currentDate, 11, "%Y-%m-%d", &tm);
    
    // set the return date of books (5 days later)
    tm.tm_mday += 5;
    strftime(borrow.toBeReturnDate, 11, "%Y-%m-%d", &tm);

    // open files
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
    // user interface
    printf("\n+====================================+\n");
    printf("\t>>> Borrow Page <<<          \n");
    printf("+====================================+\n");
    printf("> Please enter Student ID: ");
    scanf("%s", std.ID);
    printf("> Please enter ISBN: ");
    scanf("%s", borrow.ISBN);

    // check whether user Student ID exist and ISBN matches books in database
    while (fscanf(bookPtr, "%s\n%[^\n]\n%[^\n]\n%s\n%d\n%d\n", book.ISBN, book.title, book.author, book.year, &book.totalCopies, &book.copiesAvailable) == 6) {
        if (strcmp(borrow.ISBN, book.ISBN) == 0) {
            if (book.copiesAvailable > 0) {
                book.copiesAvailable --; // decrement copiesAvailable in Books.txt as book is borrowed
                // append the details into Borrow.txt
                fprintf(borrowPtr, "\n\n%s\n%s\n%s\n%s\n", std.ID, borrow.ISBN, borrow.currentDate, borrow.toBeReturnDate);
                printf("You have borrowed:\n%s\n", book.title);
                printf("\nPlease return book by %s.\nFailing to do so will result in a penalty of RM1.00 per late day.\n\n", borrow.toBeReturnDate);
            }
            else {
                printf("Apologies. Book is not available to borrow.\n");
            }
        }
        // place result into file
        fprintf(tempPtr, "%s\n%s\n%s\n%s\n%d\n%d\n\n", book.ISBN, book.title, book.author, book.year, book.totalCopies, book.copiesAvailable);
    }
    fclose(bookPtr); // close Books.txt
    fclose(tempPtr); // close temporary file

    // Replace the original file with the temporary file
    if (remove("Books.txt") != 0) {
        printf("Error deleting original file.\n");
    }
    if (rename("Temp.txt", "Books.txt") != 0) {
        printf("Error renaming temporary file.\n");
    }

    fclose(borrowPtr); // close Borrow.txt
}

// function to check whether books is returned
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

// function to return borrowed book
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
    // append into Return.txt
    fprintf(returnPtr, "\n\n%s\n%s\n%s\n%s\n%.2f", inputID, inputISBN, borrow.toBeReturnDate, r.returnDate, r.penalty);

    fclose(returnPtr); // close Return.txt
    fclose(borrowPtr); // close Borrow.txt

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

    Book books[100];
    int bookCount = 0;
    // user interface
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
    puts("");
    printf("> Enter any key to continue.\n");
    char key = getchar();
}

// function to calculate penalty for late return
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
    if (((returnPtr) = fopen("Return.txt", "r+")) == NULL) {
        puts("Error opening Return.txt file.");
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
        
        
        int returned = 0;  // Flag to check if the book has been returned

        rewind(returnPtr);  // Move the file pointer to the beginning of return.txt for each borrow entry

        while (fscanf(returnPtr, "%s\n%s\n%s\n%s\n%f\n", r.ID, r.ISBN, r.toBeReturnDate, r.returnDate, &r.penalty) == 5) {
            // Check if the current borrow entry matches a return entry
            if (strcmp(borrow.ID, r.ID) == 0 && strcmp(borrow.ISBN, r.ISBN) == 0) {
                returned = 1;  // Set the flag to indicate the book has been returned
                break;  // Exit the inner loop since we found a match
            }
    }

        // If the book has not been returned, calculate the penalty
        if (!returned) {
            // Check if current_date > borrow.toBeReturnDate
            if (time2 < time1) {
                // Calculate difference in seconds
                double difference = difftime(time1, time2);

                // Convert seconds to days
                double difference_in_days = difference / (24 * 60 * 60);

                penalty = 1 * difference_in_days;
                // append into Penalty.txt
                fprintf(penPtr, "%s\n%s\n%.2f\n\n", borrow.ID, borrow.ISBN, penalty);
                rows++;
            }
        }
    }
    rewind(penPtr); // reset the pointer in Penalty.txt
    // user interface
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
}

// function to display librarian menu
void librarianMenu() {
    int num;
    // user interface
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
    printf("> 9. Logout\n");
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
        printf("Invalid input.\n");
        librarianMenu();
        break;
    }
}

// function to add book
void addBooks() { 
    FILE *bookPtr = NULL;       // sPtr = Student.txt file pointer

    // fopen opens file; exits program if file cannot be opened
    if ((bookPtr = fopen("Books.txt", "a")) == NULL) {
        puts("File could not be opened.");
    }
    else {
        Book book;
        // user interface
        printf("+====================================+\n");
        printf("\t>>> Add Book <<<\n");
        printf("+====================================+\n");

        printf("Enter ISBN: ");
        getchar();
        scanf("%13s", book.ISBN);

        printf("Title: ");
        getchar();
        scanf("%199[^\n]", book.title);

        printf("Author: ");
        getchar();
        scanf("%49[^\n]", book.author);

        printf("Year of Publication: ");
        getchar();
        scanf("%4s", book.year);

        printf("Total Copies: ");
        getchar();
        scanf("%d", &book.totalCopies);

        printf("Copies Available: ");
        getchar();
        scanf("%d", &book.copiesAvailable);


        // append details into Books.txt
        fprintf(bookPtr, "\n\n%s\n%s\n%s\n%s\n%d\n%d", book.ISBN, book.title, book.author, book.year, book.totalCopies, book.copiesAvailable);
        // fflush(bookPtr);
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
    // display details in table form
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
    getchar(); // clear input buffer
    printf("Enter any key to continue: ");
    char key = getchar();
    puts("");
}

// function to generate monthly report
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
    printf("\n+====================================+\n");
    printf(" >>> Monthly Report November 2023 <<<          \n");
    printf("+====================================+\n");

    // Print the Monthly Report table
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-13s | %-13s | %-10s |\n", "Number of Books Borrowed", "Number of Books Returned", "Number of Books to Be Returned", "Total Fines Collected(RM)");
    printf("|--------------------------|--------------------------|--------------------------------|---------------------------|\n");
    printf("| %-24d | %-24d | %-30d | %-25.2f |\n", num_borrow, num_return, num_books_to_be_returned, total_fine);
    puts("--------------------------------------------------------------------------------------------------------------------\n");

    getchar();
    printf("Enter any key to continue.\n");
    char key = getchar();
}

// function to end the program
void end() {
    printf("+====================================+\n");
    printf("\t>>> Session Ended <<<                \n");
    printf("\t      Thank you                 \n");
    printf("+====================================+\n");
    exit(1);
}

