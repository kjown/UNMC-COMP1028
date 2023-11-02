#include <stdio.h>

int check_first_class(int *seats);
int check_economy(int *seats);
void print_boarding_pass(char* name, int seat);

int main() {
  int seats[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};//an array that represent the plane's seating chart
  int x;//store 1 or 0
  char response;//store the user's input whether or not he accept a seat in another section
  int reserved_seat;//store the seat number reserved by the user
  char name[30];//store user's name
  char if_continue;//store the user's input whether or not he want to continue the next input

  while(1) {
    printf("Please enter your name: ");//prompt user to input his name
    scanf("%s", name);
    printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\"\n");//prompt user to select between first class and economy section
    scanf("%d", &x);

    if (x == 1) {//if the person choose first-class section
      reserved_seat = check_first_class(seats);//check if there is any seat is available in the first class section

      if (!reserved_seat) {//if the first class section is full
        printf("Sorry! The first-class section is full.\nCould we assign a seat in economy section for you? (y or n)");//prompt user to input whether or not he accept a seat in the economy section
        scanf(" %c", &response);

        if (response == 'y') {//if user accepts to be placed in the economy section
          reserved_seat = check_economy(seats);//check if there is any seat is available in the economy section
          if (!reserved_seat) {//if the economy section is also full
            printf("Sorry! All seats is full.");
          } else {//if there is a seat available in the economy section
            print_boarding_pass(name, reserved_seat);
          }
        } else {//if user don't accept to be placed in the economy section
          printf("Next flight leaves in 3 hours.");
        }

      } else {//if there is a seat available in first class section
        print_boarding_pass(name, reserved_seat);
      }  
    }

    if (x == 0) {//if the person choose economy section
      reserved_seat = check_economy(seats);//check if there is any seat is available in the economy section
      if (!reserved_seat) {//if the economy section is full
        printf("Sorry! The economy section is full.\nCould we assign a seat in first-class section for you? (y or n)");//prompt user to input whether or not he accept a seat in the first-class section
        scanf(" %c", &response);
        if (response == 'y') {//if user accepts to be placed in the first-class section
          reserved_seat = check_first_class(seats);//check if there is any seat is available in the first-class section
          if (!reserved_seat) {//if the first-class section is also full
            printf("Sorry! All seats is full.");
          } else {//if there is a seat available in the first-class section
            print_boarding_pass(name, reserved_seat);
          }
        } else {//if user don't accept to be placed in the first-class section
          printf("Next flight leaves in 3 hours.");
        }
      } else {//if there is a seat available in economy class
        print_boarding_pass(name, reserved_seat);
      }  
    }

    printf("Would you like to continue? (y or n)");//ask user if he want to proceed to the next input
    scanf(" %c", &if_continue);
    if (if_continue == 'n') {
      break;//if user input 'n', break the while-loop
    }
  }

  return 0;
}

//check if there is any seat in first-class section. If so, return the seat number; if not, return 0
int check_first_class(int *seats) {
  int reserved_seat = 0;
  for (int i = 0; i < 5; i++) {
    if (seats[i] == 0) {//if there is any seat available in first-class section
      seats[i] = 1;//set the element to 1 to indicate that the seat is no longer available 
      reserved_seat = i + 1;//store the set number
      break;
    }
  }
  return reserved_seat;
}

//check if there is any seat in economy section. If so, return the seat number; if not, return 0
int check_economy(int *seats) {
  int reserved_seat = 0;
  for (int i = 5; i < 10; i++) {//if there is any seat available in economy section
    if (seats[i] == 0) {
      seats[i] = 1;//set the element to 1 to indicate that the seat is no longer available
      reserved_seat = i + 1;//store the seat number
      break;
    }
  }
  return reserved_seat;
}

void print_boarding_pass(char* name, int seat) {
  printf("=======================================\n");
  printf("      AIRLINE BOARDING PASS\n");
  printf("=======================================\n");
  printf("Passenger Name: %s\n", name);
  printf("Flight Number: XYZ123\n");
  printf("Departure City: New York\n");
  printf("Destination City: Los Angeles\n");
  printf("Departure Date: 2023-11-01\n");
  printf("Departure Time: 08:00 AM\n");
  printf("Seat Number: %d\n", seat);
  printf("Gate: 5\n");
  printf("Boarding Time: 07:30 AM\n");
  printf("=======================================\n");
}