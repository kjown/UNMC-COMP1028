#include <stdio.h>

struct card {
    const char *face;
    const char *suit;
};

int main() {
    struct card myCard;

    myCard.face = "Ace";
    myCard.suit = "Spades";

    struct card *cardPtr = &myCard;

    printf("%s of %s\n", myCard.face, myCard.suit);
    printf("%s of %s\n", cardPtr->face, cardPtr->suit);
    printf("%s of %s\n", (*cardPtr).face, (*cardPtr).suit);

    return 0;
}