#include <stdio.h>
#include <string.h>
#include <unistd.h>   
#include <termios.h>

typedef struct student_details {
    char ID[9];
    char name[30];
    char password[11];
}Student;

void studentLogin();

int main() {
    studentLogin();
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
        char ch;

        printf("Student ID: ");
        scanf("%s", inputID);
        getchar();


        printf("Password: ");
        int i;
        while ((ch = getCH()) != '\n') {
            if (ch == 127 || ch == 8) { // handle backspace
                if (i != 0) {
                    i--;
                    printf("\b \b");
                }
            }
            else {
                inputPassword[i++] = ch;
                // echo the '*' to get feel of taking password 
                printf("*");
            }
        }
        puts("");


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