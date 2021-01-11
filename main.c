
#include <stdio.h>
#define SIZE 9                    //We have defined 9  as size
#include "version2.header.h"
#include "version_2_source.c"


int main()
    {
      char grid[SIZE] = {'0', '1', '2', '3', '4', '5', '6', '7', '8' };     //we Define an 9-element array
      char currentPlayer,temp;
      int counter = 0, done = 0;

     int a;
     char a2='p';
     printf("press 1 to play against the computer \npress 2 to play the game for two player \n" );  //Asks the user for the game type
     scanf("%d",&a);
     scanf("%c",&a2);


        if(a !=1 && a != 2)
         {
          while(a !=1 && a != 2 )
          {
            printf("please enter a valid value...");    //If he/she enters an invalid value, we ask again.
            scanf("%d",&a);
            a2='p';
          }
         }
        if(a==2)      //if the user pres 1 he/she want to play with friends.
         {
           label:

           printf(" Select one x or o with uppercase letter \n");   // we ask the user which letter they chose.
           scanf("%c",&temp);

           if(temp=='X' || temp=='O')
           {
            currentPlayer = temp;            //if the user enters the correct value the value is saved
            printf("\n");

           while( !done )
           {
             drawGrid( grid );          //Game table drawn.
             takeTurn( grid, &currentPlayer );
             system("cls");              //clean the console.
             done = checkForWinner( grid, counter, &currentPlayer );
             createafile(grid);
             swapPlayer( &currentPlayer );
             counter++;

          }
    drawGrid( grid );
          }
        else if(temp!='X' || temp!='O')
          {
           printf("\n");
           system("CLS");  //clean the console.
        goto label;    //32.satýra geri döner.

          }
         }
        else if(a==1)      //if the user pres 1 he/she want to play with computer.
         {

          while( !done )
           {
            drawGrid( grid );
            takeTurn2( grid, &currentPlayer );
            system("cls");
            done = checkForWinner( grid, counter, &currentPlayer );
            createafile(grid);           //Durumu rapora yazdýrýr.
            swapPlayer( &currentPlayer );
            counter++;
           }
    drawGrid( grid );
        }

    }
