#include <stdio.h>
#include <string.h>

typedef struct student_details {
    char ID[9];
    char name[30];
    char password[11];
}Student;

void addStudent();

void main() {
    addStudent();
}

void addStudent() {
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

        fprintf(sPtr, "\n\n%s\n%s\n%s\n", std.ID, std.name, std.password);

        fclose(sPtr);
    }
}