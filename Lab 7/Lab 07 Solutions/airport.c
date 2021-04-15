/*
 * Exercise 27 - Airport
 *
 * airport.c - Source file implementing airport-related structures and functions.
 *
 * Author: Christian Grévisse
 * Date: 12.04.2018
 */

#include "airport.h"

Airport * createAirport() {
    Airport * airport;

    if((airport = malloc(sizeof(Airport))) == NULL) {
        perror("Could not allocate space for the airport.");
        exit(1);
    }

    printf("Airport name:\n");

    // input will quit the program if an error happens, otherwise it will return a pointer to the buffer
    // latter content can be used by strdup, which both allocates the necessary memory for the string in
    // the buffer and copies its content into the receiver string
    airport->name = strdup(input(BUFFER_SIZE));

    printf("\nAirport Code (%d letters):\n", AIRPORT_CODE_LENGTH-1);

    // here, the memory is already allocated, so we do not use strdup but strcpy
    strcpy(airport->code, input(AIRPORT_CODE_LENGTH));

    return airport;
}

void printAirport(Airport * airport) {
    printf("%s (%s)\n", airport->name, airport->code);
}

void freeAirport(Airport * airport) {
    // here, we do *not* free the code char array, as it was not dynamically allocated
    free(airport->name);
    free(airport);
    airport = NULL;
}

Flight * createFlight(Airport * origin) {
    Flight * flight;

    printf("\nFlight creation:\n");

    if((flight = malloc(sizeof(Flight))) == NULL) {
        perror("Could not allocate space for the flight.");
        exit(1);
    }

    printf("\nAirline:\n");
    flight->airline = strdup(input(BUFFER_SIZE));

    printf("\nFlight Number:\n");
    scanf("%d", &flight->flightNumber);

    // the '\n' may still be in the buffer form the last scanf return, so to avoid it being read
    // by the next call of fgets, we flush the input buffer
    flushInput();

    printf("\nDestination:\n");
    flight->destination = createAirport();
    flight->origin = origin;

    printf("\nDeparture Time: (hh:mm)\n");

    // remember scanf, just like printf, can specify a certain format it awaits from user input
    scanf("%d:%d", flight->departureTime, flight->departureTime+1);

    flushInput();

    printf("\nGate:\n");
    flight->gate = strdup(input(GATE_LENGTH));

    printf("\nNumber of rows:\n");
    scanf("%d", &flight->rows);
    printf("\nSeats per row:\n");
    scanf("%d", &flight->seatsPerRow);

    // first, we allocate the rows ... (note that the type of one element is a double char pointer, i.e. an array of strings [each seat can contain the name of a passenger])
    flight->seatMap = calloc(flight->rows, sizeof(char **));

    // ... then allocate the seats in each row (now, the type of one element is a char pointer, i.e. a string [the name of the passenger])
    for(int row = 0; row < flight->rows; row++)
        flight->seatMap[row] = calloc(flight->seatsPerRow, sizeof(char *));

    return flight;
}

void printFlight(Flight * flight) {
    printf("%s %d\t\t%s\t%s\t%02d:%02d\t%s\n", flight->airline, flight->flightNumber, flight->origin->code, flight->destination->code, flight->departureTime[0], flight->departureTime[1], flight->gate);
}

int allocatedSeats(Flight * flight) {
    int allocatedSeats = 0;

    for(int row = 0; row < flight->rows; row++)
        for(int seat = 0; seat < flight->seatsPerRow; seat++)
            allocatedSeats += flight->seatMap[row][seat] != NULL;

    return allocatedSeats;
}

int checkinPossible(Flight * flight) {
    return allocatedSeats(flight) < flight->rows * flight->seatsPerRow;
}

void printSeatMap(Flight * flight) {
    // header
    printf("  \t");
    for(int seat = 0; seat < flight->seatsPerRow; seat++) {
        // letters for each seat column
        printf("%c ", 'A' + seat);

        // aisle
        if(seat == flight->seatsPerRow/2 - 1)
            printf("\t");
    }
    printf("\n\n");

    // show seat map
    for(int row = 0; row < flight->rows; row++) {
        printf("%2d\t", row+1);
        for(int seat = 0; seat < flight->seatsPerRow; seat++) {
            printf("%c ", (flight->seatMap[row][seat] != NULL) ? '*' : '-');

            if(seat == flight->seatsPerRow/2 - 1)
                printf("\t");
        }
        printf("\n");
    }

    printf("\n");

    // passenger list
    if(allocatedSeats(flight) > 0) {
        for(int row = 0; row < flight->rows; row++)
            for(int seat = 0; seat < flight->seatsPerRow; seat++)
                if(flight->seatMap[row][seat] != NULL)
                    printf("- %2d%c: %s\n", row+1, 'A' + seat, flight->seatMap[row][seat]);
    } else
        printf("No passengers checked-in so far.\n");
}

void checkin(Flight * flight) {
    if(checkinPossible(flight)) {
        int row, seat;
        do {
            printf("Enter the row:\n");
            scanf("%d", &row);
            row--;
        } while(row < 0 || row >= flight->rows);

        do {
            printf("Enter the seat:\n");
            scanf("%d", &seat);
            seat--;
        } while(seat < 0 || seat >= flight->seatsPerRow);


        if(flight->seatMap[row][seat] == NULL) {
            printf("Enter the passenger name:\n");
            flushInput();
            char * passengerName = input(BUFFER_SIZE);
            flight->seatMap[row][seat] = strdup(passengerName);
        } else
            printf("Seat already allocated.\n");
    } else
        printf("Flight is full, no check-in possible anymore.\n");
}

void freeFlight(Flight * flight) {
    free(flight->airline);

    // Here, we do *not* free the origin airport, as it was not allocated within the responsibility of a flight. It can, and effectively will be reused in different flights, so deallocating it for one flight would make it vanish for the other flights as well! Only deallocate what you have allocated, and deallocate this in the corresponding creation scope!
    freeAirport(flight->destination);
    free(flight->gate);

    // free passengers, single rows of seats ...
    for(int row = 0; row < flight->rows; row++) {
        for(int seat = 0; seat < flight->seatsPerRow; seat++)
            free(flight->seatMap[row][seat]);
        free(flight->seatMap[row]);
    }

    // free all rows and the whole flight
    free(flight->seatMap);
    free(flight);
}
