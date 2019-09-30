/*
 * tests.cpp
 *
 *  Created on: Sep 25, 2019
 *      Author: gustt
 */

#include "tests.h"

bool tests() {
	bool ans = true;
	ans &= canPrintTest();
	ans &= movePieceTest();
	ans &= possibleLocationsTest();
	ans &= randMoveTest1();
	return ans;
}

bool randMoveTest1() {
	Board *testBoard = new Board();
	Player red = Player(RED);
	Player black = Player(BLACK);
	for(int i = 0; i < 6; i++){
		red.randomMove(testBoard);
		black.randomMove(testBoard);
		testBoard->printBoard();
	}
	return true;
}

bool canPrintTest() {
	Board *testBoard = new Board();
	testBoard->printBoard();
	return true;
}

bool movePieceTest() {
	Board *testBoard = new Board();
	Location oldLoc = { 2, 1 };
	Location newLoc = { 3, 2 };
	testBoard->move(oldLoc, newLoc);
	testBoard->printBoard();
	return true;
}

bool possibleLocationsTest() {
	Board *testBoard = new Board();
	Player red = Player(RED);
	red.legalMoves(testBoard);
	testBoard->printBoard();
	return true;
}
