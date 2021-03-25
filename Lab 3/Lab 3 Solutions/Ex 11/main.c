/*
 * Exercise 11 - Mini-Minesweeper
 *
 * Author: Christian Grévisse
 * Date: 05.03.2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define PROBABILITY 50

#define MINE 1
#define EMPTY 0
#define SET -1

int grid[N][N];
int numberOfMines = 0;

void fillGrid() {
    srand(time(NULL));

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            grid[i][j] = (rand() % 100) < PROBABILITY;
            numberOfMines += grid[i][j];
        }
}

void printGrid(int showMines) {
    printf("\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            if(showMines)
                printf("%c ", grid[i][j] == MINE ? '*' : ' ');
            else
                printf("%c ", grid[i][j] == SET ? ' ' : '?');

        printf("\n");
    }
    printf("\n");
}

int checkGrid() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(grid[i][j] == EMPTY)
                return 0;
    return 1;
}

int main() {

    fillGrid();

    printf("Welcome to Mini-Minesweeper. There are %d mines spread across the grid.\n", numberOfMines);

    int x, y;

    while(1) {
        printGrid(0);

        do {
            printf("x = ");
            scanf("%d", &x);
        } while(x < 0 || x >= N);

        do {
            printf("y = ");
            scanf("%d", &y);
        } while(y < 0 || y >= N);

        if(grid[x][y] == MINE) {
            printGrid(1);
            printf("BOOM!\n");
            break;
        } else {
            grid[x][y] = SET;

            if(checkGrid()) {
                printGrid(1);
                printf("You win!\n");
                break;
            }
        }
    }

    return 0;
}
