/*
 * House.h
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#ifndef HOUSE_H_
#define HOUSE_H_
#include "Layout.h"


typedef struct{
	int nLayouts;
	Layout *layouts;
	int **layoutGraph;
} House;

Layout* accessibleLayouts(House house, Layout *layouts);

int numAccessibleLayouts(House house);

Search countTreasureInLayouts(Layout layout, Search search);

Room getNewRoom(House house);


#endif /* HOUSE_H_ */
