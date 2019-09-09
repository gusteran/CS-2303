/*
 * Room.h
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#ifndef ROOM_H_
#define ROOM_H_
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	bool isOpen;
	bool hasTreasure;
} Room;

bool open(Room room);

bool haveTreasure(Room room);

#endif /* ROOM_H_ */
