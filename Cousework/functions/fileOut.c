#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct student_details {
    char ID[9];
    char name[30];
    char password[10];
}Student;

void login();

void main() {
    login();

}
void login() { // require FILE knowledge
    Student std;
    FILE *fptr = fopen("Student.txt", "r");
    char ID[9];
    char password[11];

    // User interface
    printf("+====================================+\n");
    printf("\t>>> Student Login Page <<<          \n");
    printf("+====================================+\n");

    // requires ID as username
    printf("Student ID: ");
    scanf("%s", ID);
    


        
}