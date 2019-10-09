/*
 * tests.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: gustt
 */

#include "tests.h"

bool tests() {
	bool ans = true;
	ans &= printBoardTest();
	ans &= printBoardTest2();
	ans &= shotTest1();
	ans &= shotTest2();
	ans &= shotTest3();
	ans &= randPlaceTest();
	ans &= manualPlaceTest();
//	ans &= ;
//	ans &= ;
//	ans &= ;
//	ans &= ;
	return ans;
}

Board *test = new Board();

bool manualPlaceTest() {
//	Board *random = new Board(true);
//	random->printBoard(true);
	return true;
}

bool randPlaceTest() {
	Board *random = new Board(false);
	random->printBoard(true);
	return true;
}

bool printBoardTest() {
	test->printBoard(true);
	return true;
}

bool printBoardTest2() {
	test->printBoard(false);
	return true;
}

bool shotTest1() {
	test->shot(-5, -5);
	test->printBoard(true);
	return true;
}
bool shotTest2() {
	test->shot(5, 5);
	test->printBoard(false);
	return true;
}
bool shotTest3() {
	test->shot(4, 0);
	test->printBoard(true);
	return true;
}
