#include <stdio.h> // standard input output library
#include <stdlib.h> // standard library of C
#include <time.h> //time library

void check(int guess, int random); // function prototype to check input with random number generated

void play(); // function prototype start the guessing game


int main() {
    play(); // call function to start the guessing game

    return 0;
}

void check(int guess, int random) {
    // loop until input is equal to random
    while (guess != random) {
        if (guess < random) {
            // display message to input again if guess < random
            printf("It's too low. Please try again. ");
            scanf("%d", &guess); // read user input
        }
        if (guess > random) {
            // display message to input again if guess > random
            printf("It's too high. Please try again. ");
            scanf("%d", &guess); // read user input
        }
    }
    printf("Great! That's correct!\n"); // print message if guess == random

    char ans; // initialise the ans variable
    printf("Would you like to play again (y or n)? "); // ask user whether want to play again or not
    getchar(); // function that takes a single input character from standard input
    scanf("%c", &ans); // read input from user
    if (ans == 'y') {
        // start game again if ans == y
        play();
    }
    if (ans == 'n') {
        printf("End\n"); // end program if ans == n
    }
}

void play() {
    int guess; // initialise variable guess to store user input
    int random;  //initialise variable random to store the random number generated

    srand(time(NULL));  //randomize seed
    random = rand() % 100 + 1; // random number between 1 and 100
    // print message and prompt user to guess the random number
    printf("I have an integer between 1 and 100.\nCan you guess my integer?\nPlease type your first guess: ");
    scanf("%d", &guess); // read guess from user 

    check(guess, random); // call function to check the user input whether equals to random number generated
}