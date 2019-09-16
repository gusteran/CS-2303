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
	int roomNum;
	bool isOpen;
	int treasure;
} Room;


typedef struct {
	int treasure;
	int maxTreasure;
	int nRoomSearched;
	int maxRooms;
	Room *roomsSearched; //define as array of size maxRooms
} Search;

void printRoomName(Room room);

bool open(Room room);

int getTreasure(Room room);

#endif /* ROOM_H_ */
