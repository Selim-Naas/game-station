#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

//function prototypes
void bannerTTT();
int singleplayer ();
int multiplayer ();
int displayBoard (); 
int checkTie ();
int checkWin (); 
int displayPlayAgain (char _playAgain);
int compMoveEasy ();
int compMoveMed (int a);
int compMoveHard (int a);
int compMoveLegendary ();
int playerMove (char _position, int _x);
int resetBoard ();
int sendToMainTTT ();
int winsTTT;

//2D array of the Tic Tac Toe Board
char board[3][3] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
};

int mainTTT() {
	char gamemodeTTT;
	char goBackTTT;
	
	FILE *fp;
		fp = fopen("tictactoe_stats.txt", "r");
		if(fp == NULL) {
			printf("Could not locate file! ");
			system("pause");
			return 0;
		}
		
		while (!feof(fp)) {
			fscanf(fp, "%i", &winsTTT);
		}
		fclose(fp);
	
	bannerTTT();
	printf("1 ==> Singleplayer\n");
	printf("2 ==> Multiplayer\n");
	printf("3 ==> View Stats\n");
	printf("4 ==> Change Game\n");
	printf("5 ==> Quit\nEnter Choice: ");
	
	do {
		gamemodeTTT = getch();
		if (gamemodeTTT == '1') {
			system("cls");
			singleplayer ();
		}
		if (gamemodeTTT == '2') {
			system("cls");
			multiplayer ();
		}
		if (gamemodeTTT == '3') {
			system("cls");
			bannerTTT();
			printf("Total Tic-Tac-Toe Wins: %i\n\n", winsTTT);
			printf("Go back? (Y): ");
			
			do {
				goBackTTT = getch();
				if (goBackTTT == 'Y' || goBackTTT == 'y') {
					system("cls");
					sendToMain();
					break;
				}
			} while (goBackTTT != 'Y' || goBackTTT != 'y');
		}
		if (gamemodeTTT == '4') {
			gameMenu();
		}
		if (gamemodeTTT == '5') {
			exit(1);
		}
	} while (gamemodeTTT != '1' || gamemodeTTT != '2' || gamemodeTTT != '3' || gamemodeTTT != '4' || gamemodeTTT != '5');
	return 0;
}

int singleplayer () {
	char difficultyTTT;	//the dificulty is deteremined by this variable
	char playerStartTTT;
	char positionTTT;
	char playAgainTTT;
	int x, tie;
	int resetStatsTTT;
	bannerTTT();
		
	printf("1 ==> Easy\n");			 //Computer chooses completely random spots to place 'O'.
	printf("2 ==> Medium\n");		 //Computer only checks if the player might win, can be beaten if a trap is setup.
	printf("3 ==> Hard\n");			 //Computer checks if player AND computer might win, however it does not check for advanced traps.
	printf("4 ==> Legendary\n\n");	 //Computer checks if player AND computer might win, and in additon to not get trapped, places 'O' in the middle or in the corners therefore making it imposibble to beat.
	printf("Chose the difficulty: ");

	do {
		difficultyTTT = getch();
		if (difficultyTTT == '1') {
			system("cls");
			bannerTTT();
			
			printf("Do you want to start first?\n");
			printf("1 ==> YES\n");
			printf("2 ==> NO\n");
			printf("Choice: ");
			
			do {
				playerStartTTT = getch();
				if (playerStartTTT == '1') {
					x = 0; tie = 0; //tie variable is equal to the INITIAL amount of x, becuase x will increment.
					break;
				}
				if (playerStartTTT == '2') {
					x = 1; tie = 1;	//tie variable is equal to the INITIAL amount of x, becuase x will increment.
					break;
				}
			} while (playerStartTTT != '1' || playerStartTTT != '2');
			
			for (; x <= 10; x++) {
				if (checkWin() == 1) { //checks for a win at the very start
					winsTTT++; 
					statsTTT(winsTTT);
					system("cls");
					displayBoard();
					printf("\nYou Won!\a\tTotal Tic-Tac-Toe Wins: %i\n", winsTTT);
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\n");
					printf("3 ==> Reset Stats\n");
					printf("Enter choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
						if (playAgainTTT == '3') {
							system("cls");
							bannerTTT();
							printf("Stats will be lost forever! Continue? (Y/N)");
							do {
								resetStatsTTT = getch();
								if (resetStatsTTT == 'Y' || resetStatsTTT == 'y') {
									winsTTT = 0;
									statsTTT(winsTTT);
									resetBoard();
									system("cls");
									printf("\nStats have been succesfully reset!");
									sleep(1);
									system("cls");
									sendToMain ();
								}
								if (resetStatsTTT == 'N' || resetStatsTTT == 'n') {
									exit(1);
								}
							} while (resetStatsTTT != 'Y' || resetStatsTTT != 'y' || resetStatsTTT != 'N' || resetStatsTTT != 'n');
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2' || playAgainTTT != '3');
				}
				if (checkWin() == 2) { //checks for a win at the very start
					system("cls");
					displayBoard();
					printf("\nComputer Won!\a\tTotal Tic-Tac-Toe Wins: %i\n", winsTTT);
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\n");
					printf("3 ==> Reset Stats\n");
					printf("Enter choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
						if (playAgainTTT == '3') {
							system("cls");
							bannerTTT();
							printf("Stats will be lost forever! Continue? (Y/N)");
							do {
								resetStatsTTT = getch();
								if (resetStatsTTT == 'Y' || resetStatsTTT == 'y') {
									winsTTT = 0;
									statsTTT(winsTTT);
									resetBoard();
									system("cls");
									printf("\nStats have been succesfully reset!");
									sleep(1);
									system("cls");
									sendToMain ();
								}
								if (resetStatsTTT == 'N' || resetStatsTTT == 'n') {
									exit(1);
								}
							} while (resetStatsTTT != 'Y' || resetStatsTTT != 'y' || resetStatsTTT != 'N' || resetStatsTTT != 'n');
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2' || playAgainTTT != '3');
				}
				if (x == 9 && tie == 0 || x == 10 && tie == 1) {
					system("cls");
					displayBoard();
					printf("It's a Tie!\n");
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\nEnter Choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2');
				}
				system("cls");
				displayBoard();
				
				if (x%2 == 0) {
					printf("%i", x);
					printf("\nbro, enter position (1-9): ");
					positionTTT = getch();
				
					switch (positionTTT) {
						case '1':
							if (board[0][0] == '1') { board[0][0]  = 'X'; }
							else { x--; }
						break;
						case '2':
							if (board[0][1] == '2') { board[0][1]  = 'X'; }
							else { x--; }
						break;
						case '3':
							if (board[0][2] == '3') { board[0][2]  = 'X'; }
							else { x--; }
						break;
						case '4':
							if (board[1][0] == '4') { board[1][0]  = 'X'; }
							else { x--; }
						break;
						case '5':
							if (board[1][1] == '5') { board[1][1]  = 'X'; }
							else { x--; }
						break;
						case '6':
							if (board[1][2] == '6') { board[1][2]  = 'X'; }
							else { x--; }
						break;
						case '7': 
							if (board[2][0] == '7') { board[2][0]  = 'X'; }
							else { x--; }
						break;
						case '8':
							if (board[2][1] == '8') { board[2][1]  = 'X'; }
							else { x--; }
						break;
						case '9':
							if (board[2][2] == '9') { board[2][2]  = 'X'; }
							else { x--; }
						break;
						case '\033': // If user enters 'esc' key the program exits
							return 0;
						break;
						default:
							x--;
						break;
					}
				}
				else {
					compMoveEasy();
				}
			}
		}
		
		if (difficultyTTT == '2') {
			system("cls");
			bannerTTT();
			
			printf("Do you want to start first?\n");
			printf("1 ==> YES\n");
			printf("2 ==> NO\n");
			printf("Choice: ");
			
			do {
				playerStartTTT = getch();
				if (playerStartTTT == '1') {
					x = 0; tie = 0; //tie variable is equal to the INITIAL amount of x, becuase x will increment.
					break;
				}
				if (playerStartTTT == '2') {
					x = 1; tie = 1;	//tie variable is equal to the INITIAL amount of x, becuase x will increment.
					break;
				}
			} while (playerStartTTT != '1' || playerStartTTT != '2');
			
			for (; x <= 10; x++) {
				if (checkWin() == 1) { //checks for a win at the very start
					winsTTT++; 
					statsTTT(winsTTT);
					system("cls");
					displayBoard();
					printf("\nYou Won!\a\tTotal Tic-Tac-Toe Wins: %i\n", winsTTT);
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\n");
					printf("3 ==> Reset Stats\n");
					printf("Enter choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
						if (playAgainTTT == '3') {
							system("cls");
							bannerTTT();
							printf("Stats will be lost forever! Continue? (Y/N)");
							do {
								resetStatsTTT = getch();
								if (resetStatsTTT == 'Y' || resetStatsTTT == 'y') {
									winsTTT = 0;
									statsTTT(winsTTT);
									resetBoard();
									system("cls");
									printf("\nStats have been succesfully reset!");
									sleep(1);
									system("cls");
									sendToMain ();
								}
								if (resetStatsTTT == 'N' || resetStatsTTT == 'n') {
									exit(1);
								}
							} while (resetStatsTTT != 'Y' || resetStatsTTT != 'y' || resetStatsTTT != 'N' || resetStatsTTT != 'n');
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2' || playAgainTTT != '3');
				}
				if (checkWin() == 2) { //checks for a win at the very start
					system("cls");
					displayBoard();
					printf("\nComputer Won!\a\tTotal Tic-Tac-Toe Wins: %i\n", winsTTT);
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\n");
					printf("3 ==> Reset Stats\n");
					printf("Enter choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
						if (playAgainTTT == '3') {
							system("cls");
							bannerTTT();
							printf("Stats will be lost forever! Continue? (Y/N)");
							do {
								resetStatsTTT = getch();
								if (resetStatsTTT == 'Y' || resetStatsTTT == 'y') {
									winsTTT = 0;
									statsTTT(winsTTT);
									resetBoard();
									system("cls");
									printf("\nStats have been succesfully reset!");
									sleep(1);
									system("cls");
									sendToMain ();
								}
								if (resetStatsTTT == 'N' || resetStatsTTT == 'n') {
									exit(1);
								}
							} while (resetStatsTTT != 'Y' || resetStatsTTT != 'y' || resetStatsTTT != 'N' || resetStatsTTT != 'n');
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2' || playAgainTTT != '3');
				}
				
				if (x == 9 && tie == 0 || x == 10 && tie == 1) {
					system("cls");
					displayBoard();
					printf("It's a Tie!\n");
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\nEnter Choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2');
				}
				system("cls");
				displayBoard();
				
				if (x%2 == 0) {
					
					printf("\nbro, enter position (1-9): ");
					positionTTT = getch();
				
					switch (positionTTT) {
						case '1':
							if (board[0][0] == '1') { board[0][0]  = 'X'; }
							else { x--; }
						break;
						case '2':
							if (board[0][1] == '2') { board[0][1]  = 'X'; }
							else { x--; }
						break;
						case '3':
							if (board[0][2] == '3') { board[0][2]  = 'X'; }
							else { x--; }
						break;
						case '4':
							if (board[1][0] == '4') { board[1][0]  = 'X'; }
							else { x--; }
						break;
						case '5':
							if (board[1][1] == '5') { board[1][1]  = 'X'; }
							else { x--; }
						break;
						case '6':
							if (board[1][2] == '6') { board[1][2]  = 'X'; }
							else { x--; }
						break;
						case '7':
							if (board[2][0] == '7') { board[2][0]  = 'X'; }
							else { x--; }
						break;
						case '8':
							if (board[2][1] == '8') { board[2][1]  = 'X'; }
							else { x--; }
						break;
						case '9':
							if (board[2][2] == '9') { board[2][2]  = 'X'; }
							else { x--; }
						break;
						case '\033': // If user enters 'esc' key the program exits
							return 0;
						break;
						default:
							x--;
						break;
					}
				}
				else {
					compMoveMed(x);
				}
			}
		}
		
		if (difficultyTTT == '3') {
			system("cls");
			bannerTTT();
			
			printf("Do you want to start first?\n");
			printf("1 ==> YES\n");
			printf("2 ==> NO\n");
			printf("Choice: ");
			
			do {
				playerStartTTT = getch();
				if (playerStartTTT == '1') {
					x = 0; tie = 0; //tie variable is equal to the INITIAL amount of x, becuase x will increment.
					break;
				}
				if (playerStartTTT == '2') {
					x = 1; tie = 1;	//tie variable is equal to the INITIAL amount of x, becuase x will increment.
					break;
				}
			} while (playerStartTTT != '1' || playerStartTTT != '2');
			
			for (; x <= 10; x++) {
				if (checkWin() == 1) { //checks for a win at the very start
					winsTTT++; 
					statsTTT(winsTTT);
					system("cls");
					displayBoard();
					printf("\nYou Won!\a\tTotal Tic-Tac-Toe Wins: %i\n", winsTTT);
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\n");
					printf("3 ==> Reset Stats\n");
					printf("Enter choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
						if (playAgainTTT == '3') {
							system("cls");
							bannerTTT();
							printf("Stats will be lost forever! Continue? (Y/N)");
							do {
								resetStatsTTT = getch();
								if (resetStatsTTT == 'Y' || resetStatsTTT == 'y') {
									winsTTT = 0;
									statsTTT(winsTTT);
									resetBoard();
									system("cls");
									printf("\nStats have been succesfully reset!");
									sleep(1);
									system("cls");
									sendToMain ();
								}
								if (resetStatsTTT == 'N' || resetStatsTTT == 'n') {
									exit(1);
								}
							} while (resetStatsTTT != 'Y' || resetStatsTTT != 'y' || resetStatsTTT != 'N' || resetStatsTTT != 'n');
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2' || playAgainTTT != '3');
				}
				if (checkWin() == 2) { //checks for a win at the very start
					system("cls");
					displayBoard();
					printf("\nComputer Won!\a\tTotal Tic-Tac-Toe Wins: %i\n", winsTTT);
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\n");
					printf("3 ==> Reset Stats\n");
					printf("Enter choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
						if (playAgainTTT == '3') {
							system("cls");
							bannerTTT();
							printf("Stats will be lost forever! Continue? (Y/N)");
							do {
								resetStatsTTT = getch();
								if (resetStatsTTT == 'Y' || resetStatsTTT == 'y') {
									winsTTT = 0;
									statsTTT(winsTTT);
									resetBoard();
									system("cls");
									printf("\nStats have been succesfully reset!");
									sleep(1);
									system("cls");
									sendToMain ();
								}
								if (resetStatsTTT == 'N' || resetStatsTTT == 'n') {
									exit(1);
								}
							} while (resetStatsTTT != 'Y' || resetStatsTTT != 'y' || resetStatsTTT != 'N' || resetStatsTTT != 'n');
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2' || playAgainTTT != '3');
				}
				
				if (x == 9 && tie == 0 || x == 10 && tie == 1) {
					system("cls");
					displayBoard();
					printf("It's a Tie!\n");
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\nEnter Choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2');
				}
				system("cls");
				displayBoard();
				
				if (x%2 == 0) {
					
					printf("\nbro, enter position (1-9): ");
					positionTTT = getch();
				
					switch (positionTTT) {
						case '1':
							if (board[0][0] == '1') { board[0][0]  = 'X'; }
							else { x--; }
						break;
						case '2':
							if (board[0][1] == '2') { board[0][1]  = 'X'; }
							else { x--; }
						break;
						case '3':
							if (board[0][2] == '3') { board[0][2]  = 'X'; }
							else { x--; }
						break;
						case '4':
							if (board[1][0] == '4') { board[1][0]  = 'X'; }
							else { x--; }
						break;
						case '5':
							if (board[1][1] == '5') { board[1][1]  = 'X'; }
							else { x--; }
						break;
						case '6':
							if (board[1][2] == '6') { board[1][2]  = 'X'; }
							else { x--; }
						break;
						case '7':
							if (board[2][0] == '7') { board[2][0]  = 'X'; }
							else { x--; }
						break;
						case '8':
							if (board[2][1] == '8') { board[2][1]  = 'X'; }
							else { x--; }
						break;
						case '9':
							if (board[2][2] == '9') { board[2][2]  = 'X'; }
							else { x--; }
						break;
						case '\033': // If user enters 'esc' key the program exits
							return 0;
						break;
						default:
							x--;
						break;
					}
				}
				else {
					compMoveHard(x);
				}
			}
		}
		
		if (difficultyTTT == '4') {
			system("cls");
			bannerTTT();
			
			printf("Do you want to start first?\n");
			printf("1 ==> YES\n");
			printf("2 ==> NO\n");
			printf("Choice: ");
			
			do {
				playerStartTTT = getch();
				if (playerStartTTT == '1') {
					x = 0; tie = 0; //tie variable is equal to the INITIAL amount of x, becuase x will increment.
					break;
				}
				if (playerStartTTT == '2') {
					x = 1; tie = 1;	//tie variable is equal to the INITIAL amount of x, becuase x will increment.
					break;
				}
			} while (playerStartTTT != '1' || playerStartTTT != '2');
			
			for (; x <= 10; x++) {
				if (checkWin() == 1) { //checks for a win at the very start
					winsTTT++; 
					statsTTT(winsTTT);
					system("cls");
					displayBoard();
					printf("\nYou Won!\a\tTotal Tic-Tac-Toe Wins: %i\n", winsTTT);
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\n");
					printf("3 ==> Reset Stats\n");
					printf("Enter choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
						if (playAgainTTT == '3') {
							system("cls");
							bannerTTT();
							printf("Stats will be lost forever! Continue? (Y/N)");
							do {
								resetStatsTTT = getch();
								if (resetStatsTTT == 'Y' || resetStatsTTT == 'y') {
									winsTTT = 0;
									statsTTT(winsTTT);
									resetBoard();
									system("cls");
									printf("\nStats have been succesfully reset!");
									sleep(1);
									system("cls");
									sendToMain ();
								}
								if (resetStatsTTT == 'N' || resetStatsTTT == 'n') {
									exit(1);
								}
							} while (resetStatsTTT != 'Y' || resetStatsTTT != 'y' || resetStatsTTT != 'N' || resetStatsTTT != 'n');
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2' || playAgainTTT != '3');
				}
				if (checkWin() == 2) { //checks for a win at the very start
					system("cls");
					displayBoard();
					printf("\nComputer Won!\a\tTotal Tic-Tac-Toe Wins: %i\n", winsTTT);
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\n");
					printf("3 ==> Reset Stats\n");
					printf("Enter choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
						if (playAgainTTT == '3') {
							system("cls");
							bannerTTT();
							printf("Stats will be lost forever! Continue? (Y/N)");
							do {
								resetStatsTTT = getch();
								if (resetStatsTTT == 'Y' || resetStatsTTT == 'y') {
									winsTTT = 0;
									statsTTT(winsTTT);
									resetBoard();
									system("cls");
									printf("\nStats have been succesfully reset!");
									sleep(1);
									system("cls");
									sendToMain ();
								}
								if (resetStatsTTT == 'N' || resetStatsTTT == 'n') {
									exit(1);
								}
							} while (resetStatsTTT != 'Y' || resetStatsTTT != 'y' || resetStatsTTT != 'N' || resetStatsTTT != 'n');
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2' || playAgainTTT != '3');
				}
				
				if (x == 9 && tie == 0 || x == 10 && tie == 1) {
					system("cls");
					displayBoard();
					printf("It's a Tie!\n");
					printf("------------------------------");
					
					printf("\nDo you want to play again?\n");
					printf("1 ==> YES\n");
					printf("2 ==> NO\nEnter Choice: ");
					
					do {
						playAgainTTT = getch();
						if (playAgainTTT == '1') {
							system("cls");
							resetBoard();
							x = 0;
							mainTTT();
						}
						if (playAgainTTT == '2') {
							exit(1);
						}
					} while (playAgainTTT != '1' || playAgainTTT != '2');
				}
				system("cls");
				displayBoard();
				
				if (x%2 == 0) {
					printf("%i", x);
					printf("\nbro, enter position (1-9): "); 
					positionTTT = getch();
				
					switch (positionTTT) {
						case '1':
							if (board[0][0] == '1') { board[0][0]  = 'X'; }
							else { x--; }
						break;
						case '2':
							if (board[0][1] == '2') { board[0][1]  = 'X'; }
							else { x--; }
						break;
						case '3':
							if (board[0][2] == '3') { board[0][2]  = 'X'; }
							else { x--; }
						break;
						case '4':
							if (board[1][0] == '4') { board[1][0]  = 'X'; }
							else { x--; }
						break;
						case '5':
							if (board[1][1] == '5') { board[1][1]  = 'X'; }
							else { x--; }
						break;
						case '6':
							if (board[1][2] == '6') { board[1][2]  = 'X'; }
							else { x--; }
						break;
						case '7':
							if (board[2][0] == '7') { board[2][0]  = 'X'; }
							else { x--; }
						break;
						case '8':
							if (board[2][1] == '8') { board[2][1]  = 'X'; }
							else { x--; }
						break;
						case '9':
							if (board[2][2] == '9') { board[2][2]  = 'X'; }
							else { x--; }
						break;
						case '\033': // If user enters 'esc' key the program exits
							return 0;
						break;
						default:
							x--;
						break;
					}
				}
				else {
					compMoveLegendary();
				}
			}
		}
	} while (difficultyTTT != '1' || difficultyTTT != '2' || difficultyTTT != '3' || difficultyTTT != '4');
	return;
}

int multiplayer () {
	int x;	//main loop that displays the board counter variable
	int position;	//board position
	int playAgain;	//if users want to play again
	int playerStart; //users choose who starts
	char playerTwoName[50];
	
	system("cls");
	bannerTTT();
	
	printf("Enter player 2's name: ");
	gets(playerTwoName);
	
	system("cls");
	
	bannerTTT();
	printf("Who starts first?\n");
	printf("name ==> 1\n" /*playerOneName*/);
	printf("%s ==> 2\n", playerTwoName);
	printf("Choice: ");
	
	do {
		playerStart = getch();
		if (playerStart == '1') {
			x = 0;
			break;
		}
		if (playerStart == '2') {
			x = 1;
			break;
		}
	} while (playerStart != '1' || playerStart != '2');
	
	for (; x <= 10; x++) {
		
		if (checkWin() == 1) { //checks for a win at the very start
			displayBoard();
			printf("\n%s Won!\a\t%i\n", playerTwoName, winsTTT);
			printf("------------------------------");
			
			printf("\nDo you want to play again?\n");
			printf("1 ==> YES\n");
			printf("2 ==> NO\nEnter Choice: ");
			
			do {
				playAgain = getch();
				if (playAgain == '1') {
					system("cls");
					resetBoard();
					x = 0;
					main();
				}
				if (playAgain == '2') {
					exit(1);
				}
			} while (playAgain != '1' || playAgain != '2');
		}
		if (x == 9 && playerStart == '1' || x == 10 && playerStart == '2') {
			displayBoard();
			printf("It's a Tie!");
			printf("------------------------------");
			
			printf("\nDo you want to play again?\n");
			printf("1 ==> YES\n");
			printf("2 ==> NO\nEnter Choice: ");
			
			do {
				playAgain = getch();
				if (playAgain == '1') {
					system("cls");
					resetBoard();
					x = 0;
					main();
				}
				if (playAgain == '2') {
					exit(1);
				}
			} while (playAgain != '1' || playAgain != '2');
		}
		
		system("cls");	//brings the two players two the Tic Tac Toe board.
		displayBoard();
		printf("%i", x);
		if (x%2 == 0) { printf("\nSelim enter position (1-9): "/*, playerTwoName*/); position = getch(); }
		else { printf("\n%s, enter position (1-9): ", playerTwoName); position = getch(); }
	
		switch (position) {
			case '1':
				if (board[0][0] == '1') { board[0][0] = (x%2 == 0)?'X':'O'; }
				else { x--; }
			break;
			case '2':
				if (board[0][1] == '2') { board[0][1] = (x%2 == 0)?'X':'O';	}
				else { x--; }
			break;
			case '3':
				if (board[0][2] == '3') { board[0][2] = (x%2 == 0)?'X':'O';	}
				else { x--; }
			break;
			case '4':
				if (board[1][0] == '4') { board[1][0] = (x%2 == 0)?'X':'O';	}
				else { x--; }
			break;
			case '5':
				if (board[1][1] == '5') { board[1][1] = (x%2 == 0)?'X':'O';	}
				else { x--; }
			break;
			case '6':
				if (board[1][2] == '6') { board[1][2] = (x%2 == 0)?'X':'O';	}
				else { x--; }
			break;
			case '7':
				if (board[2][0] == '7') { board[2][0] = (x%2 == 0)?'X':'O'; }
				else { x--; }
			break;
			case '8':
				if (board[2][1] == '8') { board[2][1] = (x%2 == 0)?'X':'O';	}
				else { x--; }
			break;
			case '9':
				if (board[2][2] == '9') { board[2][2] = (x%2 == 0)?'X':'O';	}
				else { x--; }
			break;
			case '\033': // If user enters 'esc' key the program exits
				return 0;
			break;
			default:
				x--;
			break;
		}
		system("cls");	//so the boards does not display a tenth time
	}
	return;
}

int checkWin () { 
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X' ||
		board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X' ||
		board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X' ||
		board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X' ||
		board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X' ||
		board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X' ||
		board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' ||
		board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') {
			return 1;
		}
		
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O' ||
		board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O' ||
	    board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O' ||
		board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O' ||
	    board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O' ||
	    board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O' ||
	    board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O' ||
		board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') {
			return 2;
		}
}

int displayBoard () {
	int x = 186;
	int y = 185;
	int z = 206;
	int a = 205;
	
	bannerTTT();
	printf("\t %c  %c  %c  %c  %c \n", board[0][0], x, board[0][1], x, board[0][2]);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", a, a, a, a, z, a, a, a, a, a, z, a, a, a, a);
    printf("\t %c  %c  %c  %c  %c \n", board[1][0], x, board[1][1], x, board[1][2]);
    printf("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", a, a, a, a, z, a, a, a, a, a, z, a, a, a, a);
	printf("\t %c  %c  %c  %c  %c \n", board[2][0], x, board[2][1], x, board[2][2]);
	return;
}

void bannerTTT() {
	printf("\t  -----------\n");
    printf("\t  Tic-Tac-Toe\n");
    printf("\t  -----------\n\n");
    return;
}

int playerMove (char _position, int _x) {
	while (_x%2 == 0) {
		printf("\nbro, enter position (1-9): ");
		_position = getch();
			
		switch (_position) {
			case '1':
				if (board[0][0] == '1') { board[0][0]  = 'X'; }
				else { _x--; }
			break;
			case '2':
				if (board[0][1] == '2') { board[0][1]  = 'X'; }
				else { _x--; }
			break;
			case '3':
				if (board[0][2] == '3') { board[0][2]  = 'X'; }
				else { _x--; }
			break;
			case '4':
				if (board[1][0] == '4') { board[1][0]  = 'X'; }
				else { _x--; }
			break;
			case '5':
				if (board[1][1] == '5') { board[1][1]  = 'X'; }
				else { _x--; }
			break;
			case '6':
				if (board[1][2] == '6') { board[1][2]  = 'X'; }
				else { _x--; }
			break;
			case '7':
				if (board[2][0] == '7') { board[2][0]  = 'X'; }
				else { _x--; }
			break;
			case '8':
				if (board[2][1] == '8') { board[2][1]  = 'X'; }
				else { _x--; }
			break;
			case '9':
				if (board[2][2] == '9') { board[2][2]  = 'X'; }
				else { _x--; }
			break;
			case '\033': // If user enters 'esc' key the program exits
				return 0;
			break;
			default:
				_x--;
			break;
			}
		}
	return;
}

int compMoveEasy () {
	int j, z;
	do {
		j = (rand()%3);
		z = (rand()%3);
	} while (board[j][z] == 'X' || board[j][z] == 'O');	//so the random taken position keeps generating one until the position is not taken
	
	board[j][z] = 'O';

	return;
}

int compMoveMed (int a) {
	//top row
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == '3') {
		if (board[0][2] == '3') { board[0][2] = 'O'; }
		else { a--; }
	}
	else if (board[0][1] == 'X' && board[0][2] == 'X' && board[0][0] == '1') {
		if (board[0][0] == '1') { board[0][0] = 'O'; }
		else { a--; }
	}
	else if (board[0][0] == 'X' && board[0][2] == 'X' && board[0][1] == '2') {
		if (board[0][1] == '2') { board[0][1] = 'O'; }
		else { a--; }
	}

	//middle row
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == '6') {
		if (board[1][2] == '6') { board[1][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'X' && board[1][2] == 'X' && board[1][0] == '4') {
		if (board[1][0] == '4') { board[1][0] = 'O'; }
		else { a--; }
	}
	else if (board[1][0] == 'X' && board[1][2] == 'X' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}

	//bottom row
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == '9') {
		if (board[2][2] == '9') { board[2][2] = 'O'; }
		else { a--; }
	}
	else if (board[2][1] == 'X' && board[2][2] == 'X' && board[2][0] == '7') {
		if (board[2][0] == '7') { board[2][0] = 'O'; }
		else { a--; }
	}
	else if (board[2][0] == 'X' && board[2][2] == 'X' && board[2][1] == '8') {
		if (board[2][1] == '8') { board[2][1] = 'O'; }
		else { a--; }
	}

	//left column
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == '7') {
		if (board[2][0] == '7') { board[2][0] = 'O'; }
		else { a--; }
	}
	else if (board[1][0] == 'X' && board[2][0] == 'X' && board[0][0] == '1') {
		if (board[0][0] == '1') { board[0][0] = 'O'; }
		else { a--; }
	}
	else if (board[0][0] == 'X' && board[2][0] == 'X' && board[1][0] == '4') {
		if (board[1][0] == '4') { board[1][0] = 'O'; }
		else { a--; }
	}

	//middle column
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == '8') {
		if (board[2][1] == '8') { board[2][1] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'X' && board[2][1] == 'X' && board[0][1] == '2') {
		if (board[0][1] == '2') { board[0][1] = 'O'; }
		else { a--; }
	}
	else if (board[0][1] == 'X' && board[2][1] == 'X' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}

	//right column
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == '9') {
		if (board[2][2] == '9') { board[2][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][2] == 'X' && board[2][2] == 'X' && board[0][2] == '3') {
		if (board[0][2] == '3') { board[0][2] = 'O'; }
		else { a--; }
	}
	else if (board[0][2] == 'X' && board[2][2] == 'X' && board[1][2] == '6') {
		if (board[1][2] == '6') { board[1][2] = 'O'; }
		else { a--; }
	}

	//Top-Down diagonal
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == '9') {
		if (board[2][2] == '9') { board[2][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'X' && board[2][2] == 'X' && board[0][0] == '1') {
		if (board[0][0] == '1') { board[0][0] = 'O'; }
		else { a--; }
	}
	else if (board[0][0] == 'X' && board[2][2] == 'X' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}

	//Down-Up diagonal
	else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == '3') {
		if (board[0][2] == '3') { board[0][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'X' && board[0][2] == 'X' && board[2][0] == '7') {
		if (board[2][0] == '7') { board[2][0] = 'O'; }
		else { a--; }
	}
	else if (board[2][0] == 'X' && board[0][2] == 'X' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}
	else {
		TAKEN_POSITION:	  ;
		int j = (rand()%3);
		int z = (rand()%3);
		if (board[j][z] == 'X' || board[j][z] == 'O') {
			goto TAKEN_POSITION;
		}
		else {
			board[j][z] = 'O';
		}
	}
	return;
}

int compMoveHard (int a) {
	if (board[1][1] == 'X' && board[2][1] == 'X' && board[0][1] == '2') {
		if (board[0][1] == '2') { board[0][1] = 'O'; }
		else { a--; }
	}
	//top row
	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == '3') {
		if (board[0][2] == '3') { board[0][2] = 'O'; }
		else { a--; }
	}
	else if (board[0][1] == 'O' && board[0][2] == 'O' && board[0][0] == '1') {
		if (board[0][0] == '1') { board[0][0] = 'O'; }
		else { a--; }
	}
	else if (board[0][0] == 'O' && board[0][2] == 'O' && board[0][1] == '2') {
		if (board[0][1] == '2') { board[0][1] = 'O'; }
		else { a--; }
	}

	//middle row
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == '6') {
		if (board[1][2] == '6') { board[1][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'O' && board[1][2] == 'O' && board[1][0] == '4') {
		if (board[1][0] == '4') { board[1][0] = 'O'; }
		else { a--; }
	}
	else if (board[1][0] == 'O' && board[1][2] == 'O' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}

	//bottom row
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == '9') {
		if (board[2][2] == '9') { board[2][2] = 'O'; }
		else { a--; }
	}
	else if (board[2][1] == 'O' && board[2][2] == 'O' && board[2][0] == '7') {
		if (board[2][0] == '7') { board[2][0] = 'O'; }
		else { a--; }
	}
	else if (board[2][0] == 'O' && board[2][2] == 'O' && board[2][1] == '8') {
		if (board[2][1] == '8') { board[2][1] = 'O'; }
		else { a--; }
	}

	//left column
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == '7') {
		if (board[2][0] == '7') { board[2][0] = 'O'; }
		else { a--; }
	}
	else if (board[1][0] == 'O' && board[2][0] == 'O' && board[0][0] == '1') {
		if (board[0][0] == '1') { board[0][0] = 'O'; }
		else { a--; }
	}
	else if (board[0][0] == 'O' && board[2][0] == 'O' && board[1][0] == '4') {
		if (board[1][0] == '4') { board[1][0] = 'O'; }
		else { a--; }
	}

	//middle column
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == '8') {
		if (board[2][1] == '8') { board[2][1] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'O' && board[2][1] == 'O' && board[0][1] == '2') {
		if (board[0][1] == '2') { board[0][1] = 'O'; }
		else { a--; }
	}
	else if (board[0][1] == 'O' && board[2][1] == 'O' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}

	//right column
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == '9') {
		if (board[2][2] == '9') { board[2][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][2] == 'O' && board[2][2] == 'O' && board[0][2] == '3') {
		if (board[0][2] == '3') { board[0][2] = 'O'; }
		else { a--; }
	}
	else if (board[0][2] == 'O' && board[2][2] == 'O' && board[1][2] == '6') {
		if (board[1][2] == '6') { board[1][2] = 'O'; }
		else { a--; }
	}

	//Top-Down diagonal
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == '9') {
		if (board[2][2] == '9') { board[2][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'O' && board[2][2] == 'O' && board[0][0] == '1') {
		if (board[0][0] == '1') { board[0][0] = 'O'; }
		else { a--; }
	}
	else if (board[0][0] == 'O' && board[2][2] == 'O' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}

	//Down-Up diagonal
	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == '3') {
		if (board[0][2] == '3') { board[0][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'O' && board[0][2] == 'O' && board[2][0] == '7') {
		if (board[2][0] == '7') { board[2][0] = 'O'; }
		else { a--; }
	}
	else if (board[2][0] == 'O' && board[0][2] == 'O' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}


	//top row
	else if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == '3') {
		if (board[0][2] == '3') { board[0][2] = 'O'; }
		else { a--; }
	}
	else if (board[0][1] == 'X' && board[0][2] == 'X' && board[0][0] == '1') {
		if (board[0][0] == '1') { board[0][0] = 'O'; }
		else { a--; }
	}
	else if (board[0][0] == 'X' && board[0][2] == 'X' && board[0][1] == '2') {
		if (board[0][1] == '2') { board[0][1] = 'O'; }
		else { a--; }
	}

	//middle row
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == '6') {
		if (board[1][2] == '6') { board[1][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'X' && board[1][2] == 'X' && board[1][0] == '4') {
		if (board[1][0] == '4') { board[1][0] = 'O'; }
		else { a--; }
	}
	else if (board[1][0] == 'X' && board[1][2] == 'X' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}

	//bottom row
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == '9') {
		if (board[2][2] == '9') { board[2][2] = 'O'; }
		else { a--; }
	}
	else if (board[2][1] == 'X' && board[2][2] == 'X' && board[2][0] == '7') {
		if (board[2][0] == '7') { board[2][0] = 'O'; }
		else { a--; }
	}
	else if (board[2][0] == 'X' && board[2][2] == 'X' && board[2][1] == '8') {
		if (board[2][1] == '8') { board[2][1] = 'O'; }
		else { a--; }
	}

	//left column
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == '7') {
		if (board[2][0] == '7') { board[2][0] = 'O'; }
		else { a--; }
	}
	else if (board[1][0] == 'X' && board[2][0] == 'X' && board[0][0] == '1') {
		if (board[0][0] == '1') { board[0][0] = 'O'; }
		else { a--; }
	}
	else if (board[0][0] == 'X' && board[2][0] == 'X' && board[1][0] == '4') {
		if (board[1][0] == '4') { board[1][0] = 'O'; }
		else { a--; }
	}

	//middle column
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == '8') {
		if (board[2][1] == '8') { board[2][1] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'X' && board[2][1] == 'X' && board[0][1] == '2') {
		if (board[0][1] == '2') { board[0][1] = 'O'; }
		else { a--; }
	}
	else if (board[0][1] == 'X' && board[2][1] == 'X' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}

	//right column
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == '9') {
		if (board[2][2] == '9') { board[2][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][2] == 'X' && board[2][2] == 'X' && board[0][2] == '3') {
		if (board[0][2] == '3') { board[0][2] = 'O'; }
		else { a--; }
	}
	else if (board[0][2] == 'X' && board[2][2] == 'X' && board[1][2] == '6') {
		if (board[1][2] == '6') { board[1][2] = 'O'; }
		else { a--; }
	}

	//Top-Down diagonal
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == '9') {
		if (board[2][2] == '9') { board[2][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'X' && board[2][2] == 'X' && board[0][0] == '1') {
		if (board[0][0] == '1') { board[0][0] = 'O'; }
		else { a--; }
	}
	else if (board[0][0] == 'X' && board[2][2] == 'X' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}

	//Down-Up diagonal
	else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == '3') {
		if (board[0][2] == '3') { board[0][2] = 'O'; }
		else { a--; }
	}
	else if (board[1][1] == 'X' && board[0][2] == 'X' && board[2][0] == '7') {
		if (board[2][0] == '7') { board[2][0] = 'O'; }
		else { a--; }
	}
	else if (board[2][0] == 'X' && board[0][2] == 'X' && board[1][1] == '5') {
		if (board[1][1] == '5') { board[1][1] = 'O'; }
		else { a--; }
	}
	
	else if (board[1][1] == '5') {
		board[1][1] = 'O';
	}
	else if (board[0][2] == '3') {
		board[0][2] = 'O';
	}
	else if (board[0][0] == '1') {
		board[0][0] = 'O';
	}
	else if (board[2][0] == '7') {
		board[2][0] = 'O';
	}
	else if (board[2][2] == '9') {
		board[2][2] = 'O';
	}

	else {
		TAKEN_POSITION:	  ;
		int j = (rand()%3);
		int z = (rand()%3);

		if (board[j][z] == 'X' || board[j][z] == 'O') {
			goto TAKEN_POSITION;
		}
		else {
			board[j][z] = 'O';
		}
	}
	return;
}

int compMoveLegendary (int a) {
	if (board[1][1] == 'X' && board[2][1] == 'X' && board[0][1] == '2') {
		if (board[0][1] == '2') { board[0][1] = 'O'; }
		else { a--; }
	}
	//Special situations
	else if (board[0][0] == 'X' && board[2][1] == 'X' && board[1][0] == '4') {
        if (board[1][0] == '4') { board[1][0] = 'O'; }
		//else { a--; }
	}
	else if (board[0][2] == 'X' && board[2][1] == 'X' && board[1][2] == '6') {
        if (board[1][2] == '6') { board[1][2] = 'O'; }
		//else { a--; }
	}
	else if (board[0][0] == 'X' && board[2][2] == 'X' && board[1][0] == '4') {
        if (board[1][0] == '4') { board[1][0] = 'O'; }
		//else { a--; }
	}
	else if (board[0][2] == 'X' && board[2][0] == 'X' && board[1][2] == '6') {
        if (board[1][2] == '6') { board[1][2] = 'O'; }
		//else { a--; }
	}
	else if (board[1][1] == 'X' && board[2][1] == 'X' && board[0][0] == '1') {
        if (board[0][0] == '1') { board[0][0] = 'O'; }
		//else { a--; }
	}
	
	else {
        compMoveHard(a);
	}
    return;
}

int resetBoard() {
	board[0][0] = '1';	board[0][1] = '2';	board[0][2] = '3';
	board[1][0] = '4';	board[1][1] = '5';	board[1][2] = '6';
	board[2][0] = '7';	board[2][1] = '8';	board[2][2] = '9';
	return;
}

int statsTTT (int playerWins[5]) {
	FILE *fpointer;
	fpointer = fopen("tictactoe_stats.txt","w+");
	
	if(fpointer == NULL) {
		printf("Could not locate file! ");
		system("pause");
		return 0;
	}
	
	fprintf(fpointer, "%i", playerWins);
	
	fclose(fpointer);
	return;
}

int sendToMainTTT () {
	mainTTT();
	return;
}
