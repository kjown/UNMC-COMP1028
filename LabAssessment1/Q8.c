#include <stdio.h> // Include the standard i/o library

int main() {
    int pay_code; // Declare variable pay_code 

    printf("Input pay code: "); // Prompt user to input paycode
    scanf("%d", &pay_code); // Read the value of pay_code inputted by user

    switch (pay_code) {
    // Managers
    case 1:
        double manager_weekly_salary; // Declare variable of manager_weekly_salary

        printf("Please enter your weekly salary: $"); // Display message to prompt user to input weekly salary of manager
        scanf("%lf", &manager_weekly_salary); // Read value inputted by user

        printf("Weekly pay of manager: $%.2lf\n", manager_weekly_salary); // Display the weekly salary of manager
        break;

    case 2:
    // Hourly worker
        double num_of_hours; // Declare variable num_of_hours
        double hourly_pay; // Declare variable of hourly_pay
        double total_salary_of_hourly_worker; // Declare variable total_salary_of_hourly_worker

        // Prompt the user for input of num_of_hours and hourly_pay
        printf("Enter hours worked this week: ");
        scanf("%lf", &num_of_hours);
        printf("Enter hourly pay: $");
        scanf("%lf", &hourly_pay);

        // Calculate the worker's weekly salary 
        if (num_of_hours > 40) {
            total_salary_of_hourly_worker = 40 * hourly_pay;
            total_salary_of_hourly_worker += ((num_of_hours - 40) * hourly_pay * 1.5);
        }

        // Display the weekly pay of hourly workers.
        printf("Weekly pay of hourly workers: $%.2lf\n", total_salary_of_hourly_worker);
        break;

    case 3:
        double gross_weekly_sales; // Declare variable gross_weekly_sales
        double total_commission_worker_salary; // Declare variable total_commission_worker_salary

        printf("Gross weekly sales: "); // Prompt the user to enter the gross weekly sales.
        scanf("%lf", &gross_weekly_sales); // Read the value inputted by user

        // Calculate the commission worker's weekly salary.
        total_commission_worker_salary = 250 + (0.057 * gross_weekly_sales);

        // Display the weekly pay of commission workers.
        printf("Weekly pay of commission workers: $%.2lf\n", total_commission_worker_salary);
        break;

    case 4:
        int number_of_items; // Declare variable number_of_items
        double item_price; // Declare variable item_price
        double total_piece_worker_salary;  // Declare variable total_piece_worker_salary

        printf("Number of items produced: "); // Prompt user for number of items
        scanf("%d", &number_of_items); // Read input by user
        printf("Price per item: $"); // Prompt user for item_price
        scanf("%lf", &item_price); // Read input by user

        total_piece_worker_salary = number_of_items * item_price; // Calculation for salary of pieceworker

        // Display the weekly pay of pieceworkers.
        printf("Weekly pay of pieceworker: $%.2lf\n", total_piece_worker_salary);
        break;

    default:
        break;
    }

    return 0; // Program will execute successfully and did what it was intended to do
}