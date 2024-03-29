/*
 * tests.c
 *
 *  Created on: Sep 4, 2019
 *      Author: gustt
 */

#include "tests.h"

bool tests() {
	bool answer = true;
	answer &= blankBoardTest();
//	answer &= printArrayTest();
//	answer &= verticalTest1();
//	answer &= verticalTest2();
//	answer &= verticalTest3();
//	answer &= horizontalTest1();
//	answer &= horizontalTest2();
//	answer &= horizontalTest3();
	answer &= compoundTest();
return answer;
}

bool blankBoardTest() {
	bool answer = true;
	Board board = makeBlankBoard(ROWS, COLS);
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			answer &= (0 == board.array[row][col]);
		}
	}
	answer &= (board.marker.x == COLS/2 && board.marker.y == ROWS/2);
	return answer;
}

bool printArrayTest() {
//	board board = makeBlankboard(ROWS, COLS);
	printboard(makeBlankBoard(ROWS, COLS));
	fflush(stdin);
	printf("Does the Board look Correct? (y or other letter): ");
	fflush(stdout);
	char a = getchar();
	bool ans = false;
	if (a == 'y') {
		ans = true;
	}
	return ans;
}

bool verticalTest1() {
	Board board = makeBlankBoard(ROWS, COLS);
	board = vertical(board, 3);
	printboard(board);
	fflush(stdin);
	printf("Does the Board look Correct? (y or other letter): ");
	fflush(stdout);
	char a = getchar();
	bool ans = false;
	if (a == 'y') {
		ans = true;
	}
	return ans;
}

bool verticalTest2() {
	Board board = makeBlankBoard(ROWS, COLS);
	board = vertical(board, -10);
	printboard(board);
	fflush(stdin);
	printf("Does the Board look Correct? (y or other letter): ");
	fflush(stdout);
	char a = getchar();
	bool ans = false;
	if (a == 'y') {
		ans = true;
	}
	return ans;
}

bool verticalTest3() {
	Board board = makeBlankBoard(ROWS, COLS);
	board = vertical(board, 10);
	printboard(board);
	fflush(stdin);
	printf("Does the Board look Correct? (y or other letter): ");
	fflush(stdout);
	char a = getchar();
	bool ans = false;
	if (a == 'y') {
		ans = true;
	}
	return ans;
}

bool horizontalTest1(){
	Board board = makeBlankBoard(ROWS, COLS);
		board = horizontal(board, 3);
		printboard(board);
		fflush(stdin);
		printf("Does the Board look Correct? (y or other letter): ");
		fflush(stdout);
		char a = getchar();
		bool ans = false;
		if (a == 'y') {
			ans = true;
		}
		return ans;
}

bool horizontalTest2(){
	Board board = makeBlankBoard(ROWS, COLS);
		board = horizontal(board, -10);
		printboard(board);
		fflush(stdin);
		printf("Does the Board look Correct? (y or other letter): ");
		fflush(stdout);
		char a = getchar();
		bool ans = false;
		if (a == 'y') {
			ans = true;
		}
		return ans;
}

bool horizontalTest3(){
	Board board = makeBlankBoard(ROWS, COLS);
		board = horizontal(board, 10);
		printboard(board);
		fflush(stdin);
		printf("Does the Board look Correct? (y or other letter): ");
		fflush(stdout);
		char a = getchar();
		bool ans = false;
		if (a == 'y') {
			ans = true;
		}
		return ans;
}

bool compoundTest(){
	Board board = makeBlankBoard(ROWS, COLS);
		board = horizontal(board, 6);
		board = vertical(board, 2);
		board = horizontal(board, -3);
		board = vertical(board, -4);
		printboard(board);
		fflush(stdin);
		printf("Does the Board look Correct? (y or other letter): ");
		fflush(stdout);
		char a = getchar();
		bool ans = false;
		if (a == 'y') {
			ans = true;
		}
		return ans;
}
