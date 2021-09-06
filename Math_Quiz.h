#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

void bannerMQ ();
int addition (char _difficulty);
int substraction (char _difficulty);
int multiplication (char _difficulty);
int division (char _difficulty);
int displayPlayAgain (char _playAgain);
int wins;
int divideSymbol = 246;

int mainMQ () {
	srand(time(NULL));
	char operation;
	char difficultyMQ;
	char goBackMQ;
	
	FILE *fp;
	fp = fopen("mathquiz_stats.txt", "r");
	if(fp == NULL) {
		printf("Could not locate file! ");
		system("pause");
		return 0;
	}
		
	while (!feof(fp)) {
		fscanf(fp, "%i", &wins);
	}
	fclose(fp);
	
	bannerMQ ();
	printf("1 ==> Addition\n");
	printf("2 ==> Substraction\n");
	printf("3 ==> Multiplication\n");
	printf("4 ==> Division\n----------------------\n");
	printf("5 ==> View Stats\n");
	printf("6 ==> Change Game\n");
	printf("7 ==> Quit\n\nChoose option: ");
	
	do {
		operation = getch();
		if (operation == '1') {  
			system("cls");
			addition (difficultyMQ);
		}
		if (operation == '2') {  
			system("cls");
			substraction (difficultyMQ);
		}
		if (operation == '3') {
			system("cls");  
			multiplication (difficultyMQ);  
		}
		if (operation == '4') { 
			system("cls"); 
			division (difficultyMQ);
		}
		if (operation == '5') { 
			system("cls");
			bannerMQ();
			printf("Total Math Quiz Questions Answered Right: %i\n\n", wins);
			printf("Go back? (Y): ");
			
			do {
				goBackMQ = getch();
				if (goBackMQ == 'Y' || goBackMQ == 'y') {
					system("cls");
					sendToMainMQ();
					break;
				}
			} while (goBackMQ != 'Y' || goBackMQ != 'y');		
		}
		if (operation == '6') {
			gameMenu();
		}
		if (operation == '7') {
			exit(1);
		}
	} while (operation != '1' || operation != '2' || operation != '3' || operation != '4' || operation != '5' || operation != '6' || operation != '7');
	
	return 0;
}

void bannerMQ () {
	printf("\t-----------\n");
    printf("\t Math Quiz\n");
    printf("\t-----------\n\n");
    return;
}

int addition (char _difficulty) {
	int x, y, result, userResult;
	char playAgainMQ;
		system("cls");
		bannerMQ();
		displayDifficulties ();
		
	do {
		_difficulty = getch();
		if (_difficulty == '1' || _difficulty == '2' || _difficulty == '3' || _difficulty == '4') {
			break;
		}
	} while (_difficulty != '1' || _difficulty != '2' || _difficulty != '3' || _difficulty != '4');
	
	if (_difficulty == '1') {
		x = (rand()%5) + 1;
		y = (rand()%5) + 1;
		result = x + y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i + %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i + %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '2') {
		x = (rand()%15) + 5;
		y = (rand()%15) + 5;
		result = x + y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i + %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i + %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '3') {
		x = (rand()%15) + 20;
		y = (rand()%15) + 20;
		result = x + y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i + %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i + %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '4') {
		x = (rand()%1000) + 35;
		y = (rand()%1000) + 35;
		result = x + y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i + %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i + %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	return;
}

int substraction (char _difficulty) {
	int x, y, result, userResult;
	char playAgainMQ;
	system("cls");
		bannerMQ();
		displayDifficulties ();
		
	do {
		_difficulty = getch();
		if (_difficulty == '1' || _difficulty == '2' || _difficulty == '3' || _difficulty == '4') {
			break;
		}
	} while (_difficulty != '1' || _difficulty != '2' || _difficulty != '3' || _difficulty != '4');
	
	if (_difficulty == '1') {
		do {
			x = (rand()%5) + 1;
			y = (rand()%5) + 1;
		} while (x < y);
		result = x - y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i - %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i - %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '2') {
		do {
			x = (rand()%15) + 5;
			y = (rand()%15) + 5;
		} while (x < y);
		result = x - y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i - %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i - %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '3') {
		do {
			x = (rand()%15) + 20;
			y = (rand()%15) + 20;
		} while (x < y);
		result = x - y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i - %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i - %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '4') {
		x = (rand()%1000) + 35;
		y = (rand()%1000) + 35;
		result = x - y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i - %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i - %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	return;
}

int multiplication (char _difficulty) {
	int x, y, result, userResult;
	char playAgainMQ;
	system("cls");
		bannerMQ();
		displayDifficulties ();
		
	do {
		_difficulty = getch();
		if (_difficulty == '1' || _difficulty == '2' || _difficulty == '3' || _difficulty == '4') {
			break;
		}
	} while (_difficulty != '1' || _difficulty != '2' || _difficulty != '3' || _difficulty != '4');
	
	if (_difficulty == '1') {
		x = (rand()%5) + 1;
		y = (rand()%5) + 1;
		result = x * y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i * %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i * %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '2') {
		x = (rand()%15) + 5;
		y = (rand()%15) + 5;
		result = x * y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i * %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i * %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '3') {
		x = (rand()%15) + 20;
		y = (rand()%15) + 20;
		result = x * y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i * %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i * %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '4') {
		x = (rand()%1000) + 35;
		y = (rand()%1000) + 35;
		result = x * y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %i * %i = ", x, y);
		scanf("%i", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %i * %i is indeed %i!\nTotal Math Quiz Questions Answered Correctly: %i\n", x, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %i!\n\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	return;
}

int division (char _difficulty) {
	float x, y, result, userResult;
	char playAgainMQ;
	system("cls");
		bannerMQ();
		displayDifficulties ();
		
	do {
		_difficulty = getch();
		if (_difficulty == '1' || _difficulty == '2' || _difficulty == '3' || _difficulty == '4') {
			break;
		}
	} while (_difficulty != '1' || _difficulty != '2' || _difficulty != '3' || _difficulty != '4');
	
	if (_difficulty == '1') {
		x = (rand()%5) + 1;
		y = (rand()%5) + 1;
		result = x / y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %.1f %c %.1f = ", x, divideSymbol, y);
		scanf("%.1f", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %.1f %c %.1f is indeed %.1f!\nTotal Math Quiz Questions Answered Correctly: %.1f\n", x, divideSymbol, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %.1f!\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '2') {
		x = (rand()%15) + 5;
		y = (rand()%15) + 5;
		result = x / y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %.1f %c %.1f = ", x, divideSymbol, y);
		scanf("%.1f", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %.1f %c %.1f is indeed %.1f!\n\nTotal Math Quiz Questions Answered Correctly: %.1f\n", x, divideSymbol, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %.1f!\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '3') {
		x = (rand()%15) + 20;
		y = (rand()%15) + 20;
		result = x / y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %.1f %c %.1f = ", x, divideSymbol, y);
		scanf("%.1f", &userResult);
			
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %.1f %c %.1f is indeed %.1f!\n\nTotal Math Quiz Questions Answered Correctly: %.1f\n", x, divideSymbol, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %.1f!\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	if (_difficulty == '4') {
		x = (rand()%1000) + 35;
		y = (rand()%1000) + 35;
		result = x / y;
		
		system("cls");
		bannerMQ();
		printf("Can you tell me what %.1f %c %.1f = ", x, divideSymbol, y);
		scanf("%.1f", &userResult);
		
		if (userResult == result) {
			wins++;
			statsMQ(wins);
			system("cls");
			bannerMQ();
			printf("Congratulations! %.1f %c %.1f is indeed %.1f!\nTotal Math Quiz Questions Answered Correctly: %.1f\n", x, divideSymbol, y, result, wins);
			displayPlayAgain(playAgainMQ);
		}
		else {
			system("cls");
			bannerMQ();
			printf("Wrong! The answer was %.1f!\n", result);
			displayPlayAgain(playAgainMQ);
		}
	}
	return;
}

int displayDifficulties () {
	printf("1 ==> Easy\n");
	printf("2 ==> Medium\n");
	printf("3 ==> Hard\n");
	printf("4 ==> Expert\n");
	printf("Chose the difficulty: ");
}

int sendToMainMQ () {
	mainMQ();
	return;
}

int displayPlayAgain (char _playAgain) {
	int resetStats;
		printf("\n1 ==> YES\n");
		printf("2 ==> NO\n");
		printf("3 ==> Reset Stats\nEnter Choice: ");
		do {
			_playAgain = getch();
			if (_playAgain == '1') {
				system("cls");
				mainMQ();
			}
			if (_playAgain == '2') {
				return 0;
			}
			if (_playAgain == '3') {
				system("cls");
				bannerMQ();
				printf("Stats will be lost forever! Continue? (Y/N)");
				do {
					resetStats = getch();
					if (resetStats == 'Y' || resetStats == 'y') {
						system("cls");
						wins = 0;
						statsMQ(wins);
						printf("\nStats have been succesfully reset!");
						sleep(1);
						system("cls");
						sendToMain ();
					}
					if (resetStats == 'N' || resetStats == 'n') {
						exit(1);
					}
				} while (resetStats != 'Y' || resetStats != 'y' || resetStats != 'N' || resetStats != 'n');
			}
		} while (_playAgain != '1' || _playAgain != '2');
	return;
}

int statsMQ (int playerWins[5]) {
	FILE *fpointer;
	fpointer = fopen("mathquiz_stats.txt","w+");
	
	if(fpointer == NULL) {
		printf("Could not locate file! ");
		system("pause");
		return 0;
	}
	
	fprintf(fpointer, "%i", playerWins);
	
	fclose(fpointer);	
	return;
}
