/*
 * Teran.h
 *
 *  Created on: Aug 28, 2019
 *      Author: Gus Teran
 */

#ifndef TERAN_H_
#define TERAN_H_
#include "Search.h"

bool open(Room room);

bool numTreasure(Room room);

int countRooms(Layout layout);

Room getFirstRoom(Layout layout);

int getNumberOfRooms(House house);

Room getNewRoom(House house);

#endif /* TERAN_H_ */
