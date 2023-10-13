#include <stdio.h>  // Include the standard i/o library

int main() {
    int paycode;  // Declare an integer variable 'paycode' to store the pay code entered by the user.

    // Prompt the user to input a pay code.
    printf("Input pay code: ");
    scanf("%d", &paycode);  // Read and store the pay code entered by the user.

    switch (paycode) {
    case 1:
        double manager_salary;  // Declare a double variable 'manager_salary' to store the manager's weekly salary.

        // Prompt the user to enter the manager's weekly salary.
        printf("Please enter your weekly salary: $");
        scanf("%lf", &manager_salary);  // Read and store the manager's weekly salary.

        // Display the weekly pay of the manager.
        printf("Weekly pay of manager: $%.2lf\n", manager_salary);
        break;

    case 2:
        double hours;  // Declare a double variable 'hours' to store the number of hours worked by an hourly worker.
        double worker_salary;  // Declare a double variable 'worker_salary' to store the worker's weekly salary.
        double hourly_wage;  // Declare a double variable 'hourly_wage' to store the worker's hourly wage.

        // Prompt the user to enter the hours worked this week and the hourly wage.
        printf("Please enter hours worked this week: ");
        scanf("%lf", &hours);
        printf("Please enter hourly wage: $");
        scanf("%lf", &hourly_wage);

        // Calculate the worker's weekly salary based on hours worked and hourly wage.
        if (hours > 40) {
            worker_salary = 40 * hourly_wage;
            worker_salary += ((hours - 40) * hourly_wage * 1.5);
        }

        // Display the weekly pay of hourly workers.
        printf("Weekly pay of hourly workers: $%.2lf\n", worker_salary);
        break;

    case 3:
        double gross_weekly_sales;  // Declare a double variable 'gross_weekly_sales' to store the gross weekly sales for commission workers.
        double commission_worker_salary;  // Declare a double variable 'commission_worker_salary' to store the worker's weekly salary.

        // Prompt the user to enter the gross weekly sales.
        printf("Gross weekly sales: ");
        scanf("%lf", &gross_weekly_sales);

        // Calculate the commission worker's weekly salary.
        commission_worker_salary = 250 + (0.057 * gross_weekly_sales);

        // Display the weekly pay of commission workers.
        printf("Weekly pay of commission workers: $%.2lf\n", commission_worker_salary);
        break;

    case 4:
        int num_of_item;  // Declare an integer variable 'num_of_item' to store the number of items produced by pieceworkers.
        double price_of_item;  // Declare a double variable 'price_of_item' to store the price per item.
        double piece_worker_salary;  // Declare a double variable 'piece_worker_salary' to store the worker's weekly salary.

        // Prompt the user to enter the number of items produced and the price per item.
        printf("Number of items produced: ");
        scanf("%d", &num_of_item);
        printf("Price per item: $");
        scanf("%lf", &price_of_item);

        // Calculate the pieceworker's weekly salary.
        piece_worker_salary = num_of_item * price_of_item;

        // Display the weekly pay of pieceworkers.
        printf("Weekly pay of pieceworker: $%.2lf\n", piece_worker_salary);
        break;

    default:
        // Handle the default case if the entered pay code is not recognized.
        break;
    }

    return 0;  // Return 0 to indicate successful program execution.
}