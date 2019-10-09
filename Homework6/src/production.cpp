/*
 * production.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#include "production.h"

bool production(int argc, char* argv[]){
	int numTurns = 100;
	if (argc == 2) {
			numTurns = atoi(argv[1]);
		} else {
			printf("Wrong number of command line arguments: Requires one for number of turns\n"
					"Please enter the number of turns: \t");
			fflush(stdout);
			scanf("%d", &numTurns);
			fflush(stdin);
		}
	Game *game = new Game();
	game->play(numTurns);
	return true;
}
