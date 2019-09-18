/*
 ============================================================================
 Name        : Homework3.c
 Author      : Gus Teran
 Version     :
 Copyright   : Your copyright notice
 Description : A series of classes that emulates a graph of a house including
 its layouts and rooms and a search capability. This program can search for treasure
 within the rooms of the house
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "Teran.h"



int main(int argc, char* argv[]) {
	FILE *outputP = fopen("output.txt", "w");
	fclose(outputP);
	if(tests())
	{
		puts("Tests Passed!");
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
