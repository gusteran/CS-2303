/*
 * Player.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#include "Player.h"

Player::Player(int team) {
	this->team = team;
}

vector<Path> Player::legalMoves(Board *board) {
	vector<Path> moves;
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			if (board->getTeam( { row, col }) == team) {
				Path path = board->possibleMoves( { row, col });
				if (path.nextLocations.size() > 0)
					moves.push_back(path);
				printf("Row: %d Col: %d Team:%d\t", row, col, board->getTeam( { row, col }));
				if (board->possibleMoves( { row, col }).nextLocations.size() > 0)
					printf("Next Loc Row: %d Col %d\n", board->possibleMoves( { row, col }).nextLocations.at(0).row,
							board->possibleMoves( { row, col }).nextLocations.at(0).col);
				else
					printf("\n");
			}
		}
	}
//	printf("Num Paths: %d\n", moves.size());
	return moves;
}

void Player::randomMove(Board *board) {
	vector<Path> possible = legalMoves(board);
	vector<Path> canJump;
	for (int i = 0; i < possible.size(); i++) {
		if (possible.at(i).jumps.size() > 0)
			canJump.push_back(possible.at(i));
	}
	if (canJump.size() > 0) {
		int moveNum = rand() % canJump.size();
		Path move = canJump.at(moveNum);
		board->randomJump(move);
	} else {
		int moveNum = rand() % possible.size();
		Path move = possible.at(moveNum);
		board->randomMove(move);
	}
//	printf("Row: %d Col: %d\t", move.location.row, move.location.col);
//	printf("Next Loc Row: %d Col %d\n", .nextLocations.at(0).row,
//			board->possibleMoves( { row, col }).nextLocations.at(0).col);

}
