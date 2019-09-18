/*
 * search->c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "Search.h"

void searchForTreasure(House house, Search *search) {
	int numLayouts = numAccessibleLayouts(house);
	Layout layoutList[house.nLayouts];
	Layout *layouts = layoutList;
	layouts = accessibleLayouts(house, layouts);
	for (int count = 0; count < numLayouts; count++) {
		searchInLayouts(layouts[count], search);
	}
	printf("We have searched: ");
	for(int countRooms = 0; countRooms < search->nRoomSearched; countRooms++){
		printRoomName(search->roomsSearched[countRooms]);
		if(countRooms+1<search->nRoomSearched) printf(", ");
	}
	printf("\nAnd we have found %f pieces of treasure in this House\n\n", search->treasure);
}

double countTreasure(House house, Search search){
	searchForTreasure(house, &search);
	return search.treasure;
}
