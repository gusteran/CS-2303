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
				board[row][col] = new Checker(BLACK);
			else
				board[row][col] = new Checker(NOT);
		}
		alternate++;
	}
	for (; row < 5; row++) {
		for (int col = 0; col < COLS; col++) {
			if (alternate++ % 2 == 0)
				board[row][col] = new Checker(EMPTY);
			else
				board[row][col] = new Checker(NOT);
		}
		alternate++;
	}
	for (; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			if (alternate++ % 2 == 0)
				board[row][col] = new Checker(RED);
			else
				board[row][col] = new Checker(NOT);
		}
		alternate++;
	}
}

Board::Board(Checker board[ROWS][COLS]) {
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			this->board[row][col] = new Checker(board[row][col].getTeam());
		}
	}
}

Board::~Board() {
	delete &board;
}

bool Board::isValid(Location location) {
	return location.row >= 0 && location.col >= 0 && location.row < ROWS && location.col < COLS;
}

bool Board::isEmpty(Location location) {
	return isValid(location) && board[location.row][location.col]->getTeam() == EMPTY;
}

int Board::getTeam(Location location) {
	return board[location.row][location.col]->getTeam();
}

vector<Location> Board::jump(Checker piece, Location oldLoc, Location newLoc) {
	vector<Location> jumpTo;
	Location farLoc = { 2 * newLoc.row - oldLoc.row, 2 * newLoc.col - oldLoc.col };
	if (isEmpty(farLoc)) {
		jumpTo.push_back(farLoc);
	}
	return jumpTo;
}

Path Board::possibleMoves(Location location) {
	Path path = board[location.row][location.col]->possibleMoves(location);
	vector<Location> nextLocs = board[location.row][location.col]->possibleMoves(location).nextLocations;
	vector<Location> possibleLocs;
	vector<Location> jumps;
	for (int i = nextLocs.size() - 1; i >= 0; i--) {
		if (isValid(nextLocs.at(i))) {
			if (isEmpty(nextLocs.at(i))) {
				possibleLocs.push_back(nextLocs.at(i));
			} else if ((getTeam(nextLocs.at(i)) == RED && getTeam(location) == BLACK)
					|| (getTeam(nextLocs.at(i)) == BLACK && getTeam(location) == RED)) {
				jumps = jump(*board[location.row][location.col], path.location, nextLocs.at(i));
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
		if (newLoc.row == 0 && board[oldLoc.row][oldLoc.col]->getTeam() == RED) {
			board[newLoc.row][newLoc.col]->~Checker();
			board[newLoc.row][newLoc.col] = new King(RED);
		} else if (newLoc.row == ROWS - 1 && board[oldLoc.row][oldLoc.col]->getTeam() == BLACK) {
			board[newLoc.row][newLoc.col]->~Checker();
			board[newLoc.row][newLoc.col] = new King(BLACK);
		} else {
			board[newLoc.row][newLoc.col]->~Checker();
			if (board[oldLoc.row][oldLoc.col]->possibleMoves(oldLoc).nextLocations.size() > 2) {
				board[newLoc.row][newLoc.col] = new King(board[oldLoc.row][oldLoc.col]->getTeam());
			} else
				board[newLoc.row][newLoc.col] = board[oldLoc.row][oldLoc.col];
		}
		board[oldLoc.row][oldLoc.col]->~Checker();
		board[oldLoc.row][oldLoc.col] = new Checker(EMPTY);
	}
}

void Board::randomMove(Path path) {
	FILE *outputP = fopen("output.txt", "r+");
	fseek(outputP, 0L, SEEK_END);
	int randNum = rand() % path.nextLocations.size();
	cout << "Jump From Row: " << path.location.row << " Column: " << path.location.col << " To Row: "
			<< path.nextLocations.at(randNum).row << " Column: " << path.nextLocations.at(randNum).col << "\n";
	fprintf(outputP, "Move From Row: %d Column: %d To Row: %d Column: %d\n", path.location.row, path.location.col,
			path.nextLocations.at(randNum).row, path.nextLocations.at(randNum).col);
	filePrintBoard();
	fclose(outputP);
	move(path.location, path.nextLocations.at(randNum));
}

void Board::randomJump(Path path) {
	FILE *outputP = fopen("output.txt", "r+");
	fseek(outputP, 0L, SEEK_END);
	int randNum = rand() % path.jumps.size();
	cout << "Move From Row: " << path.location.row << " Column: " << path.location.col << " To Row: "
			<< path.jumps.at(randNum).row << " Column: " << path.jumps.at(randNum).col << "\n";
	int row = (path.location.row + path.jumps.at(randNum).row) / 2;
	int col = (path.location.col + path.jumps.at(randNum).col) / 2;
	board[row][col]->~Checker();
	board[row][col] = new Checker(EMPTY);
	fprintf(outputP, "Jump From Row: %d Column: %d To Row: %d Column: %d\n", path.location.row, path.location.col,
			path.jumps.at(randNum).row, path.jumps.at(randNum).col);
	filePrintBoard();
	fclose(outputP);
	move(path.location, path.jumps.at(randNum));
}

void Board::printBoard() {
	for (int col = 0; col < COLS + 2; col++)
		printf("-");
	printf("\n");
	for (int row = 0; row < ROWS; row++) {
		printf("|");
		for (int col = 0; col < COLS; col++) {
			printf("%c", board[row][col]->toString().at(0));
		}
		printf("|\n");
	}
	for (int col = 0; col < COLS + 2; col++)
		printf("-");
	printf("\n\n");
}

void Board::filePrintBoard() {
	FILE *outputP = fopen("output.txt", "r+");
	fseek(outputP, 0L, SEEK_END);
	fprintf(outputP, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	for (int col = 0; col < COLS + 2; col++)
		fprintf(outputP, "-");
	fprintf(outputP, "\n");
	for (int row = 0; row < ROWS; row++) {
		fprintf(outputP, "|");
		for (int col = 0; col < COLS; col++) {
			fprintf(outputP, "%c", board[row][col]->toString().at(0));
		}
		fprintf(outputP, "|\n");
	}
	for (int col = 0; col < COLS + 2; col++)
		fprintf(outputP, "-");
	fprintf(outputP, "\n\n");
	fclose(outputP);
}

