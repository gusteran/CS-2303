/*
 * Room.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */
#include <stdio.h>

#include "Room.h"

void printRoomName(Room room){
	printf("Room %d",room.roomNum);
}

bool open(Room room){
	return room.isOpen;
}

int getTreasure(Room room){
	return (room.isOpen) ? room.treasure:0;
}
