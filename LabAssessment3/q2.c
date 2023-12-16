#include <stdio.h>
#include <string.h>
#define SPAM_KEYWORDS 30    // size of the number of spam keywords
#define EMAIL_WORDCOUNT 1000    // size of the email input by user

// array for the spam keywords
char *spam_keywords[SPAM_KEYWORDS] = {"money", "free", "click", "subscribe", "winner", "prize", "urgent", "limited time", "offer", "guaranteed", "shocking", "incredible", "work from home", "billion dollars", "lowest price", "credit", "card", "debt", "earn", "extra cash", "fast cash", "hidden", "income", "investment", "multi-level marketing", "no fees", "opportunity", "promise", "win", "act now"};

int spamScan(char *email);

int main() {
    char email[EMAIL_WORDCOUNT];
    // UI
    puts("====================");
    puts(">>> SPAM SCANNER <<<");
    puts("====================");
    printf("Insert e-mail below:\n");   // prompt user for input
    // Read message into a large char array
    fgets(email, EMAIL_WORDCOUNT, stdin);
    // remove trailing '\n' from fgets input
    email[strcspn(email, "\n")] = 0;
    
    // get the spamScore result from spanScan()
    int spamScore = spamScan(email);
    printf("Spam Score: %d\n", spamScore);
    if  (spamScore > 10) {
        // VERY likely to be a spam email if spamScore > 10
        puts("Spam Likelihood: HIGH");
    }
    if (spamScore > 5) {
        // Likely to be a spam email if spamScore > 5
        puts("Spam Likelihood: MDDERATE");
    }
    if (spamScore <= 5) {
        // Umlikely to be a spam email if spamScore <= 5
        puts("Spam Likelihood: LOW");
    }
    puts("");

    return 0;
}

int spamScan(char *email) {
    int spamScore = 0;

    for (int j = 0; j <= SPAM_KEYWORDS; j++) {
        // finds the occurence of spam_keywords in the email message
        char *match = strstr(email, spam_keywords[j]);
        while (match != NULL) {
            // if match, increment spamScore
            spamScore++;
            // finds next matching spam_keywords
            match = strstr(match + 1, spam_keywords[j]);
        }
    }
    return spamScore;
}
