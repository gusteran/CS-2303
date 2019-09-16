/*
 * Layout.h
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#ifndef LAYOUT_H_
#define LAYOUT_H_
#include "Room.h"
typedef struct {
	int layoutNum;
	int nRooms;
	Room *rooms; // the actual rooms themselves
	int **roomGraph; //2D array of whether it can be entered
} Layout;

void printLayoutName(Layout layout);

void printGraph(Layout layout);

Room* accessibleRooms(Layout layout, Room *rooms);

int numAccessibleRooms(Layout layout);

Room getFirstRoom(Layout layout);


#endif /* LAYOUT_H_ */
