#include "pch.h"
#include "windows.h"
#include <iostream>
using namespace std;

char point[3][3] = {{ ' ',' ',' ' },    /* '1','2','3'  00  01  02 */				//Creates 2D array
				    { ' ',' ',' ' },    /* '4','5','6'  10  11  12 */
					{ ' ',' ',' ' }};   /* '7','8','9'  20  21  22 */
int checkwin();																		//Initialization for checkwin function
void board();																		//Initialization for board function

int main() {																		//Start of main function
	int i;																			//
	char mark, ch, sel;																//
	bool end = false;																//Sets end variable to false
	do {																			//Everything in this loop will repeat until bool end is true
		int counter = 0;															//Initializing counter to 0 outside of main loop to prevent over-initializing it to 0 every turn and player 2 never getting a turn.
		do {																		//Our main game do loop.
			board();																//Initializing the board.
			/***************************************************************************************************************************************
			*    Title: " Need help with a easy C++ 2 player game code"
			*    Author: Andi
			*    Date: 10 November 2016
			*    Code version: Unknown
			*	 What was used?: The below available if statements were taken and modified to suit my purpose.
			*    Availability: https://cboard.cprogramming.com/cplusplus-programming/171400-need-help-easy-cplusplus-2-player-game-code.html.
			***************************************************************************************************************************************/
			if (counter % 2 == 0) {													//If statement to tell if player 1 gets a turn or player 2.
				cout << "Player 1 goes now: ";										//Displays a message for player 1 to make his selection
				cin >> sel;															//Input for the selection variable
				mark = 'X';															//Player 1 has assigned X as his mark
			}
			else {																	//After player 1 had a go let player 2 have a go.
				cout << "Player 2 goes now: ";										//Displays a message for player 2 to make his selection
				cin >> sel;															//Input for the selectino variable
				mark = '0';															//Player 2 is assigned 0 as his mark.
			}
			/******************************************************************************************************************************************
			*    Title: "Infinite loop with cin when typing string while a number is expected"
			*    Author: Doug T
			*    Date: 3 May 2011
			*    Code version: Unknown
			*	 What was used?: Code by the user was informative but didn't work as intended so I modified the below if statement so it works for me.
			*    Availability: https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected.
			******************************************************************************************************************************************/
			if (sel < '1' || sel > '9') {											
				cin.clear();														
				cin.ignore();														
				cout << "Input needs to be a number 1 - 9!" << endl;				
				Sleep(2000);														
			}
			else {																	
				/***********************************************************************************************************
				*    Title: "C++ Tic Tac Toe Game Project - source code"
				*    Author: Deepak Singh
				*    Date: 15 April 2011
				*    Code version: Unknown
				*	 What was used?: The below code until finish confirmation are modification of available code below
				*    Availability: http://www.cppforschool.com/project/tic-tac-toe-project.html.
				***********************************************************************************************************/
				
				switch (sel) {
				case '1':
				}
				
				
				
				
				/*if (sel == '1' && point[0][0] == ' ')								
					point[0][0] = mark;													
				else if (sel == '2' && point[0][1] == ' ')							
					point[0][1] = mark;													
				else if (sel == '3' && point[0][2] == ' ')							
					point[0][2] = mark;													
				else if (sel == '4' && point[1][0] == ' ')							
					point[1][0] = mark;													
				else if (sel == '5' && point[1][1] == ' ')							
					point[1][1] = mark;													
				else if (sel == '6' && point[1][2] == ' ')							
					point[1][2] = mark;													
				else if (sel == '7' && point[2][0] == ' ')							
					point[2][0] = mark;													
				else if (sel == '8' && point[2][1] == ' ')							
					point[2][1] = mark;													
				else if (sel == '9' && point[2][2] == ' ')							
					point[2][2] = mark;													
				else																
				{
					cout << "Invalid move ";										
					counter--;														
					Sleep(1000);													
				}*/
				i = checkwin();														
				counter++;															
			}
		} while (i == -1);															
		board();																	
		if (i == 1)																	
			cout << "Player 1 wins " << endl;			
		else if (i == 2)															
			cout << "Player 2 wins" << endl;								
		else {
			cout << "Nobody Wins" << endl;
		}
		/**********************************************************************************************************/
		/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
		/**********************************************************************************************************/
		cout << "Do you want to finish? (y/n): ";									
		cin >> ch;																	
		if (ch == 'y') {															
			end = true;																
		}
		/* If choice is 'n' we need to reset the board byt he following for loop. */
		for (int c = 0; c < 3; c++) {												
			for (int d = 0; d < 3; d++) {
				point[c][d] = ' ';
			}
		}

	} while (!end);																	//Again if player chooses to exit this variable will change to true.
	system("CLS");																	//Clears the screen.
	cout << "\n\n\n\n\t\t\t\t    Thank you for playing my game." << endl << endl;   //When choosing to exit show this message before exiting.
	cout << "\r\t\t\t\t\t    Exiting in 3 seconds.";								//Displays message to inform that it's exiting in 3 seconds.
	Sleep(1000);																	//Waits 1 second.
	cout << "\r\t\t\t\t\t    Exiting in 2 seconds.";								//Displays message to inform that it's exiting in 2 seconds.
	Sleep(1000);																	//Waits 1 second.
	cout << "\r\t\t\t\t\t    Exiting in 1 seconds.";								//Displays message to inform that it's exiting in 1 seconds.
	Sleep(1000);																	//Waits 1 second.
	exit(0);																		//Fully exits the program without the need for user interaction afterwards.
}
/* Just like the clear board abovethis draws the board on screen whenever it is required while storing the variables */
void board()
{
	system("cls");																	//Clears the screen each time so we don't end up with variaty of board on screen
	cout << "\n\n\t\t\t\t\t  Player 1 (X)  -  Player 2 (O)" << endl << endl;
	for (int a = 0; a < 3; a++) {
		cout << "\t\t\t\t\t          +---+---+---+" << endl;
		cout << "\t\t\t\t\t\t  ";
		for (int b = 0; b < 3; b++) {
			cout << "| " << point[a][b] << " ";
		}
		cout << "| " << endl;
	} 
	cout << "\t\t\t\t\t          +---+---+---+" << endl << endl;
} 

/*************************************************************************************************
*    Title: "C++ Tic Tac Toe Game Project - source code"
*    Author: Deepak Singh
*    Date: 15 April 2011
*    Code version: Unknown
*	 What was used?: The below function is modification of code available on below website.
*    Availability: http://www.cppforschool.com/project/tic-tac-toe-project.html.
*************************************************************************************************/
int checkwin()																						
{
	if (point[0][0] == 'X' && point[0][1] == 'X' && point[0][2] == 'X') return 1;
	else if (point[0][0] == '0' && point[0][1] == '0' && point[0][2] == '0') return 2;
	
		

	else if (point[1][0] == point[1][1] && point[1][1] == point[1][2] && point[1][0] != ' ')		
		return 1;																					
	else if (point[2][0] == point[2][1] && point[2][1] == point[2][2] && point[2][0] != ' ')		
		return 1;																					
	else if (point[0][0] == point[1][0] && point[1][0] == point[2][0] && point[0][0] != ' ')		
		return 1;																					
	else if (point[0][1] == point[1][1] && point[1][1] == point[2][1] && point[0][1] != ' ')		
		return 1;																					
	else if (point[0][2] == point[1][2] && point[1][2] == point[2][2] && point[0][2] != ' ')		
		return 1;																					
	else if (point[0][0] == point[1][1] && point[1][1] == point[2][2] && point[0][0] != ' ')		
		return 1;																					
	else if (point[0][2] == point[1][1] && point[1][1] == point[2][0] && point[0][2] != ' ')		
		return 1;																					
	else if (point[0][0] != ' ' && point[0][1] != ' ' && point[0][2] != ' '							
		  && point[1][0] != ' ' && point[1][1] != ' ' && point[1][2] != ' '
		  && point[2][0] != ' ' && point[2][1] != ' ' && point[2][2] != ' ')
		return 0;																					
	else
		return -1;																					
}