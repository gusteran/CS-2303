/*
 * Room.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */
#include <stdio.h>

#include "Room.h"

bool open(Room room){
	return room.isOpen;
}

bool getTreasure(Room room){
	return room.isOpen && room.hasTreasure;
}
