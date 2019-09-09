/*
 * Board.c
 *
 *  Created on: Aug 25, 2019
 *      Author: Therese
 */


#include "Board.h"
void displayBoard(int* board, int nRows, int nCols)
{

	int* cellP = (int*) 0; //initialize the pointer
	int cellContent = 0;
	for (int row = 0; row<nRows; row++)
	{
		printf("|"); //start the row with a vertical bar
		for(int col = 0; col<nCols; col++)
		{
			cellP = board+(row*nCols)+col;
			cellContent = *cellP;
			//content is ``what's at'' where the pointer is pointing
			printf("%d",cellContent);
		}
		printf("|\n"); //end the row with a vertical bar
		//and go to a new line
	}
}
void displayCharBoard(char* board, int nRows, int nCols)
{

	char* cellP = (char*) 0; //initialize the pointer
	int cellContent = 0;
	for (int row = 0; row<nRows; row++)
	{
		printf("|"); //start the row with a vertical bar
		for(int col = 0; col<nCols; col++)
		{
			cellP = board+(row*nCols)+col;
			cellContent = *cellP;
			//content is ``what's at'' where the pointer is pointing
			printf("%c",cellContent);
		}
		printf("|\n"); //end the row with a vertical bar
		//and go to a new line
	}
}

