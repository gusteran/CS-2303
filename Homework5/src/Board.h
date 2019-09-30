/*
 * Board.h
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#ifndef BOARD_H_
#define BOARD_H_
#define ROWS 8
#define COLS 10
#include "Checker.h"
#include "King.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <iostream>

class Board {
private:
Checker board[ROWS][COLS];
public:
Board();
Board(Checker board[ROWS][COLS]);
~Board();
void printBoard();
bool isValid(Location location);
bool isEmpty(Location location);
int getTeam(Location location);
Path possibleMoves(Location location);
vector<Location> jump(Checker checker,Location oldLoc, Location newLoc);
void move(Location oldLoc, Location newLocation);
void randomMove(Path path);
void randomJump(Path path);
};

#endif /* BOARD_H_ */
