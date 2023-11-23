#include <stdio.h>
#include <string.h>

typedef struct student_details {
    char ID[9];
    char name[30];
    char password[11];
}Student;

void studentLogin();

int main() {
    studentLogin();
}

void studentLogin() {
    Student std;
    FILE *sPtr = NULL;

    if ((sPtr = fopen("Student.txt", "r")) == NULL) {
        puts("File could not be opened");
    }

    // User interface
    printf("+====================================+\n");
    printf("\t>>> Student Login Page <<<          \n");
    printf("+====================================+\n");

    if ((sPtr = fopen("Student.txt", "r")) == NULL) {
        printf("File could not be opened");
    }
    else {
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
                printf("Match\n");
                fclose(sPtr);
                return;
            }
            else {
                printf("Invalid input. Please enter again.\n");
                studentLogin();
            }
        }
    }
}