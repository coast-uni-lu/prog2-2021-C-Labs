/*
 * Exercise 15 - Array-Pointer Duality
 *
 * array.h: Header file declaring functions for filling, printing, sorting and deleting elements in an array.
 *
 * Author: Christian Grévisse
 * Date: 22.03.2018
 */

#ifndef array_h
#define array_h

#include <stdio.h>

void input(int * array, int size);
void print_array(int * array, int size);
void filter_print(int * array, int size, int threshold);
void deleteFromArray(int * array, int size, int delete);
void sort(int * array, int size);

#endif /* array_h */
