/*
 * Exercise 27 - Airport
 *
 * airport.h - Header file declaring airport-related structures and functions.
 *
 * Author: Christian Grévisse
 * Date: 12.04.2018
 */

#ifndef airport_h
#define airport_h

#include "io.h"

#define AIRPORT_CODE_LENGTH 4
#define GATE_LENGTH 4

typedef struct {
    char * name;
    char code[AIRPORT_CODE_LENGTH];
} Airport;

typedef struct {
    char * airline;
    int flightNumber;
    Airport * origin;
    Airport * destination;
    int departureTime[2];
    char * gate;
    int rows;
    int seatsPerRow;

    // note that the type of seatMap is a triple char pointer, i.e. a two-dimensional array of strings
    char *** seatMap;
} Flight;

Airport * createAirport();
void printAirport(Airport * airport);
void freeAirport(Airport * airport);

Flight * createFlight(Airport * origin);
void printFlight(Flight * flight);
int checkinPossible(Flight * flight);
void checkin(Flight * flight);
void printSeatMap(Flight * flight);
void freeFlight(Flight * flight);

#endif
