#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

int mainHM() {
    srand(time(NULL));
	char word[50][50];
	char hint[50][50];
	char copyOfHint[50];
	char originalWord[50];
	char hiddenWord[50];
	char playAgainHM;
	char letterHM;
	char goBackHM;
	char menuChoice;
	int x, y, j, z;
	int winsHM;
	int resetStatsHM;
	int lengthHM;
	int removeNewLineChar;
	int makeSpaceChar;
	int randomHM;
	randomHM = rand()%43;
	
	//<stats>
		FILE *fp;
		fp = fopen("hangman_stats.txt", "r");
		if(fp == NULL) {
			printf("Could not locate file! ");
			system("pause");
			return 0;
		}
		
		while (!feof(fp)) {
			fscanf(fp, "%i", &winsHM);
		}
		fclose(fp);

		FILE *fpointer;
		fpointer = fopen("wordlist.txt", "r");
		if(fpointer == NULL) {
			printf("Could not locate file! ");
			system("pause");
			return 0;
		}

		while (!feof(fpointer)) {
			for (j = 0; j < 44; j++) {
				fscanf(fpointer, "%s %s", word[j], hint[j]);
			}
			strcpy(hiddenWord, word[randomHM]);
		}

		strcpy(originalWord, word[randomHM]);

	for (removeNewLineChar = 0; removeNewLineChar <= strlen(hiddenWord); removeNewLineChar++) {
        if (hiddenWord[removeNewLineChar] == '\n') {
            hiddenWord[removeNewLineChar] = '\0';
        }
	}
	
	for (removeNewLineChar = 0; removeNewLineChar <= strlen(originalWord); removeNewLineChar++) {
		if (originalWord[removeNewLineChar] == '\n') {
			originalWord[removeNewLineChar] = '\0';
		}
	}
	
	strcpy(copyOfHint, hint[randomHM]);
	
	for (removeNewLineChar = 0; removeNewLineChar <= strlen(copyOfHint); removeNewLineChar++) {
		if (copyOfHint[removeNewLineChar] == '*') {
			copyOfHint[removeNewLineChar] = ' ';
		}
	}
	fclose(fpointer);
	
	lengthHM = strlen(*word);
	
	for (x = 0; x < strlen(hiddenWord); x++) {
		hiddenWord[x] = '-';
	}
	
	bannerHM();
	printf("1 ==> Play\n");
	printf("2 ==> View Stats\n");
	printf("3 ==> Change Game\n");
	printf("4 ==> Quit\nEnter option: ");
	
	do {
		menuChoice = getch();
		if (menuChoice == '1') {
			break;
		}
	
		if (menuChoice == '2') {
			system("cls");
			bannerHM();
			printf("Total Hangman Wins: %i\n\n", winsHM);
			printf("Go back? (Y): ");
			
			do {
				goBackHM = getch();
				if (goBackHM == 'Y' || goBackHM == 'y') {
					system("cls");
					sendToMain();
					break;
				}
			} while (goBackHM != 'Y' || goBackHM != 'y');
		}
		if (menuChoice == '3') {
			gameMenu();
		}
		if (menuChoice == '4') {
			exit(1);
		}
	} while (menuChoice != '1' || menuChoice != '2' || menuChoice != '3');
	
    //printf("%s", hiddenWord);
    //return 0;
	y = 7; //sets the amount of tries
	j = 0;
	while (y != 0 || y == 0) {
		
		if (j > 0 && j < 3) {
			y--;
			y = y + 2;
			j = 0;
		}
		
		if (j > 2) {
			y = y + 4;
			j = 0;
		}
					
		if (strcmp(hiddenWord, originalWord) == 0) {
            displayHangman(y);
			winsHM++;
			statsHM(winsHM);
        	printf("You Won! The word was %s!\t\nTotal Hangman Wins: %i\n", originalWord, winsHM);
				printf("------------------------------");
				
				printf("\nDo you want to play again?\n");
				printf("1 ==> YES\n");
				printf("2 ==> NO\n");
				printf("3 ==> Reset Stats\nEnter Choice:");
				do {
					playAgainHM = getch();

					if (playAgainHM == '1') {
						//system("cls");
						//sendToMain ();
					}
					
					if (playAgainHM == '2') {
						//system("cls");
						//sendToMain (); 
						exit(1);
					}
					
					if (playAgainHM == '3') {
						system("cls");
						bannerHM();
						printf("Stats will be lost forever! Continue? (Y/N)");
						do {
							resetStatsHM = getch();
							if (resetStatsHM == 'Y' || resetStatsHM == 'y') {
								system("cls");
								winsHM = 0;
								statsHM(winsHM);
								printf("\nStats have been succesfully reset!");
								sleep(1);
								system("cls");
								sendToMain ();
							}
							if (resetStatsHM == 'N' || resetStatsHM == 'n') {
								exit(1);
							}
						} while (resetStatsHM != 'Y' || resetStatsHM != 'y' || resetStatsHM != 'N' || resetStatsHM != 'n');
					}
				} while (playAgainHM != '1' || playAgainHM != '2' || playAgainHM != '3');
		}
		
		if (y != 0) {
			displayHangman(y);
		}
		
		if (y == 0) {
			system("cls");
			bannerHM();
			displayHangman(y);
			printf("Out of Tries! The word was: %s!\n", originalWord);
			printf("------------------------------");
				
				printf("\nDo you want to play again?\n");
				printf("1 ==> YES\n");
				printf("2 ==> NO\n");
				printf("3 ==> Reset Stats\nEnter Choice:");
				do {
					playAgainHM = getch();
					int resetStats;
					if (playAgainHM == '1') {
						system("cls");
						sendToMain ();
					}
					
					if (playAgainHM == '2') {
						return 0;
					}
					
					if (playAgainHM == '3') {
						system("cls");
						bannerHM();
						printf("Stats will be lost forever! Continue? (Y/N)");
						do {
							resetStats = getch();
							if (resetStats == 'Y' || resetStats == 'y') {
								system("cls");
								winsHM = 0;
								statsHM(winsHM);
								printf("\nStats have been succesfully reset!");
								sleep(1);
								system("cls");
								sendToMain ();
							}
						} while (resetStats != 'Y' || resetStats != 'y');
					}
				} while (playAgainHM != '1' || playAgainHM != '2' || playAgainHM != '3');
		}
		printf("%s\tTries left: %i", hiddenWord, y);
		printf("\nHint: %s\n\nEnter letter ==> ", copyOfHint);
		letterHM = getch();
		system("cls");
		
        for (x = 0; x <= lengthHM; x++) {
            if (letterHM == originalWord[x]) {
                hiddenWord[x] = letterHM;
                
                for (z = 0; z <= lengthHM; z++) {
                	if (originalWord[x] == originalWord[z] && x != z) {
						y--;
						j++;
					}
				}
                y++;
            }
            else {
            	continue;
			}
        }
        y--;
	}
    return 0;
}

int displayHangman (int a) {
	int x = 186;
	int y = 201;
	int z = 205;
	int e = 187;
	int h = 188;
	int g = 209;
	int f = 179;
	int o = 234;
	int b = 215;
	int i = 196;
	int r = 204;
	int l = 185;
	int q = 200;
	int w = 188;
	
	int doneL = 198;
	int doneR = 208;
	int doneS = 196;
	
	int light = 176;
	int medium = 177;
	int dark = 178;
	
	if (a == 7) {
			system("cls");
			bannerHM ();
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, e);
			printf("   %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", x, y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, g, z, z, h);
			printf("   %c %c	  	    %c		    \n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, f);
			printf("   %c %c		     			\n", x, x, o);
			printf("   %c %c		      			\n", x, x, i, b, i);
			printf("   %c%c%c	       	    		\n", r, z, l, x);
			printf("  %c%c %c%c	  	     	   	    \n", y, w, q, e);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", doneS, doneS, doneR, doneS, doneS, doneS, doneR, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS);
		}
		if (a == 6) {
			system("cls");
			bannerHM ();
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, e);
			printf("   %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", x, y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, g, z, z, h);
			printf("   %c %c	  	    %c		    \n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, o);
			printf("   %c %c		      			\n", x, x, i, b, i);
			printf("   %c%c%c	       	    		\n", r, z, l, x);
			printf("  %c%c %c%c	  	     	   	    \n", y, w, q, e);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", doneS, doneS, doneR, doneS, doneS, doneS, doneR, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS);
		}
		if (a == 5) {
			system("cls");
			bannerHM ();
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, e);
			printf("   %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", x, y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, g, z, z, h);
			printf("   %c %c	  	    %c		    \n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, o);
			printf("   %c %c		     %c			\n", x, x, i, b, i);
			printf("   %c%c%c	       	    		\n", r, z, l, x);
			printf("  %c%c %c%c	  	     	   	    \n", y, w, q, e);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", doneS, doneS, doneR, doneS, doneS, doneS, doneR, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS);
		}
		if (a == 4) {
			system("cls");
			bannerHM ();
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, e);
			printf("   %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", x, y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, g, z, z, h);
			printf("   %c %c	  	    %c		    \n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, o);
			printf("   %c %c		    %c%c			\n", x, x, b, i);
			printf("   %c%c%c	       	    		\n", r, z, l, x);
			printf("  %c%c %c%c	  	       	    \n", y, w, q, e);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", doneS, doneS, doneR, doneS, doneS, doneS, doneR, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS);
		}
		if (a == 3) {
			system("cls");
			bannerHM ();
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, e);
			printf("   %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", x, y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, g, z, z, h);
			printf("   %c %c	  	    %c		    \n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, o);
			printf("   %c %c		   %c%c%c			\n", x, x, i, b, i);
			printf("   %c%c%c	       	     		\n", r, z, l, x);
			printf("  %c%c %c%c	  	    	   	    \n", y, w, q, e);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", doneS, doneS, doneR, doneS, doneS, doneS, doneR, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS);
		}
		if (a == 2) {
			system("cls");
			bannerHM ();
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, e);
			printf("   %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", x, y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, g, z, z, h);
			printf("   %c %c	  	    %c		    \n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, o);
			printf("   %c %c		   %c%c%c			\n", x, x, i, b, i);
			printf("   %c%c%c	       	    %c		\n", r, z, l, x);
			printf("  %c%c %c%c	  	    	   	    \n", y, w, q, e);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", doneS, doneS, doneR, doneS, doneS, doneS, doneR, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS);
		}
		if (a == 1) {
			system("cls");
			bannerHM ();
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, e);
			printf("   %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", x, y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, g, z, z, h);
			printf("   %c %c	  	    %c		    \n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, o);
			printf("   %c %c		   %c%c%c			\n", x, x, i, b, i);
			printf("   %c%c%c	       	    %c		\n", r, z, l, x);
			printf("  %c%c %c%c	  	     \\	   	    \n", y, w, q, e);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", doneS, doneS, doneR, doneS, doneS, doneS, doneR, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS);
		}
		if (a == 0) {
			system("cls");
			bannerHM ();
			printf("   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, z, e);
			printf("   %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", x, y, z, z, z, z, z, z, z, z, z, z, z, z, z, z, g, z, z, h);
			printf("   %c %c	  	    %c		    \n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, f);
			printf("   %c %c		    %c			\n", x, x, o);
			printf("   %c %c		   %c%c%c			\n", x, x, i, b, i);
			printf("   %c%c%c	       	    %c		\n", r, z, l, x);
			printf("  %c%c %c%c	  	   / \\	   	    \n", y, w, q, e);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", doneS, doneS, doneR, doneS, doneS, doneS, doneR, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS, doneS);
		}
	return a;
}


//wins passed
int statsHM (int playerWinsHM[5]) {
	FILE *fp;
	fp = fopen("hangman_stats.txt","w+");
	
	if(fp == NULL) {
		printf("Could not locate file! ");
		system("pause");
		return 0;
	}
	
	fprintf(fp, "%i", playerWinsHM);
	
	fclose(fp);	
	return;
}

int sendToMain() {
	mainHM();
	return;
}

int bannerHM () {
	printf("\t---------\n");
    printf("\t Hangman\n");
    printf("\t---------\n\n");
    return;
}
