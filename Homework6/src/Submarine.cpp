/*
 * Submarine.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#include "Submarine.h"

Submarine::Submarine(int row, int col, int direction) : Ship(row, col, direction){
	length = 3;
}

int Submarine::getLength(){
	return length;
}

char Submarine::toChar(int row, int col){
	int num = row - this->row + col - this->col;
	return isHitList[num] ? 's':'S';
}
