/*
 * Layout.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "Layout.h"

Room* accessibleRooms(Layout layout, Room *rooms) {
	int isAccessible[layout.nRooms];
	isAccessible[0] = 1;
	int roomNum = 0;
	rooms[roomNum++] = layout.rooms[0];
	for (int row = 0; row < layout.nRooms; row++) {
		if (isAccessible[row] == 1) {
			for (int col = 0; col < layout.nRooms; col++) {
				if (row != col && isAccessible[col] != 1
						&& layout.roomGraph[row * layout.nRooms + col] == 1) {
					isAccessible[col] = 1;
					rooms[roomNum++] = layout.rooms[col];
				}
			}
		}
	}
	return rooms;
}

int numAccessibleRooms(Layout layout) {
	int isAccessible[layout.nRooms];
	isAccessible[0] = 1;
	int numAccessible = 1;
	for (int row = 0; row < layout.nRooms; row++) {
		if (isAccessible[row] == 1) {
			for (int col = 0; col < layout.nRooms; col++) {
				if (row != col && isAccessible[col] != 1
						&& layout.roomGraph[row * layout.nRooms + col] == 1) {
					isAccessible[col] = 1;
					numAccessible++;
				}
			}
		}
	}
	return numAccessible;
}

void printLayoutName(Layout layout) {
	printf("Layout %d", layout.layoutNum);
}

void printGraph(Layout layout) {
	for (int i = 0; i < layout.nRooms; i++) {
		for (int j = 0; j < layout.nRooms; j++) {
			printf("%d\n", layout.roomGraph[i * layout.nRooms + j]);
		}
	}
}
