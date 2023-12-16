#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* engToSMS(char eng[]) {
  //check the input and return the corresponding sms abbreviation
  if (strcmp(eng, "laughing out loud") == 0) {
    return "lol";
  }
  if (strcmp(eng, "oh my god") == 0) {
    return "omg";
  }
  if (strcmp(eng, "on my way") == 0) {
    return "omw";
  }
  if (strcmp(eng, "be right back") == 0) {
    return "brb";
  }
  if (strcmp(eng, "I don't know") == 0) {
    return "idk";
  }
  if (strcmp(eng, "in my opinion") == 0) {
    return "imo";
  }
  if (strcmp(eng, "best friend ever") == 0) {
    return "bff";
  }
  if (strcmp(eng, "for your information") == 0) {
    return "fyi";
  }
  if (strcmp(eng, "too much information") == 0) {
    return "tmi";
  }
  if (strcmp(eng, "you only live once") == 0) {
    return "yolo";
  }

  //return null if no match
  return NULL;
}

char* SMSToEng(char abbr[]) {
  //check the input and return the corresponding english phrase
  if (strcmp(abbr, "lol") == 0) {
    return "laughing out loud";
  }
  if (strcmp(abbr, "omg") == 0) {
    return "oh my god";
  }
  if (strcmp(abbr, "omw") == 0) {
    return "on my way";
  }
  if (strcmp(abbr, "brb") == 0) {
    return "be right back";
  }
  if (strcmp(abbr, "idk") == 0) {
    return "I don't know";
  }
  if (strcmp(abbr, "imo") == 0) {
    return "in my opinion";
  }
  if (strcmp(abbr, "bff") == 0) {
    return "best friend forever";
  }
  if (strcmp(abbr, "fyi") == 0) {
    return "for your information";
  }
  if (strcmp(abbr, "tmi") == 0) {
    return "too much information";
  }
  if (strcmp(abbr, "yolo") == 0) {
    return "you only live once";
  }

  return NULL;
}

char *replace(const char *str, const char *substr, const char *replacement) {
    const char *pos = strstr(str, substr);

    if (pos == NULL) {
        // Return the original string if substring has no match
        return strdup(str);
    }

    // Calculate the new size of the string after replacement
    size_t newSize = strlen(str) - strlen(substr) + strlen(replacement) + 1;

    // Allocate memory for the modified string
    char *replacementStr = (char *)malloc(newSize);

    // Initialize the new string
    replacementStr[0] = '\0';

    // Pointer to keep track of the position in the original string
    const char *currentPos = str;

    while (pos != NULL) {
        // Copy the part before the substring
        strncat(replacementStr, currentPos, pos - currentPos);

        // Concatenate the replacement
        strcat(replacementStr, replacement);

        // Update the current position
        currentPos = pos + strlen(substr);

        // Find the next occurrence of the substring
        pos = strstr(currentPos, substr);
    }

    // Concatenate the remaining part of the original string
    strcat(replacementStr, currentPos);

    return replacementStr;
}

int main() {
    char *EngPhrases[] = {"laughing out loud", "oh my god", "on my way", "be right back", "I don't know", "in my opinion", "best friend ever", "for your information", "too much information", "you only live once"};

    char ans;
    char msg[161];

    while (1) { // Infinite loop until user chooses to exit
        printf("\n=== SMS LANGUAGE TRANSLATOR ===\n");
        printf("> 1. SMS Language to English\n");
        printf("> 2. English to SMS Language\n");
        printf("> Any other key to exit\n");
        printf("Input number and press ENTER: ");
        ans = fgetc(stdin);
        getchar();

        int c;
          switch (ans) {
              case '1':
                  // prompt user to input an SMS abbreviation
                  printf("Input SMS message: ");
                  scanf(" %[^\n]", msg); 
                  getchar();
                  char output[200] = "";

                  char *tokenPtr = strtok(msg, " ");

                  while (tokenPtr != NULL) {
                      char *ptr = SMSToEng(tokenPtr);
                      if (ptr != NULL) {
                          strcat(output, ptr);
                      } else {
                          strcat(output, tokenPtr);
                      }
                      tokenPtr = strtok(NULL, " ");
                      strcat(output, " ");
                  }

                  printf("Result: %s\n", output);
                  break;

              case '2':
                  // prompt user to input an English phrase
                  printf("Input English phrase: ");
                  fgets(msg, 161, stdin);

                  char *inputPtr = msg;
                  char *outputPtr = NULL;

                  for (int i = 0; i < 10; i++) {
                      outputPtr = replace(inputPtr, EngPhrases[i], engToSMS(EngPhrases[i]));
                      inputPtr = outputPtr;
                  }

                  printf("Result: %s\n", outputPtr);
                  break;

              default:
                  printf("Exiting program.\n");
                  return 0;
        }
    }

    // The loop will continue until the user chooses to exit
    return 0;
}