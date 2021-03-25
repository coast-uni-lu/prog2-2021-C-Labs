/*
 * Exercise 18 - "Drei Chinesen mit dem Kontrabass"
 *
 * Author: Ayman Makki
 * Date: 25.03.2021
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char vowels[] = { 'a', 'e', 'i', 'o', 'u' };

int countCharacters(char * s) {
    int count = 0;

    for(char * p = s; *p; p++)
        count += toupper(*p) >= 'A' && toupper(*p) <= 'Z';

    return count;
}

void replace(char * s, char old, char new) {
    for(char * p = s; *p; p++)
        if(toupper(*p) == toupper(old))
            *p = isupper(*p) ? toupper(new) : tolower(new);
}

int isVowel(char c) {
    return strchr(vowels, c) != NULL;
}

void replaceVowel(char * s, char c) {
    for(char * p = vowels; *p; )
        replace(s, *p++, c);
}

int main() {

    char sentence[] = "Drei Chinesen mit dem Kontrabass sassen auf der Strasse und erzaehlten sich was. Da kam die Polizei, fragt: 'Was ist denn das?' Drei Chinesen mit dem Kontrabass.";
    char backup[200];
    strcpy(backup, sentence);

    printf("%s\n\n", sentence);
    printf("Non-special characters in this sentence: %d\n\n", countCharacters(sentence));

    char old, new;
    printf("Enter the character to replace and the character to be replaced with, separated by a space:\n");
    scanf("%c %c", &old, &new);
    replace(sentence, old, new);
    printf("\n%s\n\n", sentence);

    int inputCorrect = 0;
    char vowel, trash;
    do {
        // clean input buffer
        while((trash = getchar()) != EOF && trash != '\n');

        printf("Enter a vowel the other vowels should be replaced with.\n");
        vowel = fgetc(stdin);

        if(!(inputCorrect = isVowel(vowel)))
            printf("\nNo vowel. ");
    } while(!inputCorrect);

    replaceVowel(backup, vowel);
    printf("\n%s\n\n", backup);

    return 0;
}
