/*
 * production.c
 *
 *  Created on: Aug 27, 2019
 *      Author: gustt
 */

#include "production.h"

bool production(int argc, char* argv[]) {
	int FILENAMELENGTHALLOWANCE = 100;
	bool answer = false;
	if (argc <= 1) //no interesting information
			{
		puts("Didn’t find any arguments.");
		fflush(stdout);
	} else //there is interesting information
	{
		printf("Found %d arguments.\n", argc);
		fflush(stdout);
		long rows_L;
		int rows = 0;
		long cols_L;
		int cols = 0;
		long gens_L;
		int gens = 0;
		bool print = false;
		bool pause = false;
		char filename[FILENAMELENGTHALLOWANCE];
		for (int i = 1; i < argc; i++)
			//don’t want to read argv[0]{
			//argv[i] is a string
			//in this program our arguments are NR, NC, gens, filename, print and pause
			//because pause is optional, argc could be 6 or 7
			//because print is optional (if print is not present, neither is pause) argc could be 5
			switch (i) {
			case 1:
				//this is NR
				rows_L = strtol(argv[i]);
				rows = (int) rows_L;
				break;
			case 2:
				//this is NC
				cols_L = strtol(argv[i]);
				cols = (int) cols_L;
				break;
			case 3:			//this is gens
				gens_L = strtol(argv[i]);
				gens = (int) gens_L;
				break;
			case 4:			//this is filename
				if (strlen(argv[i] > FILENAMELENGTHALLOWANCE)) {
					puts("Filename is too long.");
				} else {
					strcpy(filename, argv[i]);
				}
				break;
			case 5:
				//this is the optional print
				print = true;
				break;
			case 6:
				//this is the optional pause
				pause = true;
				break;
			default:
				puts("Unexpected argument count.");
				break;
			}
	}
	return answer;
}
