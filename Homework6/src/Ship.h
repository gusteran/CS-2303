/*
 * Ship.h
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#ifndef SHIP_H_
#define SHIP_H_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#define HORIZONTAL 1
#define VERTICAL 0

class Ship {
protected:
	int length;
	int row;
	int col;
	int direction;
	bool sunk;
	bool isHitList[5];
public:
	Ship(int row, int col, int direction);
	virtual ~Ship();
	virtual int getLength();
	virtual char toChar(int row, int col);
	bool setLocation(int row, int col);
	int getRow();
	int getCol();
	int getDirection();
	void setDirection(int direction);
	bool isHit(int row, int col);
	bool hit(int row, int col);
	bool hasSunk();
	};

#endif /* SHIP_H_ */
