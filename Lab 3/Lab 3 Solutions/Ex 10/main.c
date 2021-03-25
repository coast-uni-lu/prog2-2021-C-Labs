/*
 * Exercise 10 - Merging two sorted arrays
 *
 * main.c: Main program.
 *
 * Author: Christian Grévisse
 * Date: 05.03.2018
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define l1 10
#define l2 15

#include "headers/array.h"

int main() {
	// declaration of arrays
	int t1[l1], t2[l2];

	// setting the seed of the pseudo-random number generator
	srand(0);

	// filling the arrays with random numbers
	fill_array(t1, l1);
	fill_array(t2, l2);

	// printing their content
	printf("t1 = ");
	print_array(t1, l1);
	printf("t2 = ");
	print_array(t2, l2);

	// sorting them
	sort_array(t1, l1);
	sort_array(t2, l2);

	// printing their changed content
	printf("\nt1 = ");
	print_array(t1, l1);
	printf("t2 = ");
	print_array(t2, l2);

	// declaration of the merge array
	int merge[l1+l2];

	/*
	 * "two finger"-algorithm for merging the arrays: at each step,
	 * we check which array currently contains the lowest value, set
	 * this to the current position in the merge array and advance the
	 * "finger"; finally, we append the remaining elements in the array
	 * that have not yet been inserted during the first loop.
	 */
	int i = 0; int j = 0;
	while(i < l1 && j < l2)
		if(t1[i] <= t2[j]) {
			merge[i+j] = t1[i];
			i++;
		} else {
			merge[i+j] = t2[j];
			j++;
		}
	while(i < l1) {
		merge[i+j] = t1[i];
		i++;
	}
	while(j < l2) {
		merge[i+j] = t2[j];
		j++;
	}

	// printing the content of the sorted merge array
	printf("\nmerge = ");
	print_array(merge, l1 + l2);

	return 0;
}
