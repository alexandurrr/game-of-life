#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 21
#define MAX_COLUMNS 44

#define FALSE 0
#define TRUE 1

#define DELAY 100000000


/* main functions */
void PrintWorld(char [MAX_ROWS][MAX_COLUMNS], int, int);
void ClearWorld(char [MAX_ROWS][MAX_COLUMNS], int, int);
void CopyWorld(char [MAX_ROWS][MAX_COLUMNS], char [MAX_ROWS][MAX_COLUMNS], int, int);
void NextGeneration(char [MAX_ROWS][MAX_COLUMNS], char [MAX_ROWS][MAX_COLUMNS], int, int);
void Animate(int, int);
int LiveCell(char [MAX_ROWS][MAX_COLUMNS], int, int);

/* Adding the cardinal directions */
int North(char [MAX_ROWS][MAX_COLUMNS], int, int);
int East(char [MAX_ROWS][MAX_COLUMNS], int, int);
int South(char [MAX_ROWS][MAX_COLUMNS], int, int);
int West(char [MAX_ROWS][MAX_COLUMNS], int, int);
int NorthEast(char [MAX_ROWS][MAX_COLUMNS], int, int);
int SouthEast(char [MAX_ROWS][MAX_COLUMNS], int, int);
int SouthWest(char [MAX_ROWS][MAX_COLUMNS], int, int);
int NorthWest(char [MAX_ROWS][MAX_COLUMNS], int, int);


main()
{
    char emptyWorld[MAX_ROWS][MAX_COLUMNS] = {"!------------------------------------------!",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!                                          !",
                                              "!------------------------------------------!"};


    char stableWorld[MAX_ROWS][MAX_COLUMNS] = {"!------------------------------------------!",
                                               "!                                          !",
                                               "!       xx xx                              !",
                                               "!        x x                               !",
                                               "!        x x            xx                 !",
                                               "!       xx xx           xx                 !",
                                               "!                                          !",
                                               "!                                          !",
                                               "!                                          !",
                                               "!       xxxx             x                 !",
                                               "!                        xx                !",
                                               "!                         x                !",
                                               "!                                          !",
                                               "!                                          !",
                                               "!                                          !",
                                               "!                                          !",
                                               "!            x                             !",
                                               "!            xxx                           !",
                                               "!                                          !",
                                               "!                                          !",
                                               "!------------------------------------------!"};



    char oscillatingWorld[MAX_ROWS][MAX_COLUMNS] = {"!------------------------------------------!",
                                                    "!                                          !",
                                                    "!                                          !",
                                                    "!                                          !",
                                                    "!                                          !",
                                                    "!       xx     xx                          !",
                                                    "!        xx   xx               xxx         !",
                                                    "!     x  x x x x  x                        !",
                                                    "!     xxx xx xx xxx                        !",
                                                    "!      x x x x x x                         !",
                                                    "!       xxx   xxx                          !",
                                                    "!                                          !",
                                                    "!       xxx   xxx                          !",
                                                    "!      x x x x x x               x         !",
                                                    "!     xxx xx xx xxx              x         !",
                                                    "!     x  x x x x  x              x         !",
                                                    "!        xx   xx                           !",
                                                    "!       xx     xx                          !",
                                                    "!                                          !",
                                                    "!                                          !",
                                                    "!------------------------------------------!"};



    char spaceShipWorld[MAX_ROWS][MAX_COLUMNS] = {"!------------------------------------------!",
                                                  "!                                          !",
                                                  "!     x                                    !",
                                                  "!      x                                   !",
                                                  "!    xxx                                   !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!                                          !",
                                                  "!           x                              !",
                                                  "!          x                               !",
                                                  "!          xxx                             !",
                                                  "!                                          !",
                                                  "!------------------------------------------!"};


    char world [MAX_ROWS][MAX_COLUMNS], newWorld [MAX_ROWS][MAX_COLUMNS];
    int tick;


    CopyWorld(emptyWorld, newWorld, MAX_ROWS+1, MAX_COLUMNS+1);

    while (TRUE)
    {
        //Uncomment the type of world u want to run below, right now spaceship is run.
/*
        CopyWorld(stableWorld, world, MAX_ROWS+1, MAX_COLUMNS+1);
        for (tick=1; tick < 10; tick++)
        {
            PrintWorld(world, MAX_ROWS, MAX_COLUMNS);
            Animate(tick, DELAY);

            NextGeneration(world, newWorld, MAX_ROWS, MAX_COLUMNS);
            CopyWorld(newWorld, world, MAX_ROWS+1, MAX_COLUMNS+1);
            ClearWorld(newWorld, MAX_ROWS, MAX_COLUMNS);
            tick++;
        }

        CopyWorld(oscillatingWorld, world, MAX_ROWS+1, MAX_COLUMNS+1);
        for (tick=1; tick < 20; tick++)
        {
            PrintWorld(world, MAX_ROWS, MAX_COLUMNS);
            Animate(tick, DELAY);

            NextGeneration(world, newWorld, MAX_ROWS, MAX_COLUMNS);
            CopyWorld(newWorld, world, MAX_ROWS+1, MAX_COLUMNS+1);
            ClearWorld(newWorld, MAX_ROWS, MAX_COLUMNS);
            tick++;
        }
        */
        CopyWorld(spaceShipWorld, world, MAX_ROWS+1, MAX_COLUMNS+1);
        for (tick=1; tick < 200; tick++)
        {
            PrintWorld(world, MAX_ROWS, MAX_COLUMNS);
            Animate(tick, DELAY);

            NextGeneration(world, newWorld, MAX_ROWS, MAX_COLUMNS);
            CopyWorld(newWorld, world, MAX_ROWS+1, MAX_COLUMNS+1);
            ClearWorld(newWorld, MAX_ROWS, MAX_COLUMNS);
            tick++;
        }
    }
}

/* print the grid of the world */
void PrintWorld(char world[][MAX_COLUMNS], int m, int n)
{
    int i, j;

    printf("\n\n");
    for (i=0; i<m; i++)
    {
        for (j=0; j<n; j++)
            printf("%c", world[i][j]);
        printf("\n");
    }
}


/* clear all cells of the world; caution: do not overwrite the array elements along the margins */
void ClearWorld(char world[][MAX_COLUMNS], int m, int n)
{
    int i, j;

    for (i=1; i<m-1; i++)
    {
        for (j=1; j<n-1; j++)
            world[i][j] = ' ';
    }
}


/* make a copy of the world */
void CopyWorld(char world[][MAX_COLUMNS], char copyWorld[][MAX_COLUMNS], int m, int n)
{
    int i, j;

    for (i=0; i<m-1; i++)
    {
        for (j=0; j<n-1; j++)
            copyWorld[i][j] = world[i][j];
    }
}


/* compute the next generation of the world */
void NextGeneration(char oldWorld[][MAX_COLUMNS], char newWorld[][MAX_COLUMNS], int m, int n)
{
    int i, j;
    int numNeighbors;
    char ch;

    for (i=1; i<m-1; i++)
        for (j=1; j<n-1; j++)
        {
            /*
            printf("\n\nchecking cell (%d, %d):", i, j);
            printf("North: %d, East: %d, South: %d,West: %d\n", North(oldWorld, i, j), East(oldWorld, i, j), South(oldWorld, i, j), West(oldWorld, i, j));
            printf("NorthEast: %d, SouthEast: %d, SouthWest: %d, Northwest: %d\n", NorthEast(oldWorld, i, j), SouthEast(oldWorld, i, j), SouthWest(oldWorld, i, j), NorthWest(oldWorld, i, j));
            */

            numNeighbors = North(oldWorld, i, j) + East(oldWorld, i, j) + South(oldWorld, i, j) + West(oldWorld, i, j);
            numNeighbors += NorthEast(oldWorld, i, j) + SouthEast(oldWorld, i, j) + SouthWest(oldWorld, i, j) + NorthWest(oldWorld, i, j);

            /*
            printf("status: %d number of live neighbors: %d\n", LiveCell(oldWorld, i, j), numNeighbors);
            */

            if (LiveCell(oldWorld, i, j))
            {
                if ((numNeighbors < 2) || (numNeighbors > 3))
                {
                    newWorld[i][j] = ' ';
                }
                else
                {
                    newWorld[i][j] = 'x';
                }
            }
            else
            if (numNeighbors == 3)
            {
                newWorld[i][j] = 'x';
            }
            else
                newWorld[i][j] = ' ';
        }
}


/* insert sufficient printf("\n") statement to display the world in the same place as the
   before and delay printing the next world sufficienty so that it looks like a movie */
void Animate(int tick, int delay)
{
    int i;


    printf("\nMy world at generation %d\n\n\n", tick);

    for (i=0; i<delay; i++);

    for (i=0; i<23; i++)
        printf("\n");


}


/* return 1 if a cell at (x, y) is alive and 0 otherwise */
int LiveCell(char world[][MAX_COLUMNS], int i, int j)
{
    return (world[i][j] == 'x');
}


/* return 1 if a cell North of (x, y) is alive and 0 otherwise
   special care must be taken to find the neighbors of cells
   along the upper boundary of the world                        */
int North(char world[][MAX_COLUMNS], int row, int column)
{
    int newRow;


    newRow = row - 1;

    if (newRow == 0)
        newRow = MAX_ROWS-2;

    return (world[newRow][column] == 'x');
}


/* return 1 if a cell Northeast of (x, y) is alive and 0 otherwise
   special care must be taken to find the neighbors of cells
   along the upper and right boundaries of the world              */
int NorthEast(char world[][MAX_COLUMNS], int row, int column)
{
    int newRow, newColumn;


    newRow = row - 1;
    newColumn = column + 1;

    if (newRow == 0)
        newRow = MAX_ROWS-2;

    if (newColumn == MAX_COLUMNS-1)
        newColumn = 1;



    return (world[newRow][newColumn] == 'x');
}


/* return 1 if a cell East of (x, y) is alive and 0 otherwise
   special care must be taken to find the neighbors of cells
   along the right boundary of the world                        */
int East(char world[][MAX_COLUMNS], int row, int column)
{
    int newColumn;


    newColumn = column + 1;

    if (newColumn == MAX_COLUMNS-1)
        newColumn = 1;

    return (world[row][newColumn] == 'x');
}


/* return 1 if a cell Southeast of (x, y) is alive and 0 otherwise
   special care must be taken to find the neighbors of cells
   along the left and lower boundaries of the world             */
int SouthEast(char world[][MAX_COLUMNS], int row, int column)
{
    int newRow, newColumn;


    newRow = row + 1;
    newColumn = column + 1;

    if (newRow == MAX_ROWS-1)
        newRow = 1;

    if (newColumn == MAX_COLUMNS-1)
        newColumn = 1;

    return (world[newRow][newColumn] == 'x');
}



/* return 1 if a cell South of (x, y) is alive and 0 otherwise
   special care must be taken to find the neighbors of cells
   along the lower boundary of the world                        */
int South(char world[][MAX_COLUMNS], int row, int column)
{
    int newRow;


    newRow = row + 1;

    if (newRow == MAX_ROWS-1)
        newRow = 1;

    return (world[newRow][column] == 'x');
}


/* return 1 if a cell Southwest of (x, y) is alive and 0 otherwise
   special care must be taken to find the neighbors of cells
   along the lower and left boundaries of the world             */
int SouthWest(char world[][MAX_COLUMNS], int row, int column)
{
    int newRow, newColumn;


    newRow = row + 1;
    newColumn = column - 1;

    if (newRow == MAX_ROWS-1)
        newRow = 1;

    if (newColumn == 0)
        newColumn = MAX_COLUMNS-2;

    return (world[newRow][newColumn] == 'x');
}


/* return 1 if a cell West of (x, y) is alive and 0 otherwise
   special care must be taken to find the neighbors of cells
   along the left boundary of the world                        */
int West(char world [][MAX_COLUMNS], int row, int column)
{
    int newColumn;


    newColumn = column - 1;

    if (newColumn == 0)
        newColumn = MAX_COLUMNS-2;

    return (world[row][newColumn] == 'x');
}


/* return 1 if a cell Northwest of (x, y) is alive and 0 otherwise
   special care must be taken to find the neighbors of cells
   along the left and upper boundaries of the world             */
int NorthWest(char world [][MAX_COLUMNS], int row, int column)
{
    int newRow, newColumn;


    newRow = row - 1;
    newColumn = column - 1;

    if (newRow == 0)
        newRow = MAX_ROWS-2;

    if (newColumn == 0)
        newColumn = MAX_COLUMNS-2;

    return (world[newRow][newColumn] == 'x');
}






