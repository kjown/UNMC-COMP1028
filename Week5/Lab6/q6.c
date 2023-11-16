#include <stdio.h>

void replace_duplicate(int *array) {
    for (int i = 0; i < 10; i++) {
        int current = array[i];

        for (int j = i + 1; j < 10; j ++){
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
    int i = 1;
    for (i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    replace_duplicate(array);

    return 0;
}