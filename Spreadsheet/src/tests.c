/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "Sheet.h"


bool tests()
{
	bool answer = false;
	bool ok1 =  testSheetMandV();
	answer = ok1;
	return answer;
}

bool testSheetMandV()
{
	bool ok = false; //this is for the logical AND of the test cases.
	printf("running testSheetMandV\n");
	//There should be an array of data, that corresponds to the spreadsheet data.
	//Each sheet should be able to access at least its own data.
	//Let's say that the sheet functions are told which sheet, it is called sheetNum in the function prototype.
	//Let's use 0 to some positive number as the appropriate range for the sheetNum parameter.
	//Therefore we can make a test case with a negative sheet number,
	//and it will be the job of the function to reject such a request.

	int nSheets = 2;
	int nRows =3;
	int nCols= 4;
	double ourData[nSheets][nRows][nCols];
	for(int sheet = 0; sheet<nSheets; sheet++)
	{
		for(int row = 0; row<nRows; row++)
		{
			for(int col = 0; col<nCols; col++)
			{
				ourData[sheet][row][col]= 5; //mean will be 5, variance will be zero
			}
		}
	}
	double* dp = (double*)ourData;

	bool ok1 = false;
	int sheetNum = -3;
	MeanAndVariance mv = giveMeanAndVariance(dp, nSheets, nRows, nCols, sheetNum);
	if (mv.variance <0)
	{
		printf("Negative sheet number test passed.\n");
		ok1 = true;
	}
	bool ok2 = false;
    sheetNum = 0;
	mv = giveMeanAndVariance(dp, nSheets, nRows, nCols, sheetNum);
	double tolerance = 0.0000001;
	if (((mv.variance < tolerance) && (mv.variance >-tolerance)) && (mv.mean < 5+tolerance)&& (mv.mean > 5-tolerance))
	{
		printf("Positive sheet number test passed.\n");
		ok2 = true;
	}

	ok = ok1 && ok2;
	return ok;
}
