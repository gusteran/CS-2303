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
	float treasure = 0;
	int maxRooms = 100;
	int nRooms = 0;
	float maxTreasure = 100;
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
		scanf("%f", &maxTreasure);
	} else //there is interesting information
	{
		for (int i = 1; i < argc; i++) {
			switch (i) {
			case 1:
				maxRooms = atof(argv[i]);
				break;
			case 2:
				maxTreasure = atof(argv[i]);
				break;
			default:
				printf("\nExtra argument \"%d\" found \n\n",
						(int) strtol(eptr, &eptr, 10));
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
	int roomGraph[numRooms][numRooms];
	int **roomGraphP = new int*[numRooms];
	for (int i = 0; i < numRooms; i++) {
		for (int j = 0; j < numRooms; j++) {
			countCharacters += 2;
			roomGraph[i][j] = readIn[countCharacters] - '0';
		}
	}
	for(int i = 0; i < numRooms; i++){
			   roomGraphP[i] = roomGraph[i];
	}
	countCharacters += 1;
	Room roomList[numRooms];
	for (int i = 0; i < numRooms; i++) {
		Room room = { i + 1, true, 0 };
		roomList[i] = room;
		while (readIn[++countCharacters] >= '0'
				&& readIn[countCharacters] <= '9' && countCharacters < size) {
			roomList[i].treasure = roomList[i].treasure * 10
					+ readIn[countCharacters] - '0';
		}
	}
	Layout layout = { 1, numRooms, roomList, roomGraphP };
	Layout layouts[1] = { layout };
	int layoutGraph[1][1] = {{1}};
	int **layoutGraphP = new int*[1];
	layoutGraphP[0] = layoutGraph[0];
	House house = { 1, layouts, layoutGraphP };
	printf("Count treasure = %.1f", countTreasure(house, search));
	return answer;
}
