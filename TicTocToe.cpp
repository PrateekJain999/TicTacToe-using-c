#include <iostream>
#include <conio.h>
#include <stdio.h>

// Constants >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
#define SIZE 3
#define DRAW 9
#define PLAYER1 0
#define PLAYER2 1

// Global Variables >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
typedef struct game
{
	char board[SIZE][SIZE];
	int indicator;
	int counter;
	bool win;
}game;

game game; //making structure object and initilize value to zero.

void gameBoard()
{
    printf("\n\t\t %c | %c | %c ", game.board[0][0] , game.board[0][1] , game.board[0][2] );
    printf("\n\t\t---|---|---");
    printf("\n\t\t %c | %c | %c ", game.board[1][0] , game.board[1][1] , game.board[1][2]);
    printf("\n\t\t---|---|---");
    printf("\n\t\t %c | %c | %c \n", game.board[2][0] , game.board[2][1] , game.board[2][2]);
} //end of board

bool checkWinner()
{
    if ( ((game.board[0][0] == game.board[0][1] && game.board[0][1] == game.board[0][2]) || (game.board[0][0] == game.board[1][1] && game.board[1][1] == game.board[2][2]) || (game.board[0][0] == game.board[1][0] && game.board[1][0] == game.board[2][0])) 
			|| ((game.board[0][1] == game.board[1][1] && game.board[1][1] == game.board[2][1])) || ((game.board[1][0] == game.board[1][1] && game.board[1][1] == game.board[1][2]))
			|| ((game.board[2][0] == game.board[2][1] && game.board[2][1] == game.board[2][2]))
			|| ((game.board[0][2] == game.board[1][1] && game.board[1][1] == game.board[2][0]) || (game.board[0][2] == game.board[1][2] && game.board[1][2] == game.board[2][2])) ) //winning condition
    {
        return true;
    } //end of if
    else
    {
        return false;
    } //end of else
} //end of win


void initilizeGame()
{
	game.counter=0;
	game.indicator=0;
	game.win=0;
	int counter=0;
	int row,column;
	
	for(row=0;row<SIZE;row++)
	{
		for(column=0;column<SIZE;column++)
		{
			counter++;
			game.board[row][column]= counter+'0'; //assigning counter value to matrix by concating with '0'.
		} //end of for loop
	} //end of for loop
} //end of initilize


int main()
{
    char mark, repeat;
    int row,column;
    
    printf("Press y or Y to play game or press any key to exit:");
	repeat = _getch();
    
    while ((repeat == 'y') || (repeat == 'Y')) //execute the game until user wants to play.
    {
		initilizeGame(); //calling function
        do
        {
            system("cls"); //clearing console screen
            gameBoard(); //display TicTocToe board

            mark = ((game.indicator+1) % 2) ? 'X' : 'O'; //checking which user is active and which character assign to that user

            printf("\nPlayer %d enter the row & column value: \n", ((game.indicator+1) % 2) ? 1 : 2);
            printf("row: ");
            scanf("%d", &row);
            printf("column: ");
            scanf("%d", &column);

        again: //using goto statement for jumping to this statements
        	if (row <SIZE && column <SIZE && (game.board[row][column]!='O' && game.board[row][column]!='X'))
            {
	        	game.board[row][column]=mark; //placing their mark at their selected position.
			} //end of if
			else
			{
				if(row>SIZE-1 || column>SIZE-1) //checking condition whether user give correct input or not.
				{
					printf("Invalid move enter another values:\n");
				} //end of if
				else
				{
					printf("Position already filled enter another values:\n");
				} //end of else
				
				printf("row: ");
				scanf("%d", &row);
				printf("column: ");
				scanf("%d", &column);
				goto again;
			}//end of else
			
            game.win = checkWinner();
            
            if(game.indicator==PLAYER2)
            {
            	game.indicator=PLAYER1;
			} //end of if
			else
			{
				game.indicator=PLAYER2;
			} //end of else
			game.counter++; //incrementing counter value for each input;
			
			if(game.counter==DRAW)
			{
				break;
			}
        } while (game.win==false); //end of do while loop
		
		system("cls"); //clearing console screen
        gameBoard(); //print board

        if (game.win == true)
        {
		    printf("\n\n\n\t | player %d is the Winner |\n",((game.indicator+1) % 2) ? 2 : 1); //checking which player is active
		} //end of if
        else
        {
		    printf("\n\n\n\t\t | game draw |\n");
		} //end of else

        printf("\n\nPress y or Y to play again or press any key to exit:");
        repeat = _getch(); //taking user input whether they wants to play one more time or not.

    } //end of while loop
    
    printf("\n\n\n\t\t | Thank You For Playing |\n");

    return 0;
} //end of main::
