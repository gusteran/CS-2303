/*
 * production.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#include "production.h"
bool production(int argc, char *argv[]) {

	int numTurns = 0;

	if (argc == 2) {
		numTurns = atoi(argv[1]);
	} else {
		printf("Wrong number of command line arguments: Requires one for number of turns");
	}

	Board *testBoard = new Board();
	Player red = Player(RED);
	Player black = Player(BLACK);
	bool play = true;
	for (int i = 0; i < numTurns && play; i++) {
		play &= red.randomMove(testBoard);
		testBoard->printBoard();
		play &= black.randomMove(testBoard);
		testBoard->printBoard();
	}
	return true;
}
