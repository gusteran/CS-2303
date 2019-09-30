/*
 * Checker.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#include "Checker.h"

Checker::Checker() {
	this->team = NOT;
}

Checker::Checker(int team) {
	this->team = team;
}

Checker::~Checker() {
	delete &team;
}

int Checker::getTeam() {
	return team;
}

string Checker::toString() {
	switch (team) {
	case RED:
		return ("r");
	case BLACK:
		return ("b");
	case EMPTY:
		return "_";
	case NOT:
		return " ";
	default:
		return " ";
	}
}

Path Checker::possibleMoves(Location location) {
	vector<Location> list = vector<Location>();
	Location left;
	Location right;
	if (team == RED) {
		left = { location.row - 1, location.col - 1 };
		right = { location.row - 1, location.col + 1 };
	} else if (team == BLACK) {
		left = { location.row + 1, location.col - 1 };
		right = { location.row + 1, location.col + 1 };
	}

	list.push_back(left);
	list.push_back(right);
	return {team, location, list};
}
