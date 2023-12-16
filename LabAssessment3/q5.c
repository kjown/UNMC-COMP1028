#include <stdio.h>
// struct to store details of a worker
typedef struct worker {
    char name[10];
    int wage;
    int days;
    int payment;
} Worker;

int main() {
    Worker worker1; // initialise variable worker1
    Worker worker2; // initialise variabble worker2

    // prompt user to enter details of worker1
    printf("Enter details of first worker:\n");
    printf("Name: ");
    scanf("%s", worker1.name);

    printf("Wage: ");
    scanf("%d", &worker1.wage);

    printf("Days: ");
    scanf("%d", &worker1.days);

    // prompt user to enter details of worker2
    printf("\nEnter details of second worker:\n");
    printf("Name: ");
    scanf("%s", worker2.name);

    printf("Wage: ");
    scanf("%d", &worker2.wage);

    printf("Days: ");
    scanf("%d", &worker2.days);

    // calculate the payment of both workers by multiplying wage and days
    worker1.payment = worker1.wage * worker1.days;
    worker2.payment = worker2.wage * worker2.days;

    // display the payment of worker1
    printf("\nFirst worker: %s\n", worker1.name);
    printf("Payment: %d\n\n", worker1.payment);
    // display the payment of worker2
    printf("Second worker: %s\n", worker2.name);
    printf("Payment: %d\n", worker2.payment);

    return 0;
}