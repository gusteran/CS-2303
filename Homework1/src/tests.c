/*
 * tests.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "tests.h"

bool tests(){
	bool answer = true;
	answer &= openTest1();
	answer &= openTest2();
	answer &= getFirstRoomTest();
	answer &= getNewRoomTest();
	answer &= haveTreasureTest1();
	answer &= haveTreasureTest2();
	answer &= haveTreasuretest3();
	answer &= countRoomsTest1();
//	answer &= countRoomsTest2();
//	answer &= getNumberRoomsTest();
	return answer;
}

Room rooms[2] = {{true, false}, {true, true}};
Room moreRooms[3] = {{false, true},{false, true},{false, true}};
Room room1 = {true, false};
Room room2 = {true, true};
Room room3 = {false, true};
Layout layout1 = {rooms};
Layout layout2 = {moreRooms};
Layout layouts[2] = {{rooms}, {moreRooms}};
House house1 = {layouts};

bool openTest1(){
	return !open(room3);
}

bool openTest2(){
	return open(room2);
}

bool getFirstRoomTest(){
	return open(getFirstRoom(layout1));
}

bool getNewRoomTest(){
	return open(getNewRoom(house1));
}

bool haveTreasureTest1(){
	return !getTreasure(room1);
}

bool haveTreasureTest2(){
	return getTreasure(room2);
}

bool haveTreasuretest3(){
	return !getTreasure(room3);
}

bool countRoomsTest1(){
	return countRooms(layout1) == 2;
}

bool countRoomsTest2(){
	return countRooms(layout2) == 3;
}

bool getNumberRoomsTest(){
	return getNumberOfRooms(house1) == 5;
}
