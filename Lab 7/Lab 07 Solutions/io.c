/*
 * Exercise 27 - Airport
 *
 * io.c - Source file implementing I/O helper functions.
 *
 * Author: Christian Grévisse
 * Date: 12.04.2018
 */

#include "io.h"

void flushInput() {
    while(getchar() != '\n');
}

char * input(int maxLength) {
    static char buffer[BUFFER_SIZE];

    fflush(stdout);

    if(fgets(buffer, maxLength, stdin) != NULL) {
        if(buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';
        return buffer;
    } else {
        perror("I/O Error.");
        exit(1);
    }
}
