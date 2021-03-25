/*
* Exercise 15 - Challenges with pointers
 *
 *
 * Author: Ayman Makki
 * Date: 18.03.2021
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/functions.h"

void swap(int * num1, int * num2)
{
    int temp;

    // Copy the value of num1 to some temp variable
    temp = *num1;

    // Copy the value of num2 to num1
    *num1= *num2;

    // Copy the value of num1 stored in temp to num2
    *num2= temp;


}

void reverse_array(int *array, int size)
{
    int *left = array;  // Pointer to arr[0]
    int *right;
		int tmp;

    right = &array[size - 1];  // Pointer to arr[size - 1]

    // Loop to reverse array
    while(left < right)
    {
        /*
         * Swap element from left of array to right of array.
         */
				 tmp = *left;
        *left  = *right;
        *right = tmp;

        // Increment left array pointer and decrement right array pointer
        left++;
        right--;
    }

}

void swap_arrays(int * array1, int * array2, int size)
{
    // Pointer to last element of source array
    int * sourceArrEnd = (array1 + (size - 1));

    // Pointer to last element of destination array
    int * destArrEnd   = (array2 + (size - 1));

		int tmp;
    /*
     * Swap individual element of both arrays
     */
    while(array1 <= sourceArrEnd && array2 <= destArrEnd)
    {
				tmp = *array1;
			 *array1  = *array2;
			 *array2 = tmp;

        // Increment source array to point to next element
        array1++;

        // Increment destination array to point to next element
        array2++;
    }
}

int count_string(char *text)
{
    char * str = text; /* Declare pointer that points to text */
    int count = 0;

    /* Iterate though last element of the string */
    while(*(str++) != '\0') count++;

    return count;
}

Client create_client(char *name, float money, int id)
{
  Client client;
  client.money = money;
  client.id = id;
  strcpy(client.name, name);
  return client;
}
