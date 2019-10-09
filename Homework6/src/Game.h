/*
 * Game.h
 *
 *  Created on: Oct 8, 2019
 *      Author: gustt
 */

#ifndef GAME_H_
#define GAME_H_
#include "Board.h"

class Game {
private:
	Board *playerBoard;
	Board *computerBoard;
	bool guesses[10][10];
public:
	Game();
	bool guess();
	bool computerGuess();
	void play(int turns);
};

#endif /* GAME_H_ */
