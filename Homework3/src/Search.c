/*
 * Search.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "Search.h"

Search countTreasure(House house, Search search) {
	int numLayouts = numAccessibleLayouts(house);
	Layout layoutList[house.nLayouts];
	Layout *layouts = layoutList;
	layouts = accessibleLayouts(house, layouts);
	for (int count = 0; count < numLayouts; count++) {
		search = countTreasureInLayouts(layouts[count], search);
	}
	printf("We have searched: ");
	for(int countRooms = 0; countRooms < search.nRoomSearched; countRooms++){
		printRoomName(search.roomsSearched[countRooms]);
		if(countRooms+1<search.nRoomSearched) printf(", ");
	}
	printf("\nAnd we have found %d pieces of treasure in this House\n\n", search.treasure);
	return search;
}

