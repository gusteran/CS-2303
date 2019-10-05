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
	FILE *outputP = fopen("output.txt", "r+");
	fseek(outputP, 0L, SEEK_END);
	vector<Path> moves;
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			if (board->getTeam( { row, col }) == team) {
				Path path = board->possibleMoves( { row, col });
				if (path.nextLocations.size() > 0)
					moves.push_back(path);
				if (board->possibleMoves( { row, col }).nextLocations.size() > 0
						|| board->possibleMoves( { row, col }).jumps.size() > 0) {
					fprintf(outputP, "From Row: %d Col: %d\t", row, col);
					int posSize = board->possibleMoves( { row, col }).nextLocations.size();
					for (int i = 0; i < posSize; i++) {
						fprintf(outputP, "Possible move to Row: %d Col: %d\t",
								board->possibleMoves( { row, col }).nextLocations.at(i).row, board->possibleMoves( {
										row, col }).nextLocations.at(i).row);
					}
					int jumpSize = board->possibleMoves( { row, col }).jumps.size();
					for (int i = 0; i < jumpSize; i++) {
						fprintf(outputP, "Possible jump to Row: %d Col: %d\t",
								board->possibleMoves( { row, col }).jumps.at(i).row,
								board->possibleMoves( { row, col }).jumps.at(i).row);
					}
					fprintf(outputP, "\n");
				}
			}
		}
	}
	fclose(outputP);
	return moves;
}

bool Player::randomMove(Board *board) {
	FILE *outputP = fopen("output.txt", "r+");
	fseek(outputP, 0L, SEEK_END);
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
	} else  if (possible.size()>0){
		int moveNum = rand() % possible.size();
		Path move = possible.at(moveNum);
		board->randomMove(move);
	} else {
		if(team == BLACK){
			printf("Red Wins\n");
			fprintf(outputP,"Red Wins\n");
		} else {
			printf("Black Wins\n");
			fprintf(outputP,"Black Wins\n");
		}
		return false;
	}
	fclose(outputP);
	return true;
}
