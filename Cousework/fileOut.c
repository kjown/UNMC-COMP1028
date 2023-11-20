#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct student_details {
    char ID[9];
    char name[30];
    char password[11];
}Student;

void login();

void main(void) {
    login();
}

void login() { 
    Student std;
    FILE *fptr = fopen("Student.txt", "r");
    char ID[9];
    char password[11];
    int line[100];
    Student *stdPtr = &std;


    // User interface
    printf("+========================================+\n");
    printf("\t>>> Student Login Page <<<          \n");
    printf("+========================================+\n");

    // requires ID as username
    printf("Student ID: ");
    scanf("%s", ID);
    printf("Password: ");
    scanf("%s", password);

    fptr = fopen("Student.txt", "r");
     // if username does not match those in files, prompt again  
    while (fscanf(fptr, "%s\t%s\t%s", std.ID, std.name, std.password) == 3) {
        if(ID != std.ID && strcmp(password, std.password) != 0) {
            printf("Fail\n");
            login();
        }
        else {
            printf("Success\n");
            fclose(fptr);
        }
    }

}