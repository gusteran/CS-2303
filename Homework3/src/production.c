/*
 * production.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "production.h"

bool production(int argc, char *argv[]) {
//	int FILENAMELENGTHALLOWANCE = 100;
	bool answer = false;
	int treasure = 0;
	int maxRooms = 100;
	int nRooms = 0;
	int maxTreasure = 100;
	char *eptr;
	if (argc <= 2) //no interesting information
			{
		puts("Found the wrong number of arguments");
		fflush(stdin);
		printf("What is the maximum number of rooms to be searched? ");
		fflush(stdout);
		scanf("%d", &maxRooms);
		fflush(stdin);
		printf("What is the maximum amount of treasure to be searched for? ");
		fflush(stdout);
		scanf("%d", &maxTreasure);
	} else //there is interesting information
	{
//		printf("\nNumber Of Arguments Passed: %d",argc);
		for (int i = 1; i < argc; i++) {
			switch (i) {
			case 1:
				maxRooms = (int) strtol(argv[i], &eptr, 10);
//				printf("maxRooms = %d\n", maxRooms);
				break;
			case 2:
				maxTreasure = (int) strtol(argv[i], &eptr, 10);
//				printf("maxTreasure = %d\n", maxTreasure);
				break;
			default:
				printf("\nExtra argument \"%d\" found \n\n",
						(int) strtol(argv[i], &eptr, 10));
				break;
			}
		}
	}

	while(maxRooms < 0 || maxRooms > 1000){
				fflush(stdin);
				printf("What is the maximum number of rooms to be searched? ");
				fflush(stdout);
				scanf("%d", &maxRooms);
	}
	while(maxTreasure<0 || maxTreasure>1000){
		fflush(stdin);
		printf("What is the maximum amount of treasure to be searched for? ");
		fflush(stdout);
		scanf("%d", &maxTreasure);
	}

	FILE *fp = fopen("houseGraph.txt", "r");
	Room roomsSearched[maxRooms];
	Search search = { treasure, maxTreasure, nRooms, maxRooms, roomsSearched };
	fseek(fp, 0L, SEEK_END);
	int size = ftell(fp);
	rewind(fp);
	char readIn[size];
	fread(&readIn, sizeof(readIn), 1, fp);
	fclose(fp);
	int countCharacters = 0;

	int numRooms = readIn[countCharacters] - '0';
//	printf("numRooms %d\n", numRooms);
	int roomGraph[numRooms][numRooms];
	for (int i = 0; i < numRooms; i++) {
		for (int j = 0; j < numRooms; j++) {
			countCharacters += 2;
//			printf("Char %d: %c is value %d\n", countCharacters, readIn[countCharacters], readIn[countCharacters]);
			roomGraph[i][j] = readIn[countCharacters] - '0';
		}
	}
	countCharacters += 1;
	Room roomList[numRooms];
	for (int i = 0; i < numRooms; i++) {
		Room room = { i + 1, true, 0 };
		roomList[i] = room;
		while (readIn[++countCharacters] >= '0'
				&& readIn[countCharacters] <= '9' && countCharacters < size) {
//			printf("Read in val: %c %d\n", readIn[countCharacters], readIn[countCharacters]);
			roomList[i].treasure = roomList[i].treasure * 10
					+ readIn[countCharacters] - '0';
		}
//		printf("Treasure for %d = %d\n", i, roomList[i].treasure);
	}
	Layout layout = { 1, numRooms, roomList, roomGraph };
	Layout layouts[1] = { layout };
	House house = { 1, layouts, { { 1 } } };
	printf("Count treasure = %d", searchForTreasure(house, search).treasure);
	return answer;
}
