#include <stdio.h>

int main() {
    int grades[3];

    for (int i = 0; i < 3; i++) {
        printf("Enter student's grade: ");
        scanf("%d", &grades[i]);
    }

    for (int i = 0; i < 3; i++) {
        if (grades[i] > 5 && grades[i] < 10) {
        printf("Student's grade: %d\n", grades[i]);
        }
    }
    return 0;
}