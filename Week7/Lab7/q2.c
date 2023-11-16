#include <stdio.h>

struct Person {
    char name[30];
    int salary;
    float tax;
};


int main() {
    struct Person person1, person2, person3;
    
    printf("Enter name: ");
    scanf("%s", person1.name);
    printf("Enter yearly salary: ");
    scanf("%d", &person1.salary);

    printf("Enter name: ");
    scanf("%s", person2.name);
    printf("Enter yearly salary: ");
    scanf("%d", &person2.salary);

    printf("Enter name: ");
    scanf("%s", person3.name);
    printf("Enter yearly salary: ");
    scanf("%d", &person3.salary);

    if (person1.salary <= 100000) {
        person1.tax = 0.0;
    } else if (person1.salary <= 150000) {
        person1.tax = 0.1 * (person1.salary - 100000);
    } else if (person1.salary <= 300000) {
        person1.tax = (person1.salary - 150000) * 0.2;
    } else {
        person1.tax = (person1.salary - 300000) * 0.3;
    }

    if (person2.salary <= 100000) {
        person2.tax = 0.0;
    } else if (person2.salary <= 150000) {
        person2.tax = 0.1 * (person2.salary - 100000);
    } else if (person2.salary <= 300000) {
        person2.tax = (person2.salary - 150000) * 0.2;
    } else {
        person2.tax = (person2.salary - 300000) * 0.3;
    }

    if (person3.salary <= 100000) {
        person3.tax = 0.0;
    } else if (person3.salary <= 150000) {
        person3.tax = 0.1 * (person3.salary - 100000);
    } else if (person3.salary <= 300000) {
        person3.tax = (person3.salary - 150000) * 0.2;
    } else {
        person3.tax = (person3.salary - 300000) * 0.3;
    }

    printf("Tax to be paid by %s = %.2lf\n", person1.name, person1.tax);
    printf("Tax to be paid by %s = %.2lf\n", person2.name, person2.tax);
    printf("Tax to be paid by %s = %.2lf\n", person3.name, person3.tax);

    return 0;
}