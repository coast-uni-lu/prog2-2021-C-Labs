/*
 * Exercise 15 - Array-Pointer Duality
 *
 * array.c: Source file implementing functions for filling, printing, sorting and deleting elements in an array.
 *
 * Author: Christian Grévisse
 * Date: 22.03.2018
 */

#include "array.h"

void input(int * array, int size) {
    for(int i = 0; i < size; i++) {
        printf("Enter the value for element %d: ", i+1);
        scanf("%d", array + i);
    }
}

void print_array(int * array, int size) {
    for(int i = 0; i < size; i++)
        printf("%d\t", *(array+i));
    printf("\n");
}

void filter_print(int * array, int size, int threshold) {
    int count = 0;

    for(int i = 0; i < size; i++) {
        if(*(array + i) >= threshold) {
            printf("%d\t", *(array+i));
            count++;
        }
    }

    if(!count) {
        printf("No such values.");
    }

    printf("\n");
}

void deleteFromArray(int * array, int size, int delete) {
    for(int i = 0 ; i < size; i++) {
        if(*(array + i) == delete) {
            // shift remaining elements left
            for(int j = i; j < size - 1; j++)
                *(array + j) = *(array + j + 1);

            // change last value to 0
            *(array + size-1) = 0;
        }
    }
}

void sort(int * array, int size) {
    // a function sorting the array in ascending order
    for(int i = 0; i < size; i++) {
        // pointer to minimum value
        int * min = array + i;

        // find minimum value
        for(int j = i; j < size; j++)
            if(*(array + j) < *min)
                min = array + j;

        // swap
        int aux = *(array + i);
        *(array + i) = *min;
        *min = aux;
    }
}
