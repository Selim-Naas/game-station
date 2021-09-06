#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include "Tic Tac Toe.h"
#include "Hangman.h"
#include "Math_Quiz.h"

void gotoXY(int x, int y);
int gameMenu();
int adminMenu();
int editUsers();
int x;

char username[20];
char password[20];
int amountOfUsers = 0;

struct accountInfos {
	char usernameNotepad[20][20];
    char passwordNotepad[20][20];
};

int main(int argc, char *argv[]) {
	struct accountInfos accountInfo;
	int j;
	int i = 0;
	char c = ' ';

    FILE *fp;
    fp = fopen("userinfo.txt", "r");
    
    if (fp == NULL) {
    	system("pause");
    	return 0;
	}
    amountOfUsers += 2;
    while (!feof(fp)) {
    	amountOfUsers++;
    	for (x = 0; x <= 10; x++) {
    		fscanf(fp, "%s %s", accountInfo.usernameNotepad[x], accountInfo.passwordNotepad[x]);
    	}
	}
	fclose(fp);

	do {
		system("cls");
	    printf("\t\tACCOUNT LOGIN\n");
		printf("==============================================\n");
		printf("==        Username:                         ==\n");
		printf("==                                          ==\n");
		printf("==        Password: 	                    ==\n");
		printf("==                                          ==\n");
		printf("==============================================\n");
		
		gotoXY(20, 2);
	    gets(username);
	
		gotoXY(20, 4);
		
		int stars = 249;
		
		while (i <= 24) {
		    password[i] = getch();
		    if(password[i] == 13) {
		    	password[i] = '\0'; //trims the enter key character so it won't be included as the "password string"
		    	break;	
			}
			else if (password[i] == 8) {
				printf("\b \b");
				i--;
				password[i] = '\0';
			}
		    else {
		    	printf("%c", stars);
			}
		    i++;
		}
			
		    
	    system("cls");
	    
		for (j = 1; j <= 20; j++) {
			if (strcmp(username, accountInfo.usernameNotepad[j]) == 0 && strcmp(password, accountInfo.passwordNotepad[j]) == 0) {
				gameMenu();
			}
		}
		
		if (strcmp(username, accountInfo.usernameNotepad[0]) == 0 && strcmp(password, accountInfo.passwordNotepad[0]) == 0) {
	    	system("cls");
	    	adminMenu();
		}
		
		else {
			printf("\t\tACCOUNT LOGIN\n");
			printf("==============================================\n");
			printf("==                                          ==\n");
			printf("==     INCORRECT USERNAME OR PASSWORD!      ==\n");
			printf("==                                          ==\n");
			printf("==============================================\n");
			sleep(1);
			i = 0;
			c = ' ';
		}
	} while (strcmp(username, accountInfo.usernameNotepad[x]) != 0 && strcmp(password, accountInfo.passwordNotepad[x]) != 0);
	return 0;
}

int gameMenu() {
	system("cls");
	printf("\t\tGAME MENU\n");
	printf("==============================================\n");
	printf("==        (1) Hangman                       ==\n");
	printf("==                                          ==\n");
	printf("==        (2) Math Quiz 	            ==\n");
	printf("==                                          ==\n");
	printf("==        (3) Tic Tac Toe 	            ==\n");
	printf("==                                          ==\n");
	printf("==        Enter Choice:                     ==\n");
	printf("==============================================\n");
	do {
		gotoXY(24, 8);
		x = getch();
					
		if (x == '1') {
			system("cls");
			mainHM();
		}
		if (x == '2') {
			system("cls");
			mainMQ();
		}
		if (x == '3') {
			system("cls");
			mainTTT();
		}
		
	} while (x != '1' || x != '2' || x != '3');
	return;
}

int adminMenu() {
	struct accountInfos accountInfo; 
	int mathQuizWins, hangmanWins, tictactoeWins;
	FILE *fp;
    fp = fopen("userinfo.txt", "r");
    
    if (fp == NULL) {
    	system("pause");
    	return 0;
	}
    
    while (!feof(fp)) {
    	for (x = 0; x <= amountOfUsers; x++) {
    		fscanf(fp, "%s %s", accountInfo.usernameNotepad[x], accountInfo.passwordNotepad[x]);
    	}
	}
	fclose(fp);
	
	FILE *fpointer;
		fpointer = fopen("mathquiz_stats.txt", "r");
		if(fpointer == NULL) {
			printf("Could not locate file! ");
			system("pause");
			return 0;
		}
		
		while (!feof(fp)) {
			fscanf(fp, "%i", &mathQuizWins);
		}
	fclose(fpointer);
	FILE *fpointer1;
		fpointer1 = fopen("tictactoe_stats.txt", "r");
		if(fpointer1 == NULL) {
			printf("Could not locate file! ");
			system("pause");
			return 0;
		}
		
		while (!feof(fpointer1)) {
			fscanf(fpointer1, "%i", &tictactoeWins);
		}
	fclose(fpointer1);
	FILE *fpointer2;
		fpointer2 = fopen("hangman_stats.txt", "r");
		if(fpointer2 == NULL) {
			printf("Could not locate file! ");
			system("pause");
			return 0;
		}
		
		while (!feof(fpointer2)) {
			fscanf(fpointer2, "%i", &hangmanWins);
		}
	fclose(fpointer2);	
	char adminChoice;
	char playerStatistics;
	printf("\t\tADMIN MENU\n");
	printf("==============================================\n");
	printf("==        (1) View Player Statistics        ==\n");
	printf("==                                          ==\n");
	printf("==        (2) Edit Players	    	    ==\n");
	printf("==                                          ==\n");
	printf("==        Enter Choice:                     ==\n");
	printf("==============================================\n");	
	gotoXY(24, 6);
	
	do {
	    adminChoice = getch();
		
		if (adminChoice == '1') {
			exit(1);
		}
		 if (adminChoice == '2') {
	    	system("cls");
	    	editUsers();
		}
	} while (adminChoice != '1' || adminChoice != '2');
	return;
}

int sendToAdminMenu() {
	adminMenu();
	return;
}

int editUsers() {
	struct accountInfos accountInfo;
	char editUsers;
	int x;
	int newUser;
	newUser = amountOfUsers;
	
	FILE *fp;
		    fp = fopen("userinfo.txt", "r");
		    
		    if (fp == NULL) {
		    	system("pause");
		    	return 0;
			}
		    
		    while (!feof(fp)) {
		    	for (x = 0; x <= amountOfUsers; x++) {
		    		fscanf(fp, "%s %s", accountInfo.usernameNotepad[x], accountInfo.passwordNotepad[x]);
		    	}
			}
	fclose(fp);
			
	printf("\t\tEDIT USERS\n");
	printf("==============================================\n");
	printf("==        (1) Add Player                    ==\n");
	printf("==                                          ==\n");
	printf("==        (2) Delete Player 	            ==\n");
	printf("==                                          ==\n");
	printf("==        Enter Choice:                     ==\n");
	printf("==============================================\n");
	
	gotoXY(24, 6);
	
	do {
		editUsers = getch();
		if (editUsers == '1') {
			system("cls");
			printf("\t\tADD USER\n");
			printf("==============================================\n");
			printf("==        Player Username:                  ==\n");
			printf("==                                          ==\n");
			printf("==        Player Password: 	            ==\n");
			printf("==                                          ==\n");
			printf("==============================================\n");
		    
			gotoXY(27, 2);
		    gets(accountInfo.usernameNotepad[newUser]);
		
			gotoXY(27, 4);
		    gets(accountInfo.passwordNotepad[newUser]);
		    amountOfUsers++;
		    
			FILE *fpointer;
			fpointer = fopen("userinfo.txt","a");
			
			if(fpointer == NULL) {
				printf("Could not locate file! ");
				system("pause");
				return 0;
			}

			fprintf(fpointer, "%s %s\n", accountInfo.usernameNotepad[newUser], accountInfo.passwordNotepad[newUser]);
			fclose(fpointer);
			
			system("cls");
			printf("\t\tUSER ADDED!\n");
			printf("==============================================\n");
			printf("==                                          ==\n");
			printf("==        USER HAS BEEN ADDED!              ==\n");
			printf("==                                          ==\n");
			printf("==============================================\n");
			sleep(1);
			system("cls");
			adminMenu();
		}
		if (editUsers == '2') {
			system("cls");
			FILE *fp;
		    fp = fopen("userinfo.txt", "r");
		    
		    if (fp == NULL) {
		    	system("pause");
		    	return 0;
			}
			int newVar = 1;
		    while (!feof(fp)) {
		    	printf("\t\tPLAYER LIST\n");
		    	for (x = 0; x <= 10; x++) {
		    		fscanf(fp, "%s %s", accountInfo.usernameNotepad[x], accountInfo.passwordNotepad[x]);
		    		if (!feof(fp)) {
		    			printf("%s\n", accountInfo.usernameNotepad[x]);
					}
					else {
						exit(1);
					}
		    	}
			}
			fclose(fp);
		}
	} while (editUsers != '1' || editUsers != '2');
	return;
}

void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}
