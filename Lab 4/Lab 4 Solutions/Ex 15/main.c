/*
 * Exercise 15 - Challenges with pointers
 *
 * main.c: Main program.
 *
 * Author: Ayman Makki
 * Date: 18.03.2021
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "headers/array.h"
#include "headers/functions.h"

#define n 10
#define m 15

int main() {
	// declaration of arrays
	int a,b, *Pa, *Pb;
	Pa = &a;
	Pb = &b;
	a = 3;
	b = 5;


	// Swapping two numbers
	printf("Before swapping in swap function \n");
	printf("Value of a = %d \n", a);
	printf("Value of b = %d \n\n", b);
	swap(Pa,Pb);
	printf("After swapping in swap function \n");
	printf("Value of a = %d \n", a);
	printf("Value of b = %d \n\n", b);


	// Reversing an array
	int array[m];
	fill_array(array,m);

	printf("Before Reversing the array\n ");
	print_array(array,m);

	reverse_array(array,m);

	printf("After Reversing the array \n");
	print_array(array,m);
	printf("\n");
	//
	// Swapping two arrays
	int array2[m];
	fill_array(array2,m);

	printf("Before Swapping the array \n");
	print_array(array,m);
	print_array(array2,m);

	swap_arrays(array, array2, m);

	printf("After Swapping the array \n");
	print_array(array,m);
	print_array(array2,m);
	printf("\n");
	//
	// Counting number of elements in a string
	char str[10] = "Hello Hello Hello" ;
	int count;
	count = count_string(str);
	printf("Size of the string : %d", count);
	printf("\n");


	// Returning different types
	Client client;
	client = create_client("Thomas", 13.0, 4);
	printf("Client %d is created with name %s and money %f\n", client.id, client.name, client.money);

	return 0;
}
