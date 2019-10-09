/*
 * Destroyer.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#include "Destroyer.h"

Destroyer::Destroyer(int row, int col, int direction) : Ship(row, col, direction){
	length = 2;
}

int Destroyer::getLength(){
	return length;
}

char Destroyer::toChar(int row, int col){
	int num = row - this->row + col - this->col;
	return isHitList[num] ? 'd':'D';
}
