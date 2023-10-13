#include <stdio.h>
#include <strings.h>

int main() {
    char name1 = 'O';
    char name2 = 'w';
    char name3 = 'n';

    char name[5] = "Khoo";
    printf("%c\n%d\n%o\n%x\n", name[0], name[0], name[0], name[0]);

    printf("My name is %c%c%c\n\n", name1, name2, name3);

    printf("The decimal of %c is %d\n", name1, name1);
    printf("The hexadecimal of %c is %x\n", name1, name1);
    printf("The octal of %c is %o\n\n", name1, name2);

    printf("The decimal of %c is %d\n", name2, name2);
    printf("The hexadecimal of %c is %x\n", name2, name2);
    printf("The octal of %c is %o\n\n", name2, name2);

    return 0;
}