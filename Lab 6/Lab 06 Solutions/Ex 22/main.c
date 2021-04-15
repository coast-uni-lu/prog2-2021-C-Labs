/*
 * Exercise 23 - Memory Allocation Loop
 *
 * Author: Christian Grévisse
 * Date: 27.03.2018
 */

#include <stdio.h>
#include <stdlib.h>

#define MB 1024 * 1024
#define CHUNK_SIZE 10 * MB

void fillMemory(int freeMemory) {

    char * p;

    for(;;) {
        if((p = malloc(CHUNK_SIZE)) == NULL) {
            perror("Allocation failure.");
            exit(1);
        }

        if(freeMemory)
            free(p);
    }
}

int main(int argc, char *argv[]) {
    if(argc == 2) {
        // atoi converts a string into an integer
        int freeMemory = atoi(argv[1]);
        fillMemory(freeMemory);
        return 0;
    } else {
		printf("Usage: %s <freeMemory>\n", argv[0]);
        return 1;
    }
}
