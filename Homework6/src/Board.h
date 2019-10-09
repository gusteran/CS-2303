/*
 * Board.h
 *
 *  Created on: Oct 7, 2019
 *      Author: gustt
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "Ship.h"
#include "AircraftCarrier.h"
#include "Battleship.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>

#define EMPTY 5
#define MISS 6

#define ROWS 10
#define COLS 10

typedef struct {
	int shipNum;
	bool isHit;
} Coordinate;

class Board {
private:
	Ship *ships[5];
	int board[ROWS][COLS];
public:
	Board();
	Board(bool isPlayer);
	bool isValid(int row, int col);
	bool isHit(int row, int col);
	bool isShip(int row, int col);
	void printBoard(bool canView);
	void filePrintBoard(bool canView);
	bool shot(int row, int col);
	bool hasLost();
};

#endif /* BOARD_H_ */
