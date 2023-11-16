#include <stdio.h> // standard input and output library

int assign_seat(int class, int seatsArray[]); // function protype to assign_seat
int display_pass(int reserved); // function prototype to display boarding pass
int firstClass(int seatsArray[]); // function prototype to assign seat in first class
int economy(int seatsArray[]); // function prototype to assign seat in economy

int main() {
    int seatsArray[10] = {0}; // initialise all 10 elements of the array to 0
    int class; // initliase variable to store type of section chosen by 
    int seatNumber; // initialise variable seat number
    char ans; // initialise variable ans to store input y/n

    // loop until break
    while(1) {
        // prompt user to enter type of class (1 or 2)
        printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"\n");
        scanf("%d", &class); // read input of class from user

        while (class != 1 && class != 2) {
            // algorithm to validate input from user (accept 1 or 2 only)
            printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"\n");
            scanf("%d", &class); // read and store input from user to variable class
        }
        int result = assign_seat(class, seatsArray); // store return value of assign_seat to variable result
        if (result == -1) {
            break; // if plane is full, stop procedure of ending the program
        }
        else {
            continue; // if plane not full, continue
        }
    }
    return 0; // program executed successfully
}

// function to assign seat
int assign_seat(int class, int seatsArray[]) {

    int reserved; // initialise variable reserved
    char ans; // initialise variable ans
	int	print_boarding; // variable to determine whether to print boarding pass

	print_boarding = 1; // initialise print_boarding to 1, as default state to print boarding pass
    // First Class
    if (class == 1) {
        // assign reserved value to value returned from function firstClass
        reserved = firstClass(seatsArray);
        if (!reserved) {
            // When firstClass is full, prompt user whether or not to change to economy sectiom
            printf("The first-class section is full.\nWould you want us to arrange a seat in the economy section? (y/n)\n");
            scanf("%1s", &ans); // read and store input from user
            if (ans == 'y') { // if user answer y, then assign seat in economy section
                reserved = economy(seatsArray);
                if (!reserved) { // if economy section is full too, then print relevant message 
                    printf("Apologies. All seats on the plane are full.\nNext flight leaves in 3 hours.\n");
					print_boarding = 0; // no boarding pass will be displayed
                    return -1; // return -1 tell main() to end program
                } 
            }
            if (ans == 'n') { //if user answers n. then print relevant mesage and undergo ending procedure
                printf("Next flight leaves in 3 hours.\n");
				print_boarding = 0; // no boarding pass will be displayed
                return -1; // return -1 to tell main() to end the program
            }
        }
    }
    // Economy
    if (class == 2) { 
         // assign reserved value to value returned from function economy()
        reserved = economy(seatsArray);
        if (!reserved)  {
            // if economy section is full, then ask user whether or not to assign seat in first class section
            printf("The economy class is full.\nWould you want us to arrange a seat in the first class section? (y/n)\n");
            scanf("%1s", &ans); // read and store input from user
            if (ans == 'y') {
                reserved = firstClass(seatsArray); // if user answers y, then find seat in first c;ass section
                if (!reserved) {
                    // if plane if full, print apology message and end program
                    printf("Apologies. All seats on the plane are full.\nNext flight leaves in 3 hours.\n");
					print_boarding = 0;
                    return -1;
                }
            }
            if (ans == 'n') {
                // if user answers n, then print message and end
                printf("Next flight leaves in 3 hours.\n");
				print_boarding = 0;
                return -1;
            }
         }
    }
    // if print_boarding is True, then call function display_pass() to print boarding pass 
	if (print_boarding) {
        display_pass(reserved);
    }
}

// function to assign seat for user in the first class section
int firstClass(int seatsArray[]) {
    int reservedSeat = 0; // initialise number of reserved seat in first class to be 0
    // procedure to handle reservation of seats in first class section
    for (int seat = 0; seat < 5; seat++) {
        if (seatsArray[seat] == 0) {
            seatsArray[seat] = 1;
            reservedSeat = seat + 1;
            break;
        }
    }
    return reservedSeat; // return number of reserved seats in first class
}

// function to assign seat in economy section
int economy(int seatsArray[]) {
    int reservedSeat = 0; // initialise number of reserved seat in economy section to 0
    // procedure to handle reservation of seats in economy section
    for (int seat = 5; seat <= 10; seat++) {
        if (seatsArray[seat] == 0) {
            seatsArray[seat] = 1;
            reservedSeat = seat + 1;
            break;
        }
    }
    return reservedSeat; // return number of reserved seat in economy section
}

// function to display the boarding pass
int display_pass(int reserved) {
    printf("\n---BOARDING PASS----\n");
    printf("Seat Number: %d\n", reserved); // display the seat number
    if (reserved > 5) {
        // if seat number is > 5, then it is in economy class
        printf("Section: Economy\n");
    }
    if (reserved <= 5) {
        // if seat number < 5, the it is in first class
        printf("Section: First-Class\n");
    }
    printf("--------------------\n\n");
}