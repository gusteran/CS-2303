/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include "production.h"
#include <string.h> //for strcpy
#include <stdlib.h> //for strtol

bool production(int argc, char* argv[])
{
	bool answer = true;
	if(argc <=1) //no interesting information
	{
        puts("Didn't find any arguments.");
        fflush(stdout);
        answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d arguments.\n", argc);
		fflush(stdout);
		long rows_L;
		int rows =0;
		long cols_L;
		int cols = 0;
		long gens_L;
		int gens = 0;
		bool print = false;
		bool pause = false;
		char filename[FILENAMELENGTHALLOWANCE];
		char *eptr;
		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string
			//in this program our arguments are NR, NC, gens, filename, print and pause
			//because pause is optional, argc could be 6 or 7
			//because print is optional (if print is not present, neither is pause) argc could be 5
			switch(i)
			{
			case 1:
				//this is NR
				rows_L = strtol(argv[i], &eptr, 10);
				rows = (int) rows_L;
				if(rows<1)
				{
					answer = false;
				}
				else
				{
					printf("Asked for %d rows.\n",rows);
					fflush(stdout);
				}
				break;
			case 2:
				//this is NC
				cols_L = strtol(argv[i], &eptr, 10);
				cols = (int) cols_L;
				if(cols<1)
				{
					answer = false;
				}
				else
				{
					printf("Asked for %d columns.\n",cols);
					fflush(stdout);
				}
				break;
			case 3:
				//this is gens
				gens_L = strtol(argv[i], &eptr, 10);
				gens = (int) gens_L;
				if(gens<1)
				{
					answer = false;
				}
				else
				{
					printf("Asked for %d generations.\n",gens);
					fflush(stdout);
				}
				break;
			case 4:
				//this is filename
				printf("The length of the filename is %d.\n",strlen(argv[i]));
				printf("The proposed filename is %s.\n", argv[i]);
				if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
				{
					puts("Filename is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					strcpy(filename, argv[i]);
					printf("Filename was %s.\n", filename);
					fflush(stdout);
				}
				break;
			case 5:
				//this is the optional print
				print= true;
				break;
			case 6:
				//this is the optional pause
				pause = true;
				break;
			default:
				puts("Unexpected argument count.");
				fflush(stdout);
				answer = false;
				break;
			}
		}
	}
	return answer;
}
