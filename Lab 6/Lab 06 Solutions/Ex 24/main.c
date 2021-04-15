/*
 * Exercise 25 - Memory Reallocation (Position)
 *
 * Author: Christian Grévisse
 * Date: 27.03.2018
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    size_t size = 1;

    char * p = malloc(size), * aux;

    if(p == NULL) {
        perror("Initial allocation failed.");
        return 1;
    }

    printf("Initial pointer at %p.", p);

	for (;; size += 10) {
        aux = realloc(p, size);

        if(aux == NULL) {
            printf("Reallocation failed (size = %ld).\n", size);
            return 1;
        } else if(aux != p)
            printf("Reallocation moved from %p to %p (size = %ld).\n", p, aux, size);

        p = aux;
    }

    free(p);

    return 0;
}
