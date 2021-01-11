#include <stdio.h>

    void drawGrid(char a[])
    {
            printf( "\n" );
            printf( " %c | %c | %c \n", a[0], a[1], a[2] );
            printf( "---|---|---\n");
            printf( " %c | %c | %c \n", a[3], a[4], a[5] );      //Draw the current version of the table.
            printf( "---|---|---\n");
            printf( " %c | %c | %c \n", a[6], a[7], a[8] );
            printf("\n");
    }



    void takeTurn( char a[], char *playerPtr  )
     {
            int available[8];                //we Define an 8-element array
            int i, j = 0, choice;
            for(i = 0; i < 9; i++ )                  //By increasing the value of i one by one, it is navigated through the array a (grid)
            if( (a[i] != 'X')  && (a[i] != 'O')  )  //and the areas where the x or o value is not given are saved in the available array.
            available[ j++ ] = i;                   // This way, fields that are not valued are kept in an array.


            printf( "\n It is %c's turn.  Choose your move (", *playerPtr );     //Prints who is in the selection order on the screen

            for( i = 0; i < j; i++)
            printf( " %d", available[i]);       // It prints the available string to the screen.
            printf( " ): ");
            scanf( "%d", &choice);              //prints the user's letter in the field in the number received from the user.

            if( *playerPtr == 'X'  )
                a[ choice ] = 'X';
            else
                a[ choice ] = 'O';

     }

    void takeTurn2( char a[], char *playerPtr  )    //this function allows the user to play against the computer

         {
            int available[8];
            int i, j = 0, choice;
            for(i = 0; i < 9; i++ )                 //By increasing the value of i one by one, it is navigated through the array a (grid)
            if( (a[i] != 'X') && (a[i] != 'O')  )   //and the areas where the x or o value is not given are saved in the available array.
            available[ j++ ] = i;                   // This way, fields that are not valued are kept in an array.

            printf( "\n It is %c's turn.  Choose your move (", *playerPtr );     //Prints who is in the selection order on the screen


            for( i = 0; i < j; i++ )
                printf( " %d", available[i]);
                printf( " ): ");

            if( *playerPtr == 'X' )         //if the turn is at x it means that the computer will play
            {
                srand(time(NULL));           //this function generates a random number
                int rastgele=rand()%9;     //we got the random number mod with 9.Because we need numbers between 0 and 8
                if(a[rastgele]=='O' || a[rastgele]=='X' ) //If this part is already filled in, we generate a new number so that the computer cannot move to the same area again.
            {
               while(a[rastgele]=='O' || a[rastgele]=='X')
               {
                srand(time(NULL));
                rastgele=rand()%9;
               }                                 //We make the selection again until we come to a field that was not previously filled
              a[ rastgele ] = 'X';
               }
              a[ rastgele ] = 'X';
            }
              else
                scanf( "%d", &choice);
              if(choice!=0)                  //the turn of moves is in the user playing against the computer
               {
                a[choice] = 'O';
               }
             else if(choice=0)
                a[choice]='O';
         }

    int checkForWinner( char a[], int cnt, char* playerPtr  )
      {
                int i, gameOver = 0;            //We set the game over value as 0
            for( i = 0; i < 3; i++ )
                {
                 if( a[3*i] == a[3*i + 1] && a[3*i + 1] == a[3*i + 2])     //check whether horizontal lines are the same
                    {
                        printf( "We have a winner! It is %c.\n\n", *playerPtr );
                        gameOver = 1;
                    }
                if( a[i] == a[i + 3] && a[i + 3] == a[i + 6])        //check if the vertical lines are the same
                    {
                    printf( "Game over, man! %c dominates.\n\n", *playerPtr );
                    gameOver = 1;
                    }
                }

            if( a[0] == a[4] && a[4] == a[8])        //check if the cross areas are the same(starting from the top left to the bottom right )
                {
                    printf( "%c wins on a diagonal move!\n\n", *playerPtr );
                    gameOver = 1;
                }
            if( a[2] == a[4] && a[4] == a[6])        //check if the cross areas are the same (starting from the top right to the bottom left)
                {
                    printf( "That's it. %c has won!\n\n", *playerPtr );
                    gameOver = 1;

                }
            if( cnt == 8  && gameOver ==  0 )       // If all fields are filled, no winner is printed on the screen
                {
                    printf( "Awww. There is no winner!\n\n" );
                    gameOver = 1;
                }
            return gameOver;
      }

    void swapPlayer( char *playerPtr )  //Allows us to make changes between players.
        {
            if( *playerPtr == 'X' )
                *playerPtr = 'O';           //Return o if ptr equals x,else returns x  in this way
                                            //each time the function is called, it is passed to the other user.
            else
                *playerPtr = 'X';
        }
    void createafile(char a[]){
        FILE *da;
        da=fopen("C:\\Users\\yeozg\\OneDrive\\Masaüstü\\tablo","w");    //We opened the file

            fprintf(da, "\n" );
            fprintf(da, " %c | %c | %c \n", a[0], a[1], a[2] );
            fprintf(da, "---|---|---\n");
            fprintf(da, " %c | %c | %c \n", a[3], a[4], a[5] );              //This function creates a new file And saves the final situation.
            fprintf(da, "---|---|---\n");
            fprintf(da, " %c | %c | %c \n", a[6], a[7], a[8] );
            fprintf(da,"\n");

             fclose(da);       //we closed the file



}
