/*
 * House.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "House.h"

int getNumberOfRooms(House house){
	int count = 0;
	for(int i = 0; i < sizeof(house.layouts)/sizeof(Layout); i++){
		count += countRooms(house.layouts[i]);
	}
	return count;
}

Room getNewRoom(House house){
	return getFirstRoom(house.layouts[0]);
}



