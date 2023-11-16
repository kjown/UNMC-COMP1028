#include <stdio.h>

struct str1 
{
    char a;
};

// defining new name for str1
typedef struct str1 str1;

// another way of using typedef
typedef struct str2 {
    int x;
} str2;

int main() {
    str1 var1 = {'a'};
    str2 var2 = { 314 };

    printf("var1.a = %c\n", var1.a);
    printf("var2.x = %d\n", var2.x);

    return 0;
}
