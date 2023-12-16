#include <stdio.h>
#include <string.h>

// define a struct for user
typedef struct student {
    char stud_name[10];
    char address[20];
} Student;

// functiion to get user input
Student user_input(int i) { 
    Student std;    // define variable std 
    // prompt user to enter details of student
    printf("Enter Student %d Details:\n", i);
    printf("Name: ");
    scanf("%s", std.stud_name);
    printf("Address: ");
    scanf("%s", std.address);
    return std;
}

// function to display details of students before arranging
void displayBefore(Student *std, int limit) {
    puts("Data before arrangement:");
    puts("Student Address");
    for (int i = 1; i <= limit; i++) {
        printf("%s\t%s\n",  std[i].stud_name, std[i].address);
    }
    puts("");
}

// function to rearrangae student details in alphabetical order
void displayAfter(Student *std, int limit) {
    puts("Data after arrangement:");
    puts("Student Address");
    for(size_t i = 0 ; i < limit ; ++i){
        int inner_size = limit-1;
        for(size_t j = 0 ; j < limit ; ++j)
            if(strcmp(std[j].stud_name, std[j+1].stud_name) > 0){
                Student temp = std[j];
                std[j] = std[j+1];
                std[j+1] = temp;
            }
        }
    
    for (int i = 0; i < limit; i++) {
        printf("%s\t%s\n", std[i].stud_name, std[i].address);
    }
}

int main() {
    int limit;  // variable to store number of student details to be inputted
    Student *std;
    // prompt user to enter number of students to be entered
    printf("How many student records that you want to enter?\n");
    printf("Enter limit: ");
    scanf("%d", &limit);
    
    for (int i = 1; i <= limit; i++) {
        std[i] = user_input(i);
        puts("");
    }

    displayBefore(std, limit);
    displayAfter(std, limit);
    return 0;
}