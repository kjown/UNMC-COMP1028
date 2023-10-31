#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void check(int guess, int random);

void play();


int main() {
    play();

    return 0;
}

void check(int guess, int random) {
    while (guess != random) {
        if (guess < random) {
            printf("It's too low. Please try again. ");
            scanf("%d", &guess);
        }
        if (guess > random) {
            printf("It's too high. Please try again. ");
            scanf("%d", &guess);
        }
    }
    printf("Great! That's correct!\n");

    char ans;
    printf("Would you like to play again (y or n)? ");
    getchar();
    scanf("%c", &ans);
    if (ans == 'y') {
        play();
    }
    if (ans == 'n') {
        printf("End\n");
    }
}

void play() {
    int guess;
    int random; 

    srand(time(NULL));  //randomize seed
    random = rand() % 100 + 1;

    printf("I have an integer between 1 and 100.\nCan you guess my integer?\nPlease type your first guess: ");
    scanf("%d", &guess);

    check(guess, random);
}