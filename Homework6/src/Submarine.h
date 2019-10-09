/*
 * Submarine.h
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#ifndef SUBMARINE_H_
#define SUBMARINE_H_
#include "Ship.h"

class Submarine: public Ship {
public:
	Submarine(int row, int col, int direction);
	int getLength();
	char toChar(int row, int col);
};

#endif /* SUBMARINE_H_ */
