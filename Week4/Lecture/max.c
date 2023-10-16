#include <stdio.h>

int getMax(int* arr, int size) {
    int max = arr[0];
    for (int i = 1; i <= 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[5];

    for ;

    printf("Largest value in array: %d\n", getMax(arr, 5));

    return 0;
}