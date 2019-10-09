/*
 * BattleShip.h
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#ifndef BATTLESHIP_H_
#define BATTLESHIP_H_
#include "Ship.h"

class Battleship: public Ship {
public:
	Battleship(int row, int col, int direction);
	int getLength();
	char toChar(int row, int col);
};

#endif /* BATTLESHIP_H_ */
