/*
 * King.h
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#ifndef KING_H_
#define KING_H_
#include "Checker.h"

class King : public Checker {
public:
	King(Checker checker);
	King(int team);
	~King();
	string toString() override;
	Path possibleMoves(Location location) override;
};

#endif /* KING_H_ */
