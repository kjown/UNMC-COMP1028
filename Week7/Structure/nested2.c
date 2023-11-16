#include <stdio.h>

struct base {
    struct child {
        int i;
    }child;
};

int main() {
    struct base s_name = { 12 };

    printf("Nested Structure variable: %d\n", s_name.child.i);
    return 0;
}