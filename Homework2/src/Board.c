/*
 * Board.c
 *
 *  Created on: Sep 9, 2019
 *      Author: gustt
 */

#include "Board.h"

Board makeBlankBoard() {
	int board[ROWS][COLS];
	int x;
	int y;
	Board Board = { board, {x,y} };
	Board.marker.x = COLS / 2;
	Board.marker.y = ROWS / 2;
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			Board.array[row][col] = 0;
		}
	}
	return Board;
}


void printboard(Board board) {
	for (int i = 0; i < COLS + 2; i++) {
		printf("%s", EDGE);
	}
	printf("\n");
	for (int row = 0; row < ROWS; row++) {
		printf("%s", EDGE);
		for (int col = 0; col < COLS; col++) {
			if (row == board.marker.y && col == board.marker.x) {
				printf("@");
			} else {
				printf("%c", board.array[row][col]);
			}
		}
		printf("%s\n", EDGE);
	}
	for (int i = 0; i < COLS + 2; i++) {
		printf("%s", EDGE);
	}
	printf("\n");
}
