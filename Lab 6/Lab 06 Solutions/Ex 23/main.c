/*
 * Exercise 24 - Memory Reallocation (Strings)
 *
 * Author: Christian Grévisse
 * Date: 27.03.2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define END "END"

int input(char * buffer) {
    fflush(stdout);

    if(fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        if(buffer[strlen(buffer)-1] == '\n')
            buffer[strlen(buffer)-1] = '\0';

        return 1;
    } else {
        return 0;
    }
}

int main() {

    char buffer[BUFFER_SIZE];

    char * phrase = NULL;

    while(1) {
        printf("Please enter a phrase or '%s' to finish (maximum %d characters):\n", END, BUFFER_SIZE);

        if(input(buffer)) {

            // quit if "END" entered
            if(strcmp(buffer, END) == 0)
                break;

            if(phrase == NULL) {
                // initial allocation
                if((phrase = (char *) malloc(strlen(buffer)+1)) == NULL) {
                    perror("Could not allocate the initial string.");
                    return 1;
                }
                strcpy(phrase, buffer);
            } else {
                // reallocation (size of both old string, new string, space and '\0')
                if((phrase = (char *) realloc(phrase, strlen(phrase) + strlen(buffer) + 2)) == NULL) {
                    perror("Could not reallocate the string.");
                    return 1;
                }

                strcat(phrase, " ");
                strcat(phrase, buffer);
            }
        } else {
            perror("Could not read any input.");
            return 1;
        }
    }

    printf("%s (%ld)\n", phrase, strlen(phrase));

    free(phrase);

    return 0;
}
