#include <stdio.h>

typedef struct data{
    const char *firstname;
    const char *lastname;
    int age;
}Data;

void test(Data[]);  // prototype of function
void test2(Data *); //prototype of function pass by referenec
void test3(Data);   // prototype of function pass by value

int main() {
    Data x1[2] = {{"a", "b", 30}, {"a1", "b1", 31}};
    Data x2 = {"a", "b", 30};

    test(x1);
    test2(&x2);
    test3(x2);
    printf("The data of %s and %s is miss-matched\nwhile %s", x1[0].firstname, x1[1].firstname, x1->firstname);
}

void test(Data a1[])
{
    a1[0].age = 32;
    a1[0].firstname = "Yasir3";
    a1[0].lastname = "Hafeez3";
     printf("\nTest: The data of %s and %s is miss-matched\nwhile %s\n",a1[0].firstname,a1[1].firstname,a1->firstname);
}

void test2(Data *a)
{
    (*a).age=34;
    (*a).firstname="Yasir";
    printf("\nTest2: The data of (from Test2) %s and %s is miss-matched\nwhile %d\n",a->firstname,(*a).lastname,a->age);
}

void test3(Data a)
{
    printf("\nTest3: The data of %s %s is age %d\n",a.firstname,a.lastname,a.age);
}
