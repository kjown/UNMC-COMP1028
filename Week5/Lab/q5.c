#include <stdio.h>

int maxRow(int array[5][5]) {
    int max = array[0][0], temp;
    for (int i = 0; i < 5; i++) {
        int row_sum = 0;
        for (int j = 0; j < 5; j++) {
            row_sum += array[i][j];
        }
        temp = row_sum;
        if (temp > max) {
            max = temp;
        }
    }
    printf("Maximum sum store in row: %d\n", max);
}

int maxColumn(int array[5][5]) {
    int max = array[0][0], temp;
    for (int j = 0; j < 5; j++) {
        int col_sum = 0;
        for (int i = 0; i < 5; i++) {
            col_sum += array[i][j];
        }
        temp = col_sum;
        if (temp > max) {
            max = temp;
        }
    }
    printf("Maximum sum in column is: %d\n", max);
}

int main() {
    int array[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Enter an integer: ");
            scanf("%d", &array[i][j]);
        }
    }

    maxRow(array);
    maxColumn(array);

    return 0;
}