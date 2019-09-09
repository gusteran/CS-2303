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
	Layout *layouts;
} House;

int getNumberOfRooms(House house);

Room getNewRoom(House house);


#endif /* HOUSE_H_ */
