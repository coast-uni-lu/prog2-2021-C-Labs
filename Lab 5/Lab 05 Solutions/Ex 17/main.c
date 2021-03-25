/*
 * Exercise 17 - Pointer Arithmetic
 *
 * Author: Ayman Makki
 * Date: 25.03.2021
 */

#include <stdio.h>

#define N 21

void print(int * array, int size) {
    for(int * p = array; p < array + size; p++)
        printf("[%d]\t", *p);
}

int main() {

    int array[N];

    int * p = array;

    int sum = 0;

    // creation of initial array
    *p = 1;
    for(++p; p < array + N; p++)
        *p = *(p-1) + 1;

    // print
    print(array, N);
    printf("\n\n");

    // While iterating over the array, increment all elements by 1 and calculate the sum using a single expression.
    // The ++ and * operators are on the same precedence level, and are evaluated from right to left. Thus, the expression `++*p++` could be read as `++(*(p++))`. This means that p gets post-incremented (i.e. the pointer advances), but before, the dereferenced value p currently points at is pre-incremented, allowing us to add 1 to each item in the array. The result of this prefix operation is the new value p points at (still at the same position before the postfix pointer advancement!). This result is added to the sum.
    // Note that, while such a complex expression is extremely powerful, it is also quite hard to read and error-prone.
	for (p = array; p < array + N;)
        sum += ++*p++;

    // print
    print(array, N);
    printf("\n\nThe sum of all array elements is: %d\n\n", sum);

    return 0;
}
