/*
 * Exercise 13 - Where are you pointing at?
 *
 * Author: Ayman Makki
 * Date: 18.03.2021
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	double *ptr, i;

	// The program as such is prone to crash, as `ptr` does not point to the address of `i` before being used in scanf(). The behaviour is unpredictable, thus the following line is highly recommended:
	// ptr = &i;


	printf("i = ");
	scanf("%lf", ptr);

	printf("value of ptr = %lf\n", *ptr);
	printf("value of i = %lf\n", i);

	return 0;
}
