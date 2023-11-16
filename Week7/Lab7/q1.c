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
    scanf("%s", data1.name);

    printf("Enter account number: ");
    scanf("%d", &dataPtr->ac_no);

    printf("Enter account type: ");
    scanf("%s", data1.ac_type);

    printf("Enter Balance: ");
    scanf("%f", &dataPtr->balance);

    printf("\nName=%s\tAccountNo=%d\tAccount Type=%s\tBalance=%.2f */\n", data1.name, dataPtr->ac_no, data1.ac_type, dataPtr->balance);
    return 0;
}