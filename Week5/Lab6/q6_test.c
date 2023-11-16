#include <stdio.h>

void replaceDuplicate(int *array) {
    for (int i = 0; i < 10; i++) {
        int current = array[i];

        for (int j = i + 1; j < 10; j++) {
            if (array[j] == current) {
                array[j] = -99;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[10];

    for (int i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    replaceDuplicate(array);

    return 0;
}