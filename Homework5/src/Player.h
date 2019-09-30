/*
 * Player.h
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Checker.h"
#include "Board.h"
#include "King.h"

class Player {
private:
	int team;
public:
	Player(int team);
	vector<Path>legalMoves(Board *board);
	void randomMove(Board *board);
};

#endif /* PLAYER_H_ */
