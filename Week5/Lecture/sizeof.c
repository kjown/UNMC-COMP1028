#include <stdio.h>
#define SIZE 20

size_t getSize(const float *ptr);


int main() {
    float array[SIZE];
    
    printf("Number of bytes in the array is %zu\n", sizeof(array));
    printf("Number of bytes returned by getSize is %zu\n", getSize(array));

}

size_t getSize(const float *ptr) {
    
}