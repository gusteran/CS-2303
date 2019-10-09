/*
 * Destroyer.h
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#ifndef DESTROYER_H_
#define DESTROYER_H_
#include "Ship.h"

class Destroyer: public Ship{
public:
	Destroyer(int row, int col, int direction);
	int getLength();
	char toChar(int row, int col);
};

#endif /* DESTROYER_H_ */
