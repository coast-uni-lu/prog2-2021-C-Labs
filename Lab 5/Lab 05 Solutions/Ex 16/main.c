/*
 * Exercise 16 - Size matters
 *
 * Author: Ayman Makki
 * Date: 25.03.2021
 */

#include <stdio.h>

void print_array_wrong(int * array) {
    int size = sizeof(array)/sizeof(array[0]);
    printf("Array size: %d\n", size);
    for(int i = 0; i < size; i++) {
        printf("%d ", *(array+i));
    }
}

void print_array_correct(int * array, int size) {
    printf("Array size: %d\n", size);
    for(int i = 0; i < size; i++) {
        printf("%d ", *(array+i));
    }
}

int main() {
    int array[] = { 39, 78, 31, 27, 79, 79, 71, 69, 37, 27 };

    printf("Printing the array the wrong way:\n");
    print_array_wrong(array);

    printf("\n\nPrinting the array the correct way:\n");
    print_array_correct(array, sizeof(array)/sizeof(array[0]));

    return 0;
}
