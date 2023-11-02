#include <stdio.h>

int assign_seat(int class, int seatsArray[]);
int display_pass(int reserved);
int firstClass(int seatsArray[]);
int economy(int seatsArray[]);

int main() {
    int seatsArray[10] = {0};
    int class;
    int seatNumber;
    char ans;

    while(1) {
        printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"\n");
        scanf("%d", &class);

        while (class != 1 && class != 2) {
            printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"\n");
            scanf("%d", &class);
        }
        int result = assign_seat(class, seatsArray);
        if (result == -1) {
            break;
        }
        else {
            continue;
        }
    }
    return 0;
}

int assign_seat(int class, int seatsArray[]) {

    int reserved;
    char ans;
	int	print_boarding;

	print_boarding = 1;
    // First Class
    if (class == 1) {
        reserved = firstClass(seatsArray);
        if (!reserved) {
            printf("The first-class section is full.\nWould you want us to arrange a seat in the economy section? (y/n)\n");
            scanf("%1s", &ans);
            if (ans == 'y') {
                reserved = economy(seatsArray);
                if (!reserved) {
                    printf("Apologies. All seats on the plane are full.\nNext flight leaves in 3 hours.\n");
					print_boarding = 0;
                    return -1;
                }
            }
            if (ans == 'n') {
                printf("Next flight leaves in 3 hours.\n");
				print_boarding = 0;
                return -1;
            }
        }
    }
    // Economy
    if (class == 2) {
        reserved = economy(seatsArray);
        if (!reserved)  {
            printf("The economy class is full.\nWould you want us to arrange a seat in the first class section? (y/n)\n");
            scanf("%1s", &ans);
            if (ans == 'y') {
                reserved = firstClass(seatsArray);
                if (!reserved) {
                    printf("Apologies. All seats on the plane are full.\nNext flight leaves in 3 hours.\n");
					print_boarding = 0;
                    return -1;
                }
            }
            if (ans == 'n') {
                printf("Next flight leaves in 3 hours.\n");
				print_boarding = 0;
                return -1;
            }
         }
    }
	if (print_boarding) {
        display_pass(reserved);
    }
}

int firstClass(int seatsArray[]) {
    int reservedSeat = 0;
    for (int seat = 0; seat < 5; seat++) {
        if (seatsArray[seat] == 0) {
            seatsArray[seat] = 1;
            reservedSeat = seat + 1;
            break;
        }
    }
    return reservedSeat;
}

int economy(int seatsArray[]) {
    int reservedSeat = 0;
    for (int seat = 5; seat <= 10; seat++) {
        if (seatsArray[seat] == 0) {
            seatsArray[seat] = 1;
            reservedSeat = seat + 1;
            break;
        }
    }
    return reservedSeat;
}


int display_pass(int reserved) {
    printf("---BOARDING PASS----\n");
    printf("Seat Number: %d\n", reserved);
    if (reserved > 5) {
        printf("Section: Economy\n");
    }
    else {
        printf("Section: First-Class\n");
    }
    printf("--------------------\n\n");
}