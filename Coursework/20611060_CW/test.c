#include <stdio.h>
#include <string.h>


int main() {
    char str[10] = "hello";

    int length, i;
    char *start, *end, temp;

    length = strlen(str);
    start = str;
    end = str;

    for (i = 0; i < length - 1; i++)
    {
        end++;
    }
    for (i = 0; i < length / 2; i++)
    {
        temp = *end;
        *end = *start;
        *start = temp;

        start++;

        end--;
    }
}