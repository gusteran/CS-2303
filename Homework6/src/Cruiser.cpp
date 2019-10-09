/*
 * Cruiser.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#include "Cruiser.h"

Cruiser::Cruiser(int row, int col, int direction) : Ship(row, col, direction){
	length = 3;
}

int Cruiser::getLength(){
	return length;
}

char Cruiser::toChar(int row, int col){
	int num = row - this->row + col - this->col;
	return isHitList[num] ? 'c':'C';
}
