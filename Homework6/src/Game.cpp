/*
 * Game.cpp
 *
 *  Created on: Oct 8, 2019
 *      Author: gustt
 */

#include "Game.h"

Game::Game(){
	for(int row = 0; row < ROWS; row++)
		for(int col = 0; col < COLS; col++)
			guesses[row][col] = false;
	playerBoard = new Board(false);
	computerBoard = new Board(false);
}

bool Game::guess() {
	bool isValid = false;
	while (!isValid) {
		int row;
		int col;
		printf("Make a guess\n");
		printf("Row: \t");
		fflush(stdout);
		scanf("%d", &row);
		fflush(stdin);
		printf("Col: \t");
		fflush(stdout);
		scanf("%d", &col);
		fflush(stdin);
		isValid = computerBoard->isValid(row, col);
		computerBoard->shot(row, col);
	}
	return computerBoard->hasLost();


	srand(time(NULL));
	bool isShot = false;
	while(!isShot){
		int row = rand() % 10;
		int col = rand() % 10;
		isShot = !guesses[row][col];
		if(isShot){
			computerBoard->shot(row, col);
			guesses[row][col] = true;
		}
	}
	return computerBoard->hasLost();
}

bool Game::computerGuess() {
	srand(time(NULL));
	bool isShot = false;
	while(!isShot){
		int row = rand() % 10;
		int col = rand() % 10;
		isShot = !guesses[row][col];
//		printf("\n Guess Row: %d Col: %d\n", row, col);
		if(isShot){
			playerBoard->shot(row, col);
			guesses[row][col] = true;
		}
	}
	return playerBoard->hasLost();
}

void Game::play(int turns){
	FILE *outputP = fopen("output.txt", "r+");
	bool player = true;
	bool computer = true;
	while(player && computer && turns-- > 0){
		fflush(outputP);
		player &= !guess();
		computerBoard->printBoard(false);
		fseek(outputP, 0L, SEEK_END);
		fprintf(outputP, "Opponent's Board\n");
		computerBoard->filePrintBoard(false);
		fflush(outputP);
		computer &= !computerGuess();
		playerBoard->printBoard(true);
		fseek(outputP, 0L, SEEK_END);
		fprintf(outputP, "Your Board\n");
		playerBoard->filePrintBoard(true);
		fflush(outputP);

	}
	if(!player) printf("Player won\n");
	if(!computer) printf("Computer won\n");
	fclose(outputP);

}
