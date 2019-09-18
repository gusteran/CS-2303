/*
 * tests.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "tests.h"

bool tests(){
	initialize();
	bool answer = true;
	answer &= countRooms1();
	answer &= accessibleRooms1();
	answer &= countTreasureLayouts1();
	answer &= countTreasure1();
	answer &= countRooms2();
	answer &= accessibleRooms2();
	answer &= countTreasureLayouts2();
	answer &= countTreasureLayouts3();
	answer &= countTreasure2();
	answer &= countTreasure3();
//	answer &=
	return answer;
}

const Room room0 = {0, false, false};
const Room room1 = {1, true, false};
const Room room2 = {2, true, 1};
const Room room3 = {3, true, 3};
Room rooms1[4] = {room0, room1, room2, room3};
int roomGraph1[4][4] = {{1, 1, 0, 0}, {1, 1, 1, 1}, {0, 1, 1, 0}, {0, 1, 0, 1}};
int **roomGraph1P = new int*[4];
const Layout layout1 = {1, 4, rooms1, roomGraph1P};
const Room room10 = {10, false, false};
const Room room11 = {11, true, false};
const Room room12 = {12, true, false};
const Room room13 = {13, true, 5};
Room rooms2[4] = {room10, room11, room12, room13};
int roomGraph2[4][4] = {{1, 0, 0, 1}, {0, 1, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 1}};
int **roomGraph2P = new int*[4];
const Layout layout2 = {2, 4, rooms2, roomGraph2P};
int layoutGraph[2][2] = {{1,1},{1,1}};
int **layoutGraphP = new int*[2];
Layout layouts[2] = {layout1, layout2};
House house = {2, layouts, layoutGraphP};




void initialize(){

	for(int i = 0; i < 4; i++){
	   roomGraph1P[i] = roomGraph1[i];
	}

	for(int i = 0; i < 4; i++){
	   roomGraph2P[i] = roomGraph2[i];
	}


	for(int i = 0; i < 2; i++){
	   layoutGraphP[i] = layoutGraph[i];
	}


}

double treasure = 0;
double maxTreasure = 10;
int nRooms = 0;
int maxRooms = 20;


bool countRooms1(){
	return numAccessibleRooms(layout1) == 4;
}
bool accessibleRooms1(){
	bool ans = true;
	Room roomList[4];
	Room *roomsTest = roomList;
	roomsTest= accessibleRooms(layout1, roomsTest);
	for(int i = 0; i < 4; i++){
		ans &= rooms1[i].isOpen == roomsTest[i].isOpen && rooms1[i].treasure == roomsTest[i].treasure;
	}
	return ans;
}

bool countTreasureLayouts1(){
	Room roomsSearched[maxRooms];
	Search baseSearch = {treasure, maxTreasure, nRooms, maxRooms, roomsSearched};
	searchInLayouts(layout1, &baseSearch);
	return baseSearch.treasure == 1+3;
}

bool countRooms2(){
	return numAccessibleRooms(layout2) == 2;
}
bool accessibleRooms2(){
	bool ans = true;
		Room room2List[2] = {room10, room13};
		Room *roomsTest = room2List;
		roomsTest= accessibleRooms(layout2, roomsTest);
		for(int i = 0; i < 2; i++){
			ans &= room2List[i].isOpen == roomsTest[i].isOpen && room2List[i].treasure == roomsTest[i].treasure;
		}
		return ans;
}
bool countTreasureLayouts2(){
	Room roomsSearched[maxRooms];
	Search baseSearch = {treasure, maxTreasure, nRooms, maxRooms, roomsSearched};
	searchInLayouts(layout2, &baseSearch);
	return baseSearch.treasure == 5;
}

bool countTreasure1(){
	Room roomsSearched[maxRooms];
	Search baseSearch = {treasure, maxTreasure, nRooms, maxRooms, roomsSearched};
	return countTreasure(house, baseSearch) == 1+3+5;
}

bool countTreasureLayouts3(){
	Room roomsSearched[maxRooms];
	int maxRooms = 3;
	Search baseSearch = {treasure, maxTreasure, nRooms, maxRooms, roomsSearched};
	searchInLayouts(layout1, &baseSearch);
	return baseSearch.treasure == 1;
}

bool countTreasure2(){
	int maxRooms = 4;
	Room roomsSearched[maxRooms];
	Search baseSearch = {treasure, maxTreasure, nRooms, maxRooms, roomsSearched};
	return countTreasure(house, baseSearch) == 1+3;
}

bool countTreasure3(){
	double maxTreasure = 2;
	Room roomsSearched[maxRooms];
	Search baseSearch = {treasure, maxTreasure, nRooms, maxRooms, roomsSearched};
	return countTreasure(house, baseSearch) == 1+3;
}


