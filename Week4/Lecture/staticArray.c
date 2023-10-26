#include <stdio.h>

void staticArrayInit(void);
void automaticArrayInit(void);

int main(void) {
    puts("First call to each function:");
    staticArrayInit();
    automaticArrayInit();
    puts("");

    puts("\nSecomd call: ");
    staticArrayInit();
    automaticArrayInit();
    puts("");
}

// function to demonstrate a static local array
void staticArrayInit(void) {
    // initializes element to 0 before function is called
    static int array1[3];

    puts("\nValues on entering staticArrayInit: ");

    // output contents of array
    for (size_t i = 0; i <= 2; ++i) {  // Note: Change `<=` to `<`
        printf("array1[%zu] = %d\n", i, array1[i]);
    }
    puts("Values on exiting staticArrayInit: ");

    // modify and output contents of array1
    for (size_t i = 0; i <= 2; ++i) {  // Note: Change `<=` to `<`
        printf("array1[%zu] = %d\n", i, array1[i] += 5);
    }
}

// function to demonstrate automatic local array
void automaticArrayInit(void) {
    // init elements each time function is called
    int array2[3] = {1, 2, 3};

    puts("\nValues on entering automaticArrayInit: ");

    // output contents of array2
    for (size_t i = 0; i <= 2; ++i) {  // Note: Change `<=` to `<`
        printf("array2[%zu] = %d\n", i, array2[i]);
    }

    puts("Values on exiting automaticArrayInit: ");

    // modify and output contents of array2
    for (size_t i = 0; i <= 2; ++i) {  // Note: Change `<=` to `<`
        printf("array2[%zu] = %d\n", i, array2[i] += 5);
    }
}