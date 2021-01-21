#include "TicTacToe.c"
    int main()
    {
        char grid[SIZE] = {'0', '1', '2', '3', '4', '5', '6', '7', '8' };
        char currentPlayer = 'O';
        char computerPlayer;
        int counter = 0, done = 0;
        int c,computer;
        char computer2='c';

label1:
        printf("do you play against computer or multiplayer ?\n");
        printf("press 1 for  against computer \n");
        printf("press 2 for multiplayer \n\n");
        scanf("%d",&computer);
        scanf("%c",&computer2);

        int a;
        char a2;
        if(computer==1){
label2:
            printf("do you want to play with X or O ?\n");
            printf("enter 1 for X \n");
            printf("enter 2 for O \n\n");
            scanf("%d",&a);
            scanf("%c",&a2);
             if(a==1)
            {
                computerPlayer='O';
            }
            else if(a==2)
            {
                computerPlayer='X';
            }
            else
                goto label2;
            }
        else if(computer==2){
label3:
            printf("1st player please choose if you want to play with X or O ?\n");
            printf("enter 1 for X\n");
            printf("or anything else for O\n\n");
            scanf("%d",&a);
            scanf("%c",&a2);
        }
        else
            goto label1;

        switch(a){
            case 1:
                currentPlayer = 'X';
                break;
            case 2:
                currentPlayer = 'O';
                break;
            default:
                goto label3;
                break;
        }

        drawGrid( grid );
        while( !done )
        {
        if(computer==1 && computerPlayer==currentPlayer ){
            computerTurn( grid, &currentPlayer,computerPlayer);
        }
        else{
            takeTurn( grid, &currentPlayer );
        }
        system("cls");
        drawGrid( grid );
        done = checkForWinner( grid, counter, &currentPlayer );
        swapPlayer( &currentPlayer );
        counter++;
        drawfile(grid);

        }
}


