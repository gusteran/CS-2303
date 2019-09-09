/*
 * production.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "production.h"

void moveIterations(int count){
	int iteration = 1;
	srand(time(NULL));
	Board board = makeBlankBoard();
	for(;count>0; count--){
		printf("Iteration: %d\t", iteration++);
		if(rand()%10>5){
			int direction = rand() % COLS - board.marker.x;
			printf("Direction: %s %d\n", (direction>0)?"Right":"Left", (direction>0)?direction:-direction);
			board = horizontal(board, direction);
		} else {
			int direction = rand() % ROWS - board.marker.y;
			printf("Direction: %s %d\n", (direction>0)?"Down":"Up", (direction>0)?direction:-direction);
			board = vertical(board, direction);
		}
		printboard(board);
	}
}
