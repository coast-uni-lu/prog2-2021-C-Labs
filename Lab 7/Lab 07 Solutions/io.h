/*
 * Exercise 27 - Airport
 *
 * io.h - Header file declaring I/O helper functions.
 *
 * Author: Christian Grévisse
 * Date: 12.04.2018
 */

#ifndef io_h
#define io_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50

void flushInput();
char * input(int maxLength);

#endif
