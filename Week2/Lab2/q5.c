#include <stdio.h>

int main() {
    int product_num, quantity;
    double price, total;
    printf("Enter product number: ");
    scanf("%d", &product_num);

    printf("Quantity: ");
    scanf("%d", &quantity);

    switch (product_num) {
        case 1:
            price = 2.98;
            break;
        case 2:
            price = 4.50;
            break;
        case 3:
            price = 9.98;
            break;
        case 4:
            price = 4.49;
            break;
        case 5:
            price = 6.87;
            break;
    }
    total = quantity * price;

    printf("For Product number %d, the retail price is $%.2lf.\nThe total value of %d sold items is: $%.2lf\n", product_num, price, quantity, total);
}