#include <stdio.h>
#include <stdlib.h>
#include "TicTacToe.h"
#define SIZE 9

char grid[SIZE] = {'0', '1', '2', '3', '4', '5', '6', '7', '8' };
void drawGrid( char a[] )
{

    printf( "\n" );
    printf( " %c | %c | %c \n", a[0], a[1], a[2] );
    printf( "---|---|---\n");
    printf( " %c | %c | %c \n", a[3], a[4], a[5] );
    printf( "---|---|---\n");
    printf( " %c | %c | %c \n", a[6], a[7], a[8] );
    printf("\n");
}

void takeTurn( char a[], char *playerPtr  )
{
    int available[8];
    int i, j = 0, choice;
    for(i = 0; i < 9; i++ )
    {
         if( (a[i] != 'X') && (a[i] != 'O')  )
            {available[ j++ ] = i;}
    }


    printf( "\n It is %c's turn.  Choose your move (", *playerPtr );

    for( i = 0; i < j; i++ )
        {printf( " %d", available[i]);}
    printf(")");
    printf( " --> ");
    scanf( "%d", &choice);
            if( *playerPtr == 'X' )
            {
                a[ choice ] = 'X';
            }
            else
            {
                 a[ choice ] = 'O';
            }
}
int checkForWinner( char a[], int cnt, char* playerPtr  )
{
    int i, gameOver = 0;
    for( i = 0; i < 3; i++ )
    {
        if( a[3*i] == a[3*i + 1] && a[3*i + 1] == a[3*i + 2])
            {
                printf( "We have a winner! It is %c.\n\n", *playerPtr );
                gameOver = 1;
            }
        if( a[i] == a[i + 3] && a[i + 3] == a[i + 6])
            {
            printf( "Game over, man! %c dominates.\n\n", *playerPtr );
            gameOver = 1;
            }
    }

    if( a[0] == a[4] && a[4] == a[8])
    {
        printf( "%c wins on a diagonal move!\n\n", *playerPtr );
        gameOver = 1;
    }
    if( a[2] == a[4] && a[4] == a[6])
    {
        printf( "That's it. %c has won!\n\n", *playerPtr );
        gameOver = 1;

    }
    if( cnt == 8  && gameOver ==  0 )
    {
        printf( "Awww. There is no winner!\n\n" );
        gameOver = 1;
    }
    return gameOver;
}
void swapPlayer( char *playerPtr )
{
    if( *playerPtr == 'X' )
    {
        *playerPtr = 'O';
    }
    else
    {
        *playerPtr = 'X';
    }
}
void computerTurn( char a[], char *playerPtr, char computerPlayer)
{

    int available[8];
    int i, j = 0, choice, availableLen=0;
    for(i = 0; i < 9; i++ )
    {
        if( (a[i] != 'X') && (a[i] != 'O'))
        {
            available[ j++ ] = i;
            availableLen++;
        }
    }
    int random;
    random=rand()%((availableLen)-1);
    int nextmove=available[random];
    a[nextmove]=computerPlayer;
    printf("computer is playing next move is %d\n",nextmove);
}

    void drawfile(char a[]){
        FILE *file;
        file=fopen("tablo","w");

            fprintf(file, "\n" );
            fprintf(file, " %c | %c | %c \n", a[0], a[1], a[2] );
            fprintf(file, "---|---|---\n");
            fprintf(file, " %c | %c | %c \n", a[3], a[4], a[5] );
            fprintf(file, "---|---|---\n");
            fprintf(file, " %c | %c | %c \n", a[6], a[7], a[8] );
            fprintf(file,"\n");

             fclose(file);

}
