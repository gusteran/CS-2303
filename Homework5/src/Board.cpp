/*
 * Board.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#include "Board.h"

using namespace std;

Board::Board() {
	int row;
	int alternate = 1;
	for (row = 0; row < 3; row++) {
		for (int col = 0; col < COLS; col++) {
			if (alternate++ % 2 == 0)
				board[row][col] = Checker(BLACK);
			else
				board[row][col] = Checker(NOT);
		}
		alternate++;
	}
	for (; row < 5; row++) {
		for (int col = 0; col < COLS; col++) {
			if (alternate++ % 2 == 0)
				board[row][col] = Checker(EMPTY);
			else
				board[row][col] = Checker(NOT);
		}
		alternate++;
	}
	for (; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			if (alternate++ % 2 == 0)
				board[row][col] = Checker(RED);
			else
				board[row][col] = Checker(NOT);
		}
		alternate++;
	}
}

Board::Board(Checker board[ROWS][COLS]) {
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			this->board[row][col] = board[row][col];
		}
	}
}

Board::~Board(){
	delete &board;
}

bool Board::isValid(Location location) {
	return location.row >= 0 && location.col >= 0 && location.row < ROWS && location.col < COLS;
}

bool Board::isEmpty(Location location) {
	return isValid(location) && board[location.row][location.col].getTeam() == EMPTY;
}

int Board::getTeam(Location location) {
	return board[location.row][location.col].getTeam();
}

vector<Location> Board::jump(Checker piece, Location oldLoc, Location newLoc) {
	vector<Location> jumpTo;
	Location farLoc = {2*newLoc.row-oldLoc.col, 2*newLoc.row-oldLoc.col};
	if(isEmpty(farLoc)){
		vector<Location> next;
		for(int i = 0; i < piece.possibleMoves(oldLoc).nextLocations.size(); i++){
			vector<Location> furtherJump = jump(piece, farLoc, piece.possibleMoves(oldLoc).nextLocations.at(i));
			next.insert(next.end(), furtherJump.begin(), furtherJump.end());
		}
		if(next.size()>0)
			return next;
		else
			jumpTo.push_back(farLoc);
	}
	return jumpTo;
}

Path Board::possibleMoves(Location location) {
	Path path = board[location.row][location.col].possibleMoves(location);
	vector<Location> nextLocs = board[location.row][location.col].possibleMoves(location).nextLocations;
	vector<Location> possibleLocs;
	vector<Location> jumps;
	for (int i = nextLocs.size() - 1; i >= 0; i--) {
		if (isValid(nextLocs.at(i))) {
			if (isEmpty(nextLocs.at(i))) {
				possibleLocs.push_back(nextLocs.at(i));
			}
			else if ((getTeam(nextLocs.at(i)) == RED && getTeam(location) == BLACK)
					|| (getTeam(nextLocs.at(i)) == BLACK && getTeam(location) == RED)) {
				jumps = jump(board[location.row][location.col], path.location, nextLocs.at(i));
				nextLocs.insert(nextLocs.end(), jumps.begin(), jumps.end());
			}
		}
	}
	path.nextLocations = possibleLocs;
	path.jumps = jumps;
	return path;
}

void Board::move(Location oldLoc, Location newLoc) {
	if (isValid(newLoc)) {
		if (newLoc.row == 0 && board[oldLoc.row][oldLoc.col].getTeam() == RED) {
			board[newLoc.row][newLoc.col].~Checker();
			board[newLoc.row][newLoc.col] = King(board[oldLoc.row][oldLoc.col].getTeam());
		} else if (newLoc.row == ROWS - 1 && board[oldLoc.row][oldLoc.col].getTeam() == BLACK) {
			board[newLoc.row][newLoc.col].~Checker();
			board[newLoc.row][newLoc.col] = King(board[oldLoc.row][oldLoc.col].getTeam());
		} else {
			board[newLoc.row][newLoc.col].~Checker();
			board[newLoc.row][newLoc.col] = Checker(board[oldLoc.row][oldLoc.col].getTeam());
		}
		board[oldLoc.row][oldLoc.col] = Checker(EMPTY);
	}
}

void Board::randomMove(Path path) {
	int randNum = rand() % path.nextLocations.size();
	printf("Next Loc Row: %d Col %d\n", path.nextLocations.at(randNum).row, path.nextLocations.at(randNum).col);
	move(path.location, path.nextLocations.at(randNum));
}

void Board::randomJump(Path path){
	int randNum = rand() % path.jumps.size();
	printf("Next Loc Row: %d Col %d\n", path.jumps.at(randNum).row, path.jumps.at(randNum).col);
}

void Board::printBoard() {
	for (int col = 0; col < COLS; col++)
		printf("-");
	printf("\n");
	for (int row = 0; row < ROWS; row++) {
		printf("|");
		for (int col = 0; col < COLS; col++) {
			cout << board[row][col].toString();
		}
		printf("|\n");
	}
	for (int col = 0; col < COLS; col++)
		printf("-");
	printf("\n\n");
}

