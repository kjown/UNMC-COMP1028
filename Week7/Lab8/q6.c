#include <stdio.h>
#include <string.h>

struct data {
    char name[30];
    int ac_no;
    char ac_type[10];
    float balance;
};

int main() {
    struct data data1;
    struct data *dataPtr;
    dataPtr = &data1;

    printf("Enter name: ");
    fgets(data1.name, 30, stdin);

    printf("Enter account number: ");
    scanf("%d", &dataPtr->ac_no);
    getchar();

    printf("Enter account type: ");
    //scanf("%s", data1.ac_type);
    fgets(data1.ac_type, 10, stdin);

    printf("Enter Balance: ");
    scanf("%f", &dataPtr->balance);

    printf("\nName=%sAccountNo=%d\nAccount Type=%sBalance=%.2f\n", data1.name, dataPtr->ac_no, data1.ac_type, dataPtr->balance);
    return 0;
}