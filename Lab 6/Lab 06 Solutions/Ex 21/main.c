/*
 * Exercise 22 - Memory Allocation
 *
 * Author: Christian Grévisse
 * Date: 27.03.2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * allocateArray(int size) {
    int * array;

    // calloc is a convenience function to allocate an array of a given length and element size
    // if the allocation fails, we quit the program
	if ((array = (int *) calloc(size, sizeof(int))) == NULL) {
        perror("Allocation failure.");
        exit(1);
    }

    return array;
}

void fillArray(int * array, int size) {
    srand(0);
    for(int i = 0; i < size; i++)
        array[i] = rand() % 100;
}

void printArray(int * array, int size) {
    for(int i = 0; i < size; i++)
        printf("%2d%c", array[i], ((i+1)%20 == 0 || i+1 == size) ? '\n' : ' ');
}

char * strdouble(char * original) {
    char * result;

    // malloc is provided with twice the size of the original string + 1 spare character for '\0'. Note that the multiplication with sizeof(char) is not necessary, as this returns 1.
    if((result = (char *) malloc((strlen(original) * 2 + 1) * sizeof(char))) == NULL) {
        perror("Allocation failure.");
        exit(1);
    }

    // copy the original string at the beginning
    strcpy(result, original);

    // append it again at the end of the first
    strcat(result, original);

    return result;
}

int main() {

    // Part 1

    int n, * array;

    printf("Enter a number:\n");
    scanf("%d", &n);

    array = allocateArray(n);
    fillArray(array, n);
    printArray(array, n);

    // free the memory (it's your responsibility as you allocated it!) and, for safety reasons, set the pointer to NULL to detect easily a later illicit use of the dangling pointer
    free(array);
    array = NULL;

    // Part 2

    char * original = "For a moment, nothing happened. Then, after a second or so, nothing continued to happen.";
    char * doubleString = strdouble(original);

    printf("Original: %s\n", original);
    printf("Double:   %s\n", doubleString);

    free(doubleString);
    doubleString = NULL;

    return 0;
}
