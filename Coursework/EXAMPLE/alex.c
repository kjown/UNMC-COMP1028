#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct book {
    char title[100];
    char author[100];
    char ISBN[20];
    int yearOfPublication;
    int availableCopies;
    int totalCopies;
};

struct identity {
    int id;
    char name[100];
    char password[20];
};

struct borrowAndReturn {
    char bookISBN[20];
    int studentID;
    time_t borrowDate;
    time_t returnDate;
};

void updateDatabase(struct borrowAndReturn transactions);
void loadDatabase(struct borrowAndReturn transactions[], int *numTransactions);
void start(char userType[]);
void librarianMenu(struct book books[], int numBooks, struct identity students[], int numStudents, struct borrowAndReturn transactions[], int *numTransactions);
void studentMenu(struct book books[], int numBooks, struct identity students[], int studentID, struct borrowAndReturn transactions[], int *numTransactions, int numStudents);
void searchBook(struct book books[], int numBooks);
void borrowBook(struct book books[], int numBooks, struct identity students[], int numStudents, struct borrowAndReturn transactions[], int *numTransactions);
void returnBook(struct book books[], int numBooks, struct identity students[], int numStudents, struct borrowAndReturn transactions[], int *numTransactions);
void listBooks(struct book books[], int numBooks);
void calculatePenalty(struct borrowAndReturn transactions[], int numTransactions, struct identity students[], int numStudents);
void monthlyReport(struct borrowAndReturn transactions[], int numTransactions);

int main() {
    struct book books[10];
    struct identity students[10];
    struct borrowAndReturn transactions[100];
    int numTransactions = 0;

    loadDatabase(transactions, &numTransactions);

    FILE *booksFile = fopen ("books.txt", "r");
    if (booksFile == NULL) {
        fprintf(stderr, "Error opening books file.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < 10; i++) {
        fscanf(booksFile, "%[^\n]\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n\n", books[i].title, books[i].author,books[i].ISBN,
                   &books[i].yearOfPublication, &books[i].availableCopies, &books[i].totalCopies);
    }

    fclose(booksFile);

    FILE *studentsFile = fopen("students.txt", "r");
    if (studentsFile == NULL) {
        fprintf(stderr, "Error opening students file. \n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; i++) {
    fscanf(studentsFile, "\n%d%[^\n]\n", &students[i].id, students[i].name);
    }

    fclose(studentsFile);

    while(1) {
        char userType[10];
        start(userType);

        char username[20];
        char password[20];
        int studentID;
        int numStudents = 10; 

        printf("\n==========================");
        printf("\n||                      ||");
        printf("\n||      LOGIN PAGE      ||");
        printf("\n||                      ||");
        printf("\n==========================");
        puts("");

        if (strcmp(userType, "1") == 0) {
            // Librarian login
            printf("Enter username: ");
            scanf("%s", username);

            printf("Enter password: ");
            scanf("%s", password);

            if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
                printf("\nLIBRARIAN LOGIN SUCCESSFUL.\n");
                librarianMenu(books, 10, students, 10, transactions, &numTransactions);
            } else {
                printf("\nInvalid librarian login. Exiting.\n");
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(userType, "2") == 0) {
            // Student login
            printf("Enter student ID(8 numbers): ");
            scanf("%d", &studentID);

            printf("Enter password: ");
            scanf("%s", password);

            int studentIndex = -1;
            for (int i = 0; i < 10; i++) {
                if (students[i].id == studentID && strcmp(students[i].password, password) == 0) {
                    studentIndex = i;
                    break;
                }
            }

            if (studentIndex != -1) { 
                printf("Student login successful.\n");
                int numStudents = 10;
                studentMenu(books, 10, students, studentID, transactions, &numTransactions, numStudents);
            } else {
                printf("Invalid student login. Exiting.\n");
                exit(EXIT_FAILURE);  
            }
        } else {
            printf("Invalid user type. Exiting.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void start(char userType[]) {
    puts("");
    printf("\n================================");
    printf("\n--------------------------------");
    printf("\n---------- WELCOME TO ----------");
    printf("\n------ NOTTINGHAM LIBRARY ------");
    printf("\n--------------------------------");
    printf("\n================================");
    puts("");
    printf("\nChoose your user type: \n");
    printf("[1] Librarian\n");
    printf("[2] Student\n");
    printf("\nEnter user type: ");
    scanf("%s", userType);
}

void librarianMenu(struct book books[], int numBooks, struct identity students[], int numStudents, struct borrowAndReturn transactions[], int *numTransactions) {
    int librarianChoice;
    do {
        printf("\n------- Librarian Management System --------");
        printf("\n| (1) Search Books                         |");
        printf("\n| (2) Borrow a Book                        |");
        printf("\n| (3) Return a Book                        |");
        printf("\n| (4) Display List of Books                |");
        printf("\n| (5) Calculate Fine                       |");
        printf("\n| (6) Generate Montly Report               |");
        printf("\n| (0) Logout                               |");
        printf("\n--------------------------------------------");
        puts("");

        printf("Enter your choice: ");
        scanf("%d", &librarianChoice);

        switch (librarianChoice) {
            case 1:
                searchBook(books, numBooks);
                break;
            case 2:
                borrowBook(books, numBooks, students, numStudents, transactions, numTransactions);
                break;
            case 3:
                returnBook(books, numBooks, students, numStudents, transactions, numTransactions);
                break;
            case 4:
                listBooks(books, numBooks);
                break;
            case 5:
                calculatePenalty(transactions, *numTransactions, students, numStudents);
                break;
            case 6:
                monthlyReport(transactions, *numTransactions);
                break;
            case 0:
                printf("Logging out of account.\n\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    } while (librarianChoice != 0);
}

void studentMenu(struct book books[], int numBooks, struct identity students[], int studentID, struct borrowAndReturn transactions[], int *numTransactions, int numStudents) {
    int studentChoice;
    do { 
         printf("\n------- Librarian Management System -------\n");
        printf("\n| (1) Search Books                          |");
        printf("\n| (2) Display List of Books                 |");
        printf("\n| (3) Calculate Fine                        |");
        printf("\n| (0) Logout                                |");
        printf("\n-------------------------------------------\n");
        puts("");

        printf("Enter your choice: ");
        scanf("%d", &studentChoice);

        switch(studentChoice) {
            case 1:
                searchBook(books, numBooks);
                break;
            case 2:
                listBooks(books, numBooks);
            break;
            case 3:
                calculatePenalty(transactions, *numTransactions, students, numStudents);
                break;
            case 0:
                printf("Logging out of account.\n\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    } while (studentChoice != 0);
}


void searchBook(struct book books[], int numBooks) {
    char keyword[20];
    printf("Enter the ISBN of the book: ");
    scanf ("%s", keyword);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].ISBN, keyword) == 0) {
            printf("\nTitle: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("ISBN: %s\n", books[i].ISBN);
            printf("Year of publication: %d\n", books[i].yearOfPublication);
            printf("Number of copies available: %d\n", books[i].availableCopies);
            printf("Total copies: %d\n", books[i].totalCopies);
            found = 1;
        } 
    }

    if (found == 0) {
        printf("\nBook not found.\n");
    } 
    
}

void updateDatabase(struct borrowAndReturn transaction) {
    FILE *databaseFile = fopen("database.txt", "a");
    if (databaseFile == NULL) {
        fprintf(stderr, "Error opening database file.\n");
        exit(EXIT_FAILURE);
    }

    fprintf(databaseFile, "%s %d %ld %ld\n", transaction.bookISBN, transaction.studentID, transaction.borrowDate, transaction.returnDate);

    fclose(databaseFile);
}

void loadDatabase(struct borrowAndReturn transactions[], int *numTransactions) {
    FILE *databaseFile = fopen("database.txt", "r");
    if (databaseFile == NULL) {
        fprintf(stderr, "Error opening database file.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(databaseFile, "%s %d %ld %ld\n", transactions[*numTransactions].bookISBN,
                  &transactions[*numTransactions].studentID, &transactions[*numTransactions].borrowDate,
                  &transactions[*numTransactions].returnDate) == 4) {
        (*numTransactions)++;
    }

    fclose(databaseFile);
}


void borrowBook(struct book books[], int numBooks, struct identity students[], int numStudents, struct borrowAndReturn transactions[], int *numTransactions) {
    char bookISBN[20];
    int studentID;

    printf("Enter ISBN: ");
    scanf("%s", bookISBN);

    int bookIndex = -1;
    for (int i = 0; i < numBooks; i++) {
        if(strcmp(books[i].ISBN, bookISBN) == 0) {
            bookIndex = i;
            break;
        }
    }

    if(bookIndex == -1) {
        printf("Book not found.\n");
        return;
    }

    printf("Enter the student ID: ");
    scanf("%d", &studentID);

    int studentIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == studentID) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    // Check if there are available copies of the book
    if (books[bookIndex].availableCopies > 0) {
        // record time book was borrowed
        time_t borrowTime = time(NULL);

        transactions[*numTransactions].borrowDate = borrowTime;
        transactions[*numTransactions].returnDate = 0; // 0 if book not available
        strcpy(transactions[*numTransactions].bookISBN, bookISBN);
        transactions[*numTransactions].studentID = studentID;

        books[bookIndex].availableCopies--; // Minus available copies of book
        (*numTransactions)++; // record number of transactions

        printf("Book \"%s\" borrowed successfully.\n", books[bookIndex].title);

        // Update the database
        updateDatabase(transactions[*numTransactions - 1]);
    } else {
        printf("No available copies of the book.\n");
    }
}

void returnBook(struct book books[], int numBooks, struct identity students[], int numStudents, struct borrowAndReturn transactions[], int *numTransactions) {
    char bookISBN[20];

    printf("Enter the ISBN of the book to return: ");
    scanf("%s", bookISBN);

    // Check if the book exists
    int bookIndex = -1;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].ISBN, bookISBN) == 0) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        printf("Book not found.\n");
        return;
    }

    int studentID;

    printf("Enter the student ID: ");
    scanf("%d", &studentID);

    // Find the transaction for the specified book and student
    int transactionIndex = -1;
    for (int i = 0; i < *numTransactions; i++) {
        if (strcmp(transactions[i].bookISBN, bookISBN) == 0 && transactions[i].studentID == studentID) {
            transactionIndex = i;
            break;
        }
    }

    if (transactionIndex == -1) {
        printf("No matching transaction found.\n");
        return;
    }

    // Update the book's availability and return date
    books[bookIndex].availableCopies++;
    time_t returnTime = time(NULL);
    transactions[transactionIndex].returnDate = returnTime;

    printf("Book \"%s\" returned successfully.\n", books[bookIndex].title);

    // Update the database
    updateDatabase(transactions[transactionIndex]);
}
       
void listBooks(struct book books[], int numBooks) {
    // Sort books alphabetically by title
    for (int i = 0; i < numBooks - 1; i++) {
        for (int j = 0; j < numBooks - i - 1; j++) {
            if (strcmp(books[j].title, books[j + 1].title) > 0) {
                // Swap books if they are out of order
                struct book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    printf("\nList of Books:\n");
    for (int i = 0; i < numBooks; i++) {
        printf("<%d>\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("ISBN: %s\n", books[i].ISBN);
        printf("Year of Publication: %d\n", books[i].yearOfPublication);
        printf("Available Copies: %d\n", books[i].availableCopies);
        printf("Total Copies: %d\n", books[i].totalCopies);
        puts("");
    }
}

void calculatePenalty(struct borrowAndReturn transactions[], int numTransactions, struct identity students[], int numStudents) {
    int studentID;

    printf("Enter student ID: ");
    scanf("%d", &studentID);

    int studentIndex = -1;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == studentID) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        printf("Student not found.\n");
        return;
    }

    // Calculate penalty for the student
    double penalty = 0.0;

    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].studentID == studentID && transactions[i].returnDate > 0) {
            // Calculate the number of days late
            time_t returnDate = transactions[i].returnDate;
            time_t borrowDate = transactions[i].borrowDate;
            double daysLate = difftime(returnDate, borrowDate) / (60 * 60 * 24);

            // Add penalty based on RM1.00 per day
            penalty += daysLate * 1.00;
        }
    }

    // Display penalty if any
    printf("\nPenalty Calculation for Student %s (ID: %d):\n", students[studentIndex].name, students[studentIndex].id);
    printf("Total Penalty: RM%.2lf\n", penalty);
}

void monthlyReport(struct borrowAndReturn transactions[], int numTransactions) {
    int month;
    const char *getMonthName(int month);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    // Initialize counters
    int booksBorrowed = 0;
    int booksReturned = 0;
    int booksToBeReturned = 0;
    double totalFines = 0.0;

    // Iterate through transactions
    for (int i = 0; i < numTransactions; i++) {
        struct tm *tm_info = localtime(&transactions[i].borrowDate);

        // Check if the transaction occurred in the specified month
        if (tm_info->tm_mon + 1 == month) {
            booksBorrowed++;

            if (transactions[i].returnDate > 0) {
                booksReturned++;
            } else {
                booksToBeReturned++;
            }

            // Assuming a fixed fine of RM1.00 per day for overdue books
            time_t returnDate = transactions[i].returnDate;
            time_t borrowDate = transactions[i].borrowDate;
            double daysLate = difftime(returnDate, borrowDate) / (60 * 60 * 24);

            if (daysLate > 0) {
                totalFines += daysLate * 1.00;
            }
        }
    }

    // Display the report
    printf("\nMonthly Report - %s\n", getMonthName(month));
    printf("======================================\n");
    printf("Books Borrowed: %d\n", booksBorrowed);
    printf("Books Returned: %d\n", booksReturned);
    printf("Books to be Returned: %d\n", booksToBeReturned);
    printf("Total Penalties: RM%.2lf\n", totalFines);
    printf("======================================\n");
}

const char *getMonthName(int month) {
    // Array of month names
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};

    // Ensure month is within valid range
    if (month >= 1 && month <= 12) {
        return months[month - 1];
    } else {
        return "Please choose a proper month.";
    }
}







