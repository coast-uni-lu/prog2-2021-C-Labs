/*
* Exercise 15 - Challenges with pointers
 *
 * array.h: Header file declaring functions for filling arrays with random numbers as well as sorting and printing arrays.
 *
 * Author: Ayman Makki
 * Date: 18.03.2021
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

struct Client {
  int id;
  float money;
  char name[10];
};

typedef struct Client Client;

void swap(int *a, int *b);
void reverse_array(int *array, int size);
void swap_arrays(int *array1, int *array2, int size);
int count_string(char *string);
Client create_client(char *name, float money, int id);

#endif /* ARRAY_H_ */
