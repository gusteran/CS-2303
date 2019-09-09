/*
 * Sheet.h
 *
 *  Created on: Aug 22, 2019
 *      Author: Therese
 */

#ifndef SHEET_H_
#define SHEET_H_

typedef struct
{
	double mean;
	double variance; //cannot be negative, so negative means bad arguments
} MeanAndVariance;


MeanAndVariance giveMeanAndVariance(double* ourData, int nSheets, int nRows, int nCols, int sheetNum);

#endif /* SHEET_H_ */
