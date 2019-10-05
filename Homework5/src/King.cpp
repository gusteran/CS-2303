/*
 * King.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#include "King.h"

King::King(Checker checker) {
	King(checker.getTeam());
}

King::King(int team) :
		Checker(team) {
	this->team = team;
}

King::~King(){
	delete &team;
}

string King::toString(){
	switch(team){
	case RED:
		return "R";
	case BLACK:
		return "B";
	case EMPTY:
		return "_";
	case NOT:
		return " ";
	default:
		return " ";
	}
}

Path King::possibleMoves(Location location) {
	vector<Location> list = vector<Location>();
	Location left;
	Location right;
	Location leftBack;
	Location rightBack;
	if (team == RED) {
		left = { location.row - 1, location.col - 1 };
		right = { location.row - 1, location.col + 1 };
		leftBack = { location.row + 1, location.col - 1 };
		rightBack = { location.row + 1, location.col + 1 };
	} else if (team == BLACK) {
		left = { location.row + 1, location.col - 1 };
		right = { location.row + 1, location.col + 1 };
		leftBack = { location.row - 1, location.col - 1 };
		rightBack = { location.row - 1, location.col + 1 };
	}

	list.push_back(left);
	list.push_back(right);
	list.push_back(leftBack);
	list.push_back(rightBack);
	return {team, location, list};
}
