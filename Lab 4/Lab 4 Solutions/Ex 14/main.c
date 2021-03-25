/*
 * Exercise 14 - Array Addresses
 *
 * Author: Ayman Makki
 * Date: 18.03.2021
 */

#include <stdio.h>

#define SIZE 5

typedef float MyType;

int main(int argc, const char * argv[]) {
	MyType arr[SIZE];
	MyType * pCurrent, *pNext;
	size_t distance;

	for (int i = 0; i < SIZE; i++) {
		pCurrent = &arr[i]; // arr + i

		printf("Element %d at %p", i, pCurrent);
		if (i < SIZE - 1) {
			for (int j=1; j < SIZE-i; j++)
			{
				pNext = &arr[i+j]; // arr + i + 1
				distance = (pNext - pCurrent) * sizeof(MyType);
				printf("\n\tDistance to element %d: %ld", i+j, distance);
			}

		}

		printf("\n");
	}

	return 0;
}
