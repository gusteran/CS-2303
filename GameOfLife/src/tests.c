/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "Board.h"
#include <math.h> //for max

bool tests()
{
	bool answer = false;
	bool ok1 = testDisplayBoard();
	bool ok2 = testFileInput();
	bool ok3 = testDisplayBoard2();
	answer = ok1 && ok2 && ok3;
	return answer;
}

bool testDisplayBoard2(){
	int nRows = 8;
	int nCols = 6;
	int theBoards[nBOARDS][nRows][nCols];
	fflush(stdout);
	for(int board = 0; board<nBOARDS; board++)
		{
			for(int row=0; row<nRows; row++)
			{
				for(int col=0; col<nCols; col++)
				{
					theBoards[board][row][col] = (row==col | row==nRows-col); //X matrix
				}
			}
		}
	int* b0 = &(theBoards[0][0][0]);
	int* b1 = &(theBoards[1][0][0]);
	int* b2 = &(theBoards[2][0][0]);
	//here's the test
	puts("Here's board 0");
	displayBoard(b0, nRows, nCols);
	puts("Here's board 1");
	displayBoard(b1, nRows, nCols);
	puts("Here's board 2");
	displayBoard(b2, nRows, nCols);

	fflush(stdin);
	printf("Did they look like an X? (y or other letter): ");
	fflush(stdout);
	char a = getchar();
	bool ans = false;
	if (a == 'y')
	{
		ans =  true;
	}

	return ans;

}

bool testDisplayBoard()
{
	puts("starting testDisplayBoard");
	fflush(stdout);
	bool ok = false;
	//we need to have a board before we can display it.
	//the boards can be represented in arrays, one dimension for row, one for column
	//we could even have a dimension for the past, current and future boards.
	//this is a test case
	int nRows = 6;
	int nCols = 8;

	int theBoards[nBOARDS][nRows][nCols];
	//we set one board to a known pattern
	//we'll print out the pattern to the console
	//checking by eye.
	//set the known pattern:
	puts("initializing the board");
	fflush(stdout);
	for(int board = 0; board<nBOARDS; board++)
	{
		for(int row=0; row<nRows; row++)
		{
			for(int col=0; col<nCols; col++)
			{
				theBoards[board][row][col] = (row==col); //diagonal matrix
			}
		}
	}
	int* b0 = &(theBoards[0][0][0]);
	int* b1 = &(theBoards[1][0][0]);
	int* b2 = &(theBoards[2][0][0]);
	//here's the test
	puts("Here's board 0");
	displayBoard(b0, nRows, nCols);
	puts("Here's board 1");
	displayBoard(b1, nRows, nCols);
	puts("Here's board 2");
	displayBoard(b2, nRows, nCols);

	fflush(stdin);
	printf("Did they look like diagonal matrices?(y or other letter): ");
	fflush(stdout);
	char a = getchar();
	if (a == 'y')
	{
		ok = true;
	}

	return ok;
}

bool testFileInput()
{
	puts("starting testFileInput");
	fflush(stdout);
	bool ok = false;
	//test case
	//we know our first file is named GoL1.txt.
	//we know our purpose for opening is read

	//we will prepare our target array as in testDisplayBoard
	int nRows = 6;//these are big enough for GoL1.txt's data/
	int nCols = 8;
	char theBoards[nBOARDS][nRows][nCols];
	for(int sheet = 0; sheet<nBOARDS; sheet++)
	{
		for(int row= 0; row<nRows; row++)
		{
			for(int col = 0; col<nCols; col++)
			{
				theBoards[sheet][row][col]= ' ';//initialize to blank char
			}
		}
	}


	FILE* fp = fopen("GoL1.txt", "r");
	puts("Attempting to open file");
	fflush(stdout);
	if(fp==NULL)
	{
		puts("Could not find that file.");
	}
	else
	{
		puts("found the file.");
		fflush(stdout);
		//now we want to read the lines of the file
		//and set the values into the array.
		//we will want to center the pattern
		//so we will want to know how long the longest line is, and
		//how many lines there are in the file
		int howManyLines = 0;
		int maxCharsFound = 0;
		int charsFound = 0;
		char ch;
		int row = 0;
		int col = 0;
		while((ch = fgetc(fp)) != EOF)
		{
			charsFound = 0;//this is on a per line basis

			while((ch != '\n') && (ch != '\r') && (ch != EOF))//this loop handles a line
			{
				theBoards[0][row][col]= ch; //put the character in 0th board
				charsFound++; //update the number of chars found
				ch = fgetc(fp); //get a new character
				col++;
			}
			//we have reached a new line
			row++;
			col=0;
			howManyLines++;
			maxCharsFound = (charsFound> maxCharsFound)? charsFound : maxCharsFound;
		}
		fclose(fp);
		puts("closing the file");
		printf("The file has %d lines.\n", howManyLines);
		printf("The longest line has %d characters.\n", maxCharsFound);
		//now we know how many lines, and
		//the length of the longest line
		int offsetV = (int)floor((nRows-howManyLines)/2);
		int offsetH = (int)floor((nCols-maxCharsFound)/2);
		printf("The vertical offset is %d.\n", offsetV);
		printf("The horizontal offset is %d.\n", offsetH);
		fflush(stdout);
		if((offsetV <0) || (offsetH <0))
		{
			puts("The file is too big for the array.");
			fflush(stdout);
		}
		else
		{
			int wrow;
			int wcol;
			for(int rrow = 0; rrow< howManyLines; rrow++)
			{
				for(int rcol = 0; rcol<maxCharsFound; rcol++)
				{
					wrow = rrow+offsetV;
					wcol = rcol+offsetH;
					theBoards[1][wrow][wcol] = theBoards[0][rrow][rcol];

				}
			}
		}
		//display the results
		char* b0 = &(theBoards[0][0][0]);
		char* b1 = &(theBoards[1][0][0]);
		//here's the test
		puts("Here's board from file");
		displayCharBoard(b0, nRows, nCols);
		puts("Here's board as centered");
		displayCharBoard(b1, nRows, nCols);
        fflush(stdin);
		printf("Did the board look like the file?(y or other letter): ");
		fflush(stdout);
		char a = getchar();
		if (a == 'y')
		{
			ok = true;
		}
	}
	return ok;

}

