/*
 * BoardState.c
 *
 *  Created on: Sep 9, 2019
 *      Author: gustt
 */

#include "BoardState.h"

//I used vertical and horizontal to cover up, down, left and right in
// a more straightforward way

Board vertical(Board board, int distance) {
	int delta = (distance > 0) ? 1 : -1;
	distance = (distance > 0) ? distance : -distance;
	bool wait = true;
	while (distance > 0) {
		if(wait){
			board.array[board.marker.y][board.marker.x] = (delta>0)?'v':'^';
			board.marker.y += delta;
		}
		else if (board.marker.y  + delta >= 0 && board.marker.y  + delta < ROWS) {
			board.array[board.marker.y][board.marker.x] = '|';
			board.marker.y += delta;
		}
		wait = false;
		distance--;
	}
	return board;
}

Board horizontal(Board board, int distance) {
	int delta = (distance > 0) ? 1 : -1;
	distance = (distance > 0) ? distance : -distance;
	bool wait = true;
	while (distance > 0) {
		if(wait){
			board.array[board.marker.y][board.marker.x] = (delta>0)?'>':'<';
			board.marker.x += delta;
		}
		else if(board.marker.x  + delta >= 0 && board.marker.x + delta < COLS) {
			board.array[board.marker.y][board.marker.x] = '-';
			board.marker.x += delta;
		}
		wait = false;
		distance--;
	}
	return board;
}
