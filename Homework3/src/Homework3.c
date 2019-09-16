/*
 ============================================================================
 Name        : Homework3.c
 Author      : Gus Teran
 Version     :
 Copyright   : Your copyright notice
 Description : A series of classes that emulates a graph of a house including
 its layouts and rooms and a search capability.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "Teran.h"



int main(int argc, char* argv[]) {
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
