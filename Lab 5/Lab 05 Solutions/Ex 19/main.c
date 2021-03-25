/*
 * Exercise 19 - String Comparison
 *
 * Author: Ayman Makki
 * Date: 25.03.2021
 */

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

void mygets(char * s, int maxLength) {
    fflush(stdout);
    if(fgets(s, maxLength, stdin) != NULL) {
        size_t lastIndex = strlen(s)-1;
        if(s[lastIndex] == '\n')
            s[lastIndex] = '\0';
    }
}

int mystrcmp1(char * s1, char * s2) {
    int i = 0, j = 0;

    while(i < strlen(s1) && j < strlen(s2) && s1[i] == s2[j]) {
        i++;
        j++;
    }

    if(s1[i] < s2[j])
        return -1;
    else if(s1[i] > s2[j])
        return 1;
    else
        return 0;
}

int mystrcmp2(char * s1, char * s2) {
    while(*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }

    if(*s1 < *s2)
        return -1;
    else if(*s1 > *s2)
        return 1;
    else
        return 0;
}

int main() {

    char s1[MAX_LENGTH], s2[MAX_LENGTH];

    printf("Enter s1:\n");
    mygets(s1, MAX_LENGTH);
    printf("Enter s2:\n");
    mygets(s2, MAX_LENGTH);

    printf("Result of mystrcmp1: %d\n", mystrcmp1(s1, s2));
    printf("Result of mystrcmp2: %d\n", mystrcmp2(s1, s2));
    printf("Result of strcmp: %d\n", strcmp(s1, s2));

    return 0;
}
