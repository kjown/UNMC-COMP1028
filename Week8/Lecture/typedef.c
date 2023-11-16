#include <stdio.h>

typedef struct data
{
    const char *firstName;
    const char *lastName;
    int age;
}Data;

int main() {
    Data x1[2] = {{"huh", "bruh", 69}, {"huh1", "bruh1", 70}};
    Data x2 = {"huh", "bruh", 69};

    printf("The data of %s and %s is miss-matched\nwhile %s", x1[0].firstName, x1[1].firstName, x1->firstName);    

    printf("\nThe data without array is: %s age: %d", x2.firstName, x2.age);
    puts("");
    
    return 0;
}