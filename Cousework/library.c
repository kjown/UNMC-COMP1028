#include <stdio.h>

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
void borrowFunc();
void returnFunc();
void penalty();
void displayList();

// functions for users in librarianMenu
void borrow_return_details();
void monthlyReport();
void addBooks();

// struct to store student details
typedef struct student_details {
    int ID;
    char name[30];
    char password[10];
}Student;

typedef struct librarian_details {
    int ID;
    char name[30];
    char password[10];
}Librarian;

// struct to store book details
typedef struct book {
    char ISBN[18]; // ISBN has 13 digits and 4 dashes
    char title[200];
    int copiesAvailable;
    int totalCopies;

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
    printf("> Enter number and hit ENTER: ");
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
    default:
        printf("Invalid input");
        get_userType();
        break;
    }
}

void studentLogin() { // require FILE knowledge
    Student std;

    // User interface
    printf("+====================================+\n");
    printf("\t>>> Student Login Page <<<\n");
    printf("+====================================+\n");
    
    // requires ID as username
    printf("Student ID: ");
    scanf("%s", std.ID);

    Student *stdPtr = &std;

    // if username does not match those in files, prompt again  
    while (1) {
        if (std.ID != ) { // compare with names in student details file
            printf("User does not exist. Please enter again.");
            printf("Name: ");
            scanf("%d", std.ID);
        }
        else {
            break;
        }
    }
    // ask for password 
    printf("Password: ");
    scanf("%s", std.password);
    // if password wrong, prompt again
    while (1) {
        if (std.password != ) {
            printf("Password incorrect. Please enter again.");
            printf("Password: ");
            scanf("%s", std.password);
        }
        else {
            break;
        }
    }
    studentMenu();
}

void librarianLogin() { // require FILE knowledge
    Librarian lib;
    
    // User interface
    printf("+====================================+\n");
    printf("\t>>> Staff Login Page <<<\n");
    printf("+====================================+\n");

    // requires ID as username
    printf("Staff ID: ");
    scanf("%d", lib.ID);
    // if username does not match those in files, prompt again
    while (1) {
        if (lib.name != ) {
            printf("User does not exist. Please enter again.");
            printf("Staff ID: ");
            scanf("%d", lib.ID);
        }
        else {
            break;
        }
    }
    // prompt for password
    printf("Password: ");
    scanf("%d", lib.password);
    // if password wrong, prompt again
    while (1) {
        if (lib.password != ) {
            printf("Incorrect password. Please enter again.");
            printf("Password: ");
            scanf("%d", lib.password);
        }
        else {
            break;
        }
    }
    librarianMenu();
}

void addStudent() { // require FILE knowledge

}

void studentMenu() {
    int num;

    printf("+====================================+\n");
    printf("\t>>> Student Menu <<<");
    printf("+====================================+\n");
    printf("> 1. Book Query and Borrow");
    printf("> 2. Return Book");
    printf("> 3. Display list of books");
    printf("> 4. Calculate penalty for late return");
    printf("> 5. Previous Page");
    printf("Enter the number and press ENTER: ");
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
    default:
        printf("Invalid input.");
        studentMenu();
        break;
    }
}

// query on book using ISBN
void searchBook() { // require FILE knowledge
    // display title

    // display author

    // display ISBN

    // year

    // no. of copies available

    // total copies

    // IF copiesAvailable > 0, ask user whether want to borrow
        // If 1, call borrowFunc

        // ELSE, studentMenu() #go back to previous page
        
    // ELSE, tell user book is not available to borrow


}

// display title of books in library, in ascending alphabetical order
void displayList() { // require FILE knowledge

}

void penalty() { 

}

void librarianMenu() {
    int num;
    
    printf("+====================================+\n");
    printf(">>> Librarian Menu <<<");
    printf("+====================================+\n");
    printf("> 1. Book Query and Borrow");
    printf("> 2. Return Book");
    printf("> 3. Display list of books");
    printf("> 4. Add Books");
    printf("> 5. Calculate penalty for late return");
    printf("> 6. Borrow and Return Details");
    printf("> 7. Generate monthly report");
    printf("> 8. Previous Page");
    printf("Enter the number and press ENTER: ");
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
    default:
        printf("Invalid input.");
        librarianMenu();
        break;
    }
}

void addBooks() { // require FILE knowledge
    
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