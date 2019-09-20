/*
 * House.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "House.h"

Layout* accessibleLayouts(House house, Layout *layouts) {
	int isAccessible[house.nLayouts];
	isAccessible[0] = 1;
	int layoutNum = 0;
	layouts[layoutNum++] = house.layouts[0];
	for (int row = 0; row < house.nLayouts; row++) {
		if (isAccessible[row] == 1) {
			for (int col = 0; col < house.nLayouts; col++) {
				if (row != col && isAccessible[col] != 1
						&& house.layoutGraph[row][col] == 1) {
					isAccessible[col] = 1;
					layouts[layoutNum++] = house.layouts[col];
				}
			}
		}
	}
	return layouts;
}

int numAccessibleLayouts(House house) {
	int isAccessible[house.nLayouts];
	isAccessible[0] = 1;
	int numAccessible = 1;
	for (int row = 0; row < house.nLayouts; row++) {
		if (isAccessible[row] == 1) {
			for (int col = 0; col < house.nLayouts; col++) {
				if (row != col && isAccessible[col] != 1
						&& house.layoutGraph[row][col] == 1) {
					isAccessible[col] = 1;
					numAccessible++;
				}
			}
		}
	}
	return numAccessible;
}

void searchInLayouts(Layout layout, Search *search) {
	FILE *outputP = fopen("output.txt", "r+");
	fseek(outputP, 0L, SEEK_END);
	int countRooms = search->nRoomSearched;
	int pastTreasure = search->treasure;
	int numRooms = numAccessibleRooms(layout);
	Room roomList[numRooms];
	Room *rooms = roomList;
	rooms = accessibleRooms(layout, rooms);
	for (int count = 0;count < numRooms && search->nRoomSearched < search->maxRooms && search->treasure < search->maxTreasure; count++) {
		search->treasure += rooms[count].treasure;
		fprintf(outputP, "In room %d, we have found %.1f pieces of treasure\n", rooms[count].roomNum, search->treasure);
		search->roomsSearched[search->nRoomSearched++] = rooms[count];
	}
	printf("We have searched: ");
	for (; countRooms < search->nRoomSearched; countRooms++) {
		printRoomName(search->roomsSearched[countRooms]);
		if (countRooms + 1 < search->nRoomSearched)
			printf(", ");
	}
	fprintf(outputP,"\n");
	fclose(outputP);
	printf("\nAnd we have found %.1f pieces of treasure in this Layout\n\n",
			search->treasure - pastTreasure);
}

