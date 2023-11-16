#include <stdio.h>

struct str1{
    int i;
    char c;
    float f;
    char s[30];
};

struct str2 {
    int ii;
    char cc;
    float ff;
} var;  // variable declaration with structure template

int main() {
    struct str1 var1 = {1, 'A', 1.00, "huh"},
                var2;
    struct str2 var3 = {.ff = 5.00, .ii = 5, .cc = 'a'};

    var2 = var1;

    printf("Struct 1: \n\ti = %d, c = %c, f=%f, s=%s\n", var1.i, var1.c, var1.f, var1.s);

    printf("Struct 2: \n\ti = %d, c = %c, f = %f, s = %s\n", var2.i, var2.c, var2.f, var2.s);

    printf("Struct 3: \n\ti = %d, c = %c, f = %f\n", var3.ii, var3.cc, var3.ff);

    return 0;
}
