/*
 * Board.h
 *
 *  Created on: Sep 9, 2019
 *      Author: gustt
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Marker.h"

#define ROWS 21
#define COLS 41
#define EDGE "%"

typedef struct{
	int array[ROWS][COLS];
	Marker marker;
} Board;

void printBoard(Board board);

Board makeBlankBoard();

#endif /* BOARD_H_ */
