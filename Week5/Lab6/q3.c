#include <stdio.h>

int find_Max_Duplicate(int *array, int size) {
    int maxElement = 0;
    int maxCount = 0;
    for (int i = 0; i < size; i++) {
        int temp = array[i];
        int duplicate_count = 0;
        for (int j = i + 1; j < size; j++) {
            if (temp == array[j]) {
                duplicate_count++;
            }
            if (duplicate_count > maxCount) {
                maxCount = duplicate_count;
                maxElement = array[j];
            }
        }
    }
    return maxElement;
}

int main() {
    int array[5];
    int count = 0;
    int size = 0;

    printf("Enter an array of integers\n");
    while (count < 5) {
        scanf("%d", &array[size]);
        count += 1;
        size += 1;
    }
    int result = find_Max_Duplicate(array, size);

    printf("Element with the most occurences is: %d\n", result);

    return 0;
}