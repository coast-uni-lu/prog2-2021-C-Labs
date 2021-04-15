/*
 * Exercise 20 - Constant Strings
 *
 * Author: Christian Grévisse
 * Date: 26.03.2020
 */

#include <stdio.h>
#include <string.h>

/* Implementation of `strcpy` in the Linux kernel (Source: https://github.com/torvalds/linux/blob/1b649e0bcae71c118c1333e02249a7510ba7f70a/lib/string.c#L89) */
//char *strcpy(char *dest, const char *src) {
//    char *tmp = dest;
//
//    while ((*dest++ = *src++) != '\0')
//        /* nothing */;
//    return tmp;
//}

int main() {

    // constant string
    char * constantString = "Swift";

    // char array
    char charArray[] = "Swift";

    // pointer to charArray
    char * p = charArray;

    /* 0. Printing */
    printf("Constant string: %s\n", constantString);
    printf("Char array: %s\n", charArray);
    printf("Pointer to char array: %s\n\n", p);

    for(int i = 0; i < strlen(constantString); i++)
        printf("%c", constantString[i]);
    printf("\n");

    while(*p)
        printf("%c", *p++);
    printf("\n\n");

    /* 1. Modifications */

    // altering an element in a char array, even via pointer syntax, is allowed
    p = charArray;
    *(p+1) = 'h';
    printf("Modified string: %s\n", charArray);
    charArray[1] = 'h';
    printf("Modified string: %s\n\n", charArray);

    // altering an element in a constant, independent of the employed syntax, string is NOT allowed
//    constantString[1] = 'h';

    /* 2. Size experiments */

    printf("Size of a constant string: %ld\n", sizeof(constantString)); // gives the size of a pointer
    printf("Size of a char array: %ld\n", sizeof(charArray)); // gives the number of bytes allocated for the string
    printf("Size of a pointer to the char array: %ld\n\n", sizeof(p)); // gives the size of a pointer

    /* 3. Copying */

    strcpy(charArray, constantString); // works, as charArray is mutable
//    strcpy(constantString, charArray); // will crash, as constantString is not mutable
//    strcpy(charArray, charArray); // works fine with gcc (at least on Linux), clang might complain about "source and destination buffer overlap"
    printf("Modified string: %s\n\n", charArray);

    /* 4. Size != Size */
    char * nonAscii = "Université"; // word of 10 characters ...
    printf("Sizeof: %ld\nStrlen: %ld\n", sizeof(nonAscii), strlen(nonAscii)); // sizeof gives size of a pointer. strlen doesn't give 10!

    printf("Hex dump: ");
    for(int i = 0; i < strlen(nonAscii); i++)
        printf("%02x ", nonAscii[i] & 0xff);
    printf("\n\n");
    // The hex dump has shown that the non-ASCII character 'é' actually requires two bytes!

    // Bonus 1: Who is constant?
    printf("constantString: %p %s\n", constantString, constantString);

    constantString = "Python";
    printf("constantString: %p %s\n", constantString, constantString);

    printf("Address of 'Swift': %p\n", "Swift");
    constantString = "Swift";
    printf("constantString: %p %s\n\n", constantString, constantString);
    
    // Bonus 2: Emoji
    
    char emoji[] = "😂"; // f0 9f 98 82
    *(emoji+3) += 11; // f0 9f 98 8d
    printf("%s\n", emoji);
    
    char * emoji2 = "👩‍👦"; // f0 9f 91 a9 | e2 80 8d | f0 9f 91 a6

    char part1[5];
    strncpy(part1, emoji2, 4);
    part1[4] = '\0';

    char * part2 = emoji2 + 7;

    printf("%s = %s + %s\n", emoji2, part1, part2);

    return 0;
}
