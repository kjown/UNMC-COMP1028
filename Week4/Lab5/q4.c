#include <stdio.h>
#define SIZE 15
// function prototypes
int binarySearch(const int b[], int key, size_t low, size_t high);
void printHeader(void);
void printRow(const int b[], size_t low, size_t mid, size_t high);
// function main begins program execution
int main(void) {
   int a[SIZE] = {0}; // create array a
   // create data
   for (size_t i = 0; i < SIZE; ++i) {
      a[i] = 2 * i;
   } 
   printf("%s", "Enter a number between 0 and 28: ");
   int key = 0; // value to locate in array a
   scanf("%d", &key);
   printHeader();
   // search for key in array a
   int result = binarySearch(a, key, 0, SIZE - 1);
   // display results
   if (result != -1) {
      printf("\n%d found at subscript %d\n", key, result);
   } 
   else {
      printf("\n%d not found\n", key);
   } 
} 
// function to perform binary search of an array
int binarySearch(const int b[], int key, size_t low, size_t high) {
   // loop until low subscript is greater than high subscript
      size_t middle = (low + high) / 2; // determine middle subscript
      if (low > high) {
         return -1;
      }
      // display subarray used in this loop iteration
      printRow(b, low, middle, high);
      // if key matches, return middle subscript
      if (key == b[middle]) {
         return middle;                                       
      }                                           
      else if (key < b[middle]) { // if key < b[middle], adjust high
         high = middle - 1; // next iteration searches low end of array
         return binarySearch(b, key, low, high);
      }  
      else { // key > b[middle], so adjust low
         low = middle + 1; // next iteration searches high end of array
         return binarySearch(b, key, low, high);
      }                                            
} 
// Print a header for the output
void printHeader(void) {
   puts("\nSubscripts:");
   // output column head
   for (int i = 0; i < SIZE; ++i) {
      printf("%3d ", i);
   } 
   puts(""); // start new line of output
   // output line of - characters
   for (int i = 1; i <= 4 * SIZE; ++i) {
      printf("%s", "-");
   } 
   puts(""); // start new line of output
} 
// Print one row of output showing the current
// part of the array being processed.
void printRow(const int b[], size_t low, size_t mid, size_t high) {
   // loop through entire array
   for (size_t i = 0; i < SIZE; ++i) {
      // display spaces if outside current subarray range
      if (i < low || i > high) {
         printf("%s", "    ");
      }  
      else if (i == mid) { // display middle element
         printf("%3d*", b[i]); // mark middle value
      }  
      else { // display other elements in subarray
         printf("%3d ", b[i]);
      } 
   } 
   puts(""); // start new line of output
} 