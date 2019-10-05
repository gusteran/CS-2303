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
	ans &= isValid1();
	ans &= isValid2();
	ans &= isValid3();
	ans &= isEmpty1();
	ans &= isEmpty2();
	ans &= isEmpty3();
	ans &= kingTest();
	return ans;
}

Board *board = new Board();

bool kingTest() {
	Location oldLoc = { 2, 1 };
	Location newLoc = { 7, 0 };
	board->move( oldLoc, newLoc);
//	board->printBoard();
	return board->getTeam(newLoc) == BLACK;
}

bool isValid1() {
	return board->isValid( { 3, 3 });
}
bool isValid2() {
	return !board->isValid( { -1, 3 });
}
bool isValid3() {
	return !board->isValid( { 3, COLS + 1 });
}
bool isEmpty1() {
	return board->isEmpty( { 3, 2 });
}
bool isEmpty2() {
	return !board->isEmpty( { 2, 1 });
}
bool isEmpty3() {
	return !board->isEmpty( { 9, 9 });
}

bool randMoveTest1() {
//	Board *testBoard = new Board();
//	Player red = Player(RED);
//	Player black = Player(BLACK);
//	for(int i = 0; i < 30; i++){
//		red.randomMove(testBoard);
//		testBoard->printBoard();
//		black.randomMove(testBoard);
//		testBoard->printBoard();
//	}
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
//	testBoard->printBoard();
	return testBoard->getTeam(newLoc) == BLACK;
}

bool possibleLocationsTest() {
	Board *testBoard = new Board();
	Player red = Player(RED);
	return red.legalMoves(testBoard).size() > 0;
}
