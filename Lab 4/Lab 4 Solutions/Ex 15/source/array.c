/*
* Exercise 15 - Challenges with pointers
 *
 *
 * Author: Ayman Makki
 * Date: 18.03.2021
 */

#include<stdio.h>
#include<stdlib.h>

#include "../headers/array.h"

/*
 * This function fills an array of given size with random numbers between 0 and 99.
 */
void fill_array(int array[], int size) {
	for(int i = 0; i < size; i++)
		array[i] = rand() % 100;
}



/*
 * This function prints the contents of an array of given size.
 */
void print_array(int array[], int size) {
	printf("[ ");
	for(int i = 0; i < size; i++)
		printf("%d%c ", array[i], i != size -1 ? ',' : 0);
	printf("]\n");
}
