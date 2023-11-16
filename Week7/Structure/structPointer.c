#include <stdio.h>

struct Point 
{
    int x, y;
};

int main() {
    struct Point str = {1, 2};
    
    // p2 is a pointer to structure p1
    struct Point* ptr = &str;
    
    
    printf("%d %d\n", ptr->x, ptr->y);

    return 0;
}
