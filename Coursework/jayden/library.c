#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#define SIZE 10

//Admin ID and Password
static char* staff_ID = "12345";
static const char* staff_psw = "Admin";

//Struct useed in the program
typedef struct books{
    char* isbn; 
    char* author;
    char* title; 
    char* year_of_publication;
    int total_copies; // total number of books (available&borrowed)
    int total_copies_available; // total number of copies available to borrow
}Book;

typedef struct students{
    char* student_ID;
    char* student_name;
}Student;

typedef struct borrow_books{
    char* student_ID;
    char* isbn;
    char* title;
    char* borrowed_date;
}Borrow_Book;

typedef struct return_books{
    char* student_ID;
    char* isbn;
    char* title;
    char* returned_date;
}Return_Book;

typedef struct penalty_fees{
    char* student_ID;
    int penalty_amount;
    char* fine_date;
}Penalty_Fee;

typedef struct monthly_reports{
    size_t total_books_borrowed;
    size_t total_books_returned;
    size_t total_fines_collected;
}Monthly_Report;

//Function Prototype
//Function used for clearing previous entry
void clear_previous_entry();

//Function used for reading every file into specific array
void load_student_file(Student* a, int size);
void load_book_file(Book* b, int size);
void load_borrowed_book_file(Borrow_Book* c, int size, size_t* borrow_book_count);
void load_returned_book_file(Return_Book* d, int size, size_t* return_book_count);
void load_penalty_fee_file(Penalty_Fee* f, int size, size_t* penalty_count);

//Function used for writing array into specific file
void write_book(Book* b, int size);
void write_borrowed_book(Borrow_Book* c, int size);
void write_returned_book(Return_Book* d, int size);
void write_penalty_fee(Penalty_Fee* f, int size);

//Function mainly used for log in
int log_in(Student* a, Book* b, Borrow_Book* c, Return_Book* d, Monthly_Report* e, Penalty_Fee* f, int size);
int student_log_in(Student* a, int size);
int staff_log_in();

//Function used for showing the main page
void student_main_page(Student* a, Book* b, Borrow_Book* c, int index, int size);
void staff_main_page(Student* a, Book* b, Borrow_Book* c, Return_Book* d, Monthly_Report* e, Penalty_Fee* f, int index, int size);

//Function used for searching/sorting/displaying book array
void search_book_ISBN(Book* b,int size);
void sort_book(Book* b, int size);
void display_book(Book*b, int size);

//Function used for borrowing book
void borrow_book_page(Student* a, Book* b, Borrow_Book* c, size_t* borrow_book_count, int size);
void borrow_book(Student* a,Book* b, Borrow_Book* c, size_t* borrow_book_count, int size, char* id, char* book_isbn);
void borrow_book_record(Student* a, Borrow_Book* c, int size);

//Function used for returning book
void return_book_page(Student* a,Book* b, Borrow_Book* c, Return_Book* d, Penalty_Fee* f, size_t* return_book_count, size_t* borrow_book_count,  size_t* penalty_count, int size);
void returned_book(Student* a,Book* b, Borrow_Book* c, Return_Book* d, Penalty_Fee* f, size_t* return_book_count, size_t* borrow_book_count, size_t* penalty_count, int size, char* id, char* book_isbn);
void return_book_record(Student* a, Return_Book* d, int size);

//Function used for checking penalty
void check_penalty_page(Student* a, Borrow_Book* c, int size);
int check_penalty(Student* a, Borrow_Book* c, int size, char* id, char* book_isbn, int return_book);

//Function used for generating monthly report file
void generate_monthly_report(Book* b, Borrow_Book* c, Return_Book* d, Monthly_Report* e, Penalty_Fee* f, int size);

//main function
int main(){
    //Initialised every needed variable and array
    int exit;
    Book pre_registered_books[SIZE];
    Student pre_registered_students[SIZE];
    Borrow_Book pre_registered_borrowed_books[SIZE];
    Return_Book pre_registered_returned_books[SIZE];
    Penalty_Fee pre_registered_penalty_fee[SIZE];
    Monthly_Report monthly_report = {0};

    //Calling every load file function
    load_student_file(pre_registered_students, SIZE);
    load_book_file(pre_registered_books, SIZE);
    load_borrowed_book_file(pre_registered_borrowed_books, SIZE, &monthly_report.total_books_borrowed);
    load_returned_book_file(pre_registered_returned_books, SIZE, &monthly_report.total_books_returned);
    load_penalty_fee_file(pre_registered_penalty_fee, SIZE, &monthly_report.total_fines_collected);

    //While loop for controlling exit
    while(exit != 1){
        exit = log_in(pre_registered_students, pre_registered_books, pre_registered_borrowed_books,
                pre_registered_returned_books, &monthly_report, pre_registered_penalty_fee, SIZE);

        if(exit == 1){
            clear_previous_entry();
            puts("\nThank you for using the Library Management System. \nHave a great day and happy reading!\n");
        }
    }

    return 0;
}

//Function used for clearing previous entry
void clear_previous_entry(){
    Sleep(1000); //Terminal wait for 1 seconds

    system("cls");  //Clear the terminal
}

//Function used for reading every file into specific array
void load_student_file(Student* a, int size){
    FILE* fileptr = fopen("students.txt","r");

    //Allocate dynamic memory to the 2 string
    for (int i = 0; i < size; ++i) {
        a[i].student_ID = malloc(100);
        a[i].student_name = malloc(100);
    }

    //Write every value from file to variable
    for (int i = 0; i < size; i++) {
        fscanf(fileptr, "%[^\n]%*c%[^\n]%*c\n",
               a[i].student_ID, a[i].student_name);
    }

    fclose(fileptr);
}

//Function used for reading every file into specific array
void load_book_file(Book* b, int size){

    FILE* fileptr = fopen("books.txt","r");

    //Allocate dynamic memory to the 4 string
    for (int i = 0; i < size; ++i) {
        b[i].title = malloc(200);
        b[i].author = malloc(100);
        b[i].isbn = malloc(20);
        b[i].year_of_publication = malloc(50);
    }

    //Write every value from file to variable
    for (int i = 0; i < size; i++) {
        fscanf(fileptr, "%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c%d%*c%d%*c\n",
               b[i].title, b[i].author, b[i].isbn, b[i].year_of_publication,
                &b[i].total_copies, &b[i].total_copies_available);
    }

    fclose(fileptr);
    //Sort book in alphabetical order
    sort_book(b, size);
}

//Function used for reading every file into specific array
void load_borrowed_book_file(Borrow_Book* c, int size, size_t* borrow_book_count){
    FILE* fileptr = fopen("borrowed_books.txt","r");
    size_t i = 0;

    //Allocate dynamic memory to the 4 string
    for (int i = 0; i < size; ++i) {
        c[i].student_ID = malloc(100);
        c[i].isbn = malloc(20);
        c[i].title = malloc(200);
        c[i].borrowed_date = malloc(11);
    }

    //Write every value from file to variable
    while(!feof(fileptr)){
        fscanf(fileptr, "%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c\n",
               c[i].student_ID, c[i].isbn, c[i].title, c[i].borrowed_date);
        ++i;
        (*borrow_book_count)++;
    }
    
    fclose(fileptr);

    //Initialised every variable after i to NULL, as not in used
    if(i<size){
        for(i; i < size ; ++i){
            c[i].student_ID = NULL;
            c[i].isbn = NULL;
            c[i].title = NULL;
            c[i].borrowed_date = NULL;
        }
    }
}

//Function used for reading every file into specific array
void load_returned_book_file(Return_Book* d, int size, size_t* return_book_count){
    FILE* fileptr = fopen("returned_books.txt","r");
    size_t i = 0;

    //Allocate dynamic memory to the 4 string
    for (int i = 0; i < size; ++i) {
        d[i].student_ID = malloc(100);
        d[i].isbn = malloc(20);
        d[i].title = malloc(200);
        d[i].returned_date = malloc(11);
    }

    //Write every value from file to variable
    while(!feof(fileptr)){
        fscanf(fileptr, "%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c\n",
               d[i].student_ID, d[i].isbn, d[i].title, d[i].returned_date);
        ++i;
        (*return_book_count)++;
    }
    
    fclose(fileptr);

    //Initialised every variable after i to NULL, as not in used
    if(i<size){
        for(i; i < size ; ++i){
            d[i].student_ID = NULL;
            d[i].isbn = NULL;
            d[i].title = NULL;
            d[i].returned_date = NULL;
        }
    }
}

//Function used for reading every file into specific array
void load_penalty_fee_file(Penalty_Fee* f, int size, size_t* penalty_count){
    FILE* fileptr = fopen("penalty_fee.txt","r");
    size_t i = 0;

    //Allocate dynamic memory to the 4 string
    for (int i = 0; i < size; ++i) {
        f[i].student_ID = malloc(20);
        f[i].fine_date = malloc(11);
    }

    //Write every value from file to variable
    while(!feof(fileptr)){
        fscanf(fileptr, "%[^\n]%*c%d%*c%[^\n]%*c\n",
               f[i].student_ID, &f[i].penalty_amount, f[i].fine_date);
        (*penalty_count) += f[i].penalty_amount;
        ++i;
    }

    fclose(fileptr);

    //Initialised every variable after i to NULL or 0, as not in used
    if(i<size){
        for(i; i < size ; ++i){
            f[i].student_ID = NULL;
            f[i].penalty_amount = 0;
            f[i].fine_date = NULL;
        }
    }
}

//Function used for writing array into specific file
void write_book(Book* b, int size){
    FILE* fileptr = fopen("books.txt","w");

    //Write every variable from array into file
    for(size_t i = 0; i < size ; ++i){
        fprintf(fileptr, "%s\n", b[i].title);
        fprintf(fileptr, "%s\n", b[i].author);
        fprintf(fileptr, "%s\n", b[i].isbn);
        fprintf(fileptr, "%s\n", b[i].year_of_publication);
        fprintf(fileptr, "%d\n", b[i].total_copies);
        fprintf(fileptr, "%d\n", b[i].total_copies_available);
        fprintf(fileptr, "\n");
    }

    fclose(fileptr);
}

//Function used for writing array into specific file
void write_borrowed_book(Borrow_Book* c, int size){
    FILE* fileptr = fopen("borrowed_books.txt","w");

    //Write every variable from array into file
    for(size_t i = 0 ; i < size ; ++i){
        if(c[i].student_ID != NULL && c[i].isbn != NULL && c[i].title != NULL && c[i].borrowed_date != NULL){
            fprintf(fileptr, "%s\n", c[i].student_ID);
            fprintf(fileptr, "%s\n", c[i].isbn);
            fprintf(fileptr, "%s\n",  c[i].title);
            fprintf(fileptr, "%s\n",  c[i].borrowed_date);
            fprintf(fileptr, "\n");
        }
    }
    fclose(fileptr);
}

//Function used for writing array into specific file
void write_returned_book(Return_Book* d, int size){
    FILE* fileptr = fopen("returned_books.txt","w");

    //Write every variable from array into file
    for(size_t i = 0 ; i < size ; ++i){
        if(d[i].student_ID != NULL && d[i].isbn != NULL && d[i].title != NULL && d[i].returned_date != NULL){
            fprintf(fileptr, "%s\n", d[i].student_ID);
            fprintf(fileptr, "%s\n", d[i].isbn);
            fprintf(fileptr, "%s\n",  d[i].title);
            fprintf(fileptr, "%s\n",  d[i].returned_date);
            fprintf(fileptr, "\n");
        }
    }
    fclose(fileptr);
}

//Function used for writing array into specific file
void write_penalty_fee(Penalty_Fee* f, int size){
    FILE* fileptr = fopen("penalty_fee.txt","w");

    //Write every variable from array into file
    for(size_t i = 0 ; i < size ; ++i){
        if(f[i].student_ID != NULL && f[i].penalty_amount != 0 && f[i].fine_date != NULL){
            fprintf(fileptr, "%s\n", f[i].student_ID);
            fprintf(fileptr, "%d\n", f[i].penalty_amount);
            fprintf(fileptr, "%s\n",  f[i].fine_date);
            fprintf(fileptr, "\n");
        }
    }
    fclose(fileptr);
}

//Function mainly used for log in
int log_in(Student* a, Book* b, Borrow_Book* c, Return_Book* d, Monthly_Report* e, Penalty_Fee* f, int size){
        //Initliased variable needed for calculating the time
        time_t t = time(NULL);
        struct tm date = *localtime(&t);
        int current_year = date.tm_year + 1900;
        int current_month = date.tm_mon + 1;
        int current_day = date.tm_mday;
        int student_or_staff;
        int student_index;
        int staff_key;

        //Infinite while loop
        while(1){
            clear_previous_entry();
            puts("===========================================");
            printf("====== %d-%02d-%02d Welcome To Library ======\n", current_year, current_month, current_day);
            puts("===========================================\n");

            puts("(1) Student\n(2) Staff\n(3) Exit\n");

            printf("Choice : ");
            scanf("%d",&student_or_staff);
            getchar();

            printf("\n");

            //If statement to check for user input (1-3) or will ask user to input again
            if(student_or_staff >= 1 && student_or_staff <= 3){
                switch(student_or_staff){
                    case 1:
                        student_index = student_log_in(a,size);
                        if(student_index != -1){
                            student_main_page(a, b, c, student_index, SIZE);//Student_Main_Page
                        }
                        break;
                    case 2:
                        int staff_key = staff_log_in();
                        if(staff_key == 1){
                            staff_main_page(a, b, c, d, e, f, student_index, SIZE);
                        }
                        break;
                    case 3:
                        return 1;
                        break;
                    default:
                        break;
                }
            }else{
                puts("Error! Please input (1) for student or (2) for staff");
                printf("\n");
            }
        }
}

//Function mainly used for log in
int student_log_in(Student* a, int size){
    //Initialised variable needed for log in
    char try_again;
    char user_id[100];
    char user_name[100];

    while(1){
        clear_previous_entry();
        puts("==========================================");
        puts("============= Student Log In =============");
        puts("==========================================\n");

        puts("Log in to your student account");
        printf("ID : ");
        scanf("%s",user_id);
        getchar();

        printf("Name : ");
        fgets(user_name, 100, stdin);
        user_name[strcspn(user_name, "\n")] = '\0'; // Remove the newline character if present

        //Check if user input ID and Name similar as any element in Student Array and return the index if found
        for(size_t i = 0 ; i < size ; ++i){
            if(strcmp(a[i].student_ID, user_id) == 0 && strcmp(a[i].student_name, user_name) == 0){
                return i;
            }
        }
        
        //If none index found will ask user to input again
        printf("\n");
        puts("Student ID or Username incorrect. Would you like to try again?\n");
        printf("Try Again(1) or Exit to main menu(2) : ");
        scanf("%c",&try_again);
        getchar();
        printf("\n");

        //User choose to exit back
        if(try_again == '2'){
            return -1; // Return user back to main menu
        }
    }
}

//Function mainly used for log in
int staff_log_in(){
    //Initialised variable needed for log in
    char try_again;
    char try_staff_id[100];
    char try_staff_password[100];

    while(1){
        clear_previous_entry();
        puts("==========================================");
        puts("============== Staff Log In ==============");
        puts("==========================================\n");

        puts("Log in to staff account");
        printf("ID : ");
        scanf("%s",try_staff_id);
        getchar();

        printf("Password : ");
        fgets(try_staff_password, 100, stdin);
        try_staff_password[strcspn(try_staff_password, "\n")] = '\0'; // Remove the newline character if present

        //Check if user input ID and password same as the Admin id and password and return the index if found
        if(strcmp(staff_ID,try_staff_id) == 0 && strcmp(staff_psw,try_staff_password) == 0){
            return 1;
        }
        
        //If not same will ask user to input again
        printf("\n");
        puts("Staff ID or Password incorrect. Would you like to try again?\n");
        printf("Try Again(1) or Exit to main menu(2) : ");
        scanf("%c",&try_again);
        getchar();
        printf("\n");

        //User choose to exit back
        if(try_again == '2'){
            return -1; // Return user back to main menu
        }
    }
}

//Function used for showing the main page
void student_main_page(Student* a, Book* b, Borrow_Book* c, int index, int size){
    while(1){
        int user_choice;
        clear_previous_entry();
        puts("===========================================");
        puts("=========== Student Main Page =============");
        puts("===========================================\n");

        printf("---------- Hello %s ----------\n", a[index].student_name);
        printf("\n");

        puts("(1) Search Books");
        puts("(2) Display All Books");
        puts("(3) Calculate Late Return Fee");
        puts("(4) Log Out\n");

        printf("What would you like to do today?\n");
        printf("Choice : ");
        scanf("%d", &user_choice);
        getchar();

        //Switch statement to check user input
        switch (user_choice){
            case 1:
                search_book_ISBN(b,size);
                break;
            case 2:
                display_book(b, size);
                break;
            case 3:
                check_penalty_page(a, c, size);
                break;
            case 4:
                return;
                break;
            default:
                puts("Error! Please input (1-4)!");
                printf("\n");
                break;
        }
    }
}

//Function used for showing the main page
void staff_main_page(Student* a, Book* b, Borrow_Book* c, Return_Book* d, Monthly_Report* e, Penalty_Fee* f, int index, int size){
    while(1){
        int user_choice;
        clear_previous_entry();
        puts("===========================================");
        puts("============ Staff Main Page ==============");
        puts("===========================================\n");

        puts("(1) Search Books");
        puts("(2) Student Borrow Book");
        puts("(3) Student Return Book");
        puts("(4) Display All Books");
        puts("(5) Calculate Late Return Fee");
        puts("(6) Generate Monthly Report");
        puts("(7) Log Out\n");

        printf("What would you like to do today?\n");
        printf("Choice : ");
        scanf("%d", &user_choice);
        getchar();

        //Switch statement to check user input
        switch (user_choice){
        case 1:
            search_book_ISBN(b, size);
            break;
        case 2:
            borrow_book_page(a, b, c, &e->total_books_borrowed, size);
            break;
        case 3:
            return_book_page(a, b, c, d, f, &e->total_books_returned, &e->total_books_borrowed, &e->total_fines_collected, size);
            break;
        case 4:
            display_book(b, size);
            break;
        case 5:
            check_penalty_page(a, c, size);
            break;
        case 6:
            generate_monthly_report(b, c, d, e, f, size);
            break;
        case 7:
            return;
            break;
        default:
            puts("Error! Please input (1-7)!");
            printf("\n");
            break;
        }
    }
}

//Function used for searching book using ISBN
void search_book_ISBN(Book* b,int size){
    clear_previous_entry();

    while(1){
        char* isbn = NULL;
        int user_choice;
        puts("===========================================");
        puts("============ Search Book Page =============");
        puts("===========================================\n");

        puts("(1) Search Book");
        puts("(2) Exit Back\n");

        printf("Choice : ");
        scanf("%d",&user_choice);
        getchar();

        //Switch statement to check user input
        switch (user_choice){
            case 1:
                printf("ISBN : ");
                isbn = malloc(20); //Allocate dynamic memory for isbn as it's a string
                scanf("%s", isbn);
                getchar();
                printf("\n");
                //Loop through every element in Book array and compare every ISBN with user input ISBN
                for(size_t i = 0; i < size; i++){
                    //If same will output the found book
                    if(strcmp(isbn, b[i].isbn) == 0){
                        puts(">>>>> Found Book <<<<<\n");

                        printf("Title : %s\n", b[i].title);
                        printf("Author : %s\n", b[i].author);
                        printf("ISBN : %s\n", b[i].isbn);
                        printf("Year of Publication :  %s\n", b[i].year_of_publication);
                        printf("Total Copies : %d\n", b[i].total_copies);
                        printf("Total Copies Available For Borrow : %d\n\n", b[i].total_copies_available);
                        break; //Break out the for loop if found same isbn
                    }
                    
                    //If at the last element and isbn still not found
                    if(i == size-1){
                        free(isbn);
                        puts("Error! Invalid ISBN! Please try again\n");
                        break;
                    }
                }
                break;
            case 2:
                free(isbn);
                return;
            default:
                puts("Error! Please input (1-2)!");
                printf("\n");
                break;
        }
    }
}

//Function used for sorting book
void sort_book(Book* a, int size){
    int reducing_size = size;

    //Bubble sort for alphabetical order
    for(size_t i = 0; i < size; ++i){
        --reducing_size;
        for(size_t j = 0; j < reducing_size; ++j){
            if(strcmp(a[j].title, a[j+1].title) > 0){
                Book holder = a[j];
                a[j] = a[j+1];
                a[j+1] = holder; 
            }
        }
    }
}

//Function used for displaying book
void display_book(Book* b, int size){
    char user_input;

    //Sorting the book before printing
    sort_book(b, size);
    //Writing in file before printing
    write_book(b, size);

    clear_previous_entry();

    puts("===========================================");
    puts("=========== Display Book Page =============");
    puts("===========================================\n");

    //Loop through every element and print it out
    for(size_t i = 0; i < size ; ++i){
        printf("%d)\n", i+1);
        printf("Title of Book : %s\n", b[i].title);
        printf("Author of Book : %s\n", b[i].author);
        printf("ISBN of Book : %s\n", b[i].isbn);
        printf("Year of Publication of Book : %s\n", b[i].year_of_publication);
        printf("Total copies of Book : %d\n", b[i].total_copies);
        printf("Total copies available for borrow of Book : %d\n", b[i].total_copies_available);
        printf("\n");
    }

    puts("Enter once to exit back");
    scanf("%c",&user_input);
}

//Function used for borrowing book
void borrow_book_page(Student* a,Book* b, Borrow_Book* c, size_t* return_book_count, int size){
    while(1){
        clear_previous_entry();
        int user_choice;
        char student_id[20];
        char book_isbn[20];

        puts("===========================================");
        puts("============ Borrow Book Page =============");
        puts("===========================================\n");

        puts("(1) Student Borrow Book");
        puts("(2) Borrow Book Record");
        puts("(3) Exit Back\n");

        printf("Choice : ");
        scanf("%d",&user_choice);
        getchar();

        //Switch statement to check user input
        switch(user_choice){
            case 1:
                printf("Student ID : ");
                scanf("%s", student_id);
                getchar();
                printf("Book ISBN : ");
                scanf("%s", book_isbn);
                getchar();

                borrow_book(a, b, c, return_book_count, size, student_id, book_isbn); //Call borrow book function
                break;
            case 2:
                borrow_book_record(a, c, size); //Call borrow book record function
                break;
            case 3:
                return;
                break;
            default:
                puts("Error! Please input (1-3)!");
                printf("\n");
                break;
        }
    }
}

//Function used for borrowing book
void borrow_book(Student* a,Book* b, Borrow_Book* c, size_t* borrow_book_count, int size, char* id, char* book_isbn){
    //Initialised variable needed for function
    char user_input;
    int student_index = -1;
    int book_index = -1;
    int available_checker = 1;

    //Initliased variable needed for calculating the time
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    int current_year = date.tm_year + 1900;
    int current_month = date.tm_mon + 1;
    int current_day = date.tm_mday;

    //Store the formatted date into a string for future used
    char formatted_date[11];  // "YYYY-MM-DD\0"
    sprintf(formatted_date, "%04d-%02d-%02d", current_year, current_month, current_day);

    //Loop through every element in Student array and check if any same student id is found
    for(size_t i = 0 ; i < size ; ++i){
        if(strcmp(a[i].student_ID, id) == 0){
            student_index = i;
            break;
        }
    }

    //Loop through every element in Book array and check if any same isbn is found
    for(size_t i = 0 ; i < size ; ++i){
        if(strcmp(b[i].isbn, book_isbn) == 0){
            book_index = i;
            break;
        }
    }

    //If statement for checking both index is found or not
    if(student_index == -1 || book_index == -1){
        puts("Student ID or ISBN incorrect. Please try again.\n");
    //Else if statement checking if the total_copies is available or not
    }else if(b[book_index].total_copies_available == 0){
        printf("\n");
        printf("No extra copies of %s is available. Please borrow other books.\n", b[book_index].title);
        printf("\n");
        available_checker = 0;
    //Else both the index is found and copies available for borrow
    }else{
        b[book_index].total_copies_available--; //total copies of book available is decrementted
        
        //For loop to loop through every element in Borrow Book array
        for(size_t i = 0 ; i < size ; ++i){
            //Find which element that is not in used which is NULL
            if(c[i].student_ID == NULL && c[i].isbn == NULL && c[i].title == NULL && c[i].borrowed_date == NULL){
                //Duplicate the string in element of Student and Book array and store in Borrow Book element
                c[i].student_ID = strdup(a[student_index].student_ID);
                c[i].isbn = strdup(b[book_index].isbn);
                c[i].title = strdup(b[book_index].title);
                c[i].borrowed_date = strdup(formatted_date);

                (*borrow_book_count)++; //Increment borrow book count

                //Write value into each file
                write_borrowed_book(c, size);
                write_book(b, size);

                printf("\n");
                printf("Borrow successful! Please remind %s to return on time.\n", a[student_index].student_name);
                puts("Enter once to exit back");
                scanf("%c",&user_input);

                break;
            }
        }
    }
}

//Function used for borrow book record
void borrow_book_record(Student* a, Borrow_Book* c, int size){
    char user_input;
    clear_previous_entry();

    puts("===========================================");
    puts("=========== Borrow Book Record ============");
    puts("===========================================\n");

    //Loop through every element in Borrow Book array and print it out
    for (size_t i = 0; i < size ; ++i) {
        //Print if the element is not NULL
        if(c[i].student_ID != NULL && c[i].isbn != NULL
         && c[i].title != NULL && c[i].borrowed_date != NULL){
            printf("Book %d:\n", i + 1);
            printf("Student ID: %s\n", c[i].student_ID);
            //Printing the correct student name by comparing student_id
            for(size_t j = 0 ; j < size ; ++j){
                if(strcmp(a[j].student_ID, c[i].student_ID) == 0){
                    printf("Student Name : %s\n", a[j].student_name);
                    break;
            }
            }
            printf("ISBN: %s\n", c[i].isbn);
            printf("Title: %s\n", c[i].title);
            printf("Borrowed Date: %s\n", c[i].borrowed_date);
            printf("\n");
        }
    }

    puts("Enter once to exit back");
    scanf("%c",&user_input);
}

//Function used for returning book
void return_book_page(Student* a,Book* b, Borrow_Book* c, Return_Book* d, Penalty_Fee* f, size_t* return_book_count, size_t* borrow_book_count, size_t* penalty_count, int size){

    while(1){
        clear_previous_entry();
        int user_choice;
        char student_id[20];
        char book_isbn[20];

        puts("===========================================");
        puts("============ Return Book Page =============");
        puts("===========================================\n");

        puts("(1) Student Return Book");
        puts("(2) Return Book Record");
        puts("(3) Exit Back\n");

        printf("Choice : ");
        scanf("%d",&user_choice);
        getchar();

        //Switch statement to check user input
        switch(user_choice){
            case 1:
                printf("Student ID : ");
                scanf("%s", student_id);
                getchar();
                printf("Borrowed book ISBN : ");
                scanf("%s", book_isbn);
                getchar();

                returned_book(a, b, c, d, f, return_book_count, borrow_book_count, penalty_count, size, student_id, book_isbn); //Call return book function
                break;
            case 2:
                return_book_record(a, d, size); //Call return book record
                break;
            case 3:
                return;
                break;
            default:
                puts("Error! Please input (1-3)!");
                printf("\n");
                break;
        }
    }
}

//Function used for returning book
void returned_book(Student* a,Book* b, Borrow_Book* c, Return_Book* d, Penalty_Fee* f, size_t* return_book_count, size_t* borrow_book_count, size_t* penalty_count, int size, char* id, char* book_isbn){
    //Initialised variable needed for function
    char user_input;
    int student_index = -1;
    int book_index = -1;
    int borrow_book_index = -1;

    //Initliased variable needed for calculating the time
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    int current_year = date.tm_year + 1900;
    int current_month = date.tm_mon + 1;
    int current_day = date.tm_mday;

    //Store the formatted date into a string for future used
    char formatted_date[11];  // "YYYY-MM-DD\0"
    sprintf(formatted_date, "%04d-%02d-%02d", current_year, current_month, current_day);

    //Loop through every element in Student array and check if any same student id is found
    for(size_t i = 0 ; i < size ; ++i){
        if(strcmp(a[i].student_ID, id) == 0){
            student_index = i;
            break;
        }
    }

    //Loop through every element in Book array and check if any same isbn is found
    for(size_t i = 0 ; i < size ; ++i){
        if(strcmp(b[i].isbn, book_isbn) == 0){
            book_index = i;
            break;
        }
    }

    //Loop through every element in Borrow Book Array and find the same id and isbn which is needed for index
    for(size_t i = 0 ; i < size ; ++i){
        //If the element is not NULL will check if id and isbn is same
        if(c[i].student_ID != NULL && c[i].isbn != NULL && c[i].title != NULL && c[i].borrowed_date != NULL){
            if(strcmp(c[i].student_ID, id) == 0 && strcmp(c[i].isbn, book_isbn) == 0){
                borrow_book_index = i;
                break;
            }
        }
    }

    //If statement for checking borrow book index is found or not
    if(borrow_book_index == -1){
        printf("\n");
        puts("No student ID or ISBN found in borrowed book database.\n");
    //Else both the index is found and copies available for return
    }else{
        b[book_index].total_copies_available++; //total copies of book available is incremented
        size_t i = 0;
        int penalty_fee = check_penalty(a, c, size, id, book_isbn, 0); //Capture the penalty fee return by function

        //Loop through every element in Return Book Array
        for (size_t i = 0; i < size; ++i) {
            //Check if the current element is NULL (not in used)
            if (d[i].student_ID == NULL && d[i].isbn == NULL && d[i].title == NULL && d[i].returned_date == NULL) {
                //Duplicate the string in element of Borrow Book array and store in Return Book element
                d[i].student_ID = strdup(c[borrow_book_index].student_ID);
                d[i].isbn = strdup(c[borrow_book_index].isbn);
                d[i].title = strdup(c[borrow_book_index].title);
                d[i].returned_date = strdup(formatted_date);

                //Check if got penalty or not
                if(penalty_fee > 0){
                    //Loop through every element in Penalty Fee Array
                    for(size_t j = 0; j < size; ++j){
                        //Check if the current element is NULL (not in used)
                        if (f[j].student_ID == NULL && f[j].penalty_amount == 0 && f[j].fine_date == NULL){
                            //Duplicate the string in element of Return Book array and store in Penalty Fee element
                            f[j].student_ID = strdup(d[i].student_ID);
                            f[j].penalty_amount = penalty_fee;
                            f[j].fine_date = strdup(d[i].returned_date);

                            (*penalty_count) += penalty_fee; //Add penalty fee into penalty count

                            break;
                        }
                    }
                }

                (*return_book_count)++; //Increment return book count (As return a book)
                (*borrow_book_count)--; //Decrement borrow book count (As return a book)

                //Move initialise the current element into the next current element as a book got returned
                for (size_t i = borrow_book_index; i < size - 1; ++i) {
                    c[i] = c[i + 1];
                }

                // Set the last element to NULL or empty
                c[size - 1].student_ID = NULL;
                c[size - 1].isbn = NULL;
                c[size - 1].title = NULL;
                c[size - 1].borrowed_date = NULL;

                //Write value into each file
                write_book(b, size);
                write_borrowed_book(c, size);
                write_returned_book(d, size);
                write_penalty_fee(f, size);

                printf("\n");
                //Check if got any penalty fee
                if(penalty_fee > 0){
                    printf("Return successful! Remember to collect RM%d thanks %s for returning the book.\n", penalty_fee, a[student_index].student_name);
                }else{
                    printf("Return successful! Remember to thank %s for returning the book.\n", a[student_index].student_name);
                }
                puts("Enter once to exit back");
                scanf("%c",&user_input);

                break;
            }
        }
    }
}

//Function used for return book record
void return_book_record(Student* a, Return_Book* d, int size){
    char user_input;
    clear_previous_entry();

    puts("===========================================");
    puts("=========== Return Book Record ============");
    puts("===========================================\n");

    //Loop through every element in Return Book array and print it out
    for (size_t i = 0; i < size ; ++i) {
        //Print if the element is not NULL
        if(d[i].student_ID != NULL && d[i].isbn != NULL
         && d[i].title != NULL && d[i].returned_date != NULL){
            printf("Book %d:\n", i + 1);
            printf("Student ID: %s\n", d[i].student_ID);
            //Printing the correct student name by comparing student_id
            for(size_t j = 0 ; j < size ; ++j){
                if(strcmp(a[j].student_ID, d[i].student_ID) == 0){
                    printf("Student Name : %s\n", a[j].student_name);
                    break;
            }
            }
            printf("ISBN: %s\n", d[i].isbn);
            printf("Title: %s\n", d[i].title);
            printf("Returned Date: %s\n", d[i].returned_date);
            printf("\n");
        }
    }

    puts("Enter once to exit back");
    scanf("%c",&user_input);
}

//Function used for checking penalty
void check_penalty_page(Student* a, Borrow_Book* c, int size){
    clear_previous_entry();

    while(1){
        int user_choice;
        char student_id[20];
        char book_isbn[20];

        puts("===========================================");
        puts("========== Panalty Checker Page ===========");
        puts("===========================================\n");

        puts("(1) Penalty Checker");
        puts("(2) Exit Back\n");

        printf("Choice : ");
        scanf("%d",&user_choice);
        getchar();

        //Switch statement to check user input
        switch(user_choice){
            case 1:
                printf("Student ID : ");
                scanf("%s", student_id);
                getchar();
                printf("Borrowed book ISBN : ");
                scanf("%s", book_isbn);
                getchar();

                int user_penalty = check_penalty(a, c, size, student_id, book_isbn, 1); //Initialised user penalty to capture return value of function
                if(user_penalty == -1){ //Check if equal to -1
                    printf("\n");
                    puts("No student ID or ISBN found in borrowed book database.\n");
                }else if(user_penalty == 0){ //Check if equal to 0
                    printf("Currently no penalty will be charged.\n\n");
                }else{ //Check if equal > 0, will print out
                    printf("RM %d will be charged for late return.\n\n", user_penalty);
                }
                break;
            case 2:
                return;
                break;
            default:
                puts("Error! Please input (1-2)!");
                printf("\n");
                break;
        }
    }
}

//Function used for calculating penalty
int check_penalty(Student* a, Borrow_Book* c, int size, char* id, char* book_isbn, int return_book){
    //Initialised variable needed for function
    int borrow_book_index = -1;

    //Loop through every element in Borrow Book Array and find the same id and isbn which is needed for index
    for(size_t i = 0 ; i < size ; ++i){
        //If the element is not NULL will check if id and isbn is same
        if(c[i].student_ID != NULL && c[i].isbn != NULL && c[i].title != NULL && c[i].borrowed_date != NULL){
            if(strcmp(c[i].student_ID, id) == 0 && strcmp(c[i].isbn, book_isbn) == 0){
                borrow_book_index = i;
                break;
            }
        }else if(i == 9){
            return -1; //Error id or isbn;
        }
    }

    //Mainly used for showing
    if(return_book == 1){
        printf("\n");
        puts(">>>>> Found Borrowed Book <<<<<\n");
        printf("Student ID: %s\n", c[borrow_book_index].student_ID);
        for(size_t j = 0 ; j < size ; ++j){
            if(strcmp(a[j].student_ID, c[borrow_book_index].student_ID) == 0){
                printf("Student Name : %s\n", a[j].student_name);
                break;
            }
        }
        printf("ISBN: %s\n", c[borrow_book_index].isbn);
        printf("Title: %s\n", c[borrow_book_index].title);
        printf("Borrowed Date: %s\n", c[borrow_book_index].borrowed_date);
        printf("\n");
    }

    //Initliased variable needed for borrowed date
    int borrowed_year, borrowed_month, borrowed_day;
    sscanf(c[borrow_book_index].borrowed_date, "%d-%02d-%02d", &borrowed_year, &borrowed_month, &borrowed_day);

    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    int current_year = date.tm_year + 1900;
    int current_month = date.tm_mon + 1;
    int current_day = date.tm_mday;

    int returned_days = current_year * 365 + current_month * 30 + current_day;
    int borrowed_days = borrowed_year * 365 + borrowed_month * 30 + borrowed_day;

    // Calculate the difference in days
    int days_difference = returned_days - borrowed_days;

    // Check if the return is later than 5 days
    int days_late = days_difference - 5;

    // Calculate penalty (RM1 per day)
    int penalty = (days_late > 0) ? days_late * 1 : 0;

    return penalty;
}

//Function used for generating monthly report file
void generate_monthly_report(Book* b, Borrow_Book* c, Return_Book* d, Monthly_Report* e, Penalty_Fee* f, int size){

    //Initliased variable needed for calculating the time
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    int current_year = date.tm_year + 1900;

    //Array for finding months
    const char* months[12] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    char file_name[50]; // Adjust the size as needed
    sprintf(file_name, "monthly_report_%s.csv", months[date.tm_mon]);
    FILE* fileptr = fopen(file_name,"w");

    //write value into file
    fprintf(fileptr, "%d %s Monthly Report\n", current_year,  months[date.tm_mon]);

    //Spacing
    fprintf(fileptr, "\n");

    //write value into file
    fprintf(fileptr, "Total Number Of Books Borrowed :, %d\n", ((e->total_books_borrowed)+(e->total_books_returned)));
    fprintf(fileptr, "Student ID, ISBN\n");
    for(size_t i = 0 ; i < size ; ++i){
        if(c[i].student_ID != NULL && c[i].isbn != NULL && c[i].title != NULL && c[i].borrowed_date != NULL){
            fprintf(fileptr, "%s, \"%s\"\n", c[i].student_ID, c[i].isbn);
        }
    }

    //write value into file
    for(size_t i = 0 ; i < size ; ++i){
        if(d[i].student_ID != NULL && d[i].isbn != NULL && d[i].title != NULL && d[i].returned_date != NULL){
            fprintf(fileptr, "%s, \"%s\"\n", d[i].student_ID, d[i].isbn);
        }
    }

    //Spacing
    fprintf(fileptr, "\n");

    //write value into file
    fprintf(fileptr, "Total Number Of Books To Be Returned :, %d\n", e->total_books_borrowed);
    fprintf(fileptr, "Borrowed Date, Student ID, ISBN\n");
    for(size_t i = 0 ; i < size ; ++i){
        if(c[i].student_ID != NULL && c[i].isbn != NULL && c[i].title != NULL && c[i].borrowed_date != NULL){
            fprintf(fileptr, "%s, %s, \"%s\"\n", c[i].borrowed_date, c[i].student_ID, c[i].isbn);
        }
    }

    //Spacing
    fprintf(fileptr, "\n");

    //write value into file
    fprintf(fileptr, "Total Number Of Books Returned :, %d\n", e->total_books_returned);
    fprintf(fileptr, "Returned Date, Student ID, ISBN\n");
    for(size_t i = 0 ; i < size ; ++i){
        if(d[i].student_ID != NULL && d[i].isbn != NULL && d[i].title != NULL && d[i].returned_date != NULL){
            fprintf(fileptr, "%s, %s, \"%s\"\n", d[i].returned_date, d[i].student_ID, d[i].isbn);
        }
    }

    //Spacing
    fprintf(fileptr, "\n");

    //write value into file
    fprintf(fileptr, "Total Penalty Collected (RM) :, %d\n", e->total_fines_collected);
    fprintf(fileptr, "Fine Date, Student ID, Fines (RM)\n");
    for(size_t i = 0 ; i < size ; ++i){
        if(f[i].student_ID != NULL && f[i].penalty_amount != 0 && f[i].fine_date != NULL){
            fprintf(fileptr, "%s, %s, %d\n", f[i].fine_date, f[i].student_ID, f[i].penalty_amount);
        }
    }

    fclose(fileptr);

    puts("\nSuccessfully generated a monthly report csv file! Please check your folder located in the directory\n");
    puts("Enter once to exit back");
    getchar();
}