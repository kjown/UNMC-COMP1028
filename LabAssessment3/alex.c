//Q1
#include <stdio.h>
#include <string.h>

// Function to translate SMS Language to English
void translateEnglish(char *smsMessage) {
    // Compare string with all english language in SMS dictionary
    if (strcmp(smsMessage, "lol") == 0) {
        printf("laughing out loud ");
    } else if (strcmp(smsMessage, "omg") == 0) {
        printf("oh my god ");
    } else if (strcmp(smsMessage, "omw") == 0) {
        printf("on my way ");
    } else if (strcmp(smsMessage, "brb") == 0) {
        printf("be right back ");
    } else if (strcmp(smsMessage, "idk") == 0) {
        printf("i don't know ");
    } else if (strcmp(smsMessage, "imo") == 0) {
        printf("in my opinion ");
    } else if (strcmp(smsMessage, "bff") == 0) {
        printf("best friend forever ");
    } else if (strcmp(smsMessage, "fyi") == 0) {
        printf("for your information ");
    } else if (strcmp(smsMessage, "tmi") == 0) {
        printf("too much information ");
    } else if (strcmp(smsMessage, "yolo") == 0) {
        printf("you only live once ");
    } else {
        printf("%s ", smsMessage); // Print the word as is
    }
}

// Function to translate English to SMS Language
void translateSMS(char *englishMessage) {
    englishMessage[strcspn(englishMessage, "\n")] = '\0';
    // Compare string with all SMS language in SMS dictionary
    if (strcmp(englishMessage, "laughing out loud") == 0) {
        printf("lol ");
    } else if (strcmp(englishMessage, "oh my god") == 0) {
        printf("omg ");
    } else if (strcmp(englishMessage, "on my way") == 0) {
        printf("omw ");
    } else if (strcmp(englishMessage, "be right back") == 0) {
        printf("brb ");
    } else if (strcmp(englishMessage, "i don't know") == 0) {
        printf("idk ");
    } else if (strcmp(englishMessage, "in my opinion") == 0) {
        printf("imo ");
    } else if (strcmp(englishMessage, "best friend forever") == 0) {
        printf("bff ");
    } else if (strcmp(englishMessage, "for your information") == 0) {
        printf("fyi ");
    } else if (strcmp(englishMessage, "too much information") == 0) {
        printf("tmi ");
    } else if (strcmp(englishMessage, "you only live once") == 0) {
        printf("yolo ");
    } else {
        printf("%s", englishMessage);
    }
}

int main() {
    char message[160]; // initialize arry for 160 characters
    char hold[160]; // temporary hold so message is not lost

    int choice; // initialize choice 
    printf("What translation?:\n"); //request for user input for which translation
    printf("1. SMS to English\n");
    printf("2. English to SMS \n");
    printf("Choice: ");
    scanf("%d", &choice); // read user input for their translation choice
    getchar(); // consume new line character

    switch (choice) {
        case 1:
            printf("\nEnter a message in SMS Language: "); // prompt for user input to translate
            fgets(message, sizeof(message), stdin); // read user input
            message[strcspn(message, "\n")] = '\0'; // remove newline from message

            printf("\nTranslation to English: "); // output after translation
            char *token = strtok(strcpy(hold, message), " "); // copy message to hold
            // tokenize message
            while (token != NULL) {
                translateEnglish(token); // call english translate function
                token = strtok(NULL, " "); 
            }
            break;

        case 2:
            printf("\nEnter a message in English: "); // prompt for user input to translate
            fgets(message, sizeof(message), stdin); // read user input
            //getchar();
            message[strcspn(message, "\n")] = '\0'; // remove newline from message
            

            printf("\nTranslation to SMS Language: "); // output after translation
            translateSMS(token); // call SMS translate function

            token = strtok(strcpy(hold, message), " "); // copy message to hold
            // tokenize message
            while (token != NULL) {
                translateSMS(token); // call SMS translate function
                token = strtok(NULL, " ");
            }
            break;
    } // end switch

    return 0;
} // end function main
