/*
 * Exercise 27 - Airport
 *
 * main.c - Main program with menu to the user.
 *
 * Author: Christian Grévisse
 * Date: 12.04.2018
 */

#include "airport.h"

Airport * currentAirport;
Flight ** schedule = NULL;
int numberOfFlights = 0;

void addFlight(Flight * flight) {
    numberOfFlights++;
    if(schedule == NULL) {
        // initial allocation of a single pointer to a Flight struct
        schedule = malloc(sizeof(Flight *));
        *schedule = flight;
    } else {
        // enlarge the current schedule to append the new element at the end
        schedule = realloc(schedule, numberOfFlights * sizeof(Flight *));
        *(schedule+numberOfFlights-1) = flight;
    }
}

void printSchedule() {
    printf("\n\nFLIGHT SCHEDULE\n");
    printAirport(currentAirport);
    if(numberOfFlights == 0)
        printf("\nNo flights in the schedule.\n");
    else {
        printf("\n#\tFlight\t\t\tDep\tArr\tTime\tGate\n");
        for(int i = 0; i < numberOfFlights; i++) {
            printf("%d\t", i+1);
            printFlight(schedule[i]);
        }
    }
}

int validFlightIndex(int index) {
    return (index >= 0 && index < numberOfFlights);
}

void removeFlight(int index) {
    if(validFlightIndex(index) && schedule[index] != NULL) {
        // free the flight to be removed
        freeFlight(schedule[index]);
        numberOfFlights--;

        // squeeze the remaining flights
        for(int i = index; i < numberOfFlights; i++)
            schedule[i] = schedule[i+1];

        // shrink the schedule to the necessary size
        schedule = realloc(schedule, numberOfFlights * sizeof(Flight *));
    } else {
        printf("Flight not available.\n");
    }
}

void printMenu() {
    printf("\nAvailable options:\n\n");
    printf("1 - Add flight\n");
    printf("2 - Print timetable\n");
    printf("3 - Remove flight\n");
    printf("4 - Show seat map\n");
    printf("5 - Check-in passenger\n");
    printf("0 - Quit\n");
}

void cleanup() {
    // free different flights from schedule
    for(int i = 0; i < numberOfFlights; i++)
        freeFlight(schedule[i]);

    // free whole schedule
    free(schedule);

    // free current airport
    free(currentAirport);
}

int main() {
    printf("\nAIRPORT MANAGER\n\n");

    printf("Current airport:\n");
    currentAirport = createAirport();

    int stop = 0, choice;

    while(!stop) {
        printMenu();
        printf("\n\nChoose an option:\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                // add flight
                flushInput();
                Flight * flight = createFlight(currentAirport);
                addFlight(flight);
                } break;

            case 2:
                // print timetable
                printSchedule();
                break;

            case 3:
                // remove flight
                printSchedule();
                if(numberOfFlights > 0) {
                    printf("Which flight do you want to delete? [1-%d]\n", numberOfFlights);
                    int delete;
                    scanf("%d", &delete);
                    removeFlight(delete-1);
                }
                break;

            case 4: {
                    // show seat map
                    int flightNumber;
                    printf("Which flight do you want to perform a check-in? [1-%d]\n", numberOfFlights);
                    scanf("%d", &flightNumber);
                    flightNumber--;

                    if(validFlightIndex(flightNumber) && schedule[flightNumber] != NULL) {
                        Flight * flight = schedule[flightNumber];
                        printSeatMap(flight);
                    } else
                        printf("Invalid flight.\n");
                } break;

            case 5:
                // check-in
                printSchedule();
                int flightNumber;
                printf("Which flight do you want to perform a check-in? [1-%d]\n", numberOfFlights);
                scanf("%d", &flightNumber);
                flightNumber--;

                if(validFlightIndex(flightNumber) && schedule[flightNumber] != NULL)
                    checkin(schedule[flightNumber]);
                else
                    printf("Invalid flight.\n");
                break;

            case 0:
                // quit
                stop = 1;
                printf("Adios.\n");
                break;

            default:
                printf("Unrecognized choice.\n");
                break;
        }
    }

    cleanup();
    return 0;
}
