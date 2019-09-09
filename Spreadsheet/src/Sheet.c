/*
 * Sheet.c
 *
 *  Created on: Aug 22, 2019
 *      Author: Therese
 */


#include "Sheet.h"



MeanAndVariance giveMeanAndVariance(double* ourData, int nSheets, int nRows, int nCols, int sheetNum)
{
	MeanAndVariance mv={.2, .1};
    double* dp = (void*)0; //initialize pointers to null
	double mean = 0;
	double variance = 0;
	if ((sheetNum <0) || (nSheets<1) || (nRows < 1) || (nCols <1))
	{
		mv.variance = -1;
	}
	else
	{
		for(int row = 0; row<nRows; row++)
		{
			for(int col = 0; col<nCols; col++)
			{
				dp = ourData + (sheetNum)*(nRows*nCols)+(row*nCols)+col; //data pointer
				mean = mean + (*dp);
				variance = variance + (*dp) * (*dp);
			}
		}
		mean = mean/(nRows*nCols);
		variance = variance/(nRows*nCols) - mean*mean;
		mv.mean = mean;
		mv.variance = variance;
	}
	return mv;
}

void giveArrayAndSize(double* ourData, int nSheets, int nRows, int nCols)
{


}
