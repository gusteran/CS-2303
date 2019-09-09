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
	Room *rooms;
} Layout;

int countRooms(Layout layout);

Room getFirstRoom(Layout layout);


#endif /* LAYOUT_H_ */
