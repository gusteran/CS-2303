/*
 * Ship.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#include "Ship.h"

Ship::Ship(int row, int col, int direction) {
	length = 1;
	this->row = row;
	this->col = col;
	this->direction = direction;
	for(int i = 0; i < 5; i++)
		isHitList[i] = false;
	sunk = false;
}

Ship::~Ship() {
	delete &length;
}

bool Ship::setLocation(int row, int col){
	if(row >= 0 && row < 10 && col >= 0 && col < 10){
		this->row = row;
		this->col = col;
		return true;
	}
	return false;

}

int Ship::getLength() {
	return length;
}

char Ship::toChar(int row, int col) {
	return '$';
}

bool Ship::isHit(int row, int col){
	return isHitList[row - this->row + col - this->col];
}

bool Ship::hit(int row, int col){
	isHitList[row - this->row + col - this->col] = true;
	bool isSunk = true;
	for(int i = 0; i < length; i++){
		isSunk &= isHitList[i];
	}
	sunk = isSunk;
	return isSunk;
}

bool Ship::hasSunk(){
	return sunk;
}

int Ship::getCol() {
	return col;
}

int Ship::getDirection() {
	return direction;
}

void Ship::setDirection(int direction){
	this->direction = direction;
}

int Ship::getRow() {
	return row;
}
