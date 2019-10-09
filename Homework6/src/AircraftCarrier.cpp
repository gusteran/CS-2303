/*
 * AircraftCarrier.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#include "AircraftCarrier.h"

AircraftCarrier::AircraftCarrier(int row, int col, int direction) : Ship(row, col, direction){
	length = 5;
}

int AircraftCarrier::getLength(){
	return length;
}

char AircraftCarrier::toChar(int row, int col){
	int num = row - this->row + col - this->col;
	return isHitList[num] ? 'a':'A';
}
