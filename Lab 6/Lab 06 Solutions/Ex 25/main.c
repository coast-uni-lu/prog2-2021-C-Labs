/*
 * Exercise 26 - Address Sanitizer
 *
 * Author: Christian Grévisse
 * Date: 27.03.2018
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define N 1000

void bufferOverflow() {
    char name[MAX_SIZE];
    printf("Enter your name:\n");
    scanf("%s", name);
    printf("Your name is %s.\n", name);
}

void fillArray(int * arr, int size) {
    srand(0);
    for(int i = 0; i < size; i++)
        arr[i] = rand() % 100;
}

void printArray(int * arr, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void danglingPointer() {
    int * arr = malloc(sizeof(int) * N);

    fillArray(arr, N);
    printArray(arr, N);

    free(arr);

    fillArray(arr, N);
}

int main() {

//    bufferOverflow();
//    danglingPointer();

    return 0;
}
