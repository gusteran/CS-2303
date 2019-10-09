/*
 * Cruiser.h
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#ifndef CRUISER_H_
#define CRUISER_H_
#include "Ship.h"

class Cruiser: public Ship {
private:
public:
	Cruiser(int row, int col, int direction);
	int getLength();
	char toChar(int row, int col);
};

#endif /* CRUISER_H_ */
