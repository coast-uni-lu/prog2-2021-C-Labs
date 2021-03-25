/*
 * Exercise 15 - Array-Pointer Duality
 *
 * main.c: Main program.
 *
 * Author: Ayman Makki
 * Date: 25.03.2021
 */

#include <stdio.h>
#include "array.h"

#define SIZE 21
#define THRESHOLD 42

int main() {

    int array[SIZE], delete;

    // input
    input(array, SIZE);
    printf("\nThe resulting array:\n\n");
    print_array(array, SIZE);

    // printing values greater than a given threshold
    printf("\nValues greater than or equal to 42:\n\n");
    filter_print(array, SIZE, THRESHOLD);

    // deleting a value
    printf("\nEnter a value to be deleted: ");
    scanf("%d", &delete);
    deleteFromArray(array, SIZE, delete);
    printf("\nAfter deleting %d, the resulting array is:\n\n", delete);
    print_array(array, SIZE);

    // sorting
    sort(array, SIZE);
    printf("\nAfter sorting:\n\n");
    print_array(array, SIZE);

    return 0;
}
