#include <stdio.h>

struct inventory {
    char partName[30];
    int part_Number;
    float price;
    int stock;
    int reorder;
};

struct address {
    char streetAddress[25];
    char city[20];
    char state[3];
    char zipCode[6];
};

struct student {
    char firstName[15];
    char lastName[15];
    struct address homeAddress;
};

int main() {
    return 0;
}